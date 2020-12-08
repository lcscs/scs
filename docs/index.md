---
content_title: lcscs Overview
---

lcscs is the next-generation blockchain platform for creating and deploying smart contracts and distributed applications. lcscs comes with a number of programs. The primary ones included in lcscs are the following:

* [Nodscs](01_nodscs/index.md) (node + scs = nodscs)  - core service daemon that runs a node for block production, API endpoints, or local development.
* [Clscs](02_clscs/index.md) (cli + scs = clscs) - command line interface to interact with the blockchain (via `nodscs`) and manage wallets (via `kscsd`).
* [Kscsd](03_kscsd/index.md) (key + scs = kscsd) - component that manages lcscs keys in wallets and provides a secure enclave for digital signing.

The basic relationship between these components is illustrated in the diagram below.

![lcscs components](lcscs_components.png)

[[info | What's Next?]]
| [Install the lcscs Software](00_install/index.md) before exploring the sections above.
