#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<utility>
#define ll long long

using namespace std;


ll find(vector<ll>& set, ll x) {
	if (x == set[x])return x;
	else return find(set,set[x]);
}

void merge(vector<ll>&set,ll x, ll y) {

	ll  xleader, yleader;
	xleader = find(set, x);
	yleader = find(set, y);

	if (xleader == yleader)return;
	else{
		if (xleader <= yleader)set[yleader] = xleader;
		else set[xleader] = yleader;
	}
}



class graph {
public:

	ll numvt;
	vector<ll> set;
	vector<vector<pair<ll,ll>>> mst;
	priority_queue<pair<ll, pair<ll, ll>>,vector<pair<ll, pair<ll, ll>>>,greater<pair<ll, pair<ll, ll>>> > q;//.first==wt //.second == fr,to pair

	graph();
	graph(ll numvt) {
		this->numvt = numvt;
		vector<pair<ll,ll>> tmp(numvt+1);
		set.resize(numvt+1);
		for (ll i = 0; i < numvt; i++)set[i] = i;
		mst.resize(numvt, tmp);
	}

	void addedge(ll fr, ll to, ll wt);
	void kruskal();

};


void graph::addedge(ll fr, ll to, ll wt) {
	q.push(make_pair(wt, make_pair(fr, to)));
}




void graph::kruskal() {

	sort(vec.begin(), vec.end());
	ll mstcost = 0;
	while (!q.empty()) {
		ll edge = q.top().first;
		ll fr = q.top().second.first;
		ll to = q.top().second.second;

		q.pop();

		if (find(set, fr) != find(set, to)) {
			merge(set, fr, to);
			mst[fr].push_back(make_pair(to, edge));
			mstcost += edge;
		}
		else continue;




	}

	cout << mstcost << endl;

}





int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	ll N, M;
	cin >> N >> M;
	graph g(N);


	ll a, b, c;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b >> c;
		g.addedge(a, b, c);
	}
	g.kruskal();



	
	return 0;
}