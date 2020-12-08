#!/usr/bin/env bash
set -eo pipefail

NAME=$1
scs_PREFIX=${PREFIX}/${SUBPREFIX}
mkdir -p ${PREFIX}/bin/
#mkdir -p ${PREFIX}/lib/cmake/${PROJECT}
mkdir -p ${scs_PREFIX}/bin
mkdir -p ${scs_PREFIX}/licenses/lcscs
#mkdir -p ${scs_PREFIX}/include
#mkdir -p ${scs_PREFIX}/lib/cmake/${PROJECT}
#mkdir -p ${scs_PREFIX}/cmake
#mkdir -p ${scs_PREFIX}/scripts

# install binaries 
cp -R ${BUILD_DIR}/bin/* ${scs_PREFIX}/bin  || exit 1

# install licenses
cp -R ${BUILD_DIR}/licenses/lcscs/* ${scs_PREFIX}/licenses || exit 1

# install libraries
#cp -R ${BUILD_DIR}/lib/* ${scs_PREFIX}/lib

# install cmake modules
#sed "s/_PREFIX_/\/${SPREFIX}/g" ${BUILD_DIR}/modules/lcscsTesterPackage.cmake &> ${scs_PREFIX}/lib/cmake/${PROJECT}/lcscsTester.cmake
#sed "s/_PREFIX_/\/${SPREFIX}\/${SSUBPREFIX}/g" ${BUILD_DIR}/modules/${PROJECT}-config.cmake.package &> ${scs_PREFIX}/lib/cmake/${PROJECT}/${PROJECT}-config.cmake

# install includes
#cp -R ${BUILD_DIR}/include/* ${scs_PREFIX}/include

# make symlinks
#pushd ${PREFIX}/lib/cmake/${PROJECT} &> /dev/null
#ln -sf ../../../${SUBPREFIX}/lib/cmake/${PROJECT}/${PROJECT}-config.cmake ${PROJECT}-config.cmake
#ln -sf ../../../${SUBPREFIX}/lib/cmake/${PROJECT}/lcscsTester.cmake lcscsTester.cmake
#popd &> /dev/null

for f in $(ls "${BUILD_DIR}/bin/"); do
   bn=$(basename $f)
   ln -sf ../${SUBPREFIX}/bin/$bn ${PREFIX}/bin/$bn || exit 1
done
echo "Generating Tarball $NAME.tar.gz..."
tar -cvzf $NAME.tar.gz ./${PREFIX}/* || exit 1
rm -r ${PREFIX} || exit 1
