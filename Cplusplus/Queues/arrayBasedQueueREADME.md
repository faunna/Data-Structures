#arrayBasedQueue program

ABOUT THIS PROGRAM
__________________

This C++ program contains a class of array-based-queues. Who did say that we cannot get dynamic 
	memory with C++ arrays? 

GETTING STARTED:
________________

You just have to compile the "arrayBasedQueue.cpp" file in your terminal with the **g++** 
	command, and then type ./a.out to run the executable: 


THE PROGRAM:
____________

This program is composed by the **arrayBasedQueue** class and the **main()** function:

	The Class:
	_________

		this class contains 4 class variables:
			1-int*data: a pointer to the array that supports the queue
			2-int capacity: an **int** that stores the capacity of the array
			3-int index: an auxiliary **int** that stores a given position
			4-int size: an int that stores the current state of storage
	
		this class also contains public and private methods:
			1-The constructor **arrayBasedQueue()**: it reserves memory for an array 
				with an initial capacity of 10, and set **index** and **size** to 0.
			2-The **next(int ind)** method: it returns the next index of the current array
				 taking into the account its current size.
			3-The **push(int elem)** method: it checks if the next position of the current 
				 array is the last free one. If so, it calls the **double_capacity()** 
				method below before push the givent element.
			
			4- The destructor **~arrayBasedQueue()** to deallocate the memory block pointed
				 to by **data**.
			5- The **int pop()** method: it works as it is required, printing "empty queue!"
				 when that is the case so it is not possible to pop(); and returning
				the popped element and moving the index otherwise.  
			6- The **double_capacity** method: It replaces our array by another twice bigger,
				deleting the discarded copy.
			7- The **printArrayBasedQueue()** method to print the values of a given queue.
			


	The **main()** function:
	________________________

		It calls the constructor to create an **arrayBasedQueue p **, then it pushes the 
		first 15 **int** numbers (starting at 0) and prints the current values of **p**;
		in second place, it pops its first ten elements and prints the queue.
		Finally it pushes 127 and prints the queue again. As usual, feel free to customize it.



AUTHOR: https://github.com/faunna
___________________________________









