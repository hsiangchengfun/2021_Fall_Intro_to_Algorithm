#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<climits>
#include<utility>
#define ll long long


using namespace std;


class graph {
public:

    ll numvt;

    //vector<vector<pair<ll,ll>>> adj;
    //vector<ll> d;
    //set<pair<ll,ll>> q;
    priority_queue<pair<ll, ll>> q;
    vector<vector<ll>> c;

    graph();

    graph(ll numvt) {
        this->numvt = numvt;
       // adj.resize(numvt + 1);
        vector<ll> tmp(numvt, LLONG_MAX/2);
        c.resize(numvt, tmp);
        //d.resize(numvt,LLONG_MAX);
        //for (ll i = 0; i < numvt; i++)q.insert(make_pair(INT_MAX, i));
    }



    void addedge(ll fr, ll to , ll wt);

    void dijkstra(ll src,ll dest);
    void floy();
   

};


void graph::addedge(ll fr, ll to ,ll wt) {
    //adj[fr].push_back(make_pair(to,wt));
    if (wt <= c[fr][to])c[fr][to] = wt;
}

/*
void graph::dijkstra(ll src, ll dest) {

    q.push(make_pair(0, src));
    vector<ll> d;
    d.resize(numvt, LLONG_MAX);
    d[src] = 0;
    while (!q.empty()) {
        ll vt = q.top().second;

        q.pop();

        for (auto itr = adj[vt].begin(); itr != adj[vt].end(); itr++) {
            ll nextvt = (*itr).first;//to
            ll wt = (*itr).second;//wt
            if (d[nextvt] > d[vt] + wt) {
                d[nextvt] = d[vt] + wt;
                q.push(make_pair(d[nextvt], nextvt));
            }


        }
        //cout << "q";
    }

    if (d[dest] == LLONG_MAX){
        cout << -1 << "\n";
        return;
    }
    cout << d[dest] << "\n";



}*/


void graph::floy() {

   // for (ll i = 0; i < numvt; i++)c[i][i] = 0;
    for (ll k = 0; k < numvt; k++) {
        for (ll i = 0; i < numvt; i++) {
            for (ll j = 0; j < numvt; j++) {
                if (c[i][j] > c[i][k] + c[k][j])c[i][j] = c[i][k] + c[k][j];
            }
            
        }
    }



}






int main() {

    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N, M;
    cin >> N >> M;

    graph grp(N);

    ll a, b, c;
    for (ll i = 0; i < M; i++) {
        cin >> a >> b >> c;
        grp.addedge(a, b, c);
    }

    grp.floy();
    ll K;
    cin >> K;
    ll src, dest;
    for (ll i = 0; i < K; i++) {
        cin >> src >> dest;
        if (grp.c[src][dest] == LLONG_MAX / 2){
            cout << "-1\n"; 
            continue;
        }
        cout << grp.c[src][dest] << "\n";
        //grp.dijkstra(src, dest);
    }



    return 0;
}