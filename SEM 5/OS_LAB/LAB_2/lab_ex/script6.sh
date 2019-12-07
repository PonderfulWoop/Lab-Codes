echo $0 is running
echo Enter Format
read format
files=$(ls -f $format)
echo $files
echo Enter dest
read d
cp $files $d