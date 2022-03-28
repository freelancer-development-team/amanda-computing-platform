# Amanda Computing Platform
![Amanda Logotype](https://user-images.githubusercontent.com/53576341/160347044-1be0739a-7680-40f9-9be5-f2abea0679af.png)

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

## Acknowledgements

I would like to aknowledge some people for their contribution (be it in code, resources or just emotional support), and they are,
in no particular order (by their nicks, they know who they are 😉):

* <code>@ysordo</code>, for giving this project its first star, and for his invaluable support.
* <code>@SnowBlackQueen</code>, for designing the project logo and listening to my theoretical discussions about PLs.
* <code>@JoseCarlos_1201</code>, for his support and endearing dedication to the purpose of keeping this project alive.
* <code>@RoxAsLol</code>, <code>@Samurai_Serio</code> & <code>@Hyzokaaa</code> for pushing the limits of my imagination to unthinkable boundaries.
* <code>@Amanda_bmu</code>... I don't believe I have to say much more.

Thanks to you all, sincerely, <code>@the_philosopher_3401</code> 🇨🇺
