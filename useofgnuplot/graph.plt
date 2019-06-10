#!/usr/bin/gnuplot -persist

set terminal pdf

set output "n_times.pdf"

set title "Number Time"

set xlabel "Number"

set ylabel "Time"

set grid

plot "file.txt" using 1:3 smooth acsplines
