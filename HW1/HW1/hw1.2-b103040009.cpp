//Author: 尹信淳 B103040009
//Date: Jul.10,2022
//Purpose: 印出1到N之間所有整數階乘(factorial),N<=50

#include <iostream>
#include <cstdlib>
using namespace std;

void multiply(long long arr[],int& i,int& digit);
	//arr and A in the main function are exactly the same array.
	//i and digit are also the same as the i and digit in main function.
	//arr will stands for the number of i! after the function ends.

int main(){
	long long A[20000]={0};	//array that stores the number.
	A[0]=1;
	int N;	//for input
	int k;	//for referencing the array
	int i;	//for the do-while loop
	int digit=1; //records the digit of the number
	while(cin>>N && N){
		//calculate and store the number in A ,and then output. (from 1! to N!)
		i=1;
		do{
			multiply(A,i,digit); //renew the array((i-1)! -> i!)
					     //in order to stands for i!
			cout<<i<<"!=";
			k=digit-1;
			//print the array(i!)
			while(k>=0){
				cout<<*(A+k);
				k--;
			}
			cout<<endl;
		}while(i++<N);

		//reset A for the next N
		k=digit-1;
		while(k>=0){
			*(A+k)=0;
			k--;
		}
		A[0]=1;

	}
	system ("pause");
	return 0;
}
void multiply(long long arr[],int& i,int& digit){
	int j;	//for referencing arr
	//do the multiplication first and we'll handle the carries later
	for(j=0;j<digit;j++){
		arr[j]*=i;
	}
	//carry-in
	for(int j=0;j<digit;j++){
		if(arr[j]>10){
			arr[j+1] += arr[j]/10;
			arr[j] = arr[j]%10;
		}
	}
	j=digit;
	while(arr[j]>10){
		arr[j+1] += arr[j]/10;
		arr[j] = arr[j]%10;
		j++;
	}
	//calculate the digit of i!
	j=19999;
	while(arr[j]==0){
		j--;
	}
	digit = j+1;
	return;
}

