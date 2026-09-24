# Use the official Microsoft devcontainer base image which supports multi-arch
FROM mcr.microsoft.com/devcontainers/base:3.0.8-ubuntu26.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
 && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    cmake-data \
    gdb \
 && rm -rf /var/lib/apt/lists/*

ARG USERNAME=vscode

USER $USERNAME

ENV PATH="/usr/local/bin:${PATH}"
