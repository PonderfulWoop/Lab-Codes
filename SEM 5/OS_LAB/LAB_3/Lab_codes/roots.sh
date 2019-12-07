echo "Enter a, b, c"
read a
read b
read c
echo "roots are:"
d=$(( ($b)*($b)-4*($a)*($c) ))
if [ $d -gt 0 ]
then flag=1
elif [ $d -eq 0 ]
then flag=0
else
flag=2
fi

case $flag in
"1") echo -n "x1 = "
     echo -e "scale=2\n0.5*(-($b)+sqrt($d)/($a))" | bc
     echo -n "x2 = "
     echo -e "scale=2\n0.5*(-($b)-sqrt($d)/($a))" | bc
     ;;
"0") echo -n "x = "
     echo -e "0.5*(-($b)/($a))" | bc
     ;;
"2") echo -n "x1 = ("
     echo -e "0.5*(-($b)/($a))" | bc
     echo -e "scale=2\n0.5*(sqrt(-($d))/($a))" | bc
     echo "i)"
     echo -n "x2 = ("
     echo -e "0.5*(-($b)/($a))" | bc
     echo -e "scale=2\n0.5*(sqrt(-($d))/($a))" | bc
     echo "i)"
     ;;
esac