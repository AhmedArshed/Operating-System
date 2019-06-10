#!/bin/bash

b=1
while [ $b -lt 6 ]
do
	`gcc a.c -o a`
	output=$(./a $b)
	echo $output  >> file.txt
	b=`expr $b + 1`
if [ $b -eq 6 ]
	then
	cat file.txt
fi

  done
gnuplot graph.plt

awk ' function abslute(x){
			  if(x<0) 
				 return x*=-1 
			    else
				 return x
			}
		{print abslute($1 =$2 - 3.141567)}' file.txt > out.txt

awk ' function relative_abs(x){
			 	 if(x<0) 
					 return x*=-1 
				else 
					return x
			     }
			{print relative_abs($2 =($2 - 3.141567)/3.141567)}' file.txt > out1.txt

gnuplot xyz.plt

rm file.txt
