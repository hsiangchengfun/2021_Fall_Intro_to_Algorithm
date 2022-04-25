#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);


	long long N, p;
	cin >> N >> p;


	long long l, r;
	cin >> l >> r;
	vector<pair<long long, long long>> sec;
	pair<long long, long long> pr;

	for (long long i = 0; i < N; i++) {
		cin >> pr.first >> pr.second;
		if (pr.second > l && pr.first < r) {
			sec.push_back(pr);
		}
	}

	sort(sec.begin(), sec.end());
	bool flag = 0;

	long long minind = 0;
	long long cnt = 0;

	pair<long long, long long> maxpair;
	maxpair.second = INT32_MIN;
	maxpair.first = INT32_MIN;

	for (auto itr = sec.begin(); itr != sec.end(); itr++) {
		
		while (itr->first <= l) {
			if (itr->second > maxpair.second) { maxpair.second = itr->second; maxpair.first = itr->first; }
			itr++;
			if (itr == sec.end())break;
		}
		if (maxpair.second <= l) { cnt = 0; break; }
		cnt++;
		l = maxpair.second;
		itr--;
		if (l >= r)break;
	}

	cout << cnt * p;



	/*
	while (l < r) {
		pair<long long, long long> maxpair;
		maxpair.second = INT32_MIN;
		maxpair.first = INT32_MIN;
		long long i;
		for (i = 0; i < N; i++) {
			if (sec[i].first > l)break;
			//find i least pair  to test
		}
		i--;
		if (i < 0) { cnt = 0; break; }
		long long tmp = minind;

		for (long long j = minind; j <= i; j++) {//find in them whose right is max
			if (sec[j].second > maxpair.second) {
				maxpair.first = sec[j].first;
				maxpair.second = sec[j].second;
				minind = j;
			}
		}
		if (maxpair.second <= l) { cnt = 0; break; }
		if (minind == tmp) { cnt = 0; break; }



		l = maxpair.second;

		cnt++;
	}

	cout << cnt * p;
	*/
	

	return 0;
}