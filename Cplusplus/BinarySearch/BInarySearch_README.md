# binarySearch program


ABOUT THIS PROGRAM
__________________

This C++ program contains a binary search algorithm applied over C++ arrays:

Also known as half-interval search, logarithmic search, or binary chop, binary search is a search algorithm that finds the position of a target value within a sorted array. Binary search compares the target value to the middle element of the array; if they are unequal, the half in which the target cannot lie is eliminated and the search continues on the remaining half until it is successful or the remaining half is empty. (https://en.wikipedia.org/wiki/Binary_search_algorithm)

GETTING STARTED:
________________

You just have to compile the "binarySearch.cpp" file in your terminal with the **g++** command, and then type ./a.out to run the executable: 


THE PROGRAM:
________________


The **main** function is absolutely naïve, it just takes an ordered array, for example this one:
 
			v[]={2,2,4,6,6,7,11,13,16,17,21,54}


and calls the **void binarySearch(int a[], int init, int fin, int elem)** function where the arguments are:
		
		int a[]: the input ordered array
		int init:the starting index of the array to be binarySearched over
		int fin: the ending index of the array to be binarySearched over
		int elem: the element that we want to find in the array

This function returns an **int** representing the index of the searched element in the array. It only works if **element** belongs to **array**. If not, it will return **init**. This is so because the focus has only been in quickly implementing this algorithm, not in handling exceptions or in I/O operations. Its subtleties reside in the binarySearch() function. Feel free to customize it. 

AUTHOR: https://github.com/faunna
___________________________________
