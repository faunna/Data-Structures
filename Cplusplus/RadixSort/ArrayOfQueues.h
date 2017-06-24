#ifndef ARRAYOFQUEUES_H
#define ARRAYOFQUEUES_H


class ArrayOfQueues{

	public:
        int root;
        int dataSize;
        LinkedQueue * array;

        public:
        ArrayOfQueues();
        
        ArrayOfQueues(int a[]);

        //DESTRUCTOR
        ~ArrayOfQueues();     


       	void printArrayOfQueues();
        ArrayOfQueues secondPass();
                
        ArrayOfQueues thirdPass();
        int * outcome();
};

#endif
