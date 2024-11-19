//Author: 尹信淳
//Date: Jul.16,2022
//Purpose: 建造C++的集合類別

#include <iostream>
#include "TSet.h"
using namespace std;
int main(){
	int N;
	char ch;
	cin>>N;
	for(int i=0;i<N;i++){
		TSet A("A"),B("B");
		cin>>A>>B;
		cin.get(ch);
		TSet C,D;
		C = A+B;
		D = A*B;

		cout<<"Test Case "<< i+1 << ":"<<endl;
		cout<<A<<endl
		    <<B<<endl
		    <<C<<endl
		    <<D<<endl;
		cout<<(A-B)<<endl
		    <<(B-A)<<endl;
	        if(A>=B){
			A.getSetname();
			cout<<" contains ";
			B.getSetname();
		    	cout<<endl;
		}
		else{
			A.getSetname();
			cout<<" does not contain ";
			B.getSetname();
		    	cout<<endl;
		}
		if(B>=A){
			B.getSetname();
			cout<<" contains ";
			A.getSetname();
		    	cout<<endl;
		}
		else{
			B.getSetname();
			cout<<" does not contain ";
			A.getSetname();
		    	cout<<endl;
		}
		if(A.in(ch)){
			cout<<"'"<<ch<<"' is in ";
			A.getSetname();
			cout<<endl;
		}
		else{
			cout<<"'"<<ch<<"' is not in ";
			A.getSetname();
			cout<<endl;
		}
		if(B.in(ch)){
			cout<<"'"<<ch<<"' is in ";
			B.getSetname();
			cout<<endl<<endl;
		}
		else{
			cout<<"'"<<ch<<"' is not in ";
			B.getSetname();
			cout<<endl<<endl;
		}
		
	}

	return 0;
}
