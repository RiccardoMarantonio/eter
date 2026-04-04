// Part of the Quar Language project, under the Apache License v2.0 with LLVM
// Exceptions. See /LICENSE for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "quar/Basic/Version.h"

#include <iostream>
#include <string_view>

int main(int Argc, char **Argv) {
  if (Argc > 1 && std::string_view(Argv[1]) == "--version") {
    std::cout << quar::getVersionString() << '\n';
    return 0;
  }

  std::cout << "quar: LLVM/MLIR-oriented project scaffold is ready.\n";
  return 0;
}
