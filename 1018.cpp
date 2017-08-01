#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

char board[50][50];
int search(int j, int i) {
	int B=0, W=0;
	for (int y = 0; y < 8; y++)
	{
		if (y % 2 == 0)
		{
			for (int x = 0; x < 8; x++)
			{
				if (x % 2 == 0)
				{
					if (board[y + j][x + i] == 'B')W++;
					else B++;
				}
				else
				{
					if (board[y + j][x + i] == 'W')W++;
					else B++;
				}
			}
		}
		else
		{
			for (int x = 0; x < 8; x++)
			{
				if (x % 2 == 0)
				{
					if (board[y + j][x + i] == 'W')W++;
					else B++;
				}
				else
				{
					if (board[y + j][x + i] == 'B')W++;
					else B++;

				}
			}
		}
	}
	if (B>W)return W;
	else return B;
}

int main() {
	
	int M, N;

	cin >> M;
	cin >> N;
	
	int min = 50*50;
	int res;

	for (int r = 0; r < M; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];

	/*for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout << board[r][c];
		}
		cout << endl;
	}*/


	for (int r = 0; r < M-7; r++)
		for (int c = 0; c < N-7; c++) {

			res = search(r, c);
			//cout << res << endl;
			if (res < min) min = res;
		}
	
	cout << min << endl;
	
	

	return 1;
}
