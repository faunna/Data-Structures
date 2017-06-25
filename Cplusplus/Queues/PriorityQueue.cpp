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

template <class T>
class Node{
        public:
        T element;
        bool priority;
        Node<T> * next;
        
        Node<T>(T elem,bool prior,Node<T> *nxt){
                element=elem;
                priority=prior;
                next=nxt;
        }
};

template <class T>
class PriorityQueue{
        Node<T> * first;
        Node<T> * last_hi_prior;
        Node<T> * last;
        int numberOfHiPrElements;
        int numberOfLowPrElements;
        public:
        //Default Constructor
        PriorityQueue(){
                first=NULL;
                last_hi_prior=NULL;
                last=NULL;
                numberOfHiPrElements=0;
                numberOfLowPrElements=0;
        }
        void push(T elem, bool prior){
                Node<T> *newNode=new Node<T>(elem,prior,NULL);
                if(prior){
                        numberOfHiPrElements=numberOfHiPrElements+1;
                    
                        if((last_hi_prior==NULL)&&(last==last_hi_prior)){
                                first=newNode;
                                last=newNode;
                        }

                        else if((last_hi_prior==NULL)&&(last!=last_hi_prior)){
                                newNode->next=first;
                                first=newNode;
                        }
                        else if((last_hi_prior!=NULL)&&(last==last_hi_prior)){
                                last->next=newNode;
                                last=newNode;
                        }
                        else if((last_hi_prior!=NULL)&&(last!=last_hi_prior)){
                                newNode->next=last_hi_prior->next;
                                last_hi_prior->next=newNode;
                        }
                        last_hi_prior=newNode;
                }
                else {
                        numberOfLowPrElements=numberOfLowPrElements+1;
                        if(last!=NULL){
                                last->next=newNode;
                        }
                        else {
                                first=newNode;
                        }
                        last=newNode;
                }
        }
         //Destructor
        ~PriorityQueue<T>(){
                cout<<"PriorityQueue DESTRUCTOR was called"<<endl;
                Node<T> * oldNode;
                while (first!=NULL){
                        oldNode=first->next;
                        delete first;
                        first=oldNode;
                }
        }
                                                
        void pop(){
                Node<T> *oldNode;
                if(first==NULL){
                        cout<<"Empty queue, I cannot print!!"<<endl;
                }
                else {
                        oldNode=first;
                        first=first->next;
                        if(first==NULL){
                                last==NULL;
                                last_hi_prior==NULL;
                        }
                        if(oldNode->priority){
                                numberOfHiPrElements=numberOfHiPrElements-1;
                                if(numberOfHiPrElements==0){
                                        last_hi_prior==NULL;
                                }
                        }
                        else {
                                numberOfLowPrElements=numberOfLowPrElements-1;
                        }
                        delete oldNode;
                }
        }
        int getNumberOfHiPrElements(){
                int result;
                result=numberOfHiPrElements;
                return result;
        }
        int getNumberOfLowPrElements(){
                int result;
                result=numberOfLowPrElements;
                return result;
        }
        bool isEmpty(){
                return first==NULL;
        }
        void printPriorityQueue(){
                if(isEmpty()){
                        cout<<"Empty queue, I cannot print!!"<<endl;
                }
                else{
                        Node<T> *oldNode=first;
                        T result=first->element;
                        bool result2=first->priority;
                        while (oldNode->next!=NULL){
                        cout<<"("<<result<<","<<result2<<")";
                        oldNode=oldNode->next;
                        result=oldNode->element;
                        result2=oldNode->priority;
                        }
                        cout<<"("<<result<<","<<result2<<")"<<endl;
                        }                
        }      
};                                      
                        


int main(){
        PriorityQueue<int> c;
        c.push(0,1);
        c.push(1,0);
        c.push(2,1);
        c.push(3,0);
        c.push(4,1);
        c.push(5,0);
        c.push(6,1);
        c.push(7,0);
        c.push(8,1);
        c.push(9,0);
        c.push(10,1);
        c.push(11,0);
        c.printPriorityQueue();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
        c.pop();
        c.pop();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
	c.printPriorityQueue();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
        c.push(12,1);
        c.push(13,0);	
        c.printPriorityQueue();
	cout<<"Number of HIPR elements: "<<c.getNumberOfHiPrElements()<<endl;
	cout<<"Number of LOWPR elements: "<<c.getNumberOfLowPrElements()<<endl;
}     


