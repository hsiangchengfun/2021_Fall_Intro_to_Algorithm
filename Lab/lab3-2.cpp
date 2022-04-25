#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#include<iomanip>

using namespace std;


class furniture {
public:
	long double point = 0;
	long double pp = 0;
	long double now = 0;
	//, add, average = (long double)point / now;

};


int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	long long N;//num of furnuture
	long long k;//num of members

	cin >> N >> k;
	vector<long double> c(N);//furniture value
	vector<long double> p(N);//num of pp

	priority_queue<pair<long double, long long>> compare;

	vector<furniture> fur(N);
	


	/*

	class Comp {
	public:
		bool operator()(Fur f1, Fur f2) {
			return f1.pt * (f1.add + 1) / (f1.pre + f1.add + 1) - f1.ave * f1.add < f2.pt* (f2.add + 1) / (f2.pre + f2.add + 1) - f2.ave * f2.add;
		}
	};*/



	long double val, pp;
	for (long long i = 0; i < N; i++) {
		cin >> val >> pp;
	
		fur[i].point = val;
		fur[i].now = pp;
		long double tmp = fur[i].point / (long double)(fur[i].now + 1);
		compare.push(make_pair(tmp, i));
		
	}


	pair<long double,long long> max;
	long long maxind;
	long double ans = 0;

	for (long long i = 0; i < k; i++) {
		max = compare.top();
		maxind = max.second;
		

		if (fur[maxind].now == 0 && fur[maxind].pp == 0) {
			ans += max.first;
			fur[maxind].pp++;
			compare.pop();
		}
		else {

			ans += max.first;
			fur[maxind].pp++;
			compare.pop();
			long double tmp = fur[maxind].point * fur[maxind].now / ((fur[maxind].pp + fur[maxind].now) * (fur[maxind].pp + fur[maxind].now + 1));
			compare.push(make_pair(tmp, maxind));

		}

		//cout << "q" << maxind << endl;
	}

		cout << fixed << setprecision(7) << ans;

	return 0;
}