read -p "Enter path file: " pathfile
read -p "Enter search string: " string
read -p "Enter replace string: " newstring

if test $pathfile; then
	if [ $string != "" ] && [ $newstring != "" ]; then
		sed "s/$string/$newstring/" $pathfile
	else
		echo "ERROR"
	fi
else
	echo "ERROR..."
fi

sha=`shasum -a256 $pathfile | awk '{ print $1 }'`
time=`date +"%Y-%m-%d %H:%M"`
size=`stat -f%z $pathfile`

echo "$pathfile - $size - $time - $sha - sha256" >> ./files.log
