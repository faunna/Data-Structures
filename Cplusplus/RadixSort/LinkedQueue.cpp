#include <iostream>
#include <stdlib.h>
#include "Node.h"
#include "LinkedQueue.h"

using namespace std;

LinkedQueue::LinkedQueue(){
	first=NULL;
        last=NULL;
}

LinkedQueue::~LinkedQueue(){
	Node * newNode;
        while (first!=NULL){
        	newNode=first->next;
                delete first;
                first=newNode;
        }
}

bool LinkedQueue::isEmpty(){
	return first==NULL;
}

void LinkedQueue::push(int elem){
	Node * newNode=new Node(elem,NULL);
        if(first==NULL)
        	first=newNode;
        else
        	last->next=newNode;
        last=newNode;
}
int LinkedQueue::pop(){ 
	if(first==NULL){
        	cout<<"Empty queue, I cannot pop!"<<endl;
                 return 0;
        }
        else{
        	int result = first->value;                
                Node * newNode=first->next;
                delete first;
                first=newNode;
                if(first==NULL)
                	last==NULL;            
                        return result;
                        
                        
	}

}
        
void LinkedQueue::printLinkedQueue(){
	if(isEmpty()==true){
		cout<<"Empty queue, I cannot print!"<<endl;
        }
        else{
        	Node * newNode =first;
                int result=first->value;
                while (newNode->next!=NULL){
                	cout<<result<<",";
                        newNode=newNode->next;
                        result=newNode->value;
                }
                cout<<result<<endl;
        }                
}
        
