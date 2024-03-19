#!/usr/bin/env sh

echo "Checking prerequisites"
which cmake > /dev/null || { echo "Could not find cmake in path"; exit 1; }
echo "--------------------------------------------------"
echo "Downloading coconut"
echo "--------------------------------------------------"
if [ ! -f coconut/Makefile ]; then
    git submodule update --init || exit 1
fi
echo "--------------------------------------------------"
echo "Building coconut"
echo "--------------------------------------------------"
make -C coconut || exit 1
echo "--------------------------------------------------"
echo "Setting up debug build directory in build"
echo "--------------------------------------------------"
cmake -DCMAKE_BUILD_TYPE=Debug -S ./ -B build || exit 1
echo "--------------------------------------------------"
echo "Building project"
echo "--------------------------------------------------"
cmake --build build || exit 1
echo "--------------------------------------------------"
echo "Project configured."
