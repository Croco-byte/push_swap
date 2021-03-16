#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

### TESTS FOR 2 INTEGERS ###

total=$((0 + 0))
sorted=$((0 + 0))

printf "\n\n${CYAN}TESTS FOR 2 INTEGRERS${NC}\n\n"


for ((i = 0; i < 20; i++)); do
	a=$(ARG=$(./stackgen.pl 2 -2147483648 2147483647); ./push_swap $(echo $ARG) | wc -l)
	b=$(ARG=$(./stackgen.pl 2 -2147483648 2147483647); ./push_swap $(echo $ARG) | ./checker $(echo $ARG))
	echo "Test n°$i:	$a -- $b"
	total=$(($total + $a))
	if [[ "$b" != "OK" ]]; then
		sorted=$(($sorted + 1))
	fi

done

mean=$(($total / 20))
printf "\nAverage operation number :	$mean\n"
if [[ $sorted -eq 0 ]]; then
	printf "All sorted :	${GREEN}OK\n${NC}"
else
	printf "All sorted :	${RED}KO\n${NC}"
fi


### TESTS FOR 3 INTEGERS ###

total=$((0 + 0))
sorted=$((0 + 0))

printf "\n\n${CYAN}TESTS FOR 3 INTEGRERS${NC}\n\n"


for ((i = 0; i < 20; i++)); do
	a=$(ARG=$(./stackgen.pl 3 -2147483648 2147483647); ./push_swap $(echo $ARG) | wc -l)
	b=$(ARG=$(./stackgen.pl 3 -2147483648 2147483647); ./push_swap $(echo $ARG) | ./checker $(echo $ARG))
	echo "Test n°$i:	$a -- $b"
	total=$(($total + $a))
	if [[ "$b" != "OK" ]]; then
		sorted=$(($sorted + 1))
	fi

done

mean=$(($total / 20))
printf "\nAverage operation number :	$mean\n"
if [[ $sorted -eq 0 ]]; then
	printf "All sorted :	${GREEN}OK\n${NC}"
else
	printf "All sorted :	${RED}KO\n${NC}"
fi

### TESTS FOR 5 INTEGERS ###

total=$((0 + 0))
sorted=$((0 + 0))

printf "\n\n${CYAN}TESTS FOR 5 INTEGRERS${NC}\n\n"


for ((i = 0; i < 20; i++)); do
	a=$(ARG=$(./stackgen.pl 5 -2147483648 2147483647); ./push_swap $(echo $ARG) | wc -l)
	b=$(ARG=$(./stackgen.pl 5 -2147483648 2147483647); ./push_swap $(echo $ARG) | ./checker $(echo $ARG))
	echo "Test n°$i:	$a -- $b"
	total=$(($total + $a))
	if [[ "$b" != "OK" ]]; then
		sorted=$(($sorted + 1))
	fi

done

mean=$(($total / 20))
printf "\nAverage operation number :	$mean\n"
if [[ $sorted -eq 0 ]]; then
	printf "All sorted :	${GREEN}OK\n${NC}"
else
	printf "All sorted :	${RED}KO\n${NC}"
fi

### TESTS FOR 100 INTEGERS ###

total=$((0 + 0))
sorted=$((0 + 0))

printf "\n\n${CYAN}TESTS FOR 100 INTEGRERS${NC}\n\n"


for ((i = 0; i < 20; i++)); do
	a=$(ARG=$(./stackgen.pl 100 -2147483648 2147483647); ./push_swap $(echo $ARG) | wc -l)
	b=$(ARG=$(./stackgen.pl 100 -2147483648 2147483647); ./push_swap $(echo $ARG) | ./checker $(echo $ARG))
	echo "Test n°$i:	$a -- $b"
	total=$(($total + $a))
	if [[ "$b" != "OK" ]]; then
		sorted=$(($sorted + 1))
	fi

done

mean=$(($total / 20))
printf "\nAverage operation number :	$mean\n"
if [[ $sorted -eq 0 ]]; then
	printf "All sorted :	${GREEN}OK\n${NC}"
else
	printf "All sorted :	${RED}KO\n${NC}"
fi

### TESTS FOR 500 INTEGERS ###

total=$((0 + 0))
sorted=$((0 + 0))

printf "\n\n${CYAN}TESTS FOR 500 INTEGRERS${NC}\n\n"


for ((i = 0; i < 20; i++)); do
	a=$(ARG=$(./stackgen.pl 500 -2147483648 2147483647); ./push_swap $(echo $ARG) | wc -l)
	b=$(ARG=$(./stackgen.pl 500 -2147483648 2147483647); ./push_swap $(echo $ARG) | ./checker $(echo $ARG))
	echo "Test n°$i:	$a -- $b"
	total=$(($total + $a))
	if [[ "$b" != "OK" ]]; then
		sorted=$(($sorted + 1))
	fi

done

mean=$(($total / 20))
printf "\nAverage operation number :	$mean\n"
if [[ $sorted -eq 0 ]]; then
	printf "All sorted :	${GREEN}OK\n${NC}"
else
	printf "All sorted :	${RED}KO\n${NC}"
fi

