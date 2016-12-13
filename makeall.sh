#!/bin/sh
for MODULE in Capcom VectSega Konami Classic DeasIrem AtarNamco Others Others2 Neogeo
do
	echo "Making module mame$MODULE"
	export MODULE $MODULE
	make clean
	make -f Makefile
	if [ $? -eq 1 ]
	then
		echo "ERROR!"
		exit 1
	fi
done
