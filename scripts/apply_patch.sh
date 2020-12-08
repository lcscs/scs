#!/usr/bin/env bash
cd ../libraries/fc
git reset --hard
cd ../../
TARGET=libraries/fc/include/fc/crypto/public_key.hpp

cp $TARGET ${TARGET}.bak_$(date +%s)
patch $TARGET < ./patches/fc/update-public_key_legacy_prefix-to-SCS.patch

echo Done.
