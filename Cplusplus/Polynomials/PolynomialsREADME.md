
# Class of integer polynomials



ABOUT THIS PROGRAM
__________________

The aim of this program is to create a complete class to handle integer polynomials.



GETTING STARTED:
________________

Linux: You just have to compile the "polynomials.cpp" file in your terminal with the **g++** 
	command, and then type ./a.out to run the executable: 


THE PROGRAM:
____________

This program is composed by the **Node** and **IntPols** classes and the **main()** function:

	The Node Class:
	_______________

		It represents a monomial, and it is used by the IntPols class to generate polynomials.
		This class contains 3 class variables:
			1-int coeff: an **int** to store the coefficient of this monomial.
			2-int degree: an int to store the degree
			3-Node *next: a pointer to the next Node (monomial) of the polynomial.
	
		this class also contains a constructor:
			1- **Node(int n, Node * s)**: it creates a Node
				with a integer **value=n** and a pointer, **s** to the next Node of
				the polynomial.

	The IntPols Class: 		SPECIFICATION
	______________________

			This class generates polynomials and prints them with mathematical notation:
					a_n  x^n + ... + a_1  x + a_0
			When a coefficient is negative, for example a_{n-1}=-3, it is displayed so:
					a_n x^n + -3 x^{n-1}
				


			It contains one class variable:

				1- Node * first: a pointer to the first Node of the linked list that 
					represents a polynomial.
				


		
			This class also contains various member functions in which this program 
			has been focused:
			
			1- A default constructor: **IntPols()**, which sets the pointer **first** to NULL,
				i.e, which creates an empy polynomial.

			2- A parameterized constructor: **IntPols(int c,int d)**, which creates a
				monomial via Node class and sets the pointer **first** to it.

			3- An awesome **void** member function: **void attach(int c,int d)**
				to attach the monomial created from its parameters to the polynomial
				that has called it.

			4- The polynomials constructor: ** IntPols(int * pcoef,int * pdeg, int size)**
				which has the following parameters and associated PRECONDITIONS:
				4.1- int * pcoef: a pointer to an array with the coefficients of the
					polynomial we want to create
				PRECONDITION1: this array cannot contain zeros, because a 0 coefficient
					has no effect over the polynomial.
				4.2- int * pdeg: a pointer to an array with the degrees of the polynomial
					we want to create.
				PRECONDITION2: this array has to be sorted in descending order, its
					elemens (ints) have to be unique, and of course, it can contains 
					 a 0 representing the constant term of the polynomial.
				4.3- int size: an int storing the length of the linked list that 
					represents a polynomial.
			
			5- The class destructor: **~IntPols()**. It contains a line of code:
				    **  cout<<endl<<"Destructor was called"<<endl; **			
				to print a message when the destructor is called, i.e.,  when a object of
			        the class goes outof scope or when the **delete** expression is applied
			        to a pointer to a polynomial.
			
			6- The copy constructor: **IntPols(const IntPols & p)** called whenever a			
				polynomial is initialized ( direct-initialization or copy-initialization), 
				to make a deep copy of the polynomial that calls it.
				It also includes a line of code to print a message when it is called.
		
			7- The assignment operator: ** IntPols & operator=(const IntPols & p) **, 
				called when an polynomial appears on the left side of an assignment 
				expression. It also includes a line of code to print a message when it
				 is called. 
			
			8- Overloading the + operator: ** IntPols & operator+(const IntPols & p) ** to
				sum two polynomials by adding the coefficients of monomials with the same
				degree.
			
			9- Overloading the * operator: ** IntPols & operator*(const int & c) ** 
				to correctly multiply polynomials by constants.

			10- A **void** auxiliar member function: ** void clear(IntPols & p) ** used to
				store partial sums when multiplying two polynomials.

			11- Overloading the * operator: ** IntPols & operator*(const IntPols & p) ** to
				to correctly multiply two polynomials.

			12- An boolean **isEmpy()** member function to check whether a given polynomial 
				is empty or not.

			13- A **void** member function: ** void printIntPols() ** to print a polynomial 
				with the mathematical notation given above.


			


	The **main()** function:
	________________________

		This **main()** functions creates two polynomials, p and q from two randomly-generated arrays with the 				coefficients, from two manually created arrays with the degrees (please, read the associated PRECONDITIONS above); 		   and from two ints representing the length of both polynomials.
		Then, it tests all the implemented member functions.
		

AUTHOR: https://github.com/faunna
___________________________________









