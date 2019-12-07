echo "Enter n"
read n
x=1
c=1
while [ $c -le $n ]
do
    if [ `expr $x % 2` != 0 ]
    then 
    echo $x
    c=`expr $c + 1`
    fi
    x=`expr $x + 1`
    
done
