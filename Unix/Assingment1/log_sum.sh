#!/bin/bash

COMMAND=
LIMITLINES=
LIMITHOUR=
LIMITDAY=

while getopts "c2rFtfn:h:d:" OPT; do

case "$OPT" in
	c)
	COMMAND="c"
	;;
	
	2)
	COMMAND="2"
	;;

	r)
	COMMAND="r"
	;;

	F)
	COMMAND="F"
	;;

	t)
	COMMAND="t"
	;;

	#Limit number of lines
	n)
	LIMITLINES="$OPTARG"
	;;

	#Limit days
	d)
	LIMITDAY="$OPTARG"
	;;

	#Limit hours
	h)
	LIMITHOUR="$OPTARG"
	;;

	#Wrong argument
	\?)
		echo "Invalid -$OPTARG" >&2
	;;

	esac
done

function attempts {
	echo "attempt"
}

function successful {
	echo "success"
}

function resultcodes {
	echo "result"
}

function failure {
	echo "fail"
}

function sent {
	echo "bytes sent"
}

case "$COMMAND" in

	c)
	attempts
	;;

	2)
	successful
	;;

	r)
	resultcodes
	;;

	F)
	failure
	;;

	t)
	sent
	;;

esac
