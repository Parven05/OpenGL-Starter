#!/bin/bash

set -e

mkdir -p build
mkdir -p bin
cmake -S . -B build
