#!/usr/bin/env perl

# Created by tharchen with a ton of <3

# usage: ./genstack stacksize min max
# exemple: ./genstack 10 0 1000
# will creates 10 uniques numbers from 0 to 1000
# like: 138 527 947 967 811 33 112 526 949 27
# enjoy :)

$stacksize = $ARGV[0];
$min = $ARGV[1];
$max = $ARGV[2];
@stack = ();
$length = @stack;

if ($max - $min < $stacksize)
{
	print "Range too short for stack size. Exiting...\n";
	exit (1);
}

while ($length < $stacksize) {
    $n = int(srand() % ($max- $min) + $min);
    if (!(grep { $_ eq $n } @stack)) {
        push @stack, $n;
		$length ++;
    }
}

print "@stack\n";
