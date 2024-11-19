//this is the implementation file of class TSet and function sort.

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "TSet.h"
using namespace std;

void sort(char arr[]){
/*
this function will sort all the elements by ascii table in arr and remove the repeat elements if necessary.
*/
	//calculate the length of arr
	int length=0;
	while(arr[length++]!=0){
	}
	length--;

	//sort arr by ascii code.
	char temp;
	for(int i=length-2;i>=0;i--){
		for(int j=0;j<=i;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	//remove the repeat elements in arr.
	temp = arr[0];
	for(int i=1;i<length;i++){
		for(int j=0;j<i;j++){
			if(arr[j]==arr[i]){			
				for(int k=j;k<length;k++){
					arr[k] = arr[k+1];
				}
				arr[length] = 0;
				length--;
				j--;
			}
		}		
	}
} 
//constructors
TSet::TSet(){
	setname = "not set yet.";
	//all the elements in set[] will be NULL character when we construct the object.
	for(int i=0;i<256;i++){
		set[i]=0;
	}
}
TSet::TSet(string theName){
	setname = theName;
	//all the elements in set[] will be NULL character when we construct the object.
	for(int i=0;i<256;i++){
		set[i]=0;
	}
}
//operator<< overloading
ostream& operator <<(ostream& output,const TSet& obj){
	output<<obj.setname<<": {";
	int i=0;
	while(obj.set[i]!=0){
		output<<obj.set[i];
		i++;
	}
	output<<"}";
	
	return output;
}
//operator>> overloading
istream& operator >>(istream& input,TSet& obj){
	char ch;
	int i=0;

	input.get(ch);
	if(ch=='\n')	input.get(ch);
	while(ch!='\n'){
		obj.set[i++] = ch;
		input.get(ch);	
	}
	
	sort(obj.set);
	fflush(stdin);

	return input;
}
//check if ch is in the set
bool TSet::in(char ch) const{
	int i=0;

	while(set[i]!=0){
		if(set[i]==ch){
			return true;
		}
		i++;
	}

	return false;
}
//operator+ overloading
const TSet operator +(const TSet& obj1,const TSet& obj2){
	TSet temp(obj1.setname+"+"+obj2.setname);
	int i=0;
	int j=0;
	//put all the elements in obj1 and obj2 no matter what
	while(obj1.set[i]!=0){
		temp.set[i] = obj1.set[i];
		i++;
	}
	while(obj2.set[j]!=0){
		temp.set[i] = obj2.set[j];
		j++;
		i++;
	}
	//and then sort it.
	sort(temp.set);

	return temp;
}
//operator* overloading
const TSet operator *(const TSet& obj1,const TSet& obj2){
	TSet temp(obj1.setname+"*"+obj2.setname);
	int i=0;
	int j=0;
	//if there is an element that appears in both obj1 and obj2 ,then put it in temp.
	while(obj1.set[i]!=0){
		if(obj2.in(obj1.set[i])){
			temp.set[j++] = obj1.set[i];
		}
		i++;
	}
	
	return temp;
}
//operator- overloading
const TSet operator -(const TSet& obj1,const TSet& obj2){
	TSet temp(obj1.setname+"-"+obj2.setname);
	int i=0;
	int j=0;
	//put those elements that is in obj1 but not in obj2 into temp
	while(obj1.set[i]!=0){
		if(!obj2.in(obj1.set[i])){
			temp.set[j++] = obj1.set[i];
		}
		i++;
	}

	return temp;
}
//operator>= overloading
bool operator >=(const TSet& obj1,const TSet& obj2){
	int i=0;
	int j=0;
	int flag=0;
	//if all the elements in obj2 is in obj1 either,then return true.
	while(obj2.set[i]!=0){
		if(!obj1.in(obj2.set[i])){
			/*
			  found an element that is in obj2 but not in obj1 -> obj1 does not 				  contain obj2
			*/
			return false;
		}
		i++;
	}
	return 	true;
}
void TSet::getSetname() const{
	cout<<setname;
}
	

		
		
		
	
