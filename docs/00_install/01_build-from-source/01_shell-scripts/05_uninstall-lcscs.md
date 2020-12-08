---
content_title: Uninstall lcscs
---

If you have previously built lcscs from source and now wish to install the prebuilt binaries, or to build from source again, it is recommended to run the `lcscs_uninstall.sh` script within the `scs/scripts` folder:

```sh
cd ~/lcscs/scs
sudo ./scripts/lcscs_uninstall.sh
```

[[info | Uninstall Dependencies]]
| The uninstall script will also prompt the user to uninstall lcscs dependencies. This is recommended if installing prebuilt lcscs binaries or building lcscs for the first time.
