#include<iostream>
#include<set>
#include<map>

#define MOD 1000000007

using namespace std;

int main() {


    cin.tie(0);
    cin.sync_with_stdio(0);


    //map<int, multiset<int>> a;
    //multiset<pair<int,int>> a;//first = ind ;second = maxnum
    multiset<int> a;//put maxnum
    multiset<int> :: iterator itr;
    
    int N;
    int num;
    cin >> N;
    while (N--) {
        cin >> num;
        a.insert(num);
        //cout << 11 << " ";
    }
    int ans=1;
    for (itr = a.begin(); itr != a.end(); itr++) {
        ans *= (*itr);
        a.erase(itr);
    }


    cout << ans;
 
    return 0;
}
