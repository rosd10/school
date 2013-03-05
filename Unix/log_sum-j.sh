#!/bin/bash
# log_sum(.sh|.py) [-n N] [-h H|-d D] [-c|-2|-r|-F|-t|-f] <filename>
# -n N		number of results
# -h H | d D	limit to hours or days
#
# -c		connection attempts
# -2		successful attempts
# -r		most common result code, one IP per line
# -F		common result code indicating failure
# -t		bytes sent from server to IP, per IP

# number 1-23
regex_hour="(^[1-9]{1}$)|(^[1-2][0-3]$)"

if [[ $1 =~ $regex_hour ]]; then
	echo "$1 matches $regex_hour"
else
	echo "No match"
fi

# number 1-whatever
regex_number="^[1-9]{1}[0-9]+?$"

if [[ $1 =~ $regex_number ]]; then
	echo "$1 matches $regex_number"
else
	echo "No match"
fi

# -----------------------
# get last date limit
let secs=3*86400 #2*3600

lastdate=$(tac thttpd.log | head -n1 | awk '{print $4}' | sed 's/\[//' | sed 's/\// /g' | sed 's/\:/ /')
#echo $lastdate
lastdatestamp=$(date --date "${lastdate}" +"%s")

let newdatestamp=$lastdatestamp-$secs
#echo $newdatestamp

limittime=0
output=$(tac thttpd.log | awk '{print $4}' | sed 's/\[//')
for date in $output; do
	date=${date//\//" "}
	date="${date:0:11} ${date:12}"
	datestamp=$(date --date "${date}" +"%s")
	if [ $datestamp -gt $newdatestamp ]; then
#		echo $date
		limittime=$(expr $limittime + 1)
	else
		break
	fi
done
# echo $limittime
# -----------------------------
# sed 's/\// /g' | sed 's/\:/ /'

n=$1

#newdatetime=$(date --date "${datestring}" +"%d %b %Y %H:%M:%S")

echo "---------------"

filename=thttpd.log
# -c
# get file - print/get IP's($1) - sort them (since uniq only takes successive)
# count unique lines (IP's) - sort high to low (reversed) on count - print the result formated
# add some kind of limit
cat $filename | awk '{print $1}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $1}' | head -n${n}

echo "---------------"

# -2
# get file - print/get IP's($1) if code 200 ($9) - sort them (since uniq only takes successive)
# count unique lines (IP's) - sort high to low (reversed) on count - print the result formated
# add some kind of limit
cat $filename | awk '{if ($9 == "200") {print $1}}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $1}' | head -n${n}

echo "---------------"

# -r
# get file - print/get IP's($1) and codes($9) - sort them (since uniq only takes successive)
# count unique lines (IP's & codes) - sort high to low (reversed) on count - print the result formated
cat $filename | awk '{print $9,$1}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $3}' | head -n${n}

echo "---------------"

# -F
cat $filename | awk '{if ($9 ~ /^[4,5][0-9]/) {print $9,$1}}' | sort | uniq -c | sort -nr | awk '{print $2 "\t" $3}' | head -n${n}

echo "---------------"

# -t
uniqips=$(cat $filename | awk '{if ($10 != "-") {print $1}}' | sort | uniq )
declare -a result

for ip in $uniqips; do
	bytes=$(cat $filename | awk -v IP=$ip '{if ($10 != "-" && $1 == IP ) {print $10}}')
	sum=0
	for byte in $bytes; do
		sum=`expr $sum + $byte`
	done
	result+="$ip\t$sum\n"
done
echo -e $result | sort -nrk2

echo "---------------"

