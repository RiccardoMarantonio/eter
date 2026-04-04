# Part of the Eter Language project, under the Apache License v2.0 with LLVM
# Exceptions. See /LICENSE for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

cmake_minimum_required(VERSION 3.20)

project(eter VERSION 0.1.0 LANGUAGES C CXX)

include(GNUInstallDirs)

option(ETER_ENABLE_WERROR "Treat warnings as errors" ON)
option(ETER_ENABLE_ASSERTIONS "Enable assertions in Eter" ON)
option(ETER_INCLUDE_TESTS "Enable Eter's lit/FileCheck test suite" ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

add_library(EterProjectOptions INTERFACE)
target_compile_features(EterProjectOptions INTERFACE cxx_std_23)

if(MSVC)
  target_compile_options(EterProjectOptions INTERFACE /W4)
  if(ETER_ENABLE_WERROR)
    target_compile_options(EterProjectOptions INTERFACE /WX)
  endif()
else()
  target_compile_options(EterProjectOptions INTERFACE -Wall -Wextra -Wpedantic)
  if(ETER_ENABLE_WERROR)
    target_compile_options(EterProjectOptions INTERFACE -Werror)
  endif()
endif()

if(ETER_ENABLE_ASSERTIONS)
  target_compile_definitions(EterProjectOptions INTERFACE ETER_ENABLE_ASSERTIONS=1)
endif()

set(ETER_REQUIRED_LLVM_MAJOR 22)
set(ETER_REQUIRED_LLVM_VERSION "${ETER_REQUIRED_LLVM_MAJOR}.0.0")
math(EXPR ETER_REQUIRED_LLVM_NEXT_MAJOR "${ETER_REQUIRED_LLVM_MAJOR} + 1")
set(ETER_REQUIRED_LLVM_NEXT_VERSION "${ETER_REQUIRED_LLVM_NEXT_MAJOR}.0.0")

find_package(LLVM CONFIG REQUIRED)
find_package(MLIR CONFIG REQUIRED)

if(LLVM_PACKAGE_VERSION VERSION_LESS ETER_REQUIRED_LLVM_VERSION OR
   NOT LLVM_PACKAGE_VERSION VERSION_LESS ETER_REQUIRED_LLVM_NEXT_VERSION)
  message(FATAL_ERROR
    "Eter requires LLVM/MLIR ${ETER_REQUIRED_LLVM_MAJOR}.x, but found LLVM ${LLVM_PACKAGE_VERSION}"
  )
endif()

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION} in ${LLVM_DIR}")
message(STATUS "Found MLIR in ${MLIR_DIR}")

add_subdirectory(lib)
add_subdirectory(tools)

if(ETER_INCLUDE_TESTS)
  add_subdirectory(test)
  add_subdirectory(unittests)
endif()
