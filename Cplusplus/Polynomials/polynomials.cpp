/* 

 ######################################################################################
 # polynomials.cpp (Please visit the polynomialsREADME.md for a general description) #
#####################################################################################

     Copyright (C) 2017, faunna

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

class Node{
        public:
        int coeff;
        int degree;
        Node * next;
        // The Nodes constructor
        Node(int n,int m, Node *s){
                coeff=n;
                degree=m;
                next=s;
        }
};
       
class IntPols{
	public:
	Node * first;

	//The default constructor
	IntPols(){
	first=NULL;
	}
	// The monomials constructor
	IntPols(int c,int d){
                first=new Node(c,d,NULL);
        }
	/* An awesome operation to create and upload monomials by the
	   tail of the linked list*/
	void attach(int c,int d){
                Node * newNode = new Node(c,d,NULL);
                if(first==NULL){
                        first=newNode;
         }
                else {  
                        Node * pointer=first;  
                        while(pointer->next!=NULL){ 
                                pointer=pointer->next;
                        }       
                        pointer->next=newNode; 
                }
        }
	// The polynomials constructor
        IntPols(int * pcoef,int * pdeg, int size){
                first=NULL;
                //attach recorre los arrays (luego sube los monomios) en orden,luego en orden decreciente 
                //con respecto al grado, que es la precondición con la que se deben meter los datos,
                //Además de no meter ningún coeficiente nulo.
                for(int i=0;i<size;i++){
                        attach(pcoef[i],pdeg[i]);                                  //THE BIG THREE
                }
        }
	// The destructor	
	~IntPols(){
                cout<<endl<<"Destructor was called"<<endl;
                Node * pointer=first;
                while(pointer!=NULL){
                        Node * newNode=pointer->next;
                        delete pointer;               
                        pointer=newNode;
                }
        }
	// The copy constructor
        IntPols(const IntPols & p){
                cout<<endl<<"Copy Constructor was called"<<endl;
                Node * pointer=p.first;
                first=NULL;
                while(pointer!=NULL){
                        attach(pointer->coeff,pointer->degree);
                        pointer=pointer->next;
                }
        }
	//The assignment operator:
        IntPols & operator=(const IntPols & p){
                cout<<endl<<"Assignment Operator was called"<<endl;
		// this pointer is called **me** to take into the account that we are in the left side
                //of the assignment q=p. 
                Node * me=first;
                while(me!=NULL){
                        Node * newNode=me->next;
                        delete me;
                        me=newNode;
                }
                //Here we have released the memory reserved for q
                first=NULL;
                Node * it=p.first;
                while(it!=NULL){
                        attach(it->coeff,it->degree);
                        it=it->next;
                }
                return *this;
        }
                                         
        //OVERLOADING + OPERATOR
        //cuando realicemos una suma del tipo q+p el compilador lo interpreta
        //como la llamada q.operator+(p). me=q it=p
        IntPols & operator+(const IntPols & p){
                //declaramos y reservamos memoria heap para el resultado, 
                //que será una referencia a un  default constructed polinomio 
                IntPols & result= * new IntPols();  
                //creamos variables locales punteros al sumando parámetro (right)
                // y al sumando objeto (left)
                Node * it=p.first;
                Node * me=first;
                //ALGORITMO DE SUMA
                //Me salgo de este bucle en cuanto una apunte a NULL= se me acaba
                //el polinomio más corto.
                while ((it!=NULL)&&(me!=NULL)){
                        if((it->degree)>(me->degree)){
                                result.attach(it->coeff,it->degree);
                                it=it->next;
                        }       
                        else if ((it->degree)<(me->degree)){
                                result.attach(me->coeff,me->degree);
                                me=me->next;
                        }
                        else {
                                int x=(it->coeff)+(me->coeff);
                                //Si es cero, no subimos nada, pero avanzo
                                if(x!=0){
                                result.attach(x,it->degree);
                                }
                                it=it->next;
                                me=me->next;                              
                        }
                }
                //Con uno de estos dos bucles acabamos el polinomio más largo
                while(it!=NULL){
                        result.attach(it->coeff,it->degree);
                        it=it->next;
                }
                while(me!=NULL){
                        result.attach(me->coeff,me->degree);
                        me=me->next;
                }
                return result;
        }
        //OVERLOADING * OPERATOR:POLINOMIOS * CONSTANTES
        IntPols & operator*(const int & c){
                IntPols & result=* new IntPols();
                
                if(c==0){
                return result;
                }
                else {
                        //construyo el polinomio p argumento: it       
                        IntPols & p =* new IntPols(c,0);
                        Node * it=p.first;
                        Node * me=first;
                        //p mide 1, todo depende de me=q
                        while (me!=NULL){
                                int newcoeff=c*(me->coeff);
                                result.attach(newcoeff,me->degree);
                                me=me->next;
                        }
                        return result;
                }
        }
	        //Esta la necesito para el producto de polinomios, para almacenar las
        //sumas parciales
        void clear(IntPols & p){
                cout<<endl<<"Clear operation was called"<<endl;
                Node * it=p.first;
                while(p.first!=NULL){
                        it=p.first->next;
                        delete p.first;
                        p.first=it;
                }
        }
         //OVERLOADING * OPERATOR:POLINOMIOS * POLINOMIOS
        IntPols & operator*(const IntPols & p){
                IntPols & sums=*new IntPols();
                IntPols & result=*new IntPols();
                Node * it=p.first;
                Node * me=first;
                while (me!=NULL){
                        while(it!=NULL){
                                int newcoeff=(me->coeff)*(it->coeff);
                                //NO HAY REPRESENTACIÓN DE COEFICIENTES CERO
                                // NI POR LISTAS NI POR OPERACIONES
                                int newdegree=(me->degree)+(it->degree); 
                                sums.attach(newcoeff,newdegree);
                                it=it->next;
                        }
                        it=p.first;
                        result=result+sums;
                        clear(sums);
                        me=me->next;
                        
                }
                return result;       
        }
        bool isEmpty(){
                return first==NULL;
        }


	
         void printIntPols(){
                if(isEmpty()==true){
                         cout<<"empty polynomial, I cannot print"<<endl;
                }                                        
                else{   
                        Node * me= first;
                        int resultcoeff;
                        int resultdegree;
                        while(me->next!=NULL){
                                resultcoeff=me->coeff;
                                resultdegree=me->degree;
                                me=me->next;
                                if(resultcoeff==1 || resultcoeff==-1){
                                        if(resultdegree==0){
                                                 cout<<"1"<<"+";
                                        }
                                        else if (resultdegree==1){
                                                 cout<<"x"<<"+";
                                        }
                                        else {                                                                                           
                                                cout<<"x"<<"^"<<resultdegree<<"+";
                                        }
                                }
                                else {  
                                        if(resultdegree==0){
                                                cout<<resultcoeff<<"+";
                                        }
                                        else if(resultdegree==1){
                                                cout<<resultcoeff<<"x"<<"+";
                                        }
                                        else {
                                                cout<<resultcoeff<<"x"<<"^"<<resultdegree<<"+";
                                        }
                                }  
                        }
                        resultcoeff=me->coeff;
                        resultdegree=me->degree;
                        if(resultcoeff==1){
                                        if(resultdegree==0){
                                                 cout<<"1";
                                        }
                                        else if (resultdegree==1){
                                                 cout<<"x";
                                        }
                                        else {                                                                                           
                                                cout<<"x"<<"^"<<resultdegree;
                                        }
                                }
                                else {
                                        if(resultdegree==0){
                                                cout<<resultcoeff;
                                        }
                                        else if(resultdegree==1){
                                                cout<<resultcoeff<<"x";
                                        }
                                        else {
                                                cout<<resultcoeff<<"x"<<"^"<<resultdegree;
                                        }
                                }  
                }
                                
        }
		

};


	
 

int main(){
 /* PRECONDICIONES SOBRE LOS ARRAYS DE ENTRADA DE DATOS:
        En listacoef, que contiene los coeficientes, NO SE INCLUYEN CEROS.
        En listagrad, que contiene los grados, sí puede haber ceros, correspondientes a monomios constantes, y debe estar ordenada 
        de forma ESTRICTAMENTE decreciente. */
	int seed =7;  // randomly setting the seed (1-9)
	cout<<seed<<endl;
	srand(seed);
	int qLength=13;  // randomly setting the number of monomials of the polynomial q
	int qCoefficientsList[qLength];
	for(int i=0;i<qLength;i++){
		int qRandomInt=rand() % 19 + (-9);
		if(qRandomInt==0)
			qCoefficientsList[i]=qRandomInt+1;
		else {	
        		qCoefficientsList[i]=qRandomInt;
		}
        }
	cout<<"qCoefficientsList:"<<endl;
 	for(int i=0;i<qLength;i++){
               cout<<qCoefficientsList[i]<<",";
        }
	cout<<endl;
	int qDegreesList[qLength]={19,18,13,12,11,10,9,7,5,4,3,2,1,0};
	cout<<"qDegreesList: "<<endl;
 	for(int i=0;i<qLength;i++){
               cout<<qDegreesList[i]<<",";
        }
        
	cout<<endl;
        IntPols q(qCoefficientsList,qDegreesList,qLength);
        cout<<"polynomial q :";
        q.printIntPols();
	cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
	int pLength=5;
	int pCoefficientsList[pLength];
	for(int i=0;i<pLength;i++){
		int pRandomInt=rand() % 19 + (-9);
		if(pRandomInt==0)
			pCoefficientsList[i]=pRandomInt+1;
		else {	
        		pCoefficientsList[i]=pRandomInt;
		}
        }
	cout<<"pCoefficientsList: "<<endl;
 	for(int i=0;i<pLength;i++){
               cout<<pCoefficientsList[i]<<",";
        }
	cout<<endl;
	int pDegreesList[pLength]={11,7,3,1,0};
	cout<<"pDegreesList: "<<endl;
 	for(int i=0;i<pLength;i++){
               cout<<pDegreesList[i]<<",";
        }
	
	cout<<endl;
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
	IntPols p(pCoefficientsList,pDegreesList,pLength);
        cout<<"polynomial p :";
        p.printIntPols();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"sum p+q and assignment to r: r=p+q";
	IntPols r=p+q;
	cout<<"r:";
	r.printIntPols();
	cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"IntPols s=IntPols(1,9)+IntPols(2,3);"<<endl;
        IntPols s=IntPols(1,9)+IntPols(2,3);
        cout<<"s:";
        s.printIntPols();
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"IntPols t=IntPols(1,0);"<<endl;
        IntPols t=IntPols(1,0);
        cout<<"t:";
        t.printIntPols();
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"IntPols u=p+IntPols(8,9);"<<endl;
        IntPols u=p+IntPols(8,9);
        cout<<"u:";
        u.printIntPols();
        cout<<endl;
        cout<<"p:";
        p.printIntPols();
        cout<<endl<<"---------------------------------"<<endl;

        cout<<"p=p+q;"<<endl;
        p=p+q; //¿What with the Nodes of previous p"?
        cout<<"p:";
        p.printIntPols();
        cout<<endl;
        cout<<"q:";
        q.printIntPols();
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"p=p+p;"<<endl;
        p=p+p;
        cout<<"p:";
        p.printIntPols();
        cout<<endl;
        int c=3;
        IntPols w=p*c;
        cout<<"w=p*3;"<<endl;
        w.printIntPols();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
        int x_coeffsList[]={1,1,1};
        int x_degreesList[]={2,1,0};
        int xLength=3;
        int y_coeffsList[]={2,2,2};
        int y_degreesList[]={2,1,0};
        int yLength=3;
        IntPols y(y_coeffsList,y_degreesList,yLength);
        cout<<"polynomial y from constructor with lists:";
        y.printIntPols();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"polynomial y from constructor with lists:";
        IntPols x(x_coeffsList,x_degreesList,xLength);
        x.printIntPols();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"sum x+y and assignment: sum=x+y";
        IntPols sum=x+y;
        cout<<"sum:";
        sum.printIntPols();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"product ofx, y: x*y and assignment to polynomial xy_product: xy_product=x*y";
        IntPols xy_product=x*y;
        cout<<"producto:";
        xy_product.printIntPols();
        cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
    
	
        

       }
        
