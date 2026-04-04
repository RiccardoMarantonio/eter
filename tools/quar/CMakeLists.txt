# Part of the Quar Language project, under the Apache License v2.0 with LLVM
# Exceptions. See /LICENSE for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

add_executable(quar quar.cpp)

target_link_libraries(quar
  PRIVATE
    quar::Basic
)
