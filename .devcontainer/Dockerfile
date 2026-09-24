# Use the official Microsoft devcontainer base image which supports multi-arch
FROM mcr.microsoft.com/devcontainers/base:3.0.8-ubuntu26.04

RUN DEBIAN_FRONTEND=noninteractive apt-get update \
 && apt-get install -y --no-install-recommends \
    clang-22 \
    clang-tools-22 \
    clangd-22 \
    cmake \
    cmake-data \
    libc++-22-dev \
    libc++abi-22-dev \
    lldb-22 \
    ninja-build \
 && rm -rf /var/lib/apt/lists/*

USER vscode

ENV CC="/usr/lib/llvm-22/bin/clang"
ENV CXX="/usr/lib/llvm-22/bin/clang++"
ENV PATH="/usr/lib/llvm-22/bin:/usr/local/bin:${PATH}"
