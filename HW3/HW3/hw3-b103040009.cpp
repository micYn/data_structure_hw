//Author:尹信淳
//Date: Jul.20, 2022
//Purpose:西洋棋騎士(knight)走完棋盤的順序

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//自訂stack物件
template <class T>
class Stack{
	public:
		Stack(int stackCapacity = 10);
		bool isEmpty() const;
		T& Top() const;
		void push(const T& item);
		void pop();
	private:
		T *stack;
		int top;
		int capacity;
};
//constructor
template <class T>
Stack<T>::Stack(int stackCapacity){
	capacity = stackCapacity;
	top = -1;
	stack = new T[capacity];
}
//this function checks whether the stack is empty or not.
template <class T>
inline bool Stack<T>::isEmpty() const{
	if(top == -1)	return true;
	return false;
}
//this function returns the very top element in the stack.
template <class T>
T& Stack<T>::Top() const{
	if(isEmpty()){
		cout<<"The stack is empty.";
		exit(1);
	}
	return stack[top];
}
/*this function allows you to push an item into the stack and print an error message if the stack is already full.
*/
template <class T>
void Stack<T>::push(const T& item){
	if(top == capacity-1){
		cout<<"The stack is full, cannot push.";
		exit(1);
	}
	stack[++top] = item;
}
/*this function allows you to pop an item out of the stack and print an error messege if the stack is already empty.
*/
template <class T>
void Stack<T>::pop(){
	if(isEmpty()){
		cout<<"The stack is empty, cannot pop.";
		exit(1);
	}
	stack[top--].~T();
}
//item is the stack element we use in this problem.
struct item{
	int row;
	int col;
	int n;
	//從 (row,col) 走 第n方向
};
//A function that simply prints a 2-d array.
void printarray(int** arr,int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<setw(2)<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
/*this function does the main job of this program.It let the knight to move on the chessboard and we record the knight's path using stack, in order to know whether the knight can visit each position of the chessboard.If the answer is positive, this function will evokes the function that prints the result, otherwise prints the message that the mission has failed.
*/
void ChessKnight(int boardsize){
	int i=1,j=1,count=0;
	item temp;
	//initialize a stack
	Stack<item> a(boardsize*boardsize);
	//initialize a chessboard using a 2-d array
	int** chessboard = new int*[boardsize];
	for(int i=0;i<boardsize;i++){
		chessboard[i] = new int[boardsize];
	}
	for(int i=0;i<boardsize;i++){
		for(int j=0;j<boardsize;j++){
			chessboard[i][j] = 0;
		}
	}
	chessboard[0][0] = 1;

	//prints the answer of the easy case(boardsize=1)
	if(boardsize==1){
		printarray(chessboard,boardsize);
		return;
	}

	temp.row=0;
	temp.col=0;
	temp.n=0;
	//this while loop checks the 8 possible paths for the knight
	while(j<=8){
		switch(j){
			case 1:{
				//if path no.1 doesn't fit, try the next path.
				if((temp.row-2)<0||(temp.col+1)>boardsize-1||chessboard[temp.row-2][temp.col+1]!=0){
					j++;
					break;
				}
				//if path no.1 fits, move the knight and memorize this movement by stack.
				else{
					temp.n=1;
					a.push(temp);
					temp.row-=2;
					temp.col+=1;
					chessboard[temp.row][temp.col] = ++i;
					j=1;
					if(i==boardsize*boardsize){
					//if this move fills the whole chessboard, print the result.
						printarray(chessboard,boardsize);
						return;
					}
				}
				break;
			}
			case 2:{
				//if path no.2 doesn't fit, try the next path.
				if((temp.row-1)<0||(temp.col+2)>boardsize-1||chessboard[temp.row-1][temp.col+2]!=0){
					j++;
					break;
				}
				//if path no.2 fits, move the knight and memorize this movement by stack.
				else{

					temp.n=2;
					a.push(temp);
					temp.row-=1;
					temp.col+=2;
					chessboard[temp.row][temp.col] = ++i;
					j=1;
					if(i==boardsize*boardsize){
					//if this move fills the whole chessboard, print the result.
						printarray(chessboard,boardsize);
						return;
					}
				}
				break;
			}
			case 3:{
				//if path no.3 doesn't fit, try the next path.
				if((temp.row+1)>boardsize-1||(temp.col+2)>boardsize-1||chessboard[temp.row+1][temp.col+2]!=0){
					j++;
					break;
				}
				//if path no.3 fits, move the knight and memorize this movement by stack.
				else{
					temp.n=3;
					a.push(temp);
					temp.row+=1;
					temp.col+=2;
					chessboard[temp.row][temp.col] = ++i;
					j=1;
					if(i==boardsize*boardsize){
					//if this move fills the whole chessboard, print the result.
						printarray(chessboard,boardsize);
						return;
					}
				}
				break;
			}
			case 4:{
				//if path no.4 doesn't fit, try the next path.
				if((temp.row+2)>boardsize-1||(temp.col+1)>boardsize-1||chessboard[temp.row+2][temp.col+1]!=0){
					j++;
					break;
				}
				//if path no.4 fits, move the knight and memorize this movement by stack.
				else{
					temp.n=4;
					a.push(temp);
					temp.row+=2;
					temp.col+=1;
					chessboard[temp.row][temp.col] = ++i;
					j=1;
					if(i==boardsize*boardsize){
					//if this move fills the whole chessboard, print the result.
						printarray(chessboard,boardsize);
						return;
					}
				}
				break;
			}
			case 5:{
				//if path no.5 doesn't fit, try the next path.
				if((temp.row+2)>boardsize-1||(temp.col-1)<0||chessboard[temp.row+2][temp.col-1]!=0){
					j++;
					break;
				}
				//if path no.5 fits, move the knight and memorize this movement by stack.
				else{
					temp.n=5;
					a.push(temp);
					temp.row+=2;
					temp.col-=1;
					chessboard[temp.row][temp.col] = ++i;
					j=1;
					if(i==boardsize*boardsize){
					//if this move fills the whole chessboard, print the result.
						printarray(chessboard,boardsize);
						return;
					}
				}
				break;
			}
			case 6:{
				//if path no.6 doesn't fit, try the next path.
				if((temp.row+1)>boardsize-1||(temp.col-2)<0||chessboard[temp.row+1][temp.col-2]!=0){
					j++;
					break;
				}
				//if path no.6 fits, move the knight and memorize this movement by stack.
				else{
					temp.n=6;
					a.push(temp);
					temp.row+=1;
					temp.col-=2;
					chessboard[temp.row][temp.col] = ++i;
					j=1;
					if(i==boardsize*boardsize){
					//if this move fills the whole chessboard, print the result.
						printarray(chessboard,boardsize);
						return;
					}
				}
				break;
			}
			case 7:{
				//if path no.7 doesn't fit, try the next path.
				if((temp.row-1)<0||(temp.col-2)<0||chessboard[temp.row-1][temp.col-2]!=0){
					j++;
					break;
				}
				//if path no.7 fits, move the knight and memorize this movement by stack.
				else{
					temp.n=7;
					a.push(temp);
					temp.row-=1;
					temp.col-=2;
					chessboard[temp.row][temp.col] = ++i;
					j=1;
					if(i==boardsize*boardsize){
					//if this move fills the whole chessboard, print the result.
						printarray(chessboard,boardsize);
						return;
					}
				}
				break;
			}
			case 8:{
				/*if path no.8 doesn't fit, the knight will have to go back one step.(we have memorized all the movement of the knight, so all we have to do is pop the stack and we'll know where the knight 			          should be after it go back one movement and which path should we try next.)
				  Note that if path no.8 doean't fit and the stack is empty, it means that we have tried all the possible paths and still cannot find the solution -> prints "no solution"
				*/
				if((temp.row-2)<0||(temp.col-1)<0||chessboard[temp.row-2][temp.col-1]!=0){
					//path no.8 doesn't fit and the stack is empty.->no solution
					if(a.isEmpty()){
						cout<<"no solution"<<endl;
						return;
					}
					//path no.8 doesn't fit but the stack is not empty.->the knight can still make a step back and we can try other possible paths.
					else{
						do{
							chessboard[temp.row][temp.col]=0;
							i--;
							temp.row = a.Top().row;
							temp.col = a.Top().col;
							j = a.Top().n+1;
							a.pop();
						}while(j>8);
					}
				}
				else{
					//path no.8 fits, move the knight and memorize this movement by stack.
					temp.n=8;
					a.push(temp);
					temp.row-=2;
					temp.col-=1;
					chessboard[temp.row][temp.col] = ++i;
					j=1;
					if(i==boardsize*boardsize){
					//if this move fills the whole chessboard, print the result.
						printarray(chessboard,boardsize);
						return;
					}
				}
				break;
			}
		}
	}
}
int main(){
	for(int i=1;i<=6;i++){
		ChessKnight(i);
	}
	system("pause");
	return 0;
}


























