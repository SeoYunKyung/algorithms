#include <iostream>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M, r, c, d;

int map[50][50];

void clean(int x,int y) {
	if (map[x][y] == 1)
}

int main()
{
	ios::sync_with_stdio();
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M >>r >> c >>d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	clean(r,c);




}
