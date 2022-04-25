#include<iostream>
#include<set>
#define MOD 1000000007

using namespace std;

int main() {


    cin.tie(0);
    cin.sync_with_stdio(0);
    multiset<int> a;//put maxnum
    multiset<int> ::iterator itr;

    long long int N,t;
    long long int num;
    cin >> N;
    t = N;
    while (t--) {
        cin >> num;
        if (num > N)num = N;
        a.insert(num);
    }
    long long int ans = 1,count = 0;
    for (itr = a.begin(); itr != a.end();itr++) {
        ans = (ans * ( *(itr) - count)) % MOD;
        count++;
    }
    cout << ans;
    return 0;
}
