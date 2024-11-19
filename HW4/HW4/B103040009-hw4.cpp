//Author:尹信淳
//Date: Oct.07 2022
//Purpose: 西洋棋騎士(knight)走完棋盤的順序
#include <iostream>
#include <iomanip>
using namespace std;


int solveKTUtil(int x, int y, int movei, int** sol,int N,int xMove[], int yMove[]);

//確認該位置可以放入的函數
int isSafe(int x, int y, int** sol,int N){
	return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

//印答案
void printSolution(int** sol,int N){
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			cout << setw(3) << sol[x][y] ;
		cout << endl;
	}
}

//這個函數呼叫solveKTUtil解決這個棋盤問題
//如果有解，將印出答案並回傳1
//如果無解，回傳0
int solveKT(int N){ //N為棋盤大小；sol為棋盤

    //動態宣告一大小為N*N的棋盤
	int** sol;
	sol = new int*[N];
	for(int i=0;i<N;i++)
            sol[i] = new int[N];

	//將棋盤元素初始化為-1
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;

	//xMove[] & yMove[] 存放著八個方向分別對x,y的改變量
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	//第一格直接填入1
	sol[0][0] = 1;

	//開始使用 solveKTUtil() recursively
    //前兩個參數是此次開始的位置，第三個參數為這次進入函數將要填入棋盤的數字；
    //sol & N為棋盤及棋盤大小，xMove & yMove亦須傳入函數來使用
	if (solveKTUtil(0, 0, 2, sol,N, xMove, yMove) == 0) {
        //在(0,0)的位置卻無法填入2(意味無解，且已退回到最初的位置->已經試過所有可能的路徑)
		cout << "no solution."<<endl;
		return 0;
	}
	else
		printSolution(sol,N);

	return 1;
}

//主要在解決此問題的函數(試路)
int solveKTUtil(int x, int y, int movei, int** sol,int N,int xMove[8], int yMove[8]){
	int k, next_x, next_y;
	//k將從0迭代到7 -> 試八個不同方向
	//next_x & next_y 為走該方向x&y將會移動到的位置

	if (movei == N * N + 1)
        //如果已經把1~N都填入了棋盤，回傳1
		return 1;

	//開始試路
	for (k = 0; k < 8; k++){
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol,N)) {
            //這方向目前可行->走下去並在新位置呼叫自己(繼續試路)
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1, sol,N,
							xMove, yMove)
				== 1)
				return 1;
			else
                // 如果走這個方向將沒有任何下一步可以走->試下一個方向
				sol[next_x][next_y] = -1;
		}
	}
	return 0;
}

int main(){
	//棋盤大小1*1~6*6
    for(int i=1;i<7;i++)
        solveKT(i);
	system("pause");
	return 0;
}
