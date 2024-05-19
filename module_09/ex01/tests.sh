#!bin/bash

echo 'testing: "8 9 * 9 - 9 - 9 - 4 - 1 +"'
./bin/RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo

echo 'testing: "7 7 * 7 -"'
./bin/RPN "7 7 * 7 -"
echo

echo 'testing: "1 2 * 2 / 2 * 2 4 - +"'
./bin/RPN "1 2 * 2 / 2 * 2 4 - +"
echo

echo 'testing: "1 1 +"'
./bin/RPN "1 1 +"
echo

echo 'testing: "7 8 *"'
./bin/RPN "7 8 *"
echo

echo 'testing: "7 8 * 9- 5-"'
./bin/RPN "7 8 * 9 - 5 -"
echo

echo 'testing: "(1 + 1)"'
./bin/RPN "(1 + 1)"
echo

echo 'testing: "1 + 1"'
./bin/RPN "1 + 1"
echo

echo 'testing: "+ 1 1"'
./bin/RPN "+ 1 1"
echo

echo 'testing: "11 1 +"'
./bin/RPN "11 1 +"
echo

echo 'testing: "1 1 ++"'
./bin/RPN "1 1 ++"
echo

echo 'testing: "+ + +"'
./bin/RPN "+ + +"
echo

echo 'testing: "- - -"'
./bin/RPN "- - -"
echo

echo 'testing: "* * *"'
./bin/RPN "* * *"
echo

echo 'testing: "3 0 /"'
./bin/RPN "3 0 /"
echo

echo 'testing: "/"'
./bin/RPN "/"
echo

echo 'testing: ""'
./bin/RPN ""

