
#include <iostream>
#include <queue>

using namespace std;

char puyoMap[12][6];
bool visited[12][6];

//R은 빨강, G는 초록, B는 파랑, P는 보라, Y는 노랑이다.(모두 대문자로 주어진다.)
char RED = 'R', GREEN = 'G', BLUE = 'B', PURPLE = 'P', YELLOW = 'Y', EMPTY = '.';

bool flag = false;
int answer;

//북,동,남,서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> puyoQueue;
queue<pair<int, int>> tempQueue;

void dfs(int x, int y) {
	tempQueue.push(make_pair(x, y));
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx>11 || ny < 0 || ny>5)continue;
		if (visited[nx][ny])continue;

		if (puyoMap[nx][ny] == puyoMap[x][y]) {
			dfs(nx, ny);
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> puyoMap[i][j];
		}
	}

	while (true) {
		//visited initialize
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				visited[i][j] = false;
			}
		}
		//먼저 색을 탐색하며 dfs로 4가지 이상인지 찾으며 queue 에 넣기 
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (puyoMap[i][j] != EMPTY && !visited[i][j]) {
					dfs(i, j);
					if (tempQueue.size() >= 4) {
						while (!tempQueue.empty()) {
							pair<int, int> tmp = tempQueue.front();
							tempQueue.pop();
							puyoQueue.push(tmp);
						}
					}
					else {
						while (!tempQueue.empty()) {
							tempQueue.pop();
						}
					}
				}
			}
		}
		if (puyoQueue.empty()) {
			break;
		}
		//queue에 있는 것들 . 로 만들기 
		while (!puyoQueue.empty()) {
			pair<int, int> tmp = puyoQueue.front();
			puyoQueue.pop();

			puyoMap[tmp.first][tmp.second] = EMPTY;
		}

		answer++;

		//뿌요 내리기 
		for (int j = 0; j < 6; j++) {
			for (int i = 11; i >= 0; i--) {
				if (puyoMap[i][j] != EMPTY) {
					int ni = i;
					while (true) {
						ni++;
						if (ni > 11 ) {
							if (puyoMap[11][j] == EMPTY) {
								char tmp = puyoMap[i][j];
								puyoMap[11][j] = tmp;
								puyoMap[i][j] = EMPTY;
								break;
							}
							break;
						}
						else {
							if (puyoMap[ni][j] != EMPTY && puyoMap[i+1][j]==EMPTY) {
								char tmp = puyoMap[i][j];
								puyoMap[ni - 1][j] = tmp;
								puyoMap[i][j] = EMPTY;
								break;
							}
						}
					
						
					}
				}
			}
		}

	}
	cout << answer << endl;

}
