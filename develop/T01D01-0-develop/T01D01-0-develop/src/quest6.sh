cd ai_help
bash keygen.sh
cd key
mkdir newkey
for file in *.key; do
	mv $file newkey
done
mv newkey ..
cd ..
rm -r key
mv newkey key
