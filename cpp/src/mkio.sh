#!/usr/local/bin/zsh

for f in $(seq -f "%02g" 0 ${2})

do
    $(touch "../io/${1}i${f}.txt")
    $(touch "../io/${1}o${f}.txt")
    $(touch "../io/${1}O${f}.txt")
done

$(ls ../io/)
