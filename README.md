# Amanda Computing Platform

Welcome to the Amanda Computing Platform project: a free libre implementation of a virtual machine based on JIT compilation, 
and a framework for developing programming languages infrastructures. Amanda's goals are extensibility, scalability, portability
and high performance through a wide variety of architectures.

Amanda is free software and it is entirely released (except some third party libraries) under the terms of the GNU General Public
License on its third version.

Note that the project is still on set-up phase and in rudimentary stage.

## Overview

This repository is organized in a somewhat similar fashion to the LLVM repository. The project is designed as a collection of
libraries (providing services) and tools. In the includes folder lies the C++ and C interface to the libraries. Tools reside
into the tools subdirectory, including the reference implementation of the Amanda Programming Language compiler.

## The Amanda Programming Language

The Amanda Programming Language is the reference implementation of a programming language for this platform. It exemplifies the
processes taking part in the platform-oriented toolchains. The Amanda Programming Language compiler is implemented as an executable
that relies on several platform libraries.
