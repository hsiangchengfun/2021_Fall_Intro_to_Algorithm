#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define ll long long


using namespace std;

ll S;

class graph {
public:

    ll numvt;

    vector<vector<ll>> adj;
    vector<bool> cop;
    bool flag;
    //vector<bool> visited;

    graph();

    graph(ll numvt) {
        this->numvt = numvt;
        adj.resize(numvt + 1);
        cop.resize(numvt + 1, 0);
        //visited.resize(numvt + 1, 0);
    }


   
    void addedge(ll fr, ll to);
    
    void initcop(ll x);
    
    void bfs(ll x);
    
};


void graph::addedge(ll fr, ll to) {
    adj[fr].push_back(to);
    adj[to].push_back(fr);
}


void  graph::initcop(ll x) {
    cop[x] = 1;
}

void  graph::bfs(ll x) {

    vector<bool> visited(numvt + 1, 0);
    ll contacttime = INT_MAX;//meet pp

    queue<pair<ll, ll>> bfsfind;
    bfsfind.push(make_pair(x, 0));



/*
		ll time=0;
		ll size;
		while (1) {
			size = bfsfind.size();

			for (ll i = 0; i < size; i++) {
				ll vt = bfsfind.front();
				visited[vt] = 1;
				time++;
				for (ll j = 0;j<adj[vt].size(); j++) {
					if (!visited[adj[vt][j]]) {
						bfsfind.push(adj[vt][j]);
						if (cop[adj[vt][j]]) {
							if (contacttime < time) {
								flag = 1;
								return;
							}
							flag = 0; 
							return;
						}
						if (adj[vt][j] == S)contacttime = time;
					}
				}
				bfsfind.pop();
				//time++;
			}


		}
		*/


    while (!bfsfind.empty()) {

        ll curvt = bfsfind.front().first;
        visited[curvt] = 1;

        ll timenow = bfsfind.front().second;

        timenow++;

        bfsfind.pop();

        for (ll i = 0; i < adj[curvt].size(); i++) {

            if (!visited[adj[curvt][i]]) {

                bfsfind.push(make_pair(adj[curvt][i], timenow));

                if (cop[adj[curvt][i]]) {
                    if (contacttime < timenow) {
                        flag = 1;
                        return;
                    }
                    else {
                        flag = 0;
                        return;
                    }
                }
                //if cop then won't be here
                if (adj[curvt][i] == S)contacttime = timenow;//meet pp


            }
        }
    }
}



int main() {

    cin.tie(0);
    cin.sync_with_stdio(0);


    ll T;
    cin >> T;

    ll N, M;
    ll x, y, a, b;


    while (T--) {

        cin >> N >> M >> S;

        graph grp(N);

        for (ll i = 0; i < M; i++) {
            cin >> a >> b;
            grp.addedge(a, b);
        }

        cin >> x;
        ll p;
        for (ll i = 0; i < x; i++) {
            cin >> p;
            grp.initcop(p);
        }

        cin >> y;
        vector<ll> P;
        for (ll i = 0; i < y; i++) {
            cin >> p;

            P.push_back(p);


        }


        for (ll i = 0; i < y; i++) {

            grp.bfs(P[i]);

            if (grp.flag) { cout << "Yes\n"; break; }
        }

        if (!grp.flag) { cout << "No\n"; }


    }


    return 0;
}