# LCSCS - The Most Powerful Infrastructure for Decentralized Applications



Welcome to the LCSCS source code repository! This software enables businesses to rapidly build and deploy high-performance and high-security blockchain-based applications.

## Some of the groundbreaking features of LCSCS include:

1. The most perfect block chain traceability system has been innovated
1. The most perfect storage system
1. The most popular commercial blockchain system
1. Free Rate Limited Transactions
1. Low Latency Block confirmation (0.5 seconds)
1. Low-overhead Byzantine Fault Tolerant Finality
1. Designed for optional high-overhead, low-latency BFT finality
1. Smart contract platform powered by WebAssembly
1. Designed for Sparse Header Light Client Validation
1. Scheduled Recurring Transactions
1. Hierarchical Role Based Permissions
1. Support for Biometric Hardware Secured Keys (e.g. Apple Secure Enclave)
1. Designed for Parallel Execution of Context Free Validation Logic
1. Designed for Inter Blockchain Communication



## Supported Operating Systems

LCSCS currently supports the following operating systems:  

1. Amazon Linux 2
2. CentOS 7
3. Ubuntu 18.04
4. MacOS 10.14 (Mojave)


## Ubuntu Linux:

### Ubuntu  Package Install
```sh
wget https://github.com/lcscs/scs/releases/download/v1.0.0/lcscs_1.0.0-ubuntu-18.04_amd64.deb
sudo apt install ./lcscs_1.0.0-ubuntu-18.04_amd64.deb
```

### Ubuntu Package Uninstall
```sh
sudo apt remove lcscs
```

### Ubuntu 18.04 source code to Install

```sh
git clone https://github.com/lcscs/scs.git
```

```sh
cd scs/scripts
```

```sh
git submodule update --init --recursive  
```

```sh
cd scs/scripts
```


```sh
./lcscs_build.sh -s XXX
```

## Uninstall Script
To uninstall the lcscs built/installed binaries and dependencies, run:
```sh
./scripts/lcscs_uninstall.sh
```

