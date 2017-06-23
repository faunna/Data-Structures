
# mergeSort program 

ABOUT THIS PROGRAM
__________________



This C++ program contains a mergesort algorithm applied over C++ arrays: is an efficient, general-purpose, comparison-based sorting algorithm (https://en.wikipedia.org/wiki/Merge_sort). It is a divide and conquer algorithm which works as follows:

1. Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).
2.Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.


GETTING STARTED:
________________

You just have to compile the "mergeSort.cpp" file in your terminal with the **g++** command, and then type ./a.out to run the executable: 

The **main** function generates an array with 100 randomly generated ints and prints this array before and after the **mergeSort** was done. It returns nothing.


THE PROGRAM:
________________

This program is compounded by two **void** functions:

	1. merge(int a[], int init, int med, int fin):
		int a[]: our array of ints
		int init: the starting index of the array a to be mergeSorted
		int med: the midpoint between init and fin
		int fin: the ending index of the array a to be mergeSorted

	 which creates an auxiliar array to store the merged values.

	PRECONDITIONSs:0<=init<=mid<fin fin<l, where l=length(a)
        	    a is already ordered between init and mid,a is already ordered between  mid+1 and fin
	POSTCONDITIONS:a is already ordered between inic y fin


	2. mergeSort(int a[], int init, int fin):
	
	with the same interpretation for its arguments than above.


This functions recursively call itself for both splitted arrays and then merge them with the previous function. 


AUTHOR: https://github.com/faunna











