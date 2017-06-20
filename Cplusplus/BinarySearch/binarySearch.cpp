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

int binarySearch(int a[], int init, int fin, int elem){
		int result;
		if(init>fin)
			result=init;
		else {
			int mid=(init+fin)/2;
			if (a[mid]<elem)
				result=binarySearch(a,mid+1,fin,elem);
			else
				result=binarySearch(a,init,mid-1,elem);
		}
		return result;
}

int main(){
	int v[]={2,2,4,6,6,7,11,13,16,17,21,54};

	int pos;
	pos=binarySearch(v,0,11,2);
	cout<<"Position: "<<pos<<endl;
	return 0;
}

