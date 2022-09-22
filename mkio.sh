# Usage:
# mkio 4859 3
# create 3 input-output-answer(ioa) sets.
# so, ${1} is problem's number and ${2} is number of ioa sets.

#!/usr/local/bin/zsh
PON=${1}
IODIR="./io"
let SETS=${2}-1

for f in $(seq -f "%02g" 0 $SETS)
do
    touch "${IODIR}/${PON}in${f}.txt"
    touch "${IODIR}/${PON}ou${f}.txt"
    touch "${IODIR}/${PON}an${f}.txt"
done

ls -l ./io | grep ${PON}
