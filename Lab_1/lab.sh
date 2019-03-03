#!/bin/bash
cd d:/lab
mkdir fold1
cd fold1
mkdir fold2
cd fold2
mkdir fold3
cd d:/lab/fold1
echo $(date)>date1.txt
cp d:/lab/fold1/date1.txt d:/lab/fold1/fold2/date1.txt 
cd d:/lab/fold1/fold2
mv date1.txt date2.txt
name=date2
count=$(echo $name|wc -c)
echo $count>>date2.txt
cp d:/lab/fold1/fold2/date2.txt d:/lab/fold1/fold2/fold3/date2.txt 
cd d:/lab/fold1/fold2/fold3  
echo $OSTYPE>>date2.txt

