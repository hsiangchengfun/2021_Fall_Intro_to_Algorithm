#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define ll long long 

using namespace std;



class event {
public:
	ll a = 0, b = 0;
	char c;

};


ll find(vector<ll> & set,ll x) {
	return x == set[x] ? x : (set[x] = find(set,set[x]));
}

void merge(vector<ll>& seet, ll x, ll y ){


	ll x_lead = find(seet,x);
	ll y_lead = find(seet,y);


	if (x_lead == y_lead) {
		return;
	}
	else {
		if(x_lead<=y_lead)seet[y_lead] = x_lead;
		else seet[x_lead] = y_lead;

	}
}


	
/*
	if (set[x] != set[y])
	{
		ll gmin = min(set[x], set[y]); // 團體編號較小者
		ll gmax = max(set[x], set[y]); // 團體編號較大者

		auto itr=find(set.begin(),set.end(),gmax);
        while(itr!=set.end()){
            
            cout<<*itr<<endl;
            cout<<"set[itr] "<<set[*itr]<<endl;
            set[*itr]=gmin;
            itr=find(set.begin()+*itr,set.end(),gmax);
			if(itr==set.end())break;

        }
        cout<<endl;
        
	}




}*/


int main() {

	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N, M, Q;
	cin >> N >> M >> Q;


	//建2D關係圖
	/*vector<ll> tmp(N, 0);
	vector < vector <ll>> vec(N, tmp);*/
	set<pair<ll, ll>>rela;
	

	ll a, b;
	for (ll i = 0; i < M; i++) {
		cin >> a >> b;
		pair<ll,ll> tmp;
		if (a < b) {
			tmp.first = a;
			tmp.second = b;
		}
		else {
			tmp.first = b;
			tmp.second = a;

		}
		rela.insert(tmp);
		/*vec[a][b] = 1;
		vec[b][a] = 1;*/
	}
	//sort(rela.begin(),rela.end());

	vector<event> e(Q);
	char c;

	for (ll i = 0; i < Q; i++) {
		cin >> e[i].c >> e[i].a >> e[i].b;
		
		pair<ll, ll> tmp;
		if (e[i].a < e[i].b) {
			tmp.first = e[i].a;
			tmp.second = e[i].b;
		}
		else {
			tmp.first = e[i].b;
			tmp.second = e[i].a;

		}
		if (e[i].c == 'U') {//take out who is U
			
			auto itr = rela.find(tmp);
			rela.erase(itr);
		

		}

	}

	vector<ll> seet(N);
	for (ll i = 0; i < N; i++) seet[i] = i;


	
	for (auto itr = rela.begin(); itr != rela.end(); itr++) {
		merge(seet, (*itr).first, (*itr).second);
	}



	vector<ll> ans(Q, 0);

	for (ll i = Q - 1; i >= 0; i--) {
		if (e[i].c == 'A') {
			if (find(seet,seet[e[i].a]) == find(seet,seet[e[i].b]))ans[i] = 1;
		}
		else if (e[i].c == 'U') {
			merge(seet, e[i].a, e[i].b);
		}

	}


	for (ll i = 0; i < Q; i++) {
		if (e[i].c == 'A') {
			if (ans[i])cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}