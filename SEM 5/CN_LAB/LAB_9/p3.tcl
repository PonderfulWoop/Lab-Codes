set ns [new Simulator]

set nt [open simulate.nam w]
$ns namtrace-all $nt

set tr [open simulate.tr w]
$ns trace-all $tr

proc finish {} {
	global ns nt tr
	$ns flush-trace
	close $nt
	close $tr
	exec nam simulate.nam &
	exit 0
}

set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

$ns duplex-link $n1 $n2 2Mb 20ms DropTail
$ns duplex-link $n3 $n4 1Mb 10ms DropTail

set cbr0 [new Agent/CBR]
$ns attach-agent $n1 $cbr0
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005

set null0 [new Agent/Null]
$ns attach-agent $n2 $null0

$ns connect $cbr0 $null0

set cbr1 [new Agent/CBR]
$ns attach-agent $n3 $cbr1
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005

set null1 [new Agent/Null]
$ns attach-agent $n4 $null1

$ns connect $cbr1 $null1

$ns make-lan "$n1 $n2 $n3 $n4" 100Mb 300ms LL Queue/DropTail Mac/802_3

$ns at 0.5 "$cbr0 start"
$ns at 0.7 "$cbr1 start"
$ns at 2.5 "$cbr0 stop"
$ns at 2.6 "$cbr1 stop"

$ns at 2.8 "finish"
$ns run