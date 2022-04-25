#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	ll furniture, round;
	cin >> furniture >> round;

	vector<vector<ll>> vec(round);

	
	
	for (ll i = 0; i < round; i++) {
		vec[i].resize(furniture+2);
		for (ll j = 1; j <= furniture; j++) {
			cin >> vec[i][j];
		}
		vec[i][0] = -100000000000001;
		vec[i][furniture + 1] = -100000000000001;
	}
 
	
	vector<vector<ll>>maxvec(round);
	maxvec = vec;

	if (round == 1) {
		for (ll i = 1; i <= furniture; i++) {
			cout << vec[0][i] << " ";
		}
		return 0;
	}


	for (ll i = round-2; i >= 0 ; i-- ) {
		maxvec[i].resize(furniture + 2);
		for (ll j = 1; j <= furniture ; j++) {
			
			ll tmp = max(vec[i+1][j], vec[i+1][j - 1]);
			ll tmp2 = max(tmp, vec[i+1][j + 1]);
			
			vec[i][j] += tmp2;
			cout<<" ij "<<vec[i][j]<<" ";
			
		}
		cout<<endl;
		
	}
	for (ll i = 1; i <= furniture; i++) {
		cout << vec[0][i] << " ";
	}
	
	
	return 0;
}