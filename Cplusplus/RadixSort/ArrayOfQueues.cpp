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
#include "Node.h"
#include "LinkedQueue.h"
#include "ArrayOfQueues.h"

using namespace std;

ArrayOfQueues::ArrayOfQueues(){
	root=6;
	dataSize=25;
        array=new LinkedQueue[root];
}
        
ArrayOfQueues::ArrayOfQueues(int a[]){
	root=6;
        dataSize=25;
        array=new LinkedQueue[root];
        	for(int i=0;i<dataSize;i++){
                        int remainder=a[i]%10;
                        array[remainder].push(a[i]);
                }
        }

ArrayOfQueues::~ArrayOfQueues(){
	cout<<"ArrayOfQueues destructor was called"<<endl;
        delete[] array;
}       
                


void ArrayOfQueues::printArrayOfQueues(){
	for(int i=0;i<root;i++){
        	cout<<"Queue"<<i<<":"<<endl;
                array[i].printLinkedQueue();
        }
}
ArrayOfQueues ArrayOfQueues::secondPass(){
	ArrayOfQueues b;
        for(int i=0;i<b.root;i++){
        	while(!(array[i].isEmpty())){
                	int number=array[i].pop();
                	int remainder=(number/10)%10;
                        b.array[remainder].push(number);
                }
        }
        return b;
} 
                
ArrayOfQueues ArrayOfQueues::thirdPass(){
	ArrayOfQueues b;
        for(int i=0;i<b.root;i++){
        	while(!(array[i].isEmpty())){
                	int number=array[i].pop();
                        int remainder=number/100;
                        b.array[remainder].push(number);
                        }
                }
                return b;
}    
int * ArrayOfQueues::outcome(){
	int * output=new int[dataSize];
        int j=0;
        for(int i=0;i<root;i++){            
        	while(!(array[i].isEmpty())){
        		output[j]=array[i].pop();
        	        cout<<output[j]<<",";
        	        j=j++;
        	}
        	j=j++;
        }
        return output;
}


int main(){
	#include "Node.h"
	#include "LinkedQueue.h"
	#include "ArrayOfQueues.h"
	
        int data[] = {442,503,312,145,250,34,325,102,420,143,111,445,300,213,211,21,512,124,23,0,3,444,222,555,335};
        ArrayOfQueues a(data);
        cout<<"Pass 1: "<<endl;
        a.printArrayOfQueues();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
        ArrayOfQueues b=a.secondPass();
        cout<<"Pass 2: "<<endl;
        b.printArrayOfQueues();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
        ArrayOfQueues c=b.thirdPass();
        cout<<"Pass 3: "<<endl;        
        c.printArrayOfQueues();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Ordered Output: "<<endl;        
        c.outcome();
   
       

    
        
}     
                 
                
                
         
                
        
