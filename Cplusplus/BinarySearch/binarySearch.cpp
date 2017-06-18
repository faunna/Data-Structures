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

