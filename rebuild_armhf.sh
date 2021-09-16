#!/bin/bash
rm -rf build
set -e
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr ../ 
make
mkdir packageroot
cp -rf ../DEBIANARMHF packageroot/
mv packageroot/DEBIANARMHF packageroot/DEBIAN
mkdir -p packageroot/usr/bin/


cp bin/debughidevent packageroot/usr/bin/


dpkg-deb -b packageroot debughidevent_1.0.0_armhf.deb



