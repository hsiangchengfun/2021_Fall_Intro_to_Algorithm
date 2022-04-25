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

    vector<vector<pair<ll, ll>>> adj;
    vector<vector<pair<ll, ll>>> traadj;
    vector<ll> d;
    vector<ll> trad;

    priority_queue<pair<ll, ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> > q;

    graph();

    graph(ll numvt) {
        this->numvt = numvt;
        adj.resize(numvt + 1);
        traadj.resize(numvt + 1);
        d.resize(numvt + 1, LLONG_MAX / 2);
        trad.resize(numvt + 1, LLONG_MAX / 2);
    }

    void addedge(ll fr, ll to, ll wt);

    void dijkstra(ll src, ll dest, vector<vector<pair<ll, ll>>>& aadj, vector<ll>& d);


};


void graph::addedge(ll fr, ll to, ll wt) {
    adj[fr].push_back(make_pair(to, wt));
    traadj[to].push_back(make_pair(fr, wt));
}


void graph::dijkstra(ll src, ll dest ,vector<vector<pair<ll,ll>>>& aadj, vector<ll>& d) {

    q.push(make_pair(0, src));
    
    vector<bool> visited(numvt+1,0);
    d[src] = 0;
    while (!q.empty()) {
        ll vt = q.top().second;
        q.pop();

        if (visited[vt])continue;
        visited[vt] = 1;
        
        for (auto itr = aadj[vt].begin(); itr != aadj[vt].end(); itr++) {
            ll nextvt = (*itr).first;//to
            ll wt = (*itr).second;//wt
            if (visited[nextvt] == 0) {
                if (d[nextvt] > d[vt] + wt) {
                    d[nextvt] = d[vt] + wt;
                    q.push(make_pair(d[nextvt], nextvt));
                }
                
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

    vector<pair<ll, ll>> order;
    vector<ll> weight;

    ll a, b, c;
    for (ll i = 0; i < M; i++) {
        cin >> a >> b >> c;
        order.push_back(make_pair(a, b));
        weight.push_back(c);
        grp.addedge(a, b, c);
    }
    
    
    ll src = 1, dest = N;
    grp.dijkstra(src, dest, grp.adj, grp.d);
    grp.dijkstra(dest, src, grp.traadj, grp.trad);

    for (ll i = 0; i < order.size(); i++) {
        ll need = 0;
        //ll used = 0;
        ll from = order[i].first;
        ll end = order[i].second;

        //used = grp.d[from] + grp.trad[end];

        need = grp.d[dest] - (grp.d[from] + grp.trad[end]);// shortest sub two side == still need
        
        if ( need > weight[i] || need  < 0 )cout << "-1\n";
        else cout << weight[i] - need << "\n";

    }

    return 0;
}