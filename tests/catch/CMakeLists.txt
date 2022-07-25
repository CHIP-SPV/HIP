cmake_minimum_required(VERSION 3.16.8)

# to skip the simple compiler test
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

project(hiptests)

# function to be called by all tests
function(hip_add_exe_to_target)
  set(options)
  set(args NAME TEST_TARGET_NAME PLATFORM COMPILE_OPTIONS)
  set(list_args TEST_SRC LINKER_LIBS PROPERTY)
  cmake_parse_arguments(
    PARSE_ARGV 0
    "" # variable prefix
    "${options}"
    "${args}"
    "${list_args}"
  )

  # If using CHIP-SPV, build tests as standlone for now
  list(LENGTH TEST_SRC LEN)
  MATH(EXPR LEN "${LEN}-1")
  if(HIP_PLATFORM MATCHES "spirv")
    foreach(X RANGE ${LEN})
      list(GET TEST_SRC ${X} SRC_NAME)
      catch_executable("${SRC_NAME}")
    endforeach()
  else()
    # Create shared lib of all tests
    add_executable(${_NAME} EXCLUDE_FROM_ALL ${_TEST_SRC} $<TARGET_OBJECTS:Main_Object>)
    catch_discover_tests(${_NAME} PROPERTIES  SKIP_REGULAR_EXPRESSION "HIP_SKIP_THIS_TEST")
    if(UNIX)
      set(_LINKER_LIBS ${_LINKER_LIBS} stdc++fs)
    endif()
    if(DEFINED _LINKER_LIBS)
      target_link_libraries(${_NAME} ${_LINKER_LIBS})
    endif()

    # Add dependency on build_tests to build it on this custom target
    add_dependencies(${_TEST_TARGET_NAME} ${_NAME})

    if (DEFINED _PROPERTY)
      set_property(TARGET ${_NAME} PROPERTY ${_PROPERTY})
    endif()

    if (DEFINED _COMPILE_OPTIONS)
      target_compile_options(${_NAME} PUBLIC ${_COMPILE_OPTIONS})
    endif()

    foreach(arg IN LISTS _UNPARSED_ARGUMENTS)
        message(WARNING "Unparsed arguments: ${arg}")
    endforeach()

  endif()
endfunction()

# Check if platform and compiler are set
if(HIP_PLATFORM STREQUAL "amd")
    if(HIP_COMPILER STREQUAL "nvcc")
        message(FATAL_ERROR "Unexpected HIP_COMPILER:${HIP_COMPILER} is set for HIP_PLATFOR:amd")
    endif()
elseif(HIP_PLATFORM STREQUAL "nvidia")
    if(NOT DEFINED HIP_COMPILER OR NOT HIP_COMPILER STREQUAL "nvcc")
        message(FATAL_ERROR "Unexpected HIP_COMPILER: ${HIP_COMPILER} is set for HIP_PLATFORM:nvidia")
    endif()
elseif(HIP_PLATFORM STREQUAL "spirv")
    if(NOT DEFINED HIP_COMPILER OR NOT HIP_COMPILER STREQUAL "clang")
        message(FATAL_ERROR "Unexpected HIP_COMPILER: ${HIP_COMPILER} is set for HIP_PLATFORM:spirv")
    endif()
else()
    message(FATAL_ERROR "Unexpected HIP_PLATFORM: " ${HIP_PLATFORM})
endif()

# Set HIP Path
if(NOT DEFINED HIP_PATH)
    if(DEFINED ENV{HIP_PATH})
        set(HIP_PATH $ENV{HIP_PATH} CACHE STRING "HIP Path")
    else()
        set(HIP_PATH "${PROJECT_BINARY_DIR}")
    endif()
endif()
message(STATUS "HIP Path: ${HIP_PATH}")

# TODO HIP Add support for hipcc
# if(UNIX)
#     set(CMAKE_CXX_COMPILER "${HIP_PATH}/bin/hipcc")
#     set(CMAKE_C_COMPILER "${HIP_PATH}/bin/hipcc")
# else()
#     # using cmake_path as it handles path correctly.
#     # Set both compilers else windows cmake complains of mismatch
#     cmake_path(SET CMAKE_CXX_COMPILER "${HIP_PATH}/bin/hipcc.bat")
#     cmake_path(SET CMAKE_C_COMPILER "${HIP_PATH}/bin/hipcc.bat")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --rocm-path=${ROCM_PATH}")
# endif()


# Use Catch2 Submodule instead
# if(NOT DEFINED CATCH2_PATH)
#     if(DEFINED ENV{CATCH2_PATH})
#         set(CATCH2_PATH $ENV{CATCH2_PATH} CACHE STRING "Catch2 Path")
#     else()
#         set(CATCH2_PATH "${CMAKE_CURRENT_LIST_DIR}/external/Catch2")
#     endif()
# endif()
# message(STATUS "Catch2 Path: ${CATCH2_PATH}")

# Set JSON Parser path
if(NOT DEFINED JSON_PARSER)
    if(DEFINED ENV{JSON_PARSER})
        set(JSON_PARSER $ENV{JSON_PARSER} CACHE STRING "JSON Parser Path")
    else()
        set(JSON_PARSER "${CMAKE_CURRENT_LIST_DIR}/external/picojson")
    endif()
endif()

message(STATUS "Searching Catch2 in: ${CMAKE_CURRENT_LIST_DIR}/external")
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW) 
set(CATCH_BUILD_STATIC_LIBRARY ON)
set(Catch2_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/external/Catch2")
add_subdirectory(${Catch2_SOURCE_DIR})
list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/contrib)


include(Catch)
include(CTest)

include_directories(
    ${CATCH2_PATH}
    "./include"
    ${HIP_PATH}/include
    ${JSON_PARSER}
    ${CHIP_SRC_DIR}/HIP/include  #TODO
    ${CHIP_SRC_DIR}/include # TODO
)

file(COPY ./hipTestMain/config DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/hipTestMain)

if(HIP_PLATFORM MATCHES "amd" AND HIP_COMPILER MATCHES "clang")
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# cmake_policy(PUSH)
# if(POLICY CMP0037)
#     cmake_policy(SET CMP0037 OLD)
# endif()

# Turn off CMAKE_HIP_ARCHITECTURES Feature if cmake version is 3.21+
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.21.0)
    set(CMAKE_HIP_ARCHITECTURES OFF)
endif()
message(STATUS "CMAKE HIP ARCHITECTURES: ${CMAKE_HIP_ARCHITECTURES}")

# Identify the GPU Targets.
# This is done due to limitation of rocm_agent_enumerator
# While building test parallelly, rocm_agent_enumerator can fail and give out an empty target
# That results in hipcc building the test for gfx803 (the default target)
if(NOT DEFINED OFFLOAD_ARCH_STR AND EXISTS "${ROCM_PATH}/bin/rocm_agent_enumerator"
   AND HIP_PLATFORM STREQUAL "amd" AND UNIX)
    execute_process(COMMAND ${ROCM_PATH}/bin/rocm_agent_enumerator OUTPUT_VARIABLE HIP_GPU_ARCH
         RESULT_VARIABLE ROCM_AGENT_ENUM_RESULT)
    # Trim out gfx000
    string(REPLACE "gfx000\n" "" HIP_GPU_ARCH ${HIP_GPU_ARCH})
    string(LENGTH ${HIP_GPU_ARCH} HIP_GPU_ARCH_LEN)

    # If string has more gfx target except gfx000
    if(${HIP_GPU_ARCH_LEN} GREATER_EQUAL 1)
		string(REGEX REPLACE "\n" ";" HIP_GPU_ARCH_LIST "${HIP_GPU_ARCH}")
		set(OFFLOAD_ARCH_STR "")
		foreach(_hip_gpu_arch ${HIP_GPU_ARCH_LIST})
			set(OFFLOAD_ARCH_STR " ${OFFLOAD_ARCH_STR} --offload-arch=${_hip_gpu_arch} ")
		endforeach()
		message(STATUS "Using offload arch string: ${OFFLOAD_ARCH_STR}")
    endif()
endif()

if(DEFINED OFFLOAD_ARCH_STR)
    add_compile_options(${OFFLOAD_ARCH_STR})
endif()

# Use clang as host compiler with nvcc
if(HIP_COMPILER MATCHES "nvcc")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ccbin clang")
endif()

# Disable CXX extensions (gnu++11 etc)
set(CMAKE_CXX_EXTENSIONS OFF)

add_custom_target(build_tests)
add_custom_target(build_tests_standalone)

# Tests folder
if(HIP_PLATFORM STREQUAL "spirv")
    link_libraries(CHIP)
endif()

# A kludge fix for tests that refer files relatively to
# 'HIP/tests/catch' (=CMAKE_CURRENT_BINARY_DIR). The 'hipTestMain'
# directory is added to the path because the test driver expects to be
# run in there and puts '../' prefix to the paths.
set(TEST_DRIVER_WORKING_DIR "${CMAKE_CURRENT_BINARY_DIR}/hipTestMain")

function(catch_executable src)
    get_filename_component(barename ${src} NAME)
    string(REGEX REPLACE ".cc|.cpp" "" exec_name ${barename})

    message("Standalone Catch test: ${exec_name} ${src}")
    add_executable(${exec_name} EXCLUDE_FROM_ALL  ${src} ${CMAKE_SOURCE_DIR}/HIP/tests/catch/hipTestMain/hip_test_context.cc) 
    target_link_libraries(${exec_name} PRIVATE stdc++fs)

     if(HIP_PLATFORM MATCHES "nvidia")
         target_link_libraries(${exec_name} PRIVATE nvrtc)
     endif()

    if(HIP_PLATFORM MATCHES "spirv")
        target_link_libraries(${exec_name} PRIVATE CHIP)
    endif()

    #add_dependencies(build_tests ${exec_name})
    add_dependencies(build_tests_standalone ${exec_name})

    target_link_libraries(${exec_name} PRIVATE Catch2::Catch2WithMain)
    target_include_directories(${exec_name} PRIVATE ${Catch2_SOURCE_DIR}/include)
    catch_discover_tests(${exec_name} PROPERTIES
      WORKING_DIRECTORY "${TEST_DRIVER_WORKING_DIR}"
      SKIP_REGULAR_EXPRESSION "HIP_SKIP_THIS_TEST")
endfunction()


add_subdirectory(unit)
add_subdirectory(ABM)
add_subdirectory(hipTestMain)
add_subdirectory(stress)
#add_subdirectory(TypeQualifiers)

# if(UNIX)
#     add_subdirectory(multiproc)
# endif()

# cmake_policy(POP)
