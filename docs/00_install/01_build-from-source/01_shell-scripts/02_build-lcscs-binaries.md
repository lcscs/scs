---
content_title: Build lcscs Binaries
---

[[info | Shell Scripts]]
| The build script is one of various automated shell scripts provided in the lcscs repository for building, installing, and optionally uninstalling the lcscs software and its dependencies. They are available in the `scs/scripts` folder.

The build script first installs all dependencies and then builds lcscs. The script supports these [Operating Systems](../../index.md#supported-operating-systems). To run it, first change to the `~/lcscs/scs` folder, then launch the script:

```sh
cd ~/lcscs/scs
./scripts/lcscs_build.sh
```

The build process writes temporary content to the `scs/build` folder. After building, the program binaries can be found at `scs/build/programs`.

[[info | What's Next?]]
| [Installing lcscs](03_install-lcscs-binaries.md) is strongly recommended after building from source as it makes local development significantly more friendly.
