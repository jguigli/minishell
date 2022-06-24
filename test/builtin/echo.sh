#!/bin/bash

echo "--- TESTS ECHO ---"

echo $?lol
echo coucou
echo -n coucou
echo "coucou"
echo -n "coucou"
echo "coucou" "bonjour"
echo 'coucou' bonjour
echo
echo -nabc coucou
echo -n -n coucou
echo -n 2 : \	\	coucou
echo -n 2 : 		coucou
echo bonjour > file5
echo ""$USER""
echo ' '$USER' '
echo ">" lol
echo '"' $USER'"'
echo '"' $USER      '"'
echo ">" bonjour
echo ""''$:$''""
echo ""''$=$''""
echo "'"'$USER"'"'"
echo salut > oaoa
echo salut | ls > pop