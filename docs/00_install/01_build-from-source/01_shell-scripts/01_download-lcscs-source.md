---
content_title: Download lcscs Source
---

To download the lcscs source code, clone the `scs` repo and its submodules. It is adviced to create a home `lcscs` folder first and download all the lcscs related software there:

```sh
mkdir -p ~/lcscs && cd ~/lcscs
git clone --recursive https://github.com/lcscs/scs
```

## Update Submodules

If a repository is cloned without the `--recursive` flag, the submodules *must* be updated before starting the build process:

```sh
cd ~/lcscs/scs
git submodule update --init --recursive
```

## Pull Changes

When pulling changes, especially after switching branches, the submodules *must* also be updated. This can be achieved with the `git submodule` command as above, or using `git pull` directly:

```sh
[git checkout <branch>]  (optional)
git pull --recurse-submodules
```

[[info | What's Next?]]
| [Build lcscs binaries](02_build-lcscs-binaries.md)
