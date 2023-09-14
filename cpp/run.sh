#!/bin/bash

set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
BUILD_DIR=$SCRIPT_DIR/build

rm -rf $BUILD_DIR
mkdir -p $BUILD_DIR
cmake -B $BUILD_DIR .

cd $BUILD_DIR
make
./internship-test
cd -

