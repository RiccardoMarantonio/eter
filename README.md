The Quar Programming Language
=============================

**Quar** [/kwɔːr/] — *Derived from Quasar: an extremely luminous active galactic nucleus*

Quar is now scaffolded with an **LLVM-style layout** so it can grow cleanly toward LLVM/MLIR integration.

## Getting the Source Code and Building Quar

Consult the [Getting Started with Quar](docs/GETTING_STARTED.md) page for information on building and running Quar.

For information on how to contribute to the Quar project, please take a look at the [Contributing to Quar](docs/CONTRIBUTING.md) guide.

For IDE/LSP setup tips, including the recommended root `.clangd` file, see [Getting Started with Quar](docs/GETTING_STARTED.md).

## Project Layout

- `include/quar/` — public headers
- `lib/` — core library implementation
- `tools/` — executables and developer tools
- `test/` — `lit` / `FileCheck` regression tests, including `Smoke/`
- `unittests/` — unit-test targets
- `docs/` — guides such as `GETTING_STARTED.md` and `CONTRIBUTING.md`

## License

Quar is licensed under the Apache License v2.0 with LLVM Exceptions. See the [LICENSE](LICENSE) file for more information.