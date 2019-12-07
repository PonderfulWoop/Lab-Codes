#Case Conditionality

echo "Enter a char"
read char

case $char in
    [\+]) echo "add symbol";;
    [\-]) echo "subtract symbol";;
    [\*]) echo "multiply symbol";;
    [\/]) echo "Divide symbol";;
    esac