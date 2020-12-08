---
content_title: Amazon Linux 2
---

This section contains shell commands to manually download, build, install, test, and uninstall lcscs and dependencies on Amazon Linux 2.

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
yum update -y && yum install -y git
# clone lcscs repository
git clone https://github.com/lcscs/scs.git $lcscs_LOCATION
cd $lcscs_LOCATION && git submodule update --init --recursive
```

## Install lcscs Dependencies
These commands install the lcscs software dependencies. Make sure to [Download the lcscs Repository](#download-lcscs-repository) first and set the lcscs directories.
```sh
# install dependencies
yum install -y which sudo procps-ng util-linux autoconf automake \
    libtool make bzip2 bzip2-devel openssl-devel gmp-devel libstdc++ libcurl-devel \
    libusbx-devel python3 python3-devel python-devel libedit-devel doxygen \
    graphviz clang patch llvm-devel llvm-static vim-common jq
# build cmake
export PATH=$lcscs_INSTALL_LOCATION/bin:$PATH
cd $lcscs_INSTALL_LOCATION && curl -LO https://cmake.org/files/v3.13/cmake-3.13.2.tar.gz && \
    tar -xzf cmake-3.13.2.tar.gz && \
    cd cmake-3.13.2 && \
    ./bootstrap --prefix=$lcscs_INSTALL_LOCATION && \
    make -j$(nproc) && \
    make install && \
    rm -rf $lcscs_INSTALL_LOCATION/cmake-3.13.2.tar.gz $lcscs_INSTALL_LOCATION/cmake-3.13.2
# build boost
cd $lcscs_INSTALL_LOCATION && curl -LO https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.bz2 && \
    tar -xjf boost_1_71_0.tar.bz2 && \
    cd boost_1_71_0 && \
    ./bootstrap.sh --prefix=$lcscs_INSTALL_LOCATION && \
    ./b2 --with-iostreams --with-date_time --with-filesystem --with-system --with-program_options --with-chrono --with-test -q -j$(nproc) install && \
    rm -rf $lcscs_INSTALL_LOCATION/boost_1_71_0.tar.bz2 $lcscs_INSTALL_LOCATION/boost_1_71_0
# build mongodb
cd $lcscs_INSTALL_LOCATION && curl -LO https://fastdl.mongodb.org/linux/mongodb-linux-x86_64-amazon-3.6.3.tgz && \
    tar -xzf mongodb-linux-x86_64-amazon-3.6.3.tgz && rm -f mongodb-linux-x86_64-amazon-3.6.3.tgz && \
    mv $lcscs_INSTALL_LOCATION/mongodb-linux-x86_64-amazon-3.6.3/bin/* $lcscs_INSTALL_LOCATION/bin/ && \
    rm -rf $lcscs_INSTALL_LOCATION/mongodb-linux-x86_64-amazon-3.6.3
# build mongodb c driver
cd $lcscs_INSTALL_LOCATION && curl -LO https://github.com/mongodb/mongo-c-driver/releases/download/1.13.0/mongo-c-driver-1.13.0.tar.gz && \
    tar -xzf mongo-c-driver-1.13.0.tar.gz && cd mongo-c-driver-1.13.0 && \
    mkdir -p build && cd build && \
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$lcscs_INSTALL_LOCATION -DENABLE_BSON=ON -DENABLE_SSL=OPENSSL -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF -DENABLE_STATIC=ON -DENABLE_ICU=OFF -DENABLE_SNAPPY=OFF .. && \
    make -j$(nproc) && \
    make install && \
    rm -rf $lcscs_INSTALL_LOCATION/mongo-c-driver-1.13.0.tar.gz $lcscs_INSTALL_LOCATION/mongo-c-driver-1.13.0
# build mongodb cxx driver
cd $lcscs_INSTALL_LOCATION && curl -L https://github.com/mongodb/mongo-cxx-driver/archive/r3.4.0.tar.gz -o mongo-cxx-driver-r3.4.0.tar.gz && \
    tar -xzf mongo-cxx-driver-r3.4.0.tar.gz && cd mongo-cxx-driver-r3.4.0 && \
    sed -i 's/\"maxAwaitTimeMS\", count/\"maxAwaitTimeMS\", static_cast<int64_t>(count)/' src/mongocxx/options/change_stream.cpp && \
    sed -i 's/add_subdirectory(test)//' src/mongocxx/CMakeLists.txt src/bsoncxx/CMakeLists.txt && \
    mkdir -p build && cd build && \
    cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$lcscs_INSTALL_LOCATION .. && \
    make -j$(nproc) && \
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
cd $lcscs_BUILD_LOCATION && $lcscs_INSTALL_LOCATION/bin/cmake -DCMAKE_BUILD_TYPE='Release' -DCMAKE_CXX_COMPILER='clang++' -DCMAKE_C_COMPILER='clang' -DCMAKE_INSTALL_PREFIX=$lcscs_INSTALL_LOCATION -DBUILD_MONGO_DB_PLUGIN=true $lcscs_LOCATION
cd $lcscs_BUILD_LOCATION && make -j$(nproc)
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
