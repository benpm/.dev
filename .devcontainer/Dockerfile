# Use Ubuntu 24.04 (Noble Numbat) as the base image
FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Install latest LLVM toolchain from the official LLVM apt repository
# GPG key is fetched over HTTPS from apt.llvm.org
RUN apt-get update && apt-get install -y --no-install-recommends \
    wget \
    gnupg \
    software-properties-common \
    && wget -qO- https://apt.llvm.org/llvm-snapshot.gpg.key | tee /etc/apt/trusted.gpg.d/apt.llvm.org.asc \
    && add-apt-repository -y "deb http://apt.llvm.org/noble/ llvm-toolchain-noble main" \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
    # Core LLVM/Clang packages
    clang \
    clangd \
    clang-format \
    clang-tidy \
    clang-tools \
    lldb \
    lld \
    # Build tools
    cmake \
    ninja-build \
    make \
    # Useful development utilities
    gdb \
    git \
    curl \
    # Clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Set clang as the default compiler
ENV CC=clang
ENV CXX=clang++

# Reset to interactive mode
ENV DEBIAN_FRONTEND=dialog
