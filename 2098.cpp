#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, start, W[16][16], cache[16][65536];
const int IMPOSSIBLE = 1000000000;

/*
현재 외판원이 current번 마을에 있고, 방문한 마을 집합이 visited일 때
앞으로 남은 모든 마을을 방문하고 0번 마을로 돌아갈 때 드는 최소 비용
*/
int TSP(int current, int visited) {
	/*
	기저 사례: 모든 마을을 방문한 경우,
	현재 마을에서 시작지점으로 갈 수 있으면 해당 비용을 리턴하고
	아닐 경우 불가능 값을 리턴한다.
	*/
	if (visited == (1 << N) - 1)
		return W[current][start] ? W[current][start] : IMPOSSIBLE;
	int &ret = cache[current][visited]; // [현재node][visited에 대한 정보] - 현재node에 있는 것중에서도 어떤 노드를 방문했는지를 구분
	if (ret != -1) return ret;			// 이미 visitd한 것은 Cut

	ret = IMPOSSIBLE;
	// 아직 방문하지 않은 모든 마을을 순회해 봄
	for (int i = 0; i<N; i++) {				// N개의 마을에 대해서,
		if (visited & (1 << i)) continue;	// 이미 visited node와 길이 없는 경우는 cut
		if (W[current][i] == 0) continue;
		ret = min(ret, TSP(i, visited | (1 << i)) + W[current][i]);
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			scanf("%d", &W[i][j]);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", TSP(0, 1));
}



