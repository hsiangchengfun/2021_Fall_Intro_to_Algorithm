#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<utility>
#define MOD 1000000007
#define ll long long

using namespace std;


ll find(vector<ll>& set, ll x) {
	/*if (x == set[x])return x;
	else return find(set,set[x]);*/
	return x == set[x] ? x : (set[x] = find(set, set[x]));
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

	ll numvt, ans = 0;
	vector<ll> set;
	vector<vector<pair<ll,ll>>> mst;
	priority_queue<pair<ll, pair<ll, ll>>,vector<pair<ll, pair<ll, ll>>>,greater<pair<ll, pair<ll, ll>>> > q;//.first==wt //.second == fr,to pair
	//vector<ll> parent;

	graph();
	graph(ll numvt) {
		this->numvt = numvt;
		vector<pair<ll,ll>> tmp;
		set.resize(numvt+1);
		for (ll i = 1; i <= numvt; i++)set[i] = i;
		//set[0] = 1;
		mst.resize(numvt+1, tmp);
		//parent.resize(numvt + 1,-1);
	}

	void addedge(ll fr, ll to, ll wt);
	ll kruskal();
	ll dfs(ll,ll);

};


void graph::addedge(ll fr, ll to, ll wt) {
	//mst[fr].push_back(make_pair(to, wt));
	q.push(make_pair(wt, make_pair(fr, to)));
}




ll graph::kruskal() {

	ll mstcost = 0;
	while (!q.empty()) {
		ll edge = q.top().first;
		ll fr = q.top().second.first;
		ll to = q.top().second.second;

		q.pop();

		if (find(set, fr) != find(set, to)) {
			merge(set, fr, to);
			mst[fr].push_back(make_pair(to, edge));
			mst[to].push_back(make_pair(fr, edge));

			mstcost += edge;
		}
		else continue;

	}

	mstcost *= 2;
	mstcost %= MOD;

	return mstcost;

}


ll graph::dfs(ll x,ll parent) {

	ll subchild = 0;
	ll ttchild = 0;
	for (auto itr = mst[x].begin(); itr != mst[x].end(); itr++) {
		if ((*itr).first != parent) {
			subchild = dfs((*itr).first, x) + 1;
			ttchild += subchild;
			ll t = subchild * (numvt - subchild) % MOD;
			ans +=  t* (*itr).second %MOD;
			ans %= MOD;
			
		}
	}
	//cout << "q " << ttchild << endl;
	return ttchild;

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
	ll aaa=g.kruskal();

	
	

	
	for (ll i = 1; i <= N; i++)  g.set[i] = find(g.set, i); 
	if (count(g.set.begin(), g.set.end(), 1) != N) {
		cout << -1;
		return 0;
	}

	g.dfs(1,1);
	g.ans *= 2;
	g.ans %= MOD;
	cout << aaa << " ";
	cout << g.ans;
	cout << endl;
	

	return 0;
}