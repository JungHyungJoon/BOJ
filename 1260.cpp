#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> adj[1001];
int N, M, V;

void DFS(int vertex, bool visited[]) {

	if (visited[vertex] == true) return;

	cout << vertex; cout << " ";
	visited[vertex] = true;

	for (int i = 0; i < adj[vertex].size(); i++ ){
		int v = adj[vertex][i];
		DFS(v, visited);
	}

}

void BFS() {
	bool visited[1001];
	queue<int> Q;
	for (int i = 0;i < 1000;i++) visited[i] = 0;

	Q.push(V);
	while (!Q.empty()) {
		int curV = Q.front(); Q.pop();
		if (visited[curV]) continue;
		visited[curV] = true;

		cout << curV; cout << " ";
		for (int i = 0; i < adj[curV].size(); i++) {
			int nextV = adj[curV][i];
			Q.push(nextV);
		}
	}

}

int main() {
	
	
	cin >> N;
	cin >> M;
	cin >> V;

	int a, b;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		//adj[b].push_back(a);
	}

	bool visited_dfs[1001];
	DFS(V, visited_dfs); cout << endl;
	BFS(); cout << endl;

	return 1;
}
