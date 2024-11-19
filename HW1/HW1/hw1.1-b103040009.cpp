//Author: 尹信淳 B103040009
//Date: Jul.09,2022
//Purpose: 製作N階(N為奇數)的魔方陣(magic square)

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main(){
	int threexthree[3][3]={0};	//初始化3 x 3 陣列
	int fivexfive[5][5]={0};	//初始化5 x 5 陣列
	int sevenxseven[7][7]={0};	//初始化7 x 7 陣列
	int ninexnine[9][9]={0};	//初始化9 x 9 陣列
	
	int k;	//代表要放入的數字
	int i,j; //指引位置

	//三階魔方陣
	threexthree[0][1] = 1; //1可以直接填入
	i=0;
	j=1;
	k=2;
	while(k<10){
	//k從2到9迭代依序照魔方陣規則填進陣列
		if((i-1)<0||(j-1)<0){
		//若i-1,j-1超出範圍->i,j須做處理(方陣上下左右環狀相連)再判斷位置是否被佔用
			if((i-1)<0&&(j-1)<0){
			//i,j同時超出範圍
				if(threexthree[i-1+3][j-1+3]!=0){
				//但上下左右環狀相連後得到的位置已被佔用->放下面
					i = i+1;
					threexthree[i][j] = k++;
				}
				else{
				//沒被佔用->正常放入
					i = i-1+3;
					j = j-1+3;
					threexthree[i][j] = k++;
				}
			}
			else if((j-1)<0){
			//只有j超出範圍
				if(threexthree[i-1][j-1+3]!=0){
				//但左右環狀相連後得到的位置已被佔用->放下面
					i = i+1;
					threexthree[i][j] = k++;
				}
				else{
				//沒被佔用->正常放入
					i = i-1;
					j = j-1+3;
					threexthree[i][j] = k++;
				}
			}
			else if((i-1)<0){
			//只有j超出範圍
				if(threexthree[i-1+3][j-1]!=0){
				//但上下環狀相連後得到的位置已被佔用->放下面
					i = i+1;
					threexthree[i][j] = k++;
				}
				else{
				//沒被佔用->正常放入
					i = i-1+3;
					j = j-1;
					threexthree[i][j] = k++;
				}
			}
		}
		else if(threexthree[i-1][j-1]!=0){
		//若(i-1,j-1)未超出範圍,但欲填入的位置已被佔用->放下面
			i = i+1;
			threexthree[i][j] = k++;
		}
		else{
		//若(i-1,j-1)未超出範圍,且欲填入的位置未被佔用->正常填入
			i = i-1;
			j = j-1;
			threexthree[i][j] = k++;
		}		
	}

	/*				      
	 以下五七九階魔方陣與三階魔方陣作法相似    
	 只有在"上下左右環狀的處理"與"填入1的位置"有些微不同(與陣列大小有關）                   
	*/

	//填入五階魔方陣
	fivexfive[0][2] = 1;
	i=0;
	j=2;
	k=2;
	while(k<26){
		if((i-1)<0||(j-1)<0){
			if((i-1)<0&&(j-1)<0){
				if(fivexfive[i-1+5][j-1+5]!=0){
					i = i+1;
					fivexfive[i][j] = k++;
				}
				else{
					i = i-1+5;
					j = j-1+5;
					fivexfive[i][j] = k++;
				}
			}
			else if((j-1)<0){
				if(fivexfive[i-1][j-1+5]!=0){
					i = i+1;
					fivexfive[i][j] = k++;
				}
				else{
					i = i-1;
					j = j-1+5;
					fivexfive[i][j] = k++;
				}
			}
			else if((i-1)<0){
				if(fivexfive[i-1+5][j-1]!=0){
					i = i+1;
					fivexfive[i][j] = k++;
				}
				else{
					i = i-1+5;
					j = j-1;
					fivexfive[i][j] = k++;
				}
			}
		}
		else if(fivexfive[i-1][j-1]!=0){
			i = i+1;
			fivexfive[i][j] = k++;
		}
		else{
			i = i-1;
			j = j-1;
			fivexfive[i][j] = k++;
		}
	}

	//填入七階魔方陣
	sevenxseven[0][3] = 1;
	i=0;
	j=3;
	k=2;
	while(k<50){
		if((i-1)<0||(j-1)<0){
			if((i-1)<0&&(j-1)<0){
				if(sevenxseven[i-1+7][j-1+7]!=0){
					i = i+1;
					sevenxseven[i][j] = k++;
				}
				else{
					i = i-1+7;
					j = j-1+7;
					sevenxseven[i][j] = k++;
				}
			}
			else if((j-1)<0){
				if(sevenxseven[i-1][j-1+7]!=0){
					i = i+1;
					sevenxseven[i][j] = k++;
				}
				else{
					i = i-1;
					j = j-1+7;
					sevenxseven[i][j] = k++;
				}
			}
			else if((i-1)<0){
				if(sevenxseven[i-1+7][j-1]!=0){
					i = i+1;
					sevenxseven[i][j] = k++;
				}
				else{
					i = i-1+7;
					j = j-1;
					sevenxseven[i][j] = k++;
				}
			}
		}
		else if(sevenxseven[i-1][j-1]!=0){
			i = i+1;
			sevenxseven[i][j] = k++;
		}
		else{
			i = i-1;
			j = j-1;
			sevenxseven[i][j] = k++;
		}
	}

	//填入九階魔方陣
	ninexnine[0][4] = 1;
	i=0;
	j=4;
	k=2;
	while(k<82){
		if((i-1)<0||(j-1)<0){
			if((i-1)<0&&(j-1)<0){
				if(ninexnine[i-1+9][j-1+9]!=0){
					i = i+1;
					ninexnine[i][j] = k++;
				}
				else{
					i = i-1+9;
					j = j-1+9;
					ninexnine[i][j] = k++;
				}
			}
			else if((j-1)<0){
				if(ninexnine[i-1][j-1+9]!=0){
					i = i+1;
					ninexnine[i][j] = k++;
				}
				else{
					i = i-1;
					j = j-1+9;
					ninexnine[i][j] = k++;
				}
			}
			else if((i-1)<0){
				if(ninexnine[i-1+9][j-1]!=0){
					i = i+1;
					ninexnine[i][j] = k++;
				}
				else{
					i = i-1+9;
					j = j-1;
					ninexnine[i][j] = k++;
				}
			}
		}
		else if(ninexnine[i-1][j-1]!=0){
			i = i+1;
			ninexnine[i][j] = k++;
		}
		else{
			i = i-1;
			j = j-1;
			ninexnine[i][j] = k++;
		}
	}
	//印出一階魔方陣
	cout<<1<<endl<<setw(3)<<1<<endl<<endl;
	//印出三階魔方陣
	cout<<3<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<setw(3)<<threexthree[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	//印出五階魔方陣
	cout<<5<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<setw(3)<<fivexfive[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	//印出七階魔方陣
	cout<<7<<endl;
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			cout<<setw(3)<<sevenxseven[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	//印出九階魔方陣
	cout<<9<<endl;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<setw(3)<<ninexnine[i][j];
		}
		cout<<endl;
	}
	system ("pause");
	return 0;
}
	
	
