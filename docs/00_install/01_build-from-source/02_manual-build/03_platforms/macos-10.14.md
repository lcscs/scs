---
content_title: MacOS 10.14
---

This section contains shell commands to manually download, build, install, test, and uninstall lcscs and dependencies on MacOS 10.14.

[[info | Building lcscs is for Advanced Developers]]
| If you are new to lcscs, it is recommended that you install the [lcscs Prebuilt Binaries](../../../00_install-prebuilt-binaries.md) instead of building from source.

Select a task below, then copy/paste the shell commands to a Unix terminal to execute:

* [Download lcscs Repository](#download-lcscs-repository)
* [Install lcscs Dependencies](#install-lcscs-dependencies)
* [Build lcscs](#build-lcscs)
* [Install lcscs](#install-lcscs)
* [Test lcscs](#test-lcscs)
* [Uninstall lcscs](#uninstall-lcscs)

[[info | Building lcscs on another OS?]]
| Visit the [Build lcscs from Source](../../index.md) section.

## Download lcscs Repository
These commands set the lcscs directories, install git, and clone the lcscs repository.
```sh
# set lcscs directories
export lcscs_LOCATION=~/lcscs/scs
export lcscs_INSTALL_LOCATION=$lcscs_LOCATION/../install
mkdir -p $lcscs_INSTALL_LOCATION
# install git
brew update && brew install git
# clone lcscs repository
git clone https://github.com/lcscs/scs.git $lcscs_LOCATION
cd $lcscs_LOCATION && git submodule update --init --recursive
```

## Install Dependencies
These commands install the lcscs software dependencies. Make sure to [Download the lcscs Repository](#download-lcscs-repository) first and set the lcscs directories.
```sh
# install dependencies
brew install cmake python libtool libusb graphviz automake wget gmp pkgconfig doxygen openssl@1.1 jq boost || :
export PATH=$lcscs_INSTALL_LOCATION/bin:$PATH
# install mongodb
mkdir -p $lcscs_INSTALL_LOCATION/bin
cd $lcscs_INSTALL_LOCATION && curl -OL https://fastdl.mongodb.org/osx/mongodb-osx-ssl-x86_64-3.6.3.tgz
    tar -xzf mongodb-osx-ssl-x86_64-3.6.3.tgz && rm -f mongodb-osx-ssl-x86_64-3.6.3.tgz && \
    mv $lcscs_INSTALL_LOCATION/mongodb-osx-x86_64-3.6.3/bin/* $lcscs_INSTALL_LOCATION/bin/ && \
    rm -rf $lcscs_INSTALL_LOCATION/mongodb-osx-x86_64-3.6.3 && rm -rf $lcscs_INSTALL_LOCATION/mongodb-osx-ssl-x86_64-3.6.3.tgz
# install mongo-c-driver from source
cd $lcscs_INSTALL_LOCATION && curl -LO https://github.com/mongodb/mongo-c-driver/releases/download/1.13.0/mongo-c-driver-1.13.0.tar.gz && \
    tar -xzf mongo-c-driver-1.13.0.tar.gz && cd mongo-c-driver-1.13.0 && \
    mkdir -p cmake-build && cd cmake-build && \
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$lcscs_INSTALL_LOCATION -DENABLE_BSON=ON -DENABLE_SSL=DARWIN -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF -DENABLE_STATIC=ON -DENABLE_ICU=OFF -DENABLE_SASL=OFF -DENABLE_SNAPPY=OFF .. && \
    make -j $(getconf _NPROCESSORS_ONLN) && \
    make install && \
    rm -rf $lcscs_INSTALL_LOCATION/mongo-c-driver-1.13.0.tar.gz $lcscs_INSTALL_LOCATION/mongo-c-driver-1.13.0
# install mongo-cxx-driver from source
cd $lcscs_INSTALL_LOCATION && curl -L https://github.com/mongodb/mongo-cxx-driver/archive/r3.4.0.tar.gz -o mongo-cxx-driver-r3.4.0.tar.gz && \
    tar -xzf mongo-cxx-driver-r3.4.0.tar.gz && cd mongo-cxx-driver-r3.4.0/build && \
    cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$lcscs_INSTALL_LOCATION .. && \
    make -j $(getconf _NPROCESSORS_ONLN) VERBOSE=1 && \
    make install && \
    rm -rf $lcscs_INSTALL_LOCATION/mongo-cxx-driver-r3.4.0.tar.gz $lcscs_INSTALL_LOCATION/mongo-cxx-driver-r3.4.0
```

## Build lcscs
These commands build the lcscs software on the specified OS. Make sure to [Install lcscs Dependencies](#install-lcscs-dependencies) first.

[[caution | `lcscs_BUILD_LOCATION` environment variable]]
| Do NOT change this variable. It is set for convenience only. It should always be set to the `build` folder within the cloned repository.

```sh
export lcscs_BUILD_LOCATION=$lcscs_LOCATION/build
mkdir -p $lcscs_BUILD_LOCATION
cd $lcscs_BUILD_LOCATION && cmake -DCMAKE_BUILD_TYPE='Release' -DCMAKE_INSTALL_PREFIX=$lcscs_INSTALL_LOCATION -DBUILD_MONGO_DB_PLUGIN=true $lcscs_LOCATION
cd $lcscs_BUILD_LOCATION && make -j$(getconf _NPROCESSORS_ONLN)
```

## Install lcscs
This command installs the lcscs software on the specified OS. Make sure to [Build lcscs](#build-lcscs) first.
```sh
cd $lcscs_BUILD_LOCATION && make install
```

## Test lcscs
These commands validate the lcscs software installation on the specified OS. This task is optional but recommended. Make sure to [Install lcscs](#install-lcscs) first.
```sh
$lcscs_INSTALL_LOCATION/bin/mongod --fork --logpath $(pwd)/mongod.log --dbpath $(pwd)/mongodata
cd $lcscs_BUILD_LOCATION && make test
```

## Uninstall lcscs
These commands uninstall the lcscs software from the specified OS.
```sh
xargs rm < $lcscs_BUILD_LOCATION/install_manifest.txt
rm -rf $lcscs_BUILD_LOCATION
```
