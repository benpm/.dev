# .dev

See live website https://benpm.github.io/.dev for all code and the result of their execution!

A development container configured for C++ development with the latest LLVM toolchain.

## Features

- **Latest Ubuntu** base image
- **Latest LLVM** toolchain including:
  - `clang` / `clang++` - C/C++ compiler
  - `clangd` - Language server for IDE features
  - `clang-format` - Code formatter
  - `clang-tidy` - Static analysis / linter
  - `lldb` - Debugger
  - `lld` - Linker
- **VS Code Extensions**:
  - [vscode-clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) - C++ language support via clangd
  - [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) - Native debugger based on LLDB
  - CMake Tools - CMake build system support

## Getting Started

### Using with GitHub Codespaces

1. Click the green "Code" button on this repository
2. Select "Open with Codespaces"
3. Click "New codespace"

### Using with VS Code Dev Containers

1. Install [Docker](https://www.docker.com/products/docker-desktop)
2. Install [VS Code](https://code.visualstudio.com/) and the [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
3. Clone this repository
4. Open the repository in VS Code
5. When prompted, click "Reopen in Container" (or use the command palette: "Dev Containers: Reopen in Container")

## Quick Start

Once the devcontainer is running, try compiling and running the example:

```bash
# Compile with C++23 features
clang++ -std=c++23 -o example example.cpp

# Run the example
./example
```

## Interactive C++ with clang-repl

For quick experimentation, use `clang-repl`:

```bash
clang-repl
```

Then type C++ code interactively:

```cpp
clang-repl> #include <iostream>
clang-repl> std::cout << "Hello, World!" << std::endl;
Hello, World!
clang-repl> int x = 42;
clang-repl> x * 2
(int) 84
```

## Building Projects

For larger projects, use CMake:

```bash
mkdir build && cd build
cmake -G Ninja ..
ninja
```

## Code Formatting

Format your code using clang-format:

```bash
clang-format -i your_file.cpp
```

## Static Analysis

Run clang-tidy for static analysis:

```bash
clang-tidy your_file.cpp -- -std=c++23
```
