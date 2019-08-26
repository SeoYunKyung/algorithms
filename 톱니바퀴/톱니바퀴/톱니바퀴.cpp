
#include <iostream>

int N = 0;
int S = 1;

int saw_tooth[4][8];
int K;

int N_score[4] = { 0,0,0,0 };
int S_score[4] = { 1,2,4,8 };
int change_direction[4];

using namespace std;
void initial() {
	for (int i = 0; i < 4; i++) {
		change_direction[i] = 0;
	}
}
void check(int number, int direction) {
	change_direction[number-1] = direction;

	//left
	for (int i = number-1; i > 0; i--) {
		if (saw_tooth[i-1][2] != saw_tooth[i][6]) {
			change_direction[i - 1] = change_direction[i] * -1;
		}
		else {
			break;
		}
	}
	//right
	for (int i = number-1; i < 3; i++) {
		if (saw_tooth[i][2] != saw_tooth[i+1][6]) {
			change_direction[i+1] = change_direction[i] * -1;
		}
		else {
			break;
		}
	}
}

void turn() {
	for (int i = 0; i < 4; i++) {
		//시계방향
		if (change_direction[i] == 1) {
			int tmp = saw_tooth[i][7];
			for (int j = 7; j >=0; j--) {
				saw_tooth[i][j] = saw_tooth[i][j-1];
			}
			saw_tooth[i][0] = tmp;
		}
		//반시계방향
		else if (change_direction[i] == -1) {
			int tmp = saw_tooth[i][0];
			for (int j = 1; j <8; j++) {
				saw_tooth[i][j - 1] = saw_tooth[i][j];
			}
			saw_tooth[i][7] = tmp;
		}
	}
}

int main()
{
	ios::sync_with_stdio();
	cout.tie(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {
		string tmp="";
		cin >> tmp;
		for (int j = 0; j < 8; j++) {
			 saw_tooth[i][j]=tmp.at(j)-'0';
		}
	}
	cin >> K;

	for (int i = 0; i < K; i++) {
		int number = 0;
		int direction = 0;

		cin >> number >> direction;

		initial();
		check(number, direction);
		turn();
		
	}
    
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (saw_tooth[i][0] == N) {
			answer += N_score[i];
		}
		else {
			answer += S_score[i];
		}
	}
	cout << answer << endl;
}
