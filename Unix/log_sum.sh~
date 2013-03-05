#!/bin/bash

#Function for showing how to use the script.
show_usage(){
cat << EOF
usage $0 options

log_sum.sh [-n N] [-h H|-d D] [-c|-2|-r|-F|-t] <filename>

OPTIONS:
	-n N: Limit the number of results to N

	-h H: Limit the query to the last number of hours (<24h)
	-d D: Limit the query to the last number of days (counting from midnight)

	-c: Which IP address makes the most number of connection attempts
	-2: Which IP address makes the most number of successful attempts
	-r: What are the most common result codes and where do the come from
	-F: What are the most common result codes that indicate failure (no auth, not found etc) and where do they come from
	-t: Which IP address get the most bytes sent to them

	<filename> refers to the logfile. Use '-' or no filename to read from stdin.
EOF
}

calculate_limit(){
	lastdate=$(tail -n1 $FILENAME | awk '{print $4}' | sed 's/\[//' | sed 's/\// /g' | sed 's/\:/ /')
	lastdatestamp=$(date --date "${lastdate}" +"%s")

	let newdatestamp=$lastdatestamp-$secs

	limittime=0
	output=$(tac $FILENAME | awk '{print $4}' | sed 's/\[//')
	for date in $output; do
		date=${date//\//" "}
		date="${date:0:11} ${date:12}"
		datestamp=$(date --date "${date}" +"%s")
		if { $datestamp -gt $newdatestamp ]; then
			limittime=$(expr $limittime + 1)
		else
			break
		fi
	done
}

calc_connection_attempts(){
	if [ -z $secs && -z $number ]; then
		cat $FILENAME | awk '{print $1}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $1}'
	elif [ -z $secs && ! -z $number ]; then
		cat $FILENAME | awk '{print $1}' | sort | uniq -c | sort -nr awk '{print $2 "\t" $1}' | head -n${number}
	elif [ ! -z $secs && -z $number ]; then
		tail -n${limittime} $FILENAME | awk '{print $1}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $1}'
	elif [ ! -z $secs && !-z $number ]; then
		tail -n${limittime} $FILENAME | awk '{print $1}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $1}' | head -n${number}
	fi
}

calc_successful_attempts(){
	if [ -z $secs && -z $number ]; then
		cat $FILENAME | awk '{if ($9 == "200") {print $1}}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $1}'
	elif [ -z $secs && ! -z $number ]; then
		cat $FILENAME | awk '{if ($9 == "200") {print $1}}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $1}' | head -n${number}
	elif [ ! -z $secs && -z $number ]; then
		tail -n${limittime} $FILENAME | awk '{if ($9 == "200") {print $1}}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $1}'
	elif [ ! -z $secs && !-z $number ]; then
		tail -n${limittime} $FILENAME | awk '{if ($9 == "200") {print $1}}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $1}' | head -n${number}
	fi
}

calc_most_commom_res_code(){
	if [ -z $secs && -z $number ]; then
		cat $FILENAME | awk '{print $9,$1}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $3}'
	elif [ -z $secs && ! -z $number ]; then
		cat $FILENAME | awk '{print $9,$1}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $3}' | head -n${number}
	elif [ ! -z $secs && -z $number ]; then
		tail -n${limittime} $FILENAME | awk '{print $9,$1}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $3}'
	elif [ ! -z $secs && !-z $number ]; then
		tail -n${limittime} $FILENAME | awk '{print $9,$1}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $3}' | head -n${number}
	fi
}

calc_most_common_err_codes(){
	if [ -z $secs && -z $number ]; then
		cat $FILENAME | awk '{if ($9 ~ /^[4,5][0-9][0-9]/) {print $9,$1}}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $3}'
	elif [ -z $secs && ! -z $number ]; then
		cat $FILENAME | awk '{if ($9 ~ /^[4,5][0-9][0-9]/) {print $9,$1}}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $3}' | head -n${number}
	elif [ ! -z $secs && -z $number ]; then
		tail -n${limittime} $FILENAME | awk '{if ($9 ~ /^[4,5][0-9][0-9]/) {print $9,$1}}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $3}'
	elif [ ! -z $secs && !-z $number ]; then
		tail -n${limittime} $FILENAME | awk '{if ($9 ~ /^[4,5][0-9][0-9]/) {print $9,$1}}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $3}' | head -n${number}
	fi
}

calc_bytes_sent(){
	if [ -z $secs && -z $number ]; then
		uniqips=$(cat $FILENAME | awk '{if ($10 != "-") {print $1}}' | sort | uniq )
		declare -a result

		for ip in $uniqips; do
			bytes=$(cat $FILENAME | awk -v IP=$ip '{if ($10 != "-" && $1 == IP ) {print $10}}')
			sum=0
			for byte in $bytes; do
				sum=`expr $sum + $byte`
			done
			result+="$ip\t$sum\n"
		done
		echo -e $result | sort -nrk2
	elif [ -z $secs && ! -z $number ]; then
		uniqips=$(cat $FILENAME | awk '{if ($10 != "-") {print $1}}' | sort | uniq )
		declare -a result

		count=0
		for ip in $uniqips; do
			bytes=$(cat $FILENAME | awk -v IP=$ip '{if ($10 != "-" && $1 == IP ) {print $10}}')
			sum=0
			for byte in $bytes; do
				sum=`expr $sum + $byte`
			done
			result+="$ip\t$sum\n"
			count=`expr $count + 1`
			if [ $count -ge $number ]
				break
			fi
		done
		echo -e $result | sort -nrk2
	elif [ ! -z $secs && -z $number ]; then
		uniqips=$(tail -n${limittime} $FILENAME | awk '{if ($10 != "-") {print $1}}' | sort | uniq )
		declare -a result

		for ip in $uniqips; do
			bytes=$(tail -n${limittime} $FILENAME | awk -v IP=$ip '{if ($10 != "-" && $1 == IP ) {print $10}}')
			sum=0
			for byte in $bytes; do
				sum=`expr $sum + $byte`
			done
			result+="$ip\t$sum\n"
		done
		echo -e $result | sort -nrk2
	elif [ ! -z $secs && !-z $number ]; then
		uniqips=$(tail -n${limittime} $FILENAME | awk '{if ($10 != "-") {print $1}}' | sort | uniq )
		declare -a result

		count=0
		for ip in $uniqips; do
			bytes=$(tail -n${limittime} $FILENAME | awk -v IP=$ip '{if ($10 != "-" && $1 == IP ) {print $10}}')
			sum=0
			for byte in $bytes; do
				sum=`expr $sum + $byte`
			done
			result+="$ip\t$sum\n"
			count=`expr $count + 1`
			if [ $count -ge $number ]
				break
			fi
		done
		echo -e $result | sort -nrk2
	fi	
}

number=
hours=
days=
secs=

if [ $# -eq 0 ]; then
	show_usage
	exit 1
else
	#Runs through the arguments, setting values and modes.
	while getopts "n:h:d:c2rFt" OPTION
	do
		case $OPTION in
			n)
				number=$OPTARG
				;;
			h)
				hours=$OPTARG
				let secs=$days*3600
				;;
			d)
				days=$OPTARG
				let secs=$days*86400
				;;
			c)
				calc_connection_attempts
				;;
			2)
				calc_successful_attempts
				;;
			r)
				calc_most_commom_res_code
				;;
			F)
				calc_most_common_err_codes
				;;
			t)
				calc_bytes_sent
				;;
		esac
	done
fi

#Finds the filename among the arguments.
for args in $@; do
	FILENAME=$args
done

#If the entered file exists then it reads the contents of that file.
if [ ! -f $FILENAME ]; then
	echo "No such file"
	exit 1
fi

calculate_limit