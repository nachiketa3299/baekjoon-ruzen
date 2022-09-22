# Usage:

# exe 9498
# cat ./io/9498in** > ./bin/9498.out > ./io/9498ou**
# echo <========INPUT**=========>
# cat ./io/9498in**
# echo <========OUTPUT**========>
# cat ./io/9498ou**
# echo <========ANSWER**========>
# cat ./io/9498an**
 
#!/usr/local/bin/zsh

PON=${1}
iodir=./io/

let FNUM=$(($(find $iodir | grep $PON | wc -l) / 3))
FNUMFOR=$(($FNUM-1))

for f in $(seq -f "%02g" 0 $FNUMFOR)
do
    $(cat ${iodir}${PON}in${f}.txt) | ./bin/${PON}.out > ${iodir}${PON}ou${f}.txt

    echo "<========== INPUT ${f} ==========>"
    cat ${iodir}${PON}'in'${f}.txt
    echo "<========== OUTPU ${f} ==========>"
    cat ${iodir}${PON}ou${f}.txt
    echo "<========== ANSWE ${f} ==========>"
    cat ${iodir}${PON}an${f}.txt
done
