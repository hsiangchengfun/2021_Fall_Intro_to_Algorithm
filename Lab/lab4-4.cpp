#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define ll long long


class pand {
public:
	ll start, end, sci;
	ll games;
};

ll knap(vector<pand>& v,ll M,ll S) {
	

	vector<ll> dp(S + 1, 0);
	for (ll i = 1; i < M + 1; i++) {
		for (ll j = S; j >= 0; j--) {
			if (j >= v[i-1].sci)
				dp[j] = max(dp[j], (dp[j - v[i-1].sci] + v[i-1].games));
		}
	}

	return dp[S];

}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	 
	
	ll N, M, S;
	cin >> N >> M >> S;
	vector<ll> vec(N);
	for (ll i = 0; i < N; i++)cin >> vec[i];

	vector<pand> v(M);

	for (ll i = 0; i < M; i++) {
		cin >> v[i].start >> v[i].end >> v[i].sci;
		
	}
	ll add = N;

	sort(vec.begin(), vec.end());

	for (ll i = 0; i < M; i++) {
		auto itr = lower_bound(vec.begin(), vec.end(), v[i].start);
		auto itr2 = upper_bound(vec.begin(), vec.end(), v[i].end);
		v[i].games = itr2 - itr;
		add -= (itr2 - itr);
	}

	ll ans=knap(v, M, S);
	cout << ans + add;



	return 0;
}