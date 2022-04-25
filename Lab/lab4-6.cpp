#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define ll long long


vector<ll> val;
ll change(ll,vector<ll>&);


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N;
	cin >> N;
	val.resize(N);
	vector<ll> vec(N);
	for (ll i = 0; i < N; i++)cin >> val[i];

	ll Q;
	cin >> Q;

	vector<ll>diff(Q, 0);

	for (ll i = 0; i < Q; i++) {
		cin >> diff[i];
		for (ll j = 0; j < N; j++) {
			cin >> vec[j];
			diff[i] -= vec[j] * val[j];
		}
		if (diff[i] < 0)diff[i] = -diff[i];
	}

	ll maxdiff = *max_element(diff.begin(), diff.end());

	vector<ll> f(maxdiff + 1, 0);

	change(maxdiff,f);



	for (ll i = 0; i < Q; i++) { cout << f[diff[i]] << endl; }


	return 0;
}


ll change(ll n,vector<ll>& f)
{

	if (n == 0) { f[0] = 0; return 0; }
	else if (f[n] != 0)return f[n];
	else {
		ll tmp = INT_MAX;

		for (ll i = 0; i < val.size(); i++) {
			if (n >= val[i]) {
				tmp = min(tmp, change(n - val[i],f) + 1);
			}
		}
		f[n] = tmp;
		return f[n];
	}

}
