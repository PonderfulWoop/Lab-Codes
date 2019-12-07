echo $0 is running
echo "Sorted numbers: (also stored in out.txt)"
echo $(cat $1 $2 | sort -n -u)
cat $1 $2 | sort -n -u > out.txt
