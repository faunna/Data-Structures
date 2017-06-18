#########################
#LinkedQueue program#
#########################

ABOUT THIS PROGRAM
__________________

This C++ program contains a class for linked-list based Queues. 



GETTING STARTED:
________________

You just have to compile the "LinkedQueue.cpp" file in your terminal with the **g++** 
	command, and then type ./a.out to run the executable: 


THE PROGRAM:
____________

This program is compounded by the **Node** and **LinkedQueue** classes and the **main()** function:

	The Node Class:
	_______________

		It contains 2 class variables:
			1-int value: an **int** to store the value of this node.
			2-Node *next: a pointer to the next node of the linked list.
	
		this class also contains public and private methods:
			1-The constructor **Node(int n, Node * s)**: it creates a node
				with **value=n** and pointing to the next node with **s**

	The LinkedQueue Class:
	_______________


		it contains 2 class variables:
			1- Node * first: a pointer to the first node of the list
			2- Node * last: a pointer to the last node of the list
		
		this class also contains public and private methods:
			
			1- the constructor **LinkedQueue()**, which sets both 
				pointers to NULL.
			2- the destructor **~LinkedQueue()**. which deeply deletes
				 a LinkedQueue
			3- the boolean  **isEmpty()** method over LinkedQueues
			4- the **push(int elem)** method to add **elem** by the tail of the queue
			5- the **pop()** method to pop (and return) the required element
			6- the **printLinkedQueue()** method to print the elements of the given queue.



	The **main()** function:
	________________________

		It calls the constructor to create an **LinkedQueue p **, then it pushes the 
		first 36 **int** numbers (starting at 0) and prints the current values of **p**;
		in second place, it pops its first 22 elements and prints the queue.
		Then it pushes 127 and prints the queue again.
		Finally, it pops 20 times with only 16 elements so prints "Empty queue, I cannot pop!" 
		for times and by last, prints "Empty queue, I cannot print!" because the last call to 
		**printLinkedQueue()**. That is all. Enjoy, and feel free to customize it.




AUTHOR: https://github.com/faunna
___________________________________









