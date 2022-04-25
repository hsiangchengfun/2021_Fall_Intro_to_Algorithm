#include <iostream>
#include <vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	long long N;//num of process
	long long C;//num of cores
	long long q;//num of tasks

	cin >> N >> C >> q;
	long long m;
	vector<long long> indexvec;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, less<pair<long long, long long>>> indpro;//pair<NEXTindex,process>
	vector<long long> vec(q);//tasks
	vector <long long>tmp;
	vector<vector<long long>> process(N + 1,tmp);
	

	long long  pcslabel;
	for (long long i = 0; i < q; i++) {
		cin >> pcslabel;
		vec[i] = pcslabel;
		process[pcslabel].push_back(i);

	}

	vector<long long> track(N + 1, 0);
	set<long long> oncore;


	long long swch = 0;
	for (long long i = 1; i <= N; i++) {
		if (!process[i].empty())process[i].erase(process[i].begin());
	}
	for (long long i = 1; i <= N; i++) {
		process[i].push_back(q);

	}
	for (long long i = 0; i < q; i++) {
		auto ifsameitr = oncore.find(vec[i]);

		if (ifsameitr != oncore.end()) {
			
			long long a, b;
			a = *(process[vec[i]].begin());
			b = vec[i];
			indpro.push(make_pair(a, b));
			process[vec[i]].erase(process[vec[i]].begin());
		}
		else {
			if (oncore.size() < C){//still have space
				oncore.insert(vec[i]);
				
				long long a, b;
				a = *(process[vec[i]].begin());
				b = vec[i];
				indpro.push(make_pair(a,b));
				
				process[vec[i]].erase(process[vec[i]].begin());
			}
			else {//no space
				oncore.erase(indpro.top().second);
				oncore.insert(vec[i]);

				indpro.pop();
				

				long long a, b;
				
				a = *(process[vec[i]].begin());
				b = vec[i];
				indpro.push(make_pair(a, b));
				process[vec[i]].erase(process[vec[i]].begin());

				
			}
			swch++;

		}

	}

	cout << swch;


	return 0;
}