# Radix Sort program

ABOUT THIS PROGRAM
__________________

The aim of this program is using [Radix Sort] : (https://en.wikipedia.org/wiki/Radix_sort) to order the elements 
(here, integers) of a given array. 



GETTING STARTED:
________________

Linux: You just have to compile the "ArrayOfQueues.cpp", "LinkedQueue.cpp", "Node.cpp",  files in your terminal,
for example, just like that: g++ ArrayOfQueues.cpp LinkedQueue.cpp Node.cpp -o main, and then type ./main to run the executable.



THE PROGRAM:
____________

This program is composed by the **Node**, **LinkedQueues**, **ArrayOfQueues** classes and the **main()** function, arranged
into header and .cpp files as follows:
	
	+ The **`Node`** class is composed by the **`Node.h`** and **`Node.cpp`** files.
	+ The  **`LinkedQueues`** class is composed by the **`LinkedQueue.h`** and **`LinkedQueue.cpp`** files.
	+ The  **`ArrayOfQueues`** class is composed by the **`ArrayOfQueues.h`** and **`ArrayOfQueues.cpp`** files.
		The **`ArrayOfQueues.cpp`** file also contains the **`main()`** function.






	The Node Class:
	_______________

		It represents a node of a LinkedQueue. It contains a value and a pointer to the next node of the LinkedQueue:
			1-int value: an **int** to store the value of this node.
			2-Node *next: a pointer to the next node of the linkedQueue.
	
		this class also contains a constructor:
			1- **Node(int n, Node * s)** creates a Node with **value=n** and pointing to the next Node with **s**.

	The LinkedQueue Class:
	______________________


		it contains 2 class variables:
			1- Node * first: a pointer to the first node of the list
			2- Node * last: a pointer to the last node of the list
		
		this class also contains class members:
			
			1- the constructor **LinkedQueue()**, which sets both 
				pointers to NULL.
			2- the destructor **~LinkedQueue()**. which deeply deletes
				 a LinkedQueue
			3- the boolean  **isEmpty()** method over LinkedQueues
			4- the **push(int elem)** method to add **elem** by the tail of the queue
			5- the **pop()** method to pop (and return) the required element
			6- the **printLinkedQueue()** method to print the elements of the given queue.


	The ArrayOfQueuesClass:			SPECIFICATION
	_______________________

		This class has three class variables:
			1- int root: an int between 2 and 10 to fix the base of the numeric representation; here root=6.
			2- int dataSize: an int to store the length of the input array with the numbers to be sorted.
			3- LinkedQueue * array: a pointer to an array of queues, one for each different digit in the consequent representation
				 (i.e. if root =6 we have 6 possible digits, and we need one queue for each one).


		
		PRECONDITIONS: This implementation was made with three passes, so, the input array only can contain integers
		(in base **root**) with at most three digits.

		
		This class also contains seven class members:
			1- A default constructor: **ArrayOfQueues()** which sets the root to 6 and the size of the input array
				to 25.
			2- A parameterized constructor: **ArrayOfQueues(int a[])** which also sets the root to 6, and the size of
				the input array to 25 and makes the first pass, ordering the pass units.
			3- The class destructor: **~ArrayOfQueues()**
			4- **void printArrayOfQueues()**: A **void** function to print the values stored on the linked queues contained in the array,
				whic uses the class member **printLinkedQueue()** of the LinkedQueue class stored in the LinkedQueue.cpp file.
			5- **ArrayOfQueues secondPass()** : A class member which, called by a ArrayOfQueues, makes the second pass, ordering the
				second digit of each input number.
			6- **ArrayOfQueues thirdPass()** : A class member which, called by a ArrayOfQueues, makes the third pass, ordering the
				third digit of each input number.
			7- **int * outcome()**: An awesome function to print and store the sorted output array. It returns a pointer to an array
				 that stores (and prints) all the popped elements of the six linked queues which store the numbers.

		NOTE: As the outer structure of this class is an array it is not necessary to build a copy constructor and an assignment operator,
			because they would not be used.

		


	The **main()** function:
	________________________

		It **`#include`**s the three header files required to run the program.
		Then it takes the following input array:

		int data[] = {442,503,312,145,250,34,325,102,420,143,111,445,300,213,211,21,512,124,23,0,3,444,222,555,335};
		
		then makes the first pass with the parameterized contructor and prints the state of the queues.
		Then, it repeats this process calling to the **ArrayOfQueues secondPass()** function and printing state, and
		the same stuff (call-print) with the last pass  **ArrayOfQueues thirdPass()** function.
		Finally, it calls the awesome **int * outcome()** to print and store all the popped elements in the right order.




AUTHOR: https://github.com/faunna
___________________________________








