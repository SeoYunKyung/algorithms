
#include <iostream>
#include <vector>
using namespace std;

int num;
double E, N, S, W, answer;
bool visited[30][30];

//북,동, 남,서
char way[4] = { 'N','E','S','W' };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector<char> way_vector;


void dfs(int x, int y) {
	if (way_vector.size() == num) {
		double tmp_answer = 1;
		for (char c : way_vector) {
			if (c == 'E')tmp_answer *= (double)E / 100.0;
			else if (c == 'W')tmp_answer *= (double)W / 100.0;
			else if (c == 'N')tmp_answer *= (double)N / 100.0;
			else if (c == 'S')tmp_answer *= (double)S / 100.0;
		}
		answer += tmp_answer;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visited[nx][ny])continue;
		visited[nx][ny] = true;
		way_vector.push_back(way[i]);
		dfs(nx,ny);
		way_vector.pop_back();
		visited[nx][ny] = false;
	}
};
int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);

	cout.precision(11);

	cin >> num >> E >> W >> S >>N;
	for (int i = 0; i < 4; i++) {
		visited[14][14] = true;
		way_vector.push_back(way[i]);
		visited[14+dx[i]][14+dy[i]] = true;
		dfs(14+dx[i], 14+dy[i]);
		visited[14 + dx[i]][14 + dy[i]] = false;
		way_vector.pop_back();
	}
	std::cout << answer<<endl;
}

