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

class arrayBasedQueue{
	int*data;
	int capacity;
	int index;
	int size;
	public:
	arrayBasedQueue(){
		data=new int[10];
		capacity=10;
		size=0;
		index=0;
	}
	private:
	int next(int ind){
		return(ind+1) % capacity;
	}
	public:
	void  push(int elem){
		if(next(size)==index)
			double_capacity();
		data[size]=elem;
		size=next(size);
	}
	~arrayBasedQueue(){
           delete[] data;
         }
	int pop(){
		if(index==size){
			cout<<"empty queue!"<<endl;
			return 0;
		}
		else {
			int result;
			result=data[index];
			index=next(index);
			return result;
		}
	}

	void double_capacity(){
            int * new_data=new int[capacity*2];
            for(int i=index;i<capacity;i++){
                    new_data[i]=data[i];
            }
            capacity=capacity*2;
            delete[] data;
            data=new_data;
        }

	void printArrayBasedQueue(){
		for(int i=index;i<size;i++){
		cout<<data[i]<<",";
		}
	}


};
	int main(){
		arrayBasedQueue p;
		for(int i=0;i<15;i++){
           		p.push(i);
       		}
        	p.printArrayBasedQueue();
		cout<<endl<<"-------------------------------------------"<<endl;
		for(int i=0;i<9;i++){
           		cout<<p.pop()<<",";
       		}

		cout<<endl<<"-------------------------------------------"<<endl;
		p.push(127);
		p.printArrayBasedQueue();
		cout<<endl;

}

