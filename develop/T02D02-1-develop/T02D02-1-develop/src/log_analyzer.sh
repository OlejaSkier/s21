read pathfile

count=`wc -l $pathfile | awk '{print $1}'`
counthash=-1
hashlast=0
pathlast="scr/history_of_vim.txt"
touch conf.txt
touch config.txt

while IFS=" - ", read path size year month day time hash alg; do
	if [ $hash != $hashlast ]; then
		counthash=$[counthash + 1]
	fi
	hashlast=$hash

	echo $path >> conf.txt
done < $pathfile

sort conf.txt | uniq > config.txt
countuniq=`wc -l config.txt | awk '{print $1}'`

if test $pathfile; then
	echo $count $countuniq $counthash
else
	echo "File not exist"
fi

rm conf.txt
rm config.txt
