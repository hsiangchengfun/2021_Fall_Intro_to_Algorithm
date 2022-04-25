#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define ll long long
#define MOD 1000000007



int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	 
	ll T;
	
	
	cin >> T;


	vector<ll>N(T);

	for (ll i = 0; i < T; i++) {
		cin >> N[i];

	}

	ll maxn = *max_element(N.begin(), N.end());


	vector<ll> tmp(maxn-1, 0);
	vector<vector<ll>> vec(2, tmp);

	

	vec[0][0] = 1;
	vec[1][0] = 2;
	vec[0][1] = 3;
	vec[1][1] = 5;


	ll sumi = 5;
	for (ll i = 2; i < maxn-1; i++) {
		for (int j = 0; j < 2;j++) {
			if (j == 1)vec[1][i] = (vec[0][i - 1] + sumi + 1) % MOD;
			else vec[0][i] = (vec[1][i - 2] + sumi + 1) % MOD;

			sumi = vec[j][i] % MOD;
		}
		
	}
	
	for (ll i = 0; i < T; i++) {
		if (N[i] == 1)cout << "1\n";
		else cout << (4*vec[1][N[i]-2]+1)%MOD << "\n";
	}
	
	



	return 0;
}





