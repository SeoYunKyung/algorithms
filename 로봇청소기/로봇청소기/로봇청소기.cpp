#include <iostream>

using namespace std;

//북,동,남,서 (청소 순서 북->서->남->동->북 // 0 1 2 3 0)
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M, r, c, d;

int map[50][50];
int answer;

void clean(int x, int y, int d) {
	bool flag = true;
	//청소 안된 빈칸 청소 시켜주기
	while (true) {
		if (map[x][y] == 0 && flag) {
			map[x][y] = 2;
			answer++;
		}
		//네 방향 모두 청소할 공간이 없을 때,
		if (map[x + dx[0]][y + dy[0]] != 0 && map[x + dx[1]][y + dy[1]] != 0 &&
			map[x + dx[2]][y + dy[2]] != 0 && map[x + dx[3]][y + dy[3]] != 0) {
			//뒤쪽방향이 벽이라면
			if (map[x - dx[d]][y - dy[d]] == 1)return;
			else {
				x -= dx[d];
				y -= dy[d];
				flag = false;
			}
		}
		else {
			int nd = (d + 3) % 4;
			if (map[x + dx[nd]][y + dy[nd]] == 0) {
				d = nd;
				x += dx[d];
				y += dy[d];
				flag = true;
			}
			else {
				flag = false;
				d = nd;
			}

		}
	}
}
	


int main()
{
	ios::sync_with_stdio();
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	clean(r, c, d);
	cout << answer << endl;

}
