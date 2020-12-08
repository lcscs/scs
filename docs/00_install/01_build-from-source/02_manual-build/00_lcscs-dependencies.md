---
content_title: lcscs Software Dependencies
---

The lcscs software requires specific software dependencies to build the lcscs binaries. These dependencies can be built from source or installed from binaries directly. Dependencies can be pinned to a specific version release or unpinned to the current version, usually the latest one. The main lcscs dependencies hosted outside the lcscs repos are:

* Clang - the C++17 compliant compiler used by lcscs
* CMake - the build system used by lcscs
* Boost - the C++ Boost library used by lcscs
* OpenSSL - the secure communications (and crypto) library
* LLVM - the LLVM compiler/toolchain infrastructure

Other dependencies are either inside the lcscs repo, such as the `secp256k1` elliptic curve DSA library, or they are otherwise used for testing or housekeeping purposes, such as:

* automake, autoconf, autotools
* doxygen, graphviz
* python2, python3
* bzip2, zlib
* etc.

## Pinned Dependencies

To guarantee interoperability across different lcscs software releases, developers may opt to reproduce the exact "pinned" dependency binaries used in-house. Block producers may want to install and run the lcscs software built with these pinned dependencies for portability and stability reasons. Pinned dependencies are usually built from source.

## Unpinned Dependencies

Regular users or application developers may prefer installing unpinned versions of the lcscs dependencies. These correspond to the latest or otherwise stable versions of the dependencies. The main advantage of unpinned dependencies is reduced installation times and perhaps better performance. Pinned dependencies are typically installed from binaries.

## Automatic Installation of Dependencies

lcscs dependencies can be built or installed automatically from the [Build Script](../01_shell-scripts/02_build-lcscs-binaries.md) when building lcscs from source. To build the pinned dependencies, the optional `-P` parameter can be specified when invoking the script. Otherwise, the unpinned dependencies will be installed instead, with the exception of `boost` and `cmake` which are always pinned:

```sh
cd ~/lcscs/scs
./scripts/lcscs_build.sh [-P]
```

### Unupported Platforms

lcscs dependencies can also be built and installed manually by reproducing the same commands invoked by the [Build Script](../01_shell-scripts/02_build-lcscs-binaries.md). The actual commands can be generated from the script directly by exporting specific environment variables and CLI parameters to the script when invoked:

```sh
cd ~/lcscs/scs
export VERBOSE=true && export DRYRUN=true && ./scripts/lcscs_build.sh -y [-P]
```
