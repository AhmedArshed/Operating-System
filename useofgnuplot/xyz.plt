#!/usr/bin/gnuplot -persist

set terminal pdf

set output "absolute_error.pdf"

set title "Absolute"

set xlabel "Number"

set ylabel "Time"

set grid

plot "<paste out.txt out1.txt" using 1:2
