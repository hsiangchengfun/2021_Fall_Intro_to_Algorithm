#include<iostream>
#include<set>
using namespace std;


int main() {


    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int N, t;
    //vector<long long> a;
    multiset<int> a;
    cin >> N >> t;
    int ipt;
    for (int i = 0; i < N; i++) {
        cin >> ipt;
        a.insert(ipt);
    }

    multiset<int>::iterator itr1;
    multiset<int>::iterator itr2;    
    int ans = 0;
    for (itr1 = a.begin();itr1!=a.end();itr1=a.upper_bound(*itr1)){
        int previoussec = 10000000;
        for ( itr2 = itr1; itr2 != a.end(); itr2++) {
            //cout<<*itr1<<" "<<*itr2<<" "<<(t - *itr1 - *itr2)<<endl;;
            if (itr1==itr2 || previoussec == *itr2) continue;
            else if ((t - *itr1 - *itr2) >= *itr2 && a.count(t - *itr1 - *itr2) - (*itr1 == t - *itr1 - *itr2) - (*itr2 == t - *itr1 - *itr2)) {
                ans++;
                
            }
            previoussec = *itr2;
        }
    }

    if (ans == 0)cout << "FeiDooDoo_Zuo_Wei_Men";
    else cout << ans;

    return 0;
}
