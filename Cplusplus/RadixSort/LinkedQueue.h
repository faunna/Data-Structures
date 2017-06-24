#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H



class LinkedQueue{

	public:
        Node * first;
        Node * last;

        public:
        LinkedQueue();

        ~LinkedQueue();

        bool isEmpty();

        void push(int elem);

        int pop();

        void printLinkedQueue();
                        
};

#endif
