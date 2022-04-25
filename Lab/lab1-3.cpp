#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

int main() {

    cin.tie(0);
    cin.sync_with_stdio(0);

    long long N, k;//N num of furniture ,k num of member
    cin >> N >> k;

    vector<long long> val;
    vector<long long> pp;
    val.resize(N);
    pp.resize(N);
    for (long long i = 0; i < N;i++) {
        cin >> val[i] >> pp[i];
    }
    /*double lft=*min_element(c.begin(),c.end());
    double rgt=*max_element(c.begin(),c.end());*/
    double lft=0.0,rgt=1000000000.0;
    
    while ((rgt - lft) > 0.000001) {
        double mid = (lft + rgt) / 2;
        long long sum = 0;
        for (long long i = 0; i < N; i++) {
            long long tmp = (long long)(val[i] / mid) - pp[i];
            if (tmp > 0)sum += tmp;
        }
        if (sum >= k)lft = mid;
        else rgt = mid;
    }
    cout << setprecision(9) << (lft + rgt) / 2;

    return 0;
}