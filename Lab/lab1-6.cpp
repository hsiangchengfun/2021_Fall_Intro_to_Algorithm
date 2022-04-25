#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {


    cin.tie(0);
    cin.sync_with_stdio(0);
    long long  N, K, L;
    cin >> N >> L >> K;
    long long  ipt, count = 0;
    vector<long long> a;
    while (N--) {
        cin >> ipt;
        a.push_back(ipt);
    }
    sort(a.begin(), a.end());
    long long* pt1; pt1 = &a.front();
    long long* pt2; pt2 = &a.back();
    long long min, max;
    while (pt1 < pt2) {
        min = *pt1;
        
        max = *pt2;
        pt2--;
        if (min + max <= L) pt1++;
        count++;
    }
    if (pt1 == pt2)count++;
    cout << count * 2 * K;

    return 0;
}
