---
content_title: Kscsd
---

## Introduction

`kscsd` is a key manager service daemon for storing private keys and signing digital messages. It provides a secure key storage medium for keys to be encrypted at rest in the associated wallet file. `kscsd` also defines a secure enclave for signing transaction created by `clscs` or a third part library.

## Installation

`kscsd` is distributed as part of the [lcscs software suite](https://github.com/lcscs/scs/blob/master/README.md). To install `kscsd` just visit the [lcscs Software Installation](../00_install/index.md) section.

## Operation

When a wallet is unlocked with the corresponding password, `clscs` can request `kscsd` to sign a transaction with the appropriate private keys. Also, `kscsd` provides support for hardware-based wallets such as Secure Encalve and YubiHSM.

[[info | Audience]]
| `kscsd` is intended to be used by lcscs developers only.
