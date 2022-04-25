#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> a(1),b(1);
	a[0] = 1;
	b[0] = 1;
	for (int i = 0; i < N; i++) {

		b.resize(a.size());
		for (int j = 0; j < b.size(); j++) {
			b[j] = a[j] + pow(2, i );
		}
		reverse(a.begin(), a.end());
		a.insert(a.begin(),b.begin(),b.end());
	}
	for (int i = 0; i < pow(2, N); i++)cout << a[i] << " ";

	return 0;
}