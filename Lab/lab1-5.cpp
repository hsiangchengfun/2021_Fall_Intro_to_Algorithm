#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    cin.tie(0);
    cin.sync_with_stdio(0);

    long long N, k, t, Q, x, l, ans;
    cin >> N >> k;
    t = N;
    multiset<long long, long long> a;
    vector<long long> b;
    //k => 最大可分k-1次
    long long s;
    while (t--) {
        cin >> s;
        //a.insert(s);
        b.push_back(s);
    }
    sort(b.begin(), b.end());
    cin >> Q;
    while (Q--) {
        ans = 0;
        cin >> x >> l;
        long long count = 0;
        vector<long long > ::iterator itr1;
        vector<long long > ::iterator itr2;
        itr1 = upper_bound(b.begin(), b.end(), x * k > l ? l : x * k);
        itr2 = lower_bound(b.begin(), b.end(), x);
        for (long long i = 1; i <= k && i * x <= l; i++) {
            vector<long long > ::iterator low;
            vector<long long > ::iterator upp;
            low = lower_bound(itr2, itr1, i * x);
            upp = lower_bound(itr2, itr1, (i + 1) * x);
            ans += i * (upp - low);
        }

        cout << ans << "\n";
    }
    //system("pause");
    return 0;
}
