#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long



int lengthOfLIS(vector<ll>& nums, vector<ll>& length) {
	vector<int> res;
	for (int i = 0; i < nums.size(); i++) {
		auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
		if (it == res.end()) res.push_back(nums[i]);
		else *it = nums[i];
		length[i] = res.size();
	}
	return res.size();
}

class greater<ll> great;
int lengthOfLDS(vector<ll>& nums, vector<ll>& length) {
	vector<int> res;
	for (int i = 0; i < nums.size(); i++) {

		auto it = std::lower_bound(res.begin(), res.end(), nums[i], great);
		if (it == res.end()) res.push_back(nums[i]);
		else *it = nums[i];
		length[i] = res.size();
	}
	return res.size();
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N;
	cin >> N;
	vector<ll> vec(N);

	vector<ll> lengtha(N);
	vector<ll> lengthb(N, 1);
	vector<ll> lengthc(N);
	vector<ll> lengthd(N, 1);



	for (ll i = 0; i < N; i++)cin >> vec[i];

	int A = lengthOfLIS(vec, lengtha) + 1;

	int B = lengthOfLDS(vec, lengthb) + 1;


	
	reverse(vec.begin(), vec.end());

	int C = lengthOfLIS(vec, lengthc) + 1;

	int D = lengthOfLDS(vec, lengthd) + 1;
	
	
	reverse(lengthc.begin(), lengthc.end());
	reverse(lengthd.begin(), lengthd.end());
	
	for (ll i = 0; i < N; i++) {
		lengtha[i] += lengthc[ i]; lengthb[i] += lengthd[ i];
	}
	ll a = *max_element(lengtha.begin(), lengtha.end()) - 1;
	ll b = *max_element(lengthb.begin(), lengthb.end()) - 1;

	if (a > b)cout << a;
	else cout << b;






	return 0;
}