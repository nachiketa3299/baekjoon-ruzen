#!/usr/local/bin/zsh

for input in $(ls ../io/ | grep ${1})
do
    # 1111i01.txt
    # 1111o01.txt
    # 1111O01.txt
    $(echo '------------------')
    $(echo 'IFILE: ${input}')
    $(cat ${input})
    $(echo '------------------')
    $(echo 'output')
    OUT='../io/${1}o.txt'
    $(${input} | ../bin/${1}.out > ${OUT})
    $(cat ${OUT})
    $(echo '------------------')
    ANS='../io/${1}O.txt'
    $(cat ${ANS})
    $(echo 'output')
done

$(echo '------------------')

