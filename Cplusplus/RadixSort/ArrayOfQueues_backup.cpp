/* IMPLEMENTACIÓN EJERCICIO 6 HOJA1 EDAT:
Implementación basada en un array de 6 colas enlazadas. La clase ArrayColas tiene 3 variables miembro: la base en la que estamos trabajando= raiz, el número de elementos a ordenar=tamdatos, y un puntero a array de colas enlazadas. Esta clase tiene dos constructores, el default, y uno que crea el array de colas a partir del array de datos a ordenar haciendo la primera pasada de ordenación de unidades de paso. Las otras dos pasadas de ordenación se hacen desde sendas funciones, pasadaDos(). pasadaTres(), que tienen como parámetro un array de colas y devuelven otro extrayendo datos e insertando de manera adecuada. 
La clase Array de Colas tiene constructor de copia y operador de asignación, pero sólo usa el constructor de copia con este main, y porque lo llamo explícitamente para  verificar su funcionamiento, para resolver el ejercicio no lo debe de necesitar. El operador de asignación no consigo que lo use, pero como compila, entiendo que para manejar arrays no necesita deep copy y por eso no lo usa.*/
#include <iostream>
#include <stdlib.h>
#include "Node.h"
#include "LinkedQueue.h"
#include "ArrayOfQueues.h"

using namespace std;

ArrayOfQueues::ArrayOfQueues(){
	root=6;
	dataSize=10;
        array=new LinkedQueue[root];
}
        
ArrayOfQueues::ArrayOfQueues(int a[]){
	root=6;
        dataSize=10;
        array=new LinkedQueue[root];
        	for(int i=0;i<dataSize;i++){
                        int remainder=a[i]%10;
                        array[remainder].push(a[i]);
                }
        }
        //DESTRUCTOR
ArrayOfQueues::~ArrayOfQueues(){
	cout<<"ArrayOfQueues destructor was called"<<endl;
        delete[] array;
}       
                

        //ASSIGNMENT OPERATOR
ArrayOfQueues & ArrayOfQueues::operator=(const ArrayOfQueues &p){
	cout<<endl<<"ArrayOfQueues Assignment Operator was called"<<endl;
        LinkedQueue *me= array;
        delete[] me;
        array=new LinkedQueue[root];
        for(int i=0;i<root;i++){
        	array[i]=p.array[i];
        }
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
        int data[] = {442,503,312,145,250,34,325,102,420,143};
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
                 
                
                
         
                
        
