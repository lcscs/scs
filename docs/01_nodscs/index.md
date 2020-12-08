---
content_title: Nodscs
---

## Introduction

`nodscs` is the core service daemon that runs on every lcscs node. It can be configured to process smart contracts, validate transactions, produce blocks containing valid transactions, and confirm blocks to record them on the blockchain.

## Installation

`nodscs` is distributed as part of the [lcscs software suite](https://github.com/lcscs/scs/blob/master/README.md). To install `nodscs`, visit the [lcscs Software Installation](../00_install/index.md) section.

## Explore

Navigate the sections below to configure and use `nodscs`.

* [Usage](02_usage/index.md) - Configuring and using `nodscs`, node setups/environments.
* [Plugins](03_plugins/index.md) - Using plugins, plugin options, mandatory vs. optional.
* [Replays](04_replays/index.md) - Replaying the chain from a snapshot or a blocks.log file.
* [RPC APIs](05_rpc_apis/index.md) - Remote Procedure Call API reference for plugin HTTP endpoints.
* [Logging](06_logging/index.md) - Logging config/usage, loggers, appenders, logging levels.
* [Upgrade Guides](07_upgrade-guides/index.md) - lcscs version/consensus upgrade guides.
* [Troubleshooting](08_troubleshooting/index.md) - Common `nodscs` troubleshooting questions.

[[info | Access Node]]
| A local or remote lcscs access node running `nodscs` is required for a client application or smart contract to interact with the blockchain.
