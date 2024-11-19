//Author:���H�E
//Date: Oct.07 2022
//Purpose: ��v���M�h(knight)�����ѽL������
#include <iostream>
#include <iomanip>
using namespace std;


int solveKTUtil(int x, int y, int movei, int** sol,int N,int xMove[], int yMove[]);

//�T�{�Ӧ�m�i�H��J�����
int isSafe(int x, int y, int** sol,int N){
	return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

//�L����
void printSolution(int** sol,int N){
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			cout << setw(3) << sol[x][y] ;
		cout << endl;
	}
}

//�o�Ө�ƩI�ssolveKTUtil�ѨM�o�ӴѽL���D
//�p�G���ѡA�N�L�X���רæ^��1
//�p�G�L�ѡA�^��0
int solveKT(int N){ //N���ѽL�j�p�Fsol���ѽL

    //�ʺA�ŧi�@�j�p��N*N���ѽL
	int** sol;
	sol = new int*[N];
	for(int i=0;i<N;i++)
            sol[i] = new int[N];

	//�N�ѽL������l�Ƭ�-1
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;

	//xMove[] & yMove[] �s��ۤK�Ӥ�V���O��x,y�����ܶq
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	//�Ĥ@�檽����J1
	sol[0][0] = 1;

	//�}�l�ϥ� solveKTUtil() recursively
    //�e��ӰѼƬO�����}�l����m�A�ĤT�ӰѼƬ��o���i�J��ƱN�n��J�ѽL���Ʀr�F
    //sol & N���ѽL�δѽL�j�p�AxMove & yMove�綷�ǤJ��ƨӨϥ�
	if (solveKTUtil(0, 0, 2, sol,N, xMove, yMove) == 0) {
        //�b(0,0)����m�o�L�k��J2(�N���L�ѡA�B�w�h�^��̪쪺��m->�w�g�չL�Ҧ��i�઺���|)
		cout << "no solution."<<endl;
		return 0;
	}
	else
		printSolution(sol,N);

	return 1;
}

//�D�n�b�ѨM�����D�����(�ո�)
int solveKTUtil(int x, int y, int movei, int** sol,int N,int xMove[8], int yMove[8]){
	int k, next_x, next_y;
	//k�N�q0���N��7 -> �դK�Ӥ��P��V
	//next_x & next_y �����Ӥ�Vx&y�N�|���ʨ쪺��m

	if (movei == N * N + 1)
        //�p�G�w�g��1~N����J�F�ѽL�A�^��1
		return 1;

	//�}�l�ո�
	for (k = 0; k < 8; k++){
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol,N)) {
            //�o��V�ثe�i��->���U�h�æb�s��m�I�s�ۤv(�~��ո�)
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1, sol,N,
							xMove, yMove)
				== 1)
				return 1;
			else
                // �p�G���o�Ӥ�V�N�S������U�@�B�i�H��->�դU�@�Ӥ�V
				sol[next_x][next_y] = -1;
		}
	}
	return 0;
}

int main(){
	//�ѽL�j�p1*1~6*6
    for(int i=1;i<7;i++)
        solveKT(i);
	system("pause");
	return 0;
}
