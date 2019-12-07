echo "Enter two Numbers:"
read num1
read num2
echo "Enter an Operator"
read char

case $char in
    [\+]) echo `expr $num1 + $num2`;;
    [\-]) echo `expr $num1 \- $num2`;;
    [\*]) echo `expr $num1 \* $num2`;;
    [\/]) echo -e "scale=2; $num1 / $num2" | bc;;
    *) echo "ILLEGAL OPERATOR";;
    esac
