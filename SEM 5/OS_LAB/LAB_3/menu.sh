echo "Menu Test"
stop=0
while [ $stop -eq 0 ]
do
    echo "1: Date"
    echo "2, 3: Current Directory"
    echo "4: exit"
    echo "Your choice?"
    read reply
    echo
    case $reply in
        "1") date;;
        "2" | "3") pwd;;
        "4") stop=1;;
        *) echo "Illegal";;
    esac
done