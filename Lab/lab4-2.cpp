#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define ll long long




int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	 
	
	ll N;
	cin >> N;
	vector<ll> vec(N+1);
	vector<ll> sum(N + 1, 0);
	sum[0] = 0;
	for (ll i = 1; i <= N; i++) { cin >> vec[i]; sum[i] = sum[i - 1] + vec[i]; }

	vector<vector<ll>> v(N + 1, vector<ll>(N + 1, LLONG_MIN));//reward


	for (ll i = 1; i <= N; i++)v[i][1] = 0;

	for (ll j = 3; j <= N; j += 2){
		for (ll i = 1; i + j -1 <= N; i++) {
			for (ll k = 1; k < j; k += 2) {
				for (ll l = 1;  k + l -1 < j; l+=2) {
					v[i][j] = max(v[i][j], v[i][k] + v[i + k][l] 
						+ v[i + k + l][j - k - l] 
						+ (sum[i + k - 1]-sum[i -1]) * (sum[i + j -1] - sum[ i + k + l - 1]) - (sum[i + k + l - 1 ] - sum[i + k -1]));
				}
			}
		}
	}
	
	cout << v[1][N];


	return 0;
}





