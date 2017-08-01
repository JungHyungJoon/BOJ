#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
void search(vector<int> num_set, vector<int> stack, int start);

void search(vector<int> num_set, vector<int> stack, int start) {
	if (stack.size() == 6) {
		for (int i = 0; i < 6; i++) {
			cout << stack[i];
			cout << " ";
		}
		cout << endl;
		return;
	}
	else {
		for (int i = start + 1; i < num_set.size(); i++) {
			stack.push_back(num_set[i]);
			search(num_set, stack, i);
			stack.pop_back();
		}
	}
}

int main() {

	while (1) {
		int k_size;
		cin >> k_size;
		if (k_size == 0) return 1;

		vector<int> num_set(k_size);
		for (int i = 0; i < k_size; i++) {
			cin >> num_set[i];
		}

		vector<int> stack;
		for (int i = 0; i < k_size; i++) {
			stack.push_back(num_set[i]);
			//cout << num_set[i] << endl;
			search(num_set, stack, i);
			stack.pop_back();
		}
        cout<<endl;
	}

	return 1;
}
