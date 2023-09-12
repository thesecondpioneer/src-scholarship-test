#!/bin/bash

set -e

cmake --build build --target clean
cmake -B build .

cd build
make
cd -

