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
 /*
       Preconditions:0<=init<=mid<fin fin<l, where l=length(a)
            a is already ordered between init and mid,a is already ordered between  mid+1 and fin
       Postcondition:a is already ordered between inic y fin
       */

void merge(int a[], int init, int mid, int fin){
	int i=init;
	int j=mid+1;
	int aux[fin-init+1];
	int pos=0;
	while(i<=mid & j<=fin){
		if(a[i]<=a[j]){
			aux[pos]=a[i];
			i++;
			pos++;
		}
		else {
			aux[pos]=a[j];
			j++;
			pos++;
		}
	//Here, or a[i] or a[j] has reached its boundary
	}
	for(int k=i;k<=mid;k++){
		aux[pos]=a[k];
		pos++;
	}
	for(int k=j;k<=fin;k++){
		aux[pos]=a[k];
		pos++;
	}

	pos=0;
	for(int k=init;k<=fin;k++){
		a[k]=aux[pos];
		pos++;
		}
	}

void mergeSort(int a[], int init, int fin){
	/*
        Precondition: 0<=init<=fin<l, where l=length(a)
        Post: a is already ordered between inic y fin
        */
	//If init=fin, our array has only an element and it is no possible to pass an empty list to the method. So we ignore this case.
	if(init<fin){
		int mid=(init+fin)/2;
		mergeSort(a,init, mid);
		mergeSort(a,mid+1,fin);
		merge(a, init, mid, fin);
	}
}

int main(){
	srand(100);
	int a[100];
	for(int i=0;i<100;i++){
           a[i]=rand() % 100;
        }
	cout<<"Original array: "<<endl;
 	for(int i=0;i<100;i++){
               cout<<a[i]<<",";
      }
	mergeSort(a,0,99);
	cout<<"  "<<endl;	
	cout<<"Ordered array: "<<endl;
 	for(int i=0;i<100;i++){
               cout<<a[i]<<",";
      }
	cout<<"  "<<endl;
	return 0;
}
