#include <iostream>
#include <cstdio>
#include <algorithm>

#define NR_COIN 100
#define NR_VALUE 10000
using namespace std;
int coin[NR_COIN] = { 0, };
int dp[NR_VALUE] = { 0, };
int N, K;

int check() {
	dp[0] = 1;

	for (int i = 0;i < N; i++) {
		for (int j = 0; j <= K; j++) { //j는 가치.
			//cout << i << ", " << j << endl;
			if (j >= coin[i]) {
				dp[j] += dp[j - coin[i]]; //
				//cout << "dp : " << dp[j] << endl;
			}
		}
	}

	cout<< dp[K] << endl;
	

	return 1;
}

void main() {

	cin >> N >> K;

	for (int i = 0;i < N;i++)
		cin >> coin[i];
	


	check();

}
