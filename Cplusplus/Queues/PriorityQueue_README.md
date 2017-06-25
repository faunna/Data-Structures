*\
    Copyright (C) 2017. faunna

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



# PriorityQueue program

ABOUT THIS PROGRAM
__________________

This C++ program contains a class for linked-list based priority queues. (https://en.wikipedia.org/wiki/Priority_queue)



GETTING STARTED:
________________

Linux: You just have to compile the **`PriorityQueue.cpp`** file in your terminal with the **`g++`** command, and then type **`./a.out`** to run the executable: 


THE PROGRAM:
____________

This program is composed by the **`Node`** and **`PriorityQueue`** templated classes and the **`main()`** function:

The Node templated Class:			SPECIFICATION
_________________________

It contains 2 class variables:
	1- **T element**: an element of type T. **int** is used as T in the **main()** function.
        2- **bool priority**: a boolean that represents the priority of the given element T (0-no priority, 1- priority)
        3- **Node<T> * next**: a pointer to the next Node of the priority queue.
			
This class also contains a member:
	1-A parameterized constructor **Node<T>(T elem,bool prior,Node<T> *nxt)**: it creates a node with **T element=elem**, 	
	**bool priority=prior** and pointing to the next node of the priority queue with **Node<T> next=nxt**

The PriorityQueue templated Class:		SPECIFICATION
__________________________________


It contains 5 class variables:
	1- **Node<T> * first**: a pointer to the first T node of the priority queue. 
	2- **Node<T> * last_hi_prior**: a pointer to the last T node with higher priority (this queue first stores the elements 
		with priority=1 and then stores the lower priority elements (priority=0).
        3- **Node<T> * last**: a pointer to the last T node which agrees with the last lower priority node.
        4- **int numberOfHiPrElements**: an **int** that stores the number of elements with higher priority.		  	 
	5- **int numberOfLowPrElements**: an **int** that stores the number of elements with lower priority.			

This class also contains 8 class members:
	1- A default constructor **PriorityQueue()**, which sets the three pointers to NULL, and sets the number of elements of 
		both priorities to 0. (i.e., it creates an empty priority queue).	
	2- **void push(T elem, bool prior)**: the modified **void push** function of a queue, which here, it stores the element	
		according to its priority.				
	3- The destructor **~PriorityQueue<T>()**: which deeply deletes a PriorityQueue out of scope.
	4-  **void pop()**: here, the **pop()** function is **void**, it does not return the popped element, it is limited to pop 
		the elements respecting the order in which they have been pushed.	
	5- The ** int getNumberOfHiPrElements()** to return the number of high priority elements in the queue.
	6- The ** int getNumberOfLowPrElements()** to return the number of low priority elements in the queue.
	7- The boolean **isEmpty()** function to determine whether a given **PriorityQueue** is empty or not.
	8- The **void printPriorityQueue()** function to print the values stored in the PriorityQueue that calls it.



The **main()** function:
________________________

This naïve **main()** function is limited to create a priority queue of ints: **PriorityQueue<int> c** and to push one by one the 
pairs of (int,bool) which represents (T element, bool priority) in the following set:
				
			{(0,1),(1,0),(2,1),(3,0),(4,1),(5,0),(6,1),(7,0),(8,1),(9,0),(10,1),(11,0),(12,1)}


So, here we have constructed a priority queue which already has its elements sorted, first by priority, and second by push order. 
To check this, the **main()** function requests a print and we see:

				(0,1)(2,1)(4,1)(6,1)(8,1)(10,1)(1,0)(3,0)(5,0)(7,0)(9,0)(11,0)

Then it calls twice the **pop()** function and our queue looks like:

				(4,1)(6,1)(8,1)(10,1)(1,0)(3,0)(5,0)(7,0)(9,0)(11,0)

i.e. the first two elements, (0,1) and (2,1) have been popped. Here, it pushes (12,1) and (13,0), prints the queue and the current 
number of high and low priority elements (here ints) stored in the queue:
  
				(4,1)(6,1)(8,1)(10,1)(12,1)(1,0)(3,0)(5,0)(7,0)(9,0)(11,0)(13,0)
				Number of HIPR elements: 5
				Number of LOWPR elements: 7

AUTHOR: https://github.com/faunna
___________________________________








