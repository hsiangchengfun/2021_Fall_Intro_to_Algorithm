#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define ll long long
#define llpair pair<ll,ll>

using namespace std;

char tp;
ll F, S, K;



ll find(vector<ll>& set, ll x) {
    //if (set[x] == x)return x;
    //return find(set, set[x]);
    return x == set[x] ? x : (set[x] = find(set, set[x]));
}

void merge(vector<ll>& seet, ll x, ll y) {


    ll x_lead = find(seet, x);
    ll y_lead = find(seet, y);


    if (x_lead == y_lead) {
        return;
    }
    else {
        if (x_lead <= y_lead)seet[y_lead] = x_lead;
        else seet[x_lead] = y_lead;

    }
}

ll ans = 0;

ll dfs(vector<vector<llpair>>& tmpmtx, ll x, ll parent) {

    ll subchildnum = 0;
    ll totalchildnum = 0;

    for (auto itr = tmpmtx[x].begin(); itr != tmpmtx[x].end(); itr++) {
        if ((*itr).first != parent) {
            /*subchildnum = dfs(tmpmtx, (*itr).first, x) + 1;
            totalchildnum += subchildnum;
            ll temp = subchildnum * ((long long)tmpmtx.size() - 1 - subchildnum) % MOD;
            ans += temp * (*itr).second % MOD;
            ans %= MOD;
            */
        }

    }

    return totalchildnum;

}


//prim
class graph {
public:

    ll numvt;
    //vector<llpair>> adj;
    vector<llpair> adjF;
    vector<llpair> adjS;

    //vector<llpair>* adjmtx;
    bool flag;
    ll tt;

    ll x1, x2, y1, y2;

    vector<ll> set;
    vector<ll> setF;
    vector<ll> setS;

    
    graph();

    graph(ll numvt) {
        this->numvt = numvt;

        //adj.resize(numvt , vector<llpair>());
        adjF.resize(numvt);
        adjS.resize(numvt);

        //set.resize(numvt );
        setF.resize(numvt);
        setS.resize(numvt);

       

        for (ll i = 0; i < numvt; i++) { setF[i] = setS[i] = i; }
    }

    void addedge(ll fr, ll to, char tp) {
        if (tp == 'F') {
            
            adjF.push_back(make_pair(fr, to));
            
        }
        else {

            adjS.push_back(make_pair(fr, to));
        }

    }

    ll  prim(vector<llpair>&, vector<ll>&);


    void findans();



};





ll  graph::prim(vector<llpair>& tmp, vector<ll>& set) {


    ll count = 0;


        
    for (auto itr = tmp.begin(); itr != tmp.end(); ++itr) {
        ll vt1 = (*itr).first;
        ll vt2 = (*itr).second;
        
        if(find(set,set[vt1])!=find(set,set[vt2])){
            merge(set, vt1, vt2);
            count++;
        }
            


    }
    
        
    for (int i = 0; i < numvt; i++) {
        set[i] = find(set, i);
    }

    return count;
}



void graph::findans() {

    if (x1 + y2 != numvt - 1 || x2 + y1 != numvt - 1) {
        flag = 0;
        return;
    }
    for (ll i = x1; i >= x2; i--) {
        if (K == i * F + (numvt - 1 - i) * S && y1 >= (numvt - 1 - i) && (numvt - 1 - i) >= y2) {
            flag = 1;
            return;
        }


    }
    flag = 0;

}








int main() {

    cin.tie(0);
    cin.sync_with_stdio(0);


    ll T, N, M;
    ll a, b;
    cin >> T;
    while (T--) {


        cin >> N >> M >> K >> F >> S;

        graph grp(N);

        for (ll i = 0; i < M; i++) {
            cin >> a >> b >> tp;
            grp.addedge(a, b, tp);

        }


        grp.x1 = grp.prim(grp.adjF, grp.setF);
        grp.y2 = grp.prim(grp.adjS, grp.setF);
        grp.y1 = grp.prim(grp.adjS, grp.setS);
        grp.x2 = grp.prim(grp.adjF, grp.setS);

        cout<<grp.x1<<grp.x2<<grp.y1<<grp.y2<<endl;

        grp.findans();


        if (grp.flag)cout << "Yes\n";
        else cout << "No\n";


    }


    return 0;
}