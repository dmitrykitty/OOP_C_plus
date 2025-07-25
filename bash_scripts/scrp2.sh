#!/usr/bin/env bash

#0 - true
# wszystko pozostałe -false

#u kazdej komendy jest status 0 lub inna liczba.
#zeby sprawdzic, czy komedna została spełniona echo$? - 0 - true

test 10 -lt 5 #false (10 less then 5)
test -f Filename #sprawdzenie czy file istnieje

#zamiast test mozna uzyc
[[ -d .Filename ]]
(( 10 > 5 ))