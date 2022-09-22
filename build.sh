#!/usr/local/bin/zsh
# Usage:
# ./build.sh 3000
# This builds ./src/3000.cpp and makes ./bin/3000.out

cppstandards="-std=c++11"
COMPILER="g++-12"
SRCDIR="./src/"
BINDIR="./bin/"
PON=${1}
FLAGS="${cppstandards} -g"

$(${COMPILER} -std=c++11 -g ${SRCDIR}${PON}.cpp -o ${BINDIR}${PON}.out)

ls -l ${BINDIR} | grep ${PON}
