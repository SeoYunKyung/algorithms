
#include <iostream>

//  2
//4 1 3
//  5
//  6
using namespace std;

int N, M, x, y, K;
int map[20][20];
int dice[7];

//동,서,북,남
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
	ios::sync_with_stdio();
	cout.tie(0);
	cin.tie(0);
	
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//동쪽 : 1, 서쪽 : 2, 북쪽 : 3, 남쪽 : 4
	for (int i = 0; i < K; i++) {
		int dir=0;
		cin >> dir;


		int nx= x+dx[dir - 1];
		int ny= y+dy[dir - 1];
		
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		int tmp = 0;
		switch(dir) {
		
			case 1:
				tmp = dice[3];
				dice[3] = dice[1];
				dice[1] = dice[4];
				dice[4] = dice[6];
				dice[6] = tmp;
;				break;
			case 2:
				tmp = dice[3];
				dice[3] = dice[6];
				dice[6] = dice[4];
				dice[4] = dice[1];
				dice[1] = tmp;
				break;
			case 3:
				tmp = dice[2];
				dice[2] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[6];
				dice[6] = tmp;
				break;
			case 4:
				tmp = dice[2];
				dice[2] = dice[6];
				dice[6] = dice[5];
				dice[5] = dice[1];
				dice[1] = tmp;
				break;
		}
		if (map[nx][ny] != 0) {
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		else {
			map[nx][ny] = dice[6];
		}
		cout << dice[1] << endl;
		x = nx;
		y = ny;
	}
}
