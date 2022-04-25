#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<utility>
#include<map>
#define MOD 1000000007
#define ll long long

using namespace std;



class graph {
public:
	ll numvt;


	//vector<vector<pair<ll, ll>>> adj;
	vector<map<ll, ll>>adj;
	vector<bool> visited;
	vector<ll> parent;

	graph();
	graph(ll numvt) {
		this->numvt = numvt;
		adj.resize(numvt + 2);
		visited.resize(numvt + 2, false);
		parent.resize(numvt + 2);
	}



	void addedge1(ll, ll, ll);
	void addedge0(ll, ll, ll);
	bool bfs();
	void fordFulkerson( );


};

void graph::addedge1(ll fr, ll to, ll wt) {
	adj[fr].insert(make_pair(to, wt));

	adj[to].insert(make_pair(fr, wt));
}

void graph::addedge0(ll fr, ll to, ll wt) {
	adj[fr].insert(make_pair(to, wt));
}




bool graph::bfs()
{
	//cout << "b" << endl;

	//vector<bool> visited(numvt + 2, 0);


	for (int i = 0; i < numvt + 2; i++) {
		parent[i] = -1;
		visited[i] = false;
	}

	queue<ll> q;
	q.push(0);
	visited[0] = 1;
	

	// Standard BFS Loop
	ll u;
	while (!q.empty())
	{
		u = q.front();  // head point u
		q.pop();
		visited[u] = 1;

		for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++) {
			ll vt = itr->first;
			ll wt = itr->second;

			if (!visited[vt] && wt > 0)  // find one linked vertex
			{
				q.push(vt);
				//cout << "QSIZE" << q.size() << endl;
				//cout << "n" << (*itr).first << endl;
				parent[vt] = u;  // find pre point
				//visited[(*itr).first] = true;
				if (vt == numvt + 1)return true;
			}
		}
	}

	return false;
}

void graph::fordFulkerson() {
	ll u;

	
	

	ll max_flow = 0;

	while (bfs())
	{
		ll path_flow = LLONG_MAX;
		for (ll v = numvt+1; v != 0; v = parent[v])
		{
			ll p = parent[v];
			auto itr = adj[p].find(v);

			path_flow = min(path_flow, (*itr).second);
		}

		for (ll v = numvt+1; v != 0; v = parent[v])
		{
			ll p = parent[v];
			auto itr = adj[p].find(v);
			auto itr2 = adj[v].find(p);

			itr->second -= path_flow;
			if (itr2 != adj[v].end()) {
				(*itr2).second += path_flow;
			}
			else {
				adj[v].insert(make_pair(p, path_flow));
			}

		}
		max_flow += path_flow;
		

	}

	cout << max_flow;

}





int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);
	ll N;
	cin >> N;
	graph g(N);
	ll a;
	for (ll j = 0; j < N; j++) {
		cin >> a;
		g.addedge0(0, j + 1 , a);
	}
	for (ll j = 0; j < N; j++) {
		cin >> a;
		g.addedge0(j + 1 , N + 1, a);
	}

	ll M;
	cin >> M;
	ll c, d, e;
	for (ll i = 0; i < M; i++) {
		cin >> c >> d >> e;
		g.addedge1(c, d, e);
	}
	
	g.fordFulkerson();





	return 0;
}