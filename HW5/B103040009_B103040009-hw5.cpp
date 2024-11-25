//Author:尹信淳
//Date:Oct. 10 2022
//Purpose: 設計一個程式，可以處理兩個多項式之加法與乘法
#include <iostream>
#include <cstdlib>
using namespace std;
//polynode 代表多項式的項，存放著各項的係數(coef)及次方(exp)還有一個指向下一項的指標(next)
class polynode{
    //poly能夠直接使用polynode中的data&operation
	friend class poly;
	public:
        //constructor for polynode
		polynode(int thecoef,int theexp,polynode* thenext){
			coef = thecoef;
			exp = theexp;
			next = thenext;
		}
        //accessors
		int getcoef() const{return coef;}
		int getexp() const{return exp;}
		polynode* getnext() const{return next;}
	private:
		int coef;
		int exp;
		polynode* next;
};
//poly 代表多項式物件，是由很多polynode串接而成
class poly{
	public:
        //default constructor
        //when the poly has 0 term, we let that poly's first=NULL.
		poly(){first=NULL;}
		//copy constructor -> vital when you have pointers or dynamic memory allocations in your class.
		poly(const poly& polyobj){
			if(polyobj.first==NULL){
				first = NULL;
			}
			else{
				polynode* current1 = polyobj.first;
				polynode* current2 = first;
				current2 = new polynode(current1->coef,current1->exp,NULL);
				current1 = current1->next;
				while(current1!=NULL){
					current2->next = new polynode(current1->coef,current1->exp,NULL);
					current1 = current1->next;
					current2 = current2->next;
				}
			}
		}
        //constructor
		poly(polynode* thefirst):first(thefirst){}
		//destructor -> vital when you have pointers or dynamic memory allocations in your class.
		~poly(){
			free(first);
			first = NULL;
		}
		//accessor
		polynode* getfirst() const{return first;}
		//insertnode function inserts a new node into poly and sorts the poly in exp-decreasing order.
		//Moreover, if there is a 0 term in the poly, insertnode will delete it.
		void insertnode(polynode* x);
		//deletenode will be used in insertnode. deletenode deletes the node that ptr2 points at.
		void deletenode(polynode* ptr1,polynode* ptr2);
		//operator overloading
		const poly operator +(const poly& poly1);
		const poly operator *(const poly& poly1);
		// assignment operator overloading -> vital when you have pointers or dynamic memory allocations in your class.
		poly& operator =(const poly& poly1);
	private:
		polynode* first;
};
//prints out the poly.
//Overloaded as non-member function, thus we must use accessors in this function.
ostream& operator <<(ostream& out,poly& poly);

void poly::insertnode(polynode* x){
	polynode* current;
	if(first==NULL){
        //there is no terms in the poly.insert x directly.
		first = x;
	}
	else if(first->exp < x->exp){
	    //In this case, there are some terms in the poly,so in order to make the poly in an exp-decreasing order, we have to insert x at the very front of the poly.
		x->next = first;
		first = x;
	}
	else{
		current = first;
		while(current!=NULL){
			if(current->exp > x->exp && current->next==NULL){
                //In this case, we insert x at the rear of the poly.
				x->next=NULL;
				current->next = x;
				break;
			}
			else if(current->exp > x->exp && current->next->exp < x->exp){
			    //In this case, we insert a at the middle of two terms.
				x->next=current->next;
				current->next = x;
				break;
			}
			else if(current->exp==x->exp){
			    //In this case, the exp of x is already exists in the poly, we simply adds two coefs.
				current->coef+=x->coef;
			}
			current = current->next;
		}
	}
	//delete all the 0 terms after one node insertion.
	current = first;
	while(current!=NULL){
	    //we traversals the poly in order to finds all 0 terms after this insertion.
		if(current->coef==0){
            //we execute deletion only if the term's coef is 0
			if(current==first){
			    //In this case, the term that we inclined to delete was placed at the very front of the poly.
				if(first->next!=NULL){
				    //if this poly contains more than one terms.
					first = first->next;
					free(current);
					current = first;
				}
				else{
                    //if this poly has only one term.
					free(first);
					first = NULL;
					current=first;
				}
			}
			else{
			    //In this case, the term that we are about to delete is anywhere but the very front of the poly.
				polynode* temp;
				temp = first;
				while(temp->next!=current){
					temp = temp->next;
				}
				deletenode(temp,current);
				current = temp->next;
			}
		}
		else{
			current=current->next;
		}
	}
	return;
}
//this function we delete the term that ptr2 points at.
void poly::deletenode(polynode* ptr1,polynode* ptr2){
	ptr1->next = ptr2->next;
	free(ptr2);
}
poly& poly::operator =(const poly& poly1){
	if(this==&poly1){
		return *this;
	}
	else if(poly1.first==NULL){
		first = NULL;
		return *this;
	}
	polynode* current1 = poly1.first;
	first = new polynode(current1->coef,current1->exp,NULL);
	polynode* current2 = first;
	current1 = current1->next;
	while(current1!=NULL){
		current2->next = new polynode(current1->coef,current1->exp,NULL);
		current2 = current2->next;
		current1 = current1->next;
	}
	return *this;
}
const poly poly::operator +(const poly& poly1){
    //In this function, we simply insert every polynodes either the calling object or poly1.
    //Because our insertnode function deals with those "sorting" thing already, all we have to do is insert all the polynodes.
	poly temp;
	polynode* current;
	current = first;
	while(current!=NULL){
		polynode* tempnode = new polynode(current->coef,current->exp,NULL);
		temp.insertnode(tempnode);
		current = current->next;
	}
	current = poly1.first;
	while(current!=NULL){
		polynode* tempnode = new polynode(current->coef,current->exp,NULL);
		temp.insertnode(tempnode);
		current = current->next;
	}
	return temp;
}
const poly poly::operator *(const poly& poly1){
    //In this function, we multiplies two polys and store the outcome in poly temp.
    //Make sure to handle the poly that has no term.
	poly temp;
	if(first==NULL||poly1.first==NULL){
		return temp;
	}
	polynode* current1;
	current1=first;
	polynode* current2;
	current2=poly1.first;
	while(current2!=NULL){
		while(current1!=NULL){
			polynode* tempnode = new polynode(current1->coef*current2->coef,current1->exp+current2->exp,NULL);
			temp.insertnode(tempnode);
			current1=current1->next;
		}
		current1 = first;
		current2 = current2->next;
	}
	return temp;
}
//Simply outputs a poly object in a certain way in order to match the input requirement.
ostream& operator <<(ostream& out,poly& poly1){
	polynode* current = poly1.getfirst();
	if(current==NULL){
		out<<"0 0"<<endl;
		return out;
	}
	while(current!=NULL){
		out<<(*current).getcoef()<<" "<<(*current).getexp()<<endl;
		current = (*current).getnext();
	}
	return out;
}
//driver
int main(){
	int P,Q,count=0;
	int tempcoef,tempexp;
	while(1){
		poly A,B,C,D;
		cin>>P;
		for(int i=0;i<P;i++){
			cin>>tempcoef>>tempexp;
			polynode* tempnode = new polynode(tempcoef,tempexp,NULL);
			A.insertnode(tempnode);
		}
		cin>>Q;
		for(int i=0;i<Q;i++){
			cin>>tempcoef>>tempexp;
			polynode* tempnode = new polynode(tempcoef,tempexp,NULL);
			B.insertnode(tempnode);
		}
		if(P==0&&Q==0)	return 0;
		cout<<"Case"<<++count<<":"<<endl<<"ADD"<<endl;
		C = A+B;
		cout<<C;
		cout<<"MULTIPLY"<<endl;
		D = A*B;
		cout<<D;
	}
	system ("pause");
	return 0;
}
