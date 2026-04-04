# Part of the Quar Language project, under the Apache License v2.0 with LLVM
# Exceptions. See /LICENSE for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

add_library(QuarBasic
  Basic/Version.cpp
)

add_library(quar::Basic ALIAS QuarBasic)

target_link_libraries(QuarBasic
  PUBLIC
    QuarProjectOptions
)

target_include_directories(QuarBasic
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
