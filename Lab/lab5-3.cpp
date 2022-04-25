#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<utility>
#include<stack>
#define ll long long

using namespace std;



class graph {
public:
	ll numvt, k;
	stack<ll> order;
	vector<vector<ll>> adj;
	vector<vector<ll>> traadj;
	vector<ll> visited;
	vector<ll> visited2;
	vector<ll> sccset;
	vector<ll> numnode;
	vector<vector<ll>> sccmtx;
	ll diffsetnum, sccnum;
	vector<ll> indegree;
	graph();
	graph(ll numvt) {
		this->numvt = numvt;
		adj.resize(numvt);
		traadj.resize(numvt);
		visited.resize(numvt, 0);
		visited2.resize(numvt, 0);
		numnode.resize(numvt);
		//indegree.resize(numvt, 0);
		sccset.resize(numvt);
		for (ll i = 0; i < numvt; i++)sccset[i] = i;

	}

	void addedge(ll, ll);
	void dfs1(ll);
	void dfs2(ll);
	void scc();
	void tp();
};



void graph::addedge(ll fr, ll to) {
	adj[fr].push_back(to);
	traadj[to].push_back(fr);
}

void graph::dfs1(ll x) {

	visited[x] = 1;
	for (auto itr = adj[x].begin(); itr != adj[x].end(); itr++) {
		if (!visited[(*itr)]) {
			dfs1((*itr));
		}

	}
	order.push(x);
	//sccnum = order.size();
}

void graph::dfs2(ll x) {

	visited2[x] = 1;
	for (auto itr = traadj[x].begin(); itr != traadj[x].end(); itr++) {
		if (!visited2[(*itr)]) {
			dfs2((*itr));
		}
		sccset[x] = k;
	}
	numnode[k]++;

}


void graph::scc() {



	for (ll i = 0; i < numvt; i++) {
		if (!visited[i])dfs1(i);
	}
	
	while (!order.empty()) {

		ll v = order.top();
		k = v;
		order.pop();
		if (!visited2[v]) {
			dfs2(v);
			diffsetnum++;
		}
		sccnum++;
	}
}

void graph::tp() {

	sccmtx.resize(numvt);
	indegree.resize(numvt, 0);
	for (ll i = 0; i < numvt; i++) {
		for (ll j = 0; j < adj[i].size(); j++) {
			if (sccset[i] != sccset[adj[i][j]]) {
				sccmtx[sccset[i]].push_back(sccset[adj[i][j]]);
				indegree[sccset[adj[i][j]]]++;
			}
		}
	}

	queue<ll> q;

	for (ll i = 0; i < numvt; i++) {
		if (indegree[i] == 0 && i == sccset[i]) {
			q.push(i);
		}
	}

	vector<ll> dp(numvt, 0);

	ll maxsum = LLONG_MIN;
	ll cur;

	//for (ll i = 0; i < diffsetnum; i++) {
	while(!q.empty()){
		cur = q.front();
		q.pop();

		dp[cur] += numnode[cur];
		maxsum = max(maxsum, dp[cur]);

		for (ll j = 0; j < sccmtx[cur].size(); j++) {
			dp[sccmtx[cur][j]] = max(dp[sccmtx[cur][j]], dp[cur]);
			indegree[sccmtx[cur][j]]--;

			if (indegree[sccmtx[cur][j]] == 0) {
				q.push(sccmtx[cur][j]);
			}
		}
	}
	/*for (ll i = 0; i < numvt; i++)cout << sccset[i] << " ";
	cout << endl;
	for (ll i = 0; i < numvt; i++)cout << numnode[i] << " ";
	cout << endl;*/
	cout << maxsum;

}



int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	ll N, M;
	cin >> N >> M;

	graph g(N);
	ll a, b;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b;
		g.addedge(a, b);
	}

	g.scc();
	g.tp();



	return 0;
}