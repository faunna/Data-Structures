/*
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


#include <iostream>
#include <stdlib.h>

using namespace std;


class Node;

class Node{
     public:
        int value;
        Node * next;         
     public:
        Node(int n, Node * s){
                value=n;
                next=s;
        }
};

class LinkedQueue{
        Node * first;
        Node * last;

        public:
        LinkedQueue(){
                first=NULL;
                last=NULL;
        }

        ~LinkedQueue(){
                Node * newNode;
                while (first!=NULL){
                        newNode=first->next;
                        delete first;
                        first=newNode;
                }
        }

        bool isEmpty(){
                return first==NULL;
        }

        void push(int elem){

                Node * newNode=new Node(elem,NULL);
                if(first==NULL)
                        first=newNode;
 
                else
                        last->next=newNode;
                last=newNode;
        }
        int pop(){ 
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
        

                void printLinkedQueue(){
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
                        
};

int main(){
        LinkedQueue p;
        for(int i=0;i<36;i++){
           	p.push(i);
       	}
        p.printLinkedQueue();
	cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
        for(int i=0;i<22;i++){
                cout<<p.pop()<<",";
        }
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
        p.push(127);
	p.printLinkedQueue();
	 cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
	for(int i=0;i<20;i++){
                cout<<p.pop()<<",";
        }
        p.printLinkedQueue();
}     
                 
                
                
         
                
        
