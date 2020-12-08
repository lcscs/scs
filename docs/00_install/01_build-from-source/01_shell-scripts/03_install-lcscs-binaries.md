---
content_title: Install lcscs Binaries
---

## lcscs install script

For ease of contract development, content can be installed at the `/usr/local` folder using the `lcscs_install.sh` script within the `scs/scripts` folder. Adequate permission is required to install on system folders:

```sh
cd ~/lcscs/scs
sudo ./scripts/lcscs_install.sh
```

## lcscs manual install

In lieu of the `lcscs_install.sh` script, you can install the lcscs binaries directly by invoking `make install` within the `scs/build` folder. Again, adequate permission is required to install on system folders:

```sh
cd ~/lcscs/scs/build
sudo make install
```

[[info | What's Next?]]
| Configure and use [Nodscs](../../../01_nodscs/index.md), or optionally [Test the lcscs binaries](04_test-lcscs-binaries.md).
