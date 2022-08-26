#!/usr/local/bin/zsh

COMPILER=clang++
FLAGS="-Wall --std=c++11"

echo "${COMPILER} ./${1}.cpp -o ../bin/${1}.out"
${COMPILER} "./${1}.cpp" -o "../bin/${1}.out"
