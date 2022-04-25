#include<iostream>
#include<map>

using namespace std;

int main() {


    cin.tie(0);
    cin.sync_with_stdio(0);
    
    map<int, int> a;
    
    int N, M;
    cin >> N >> M;
    int height,findnum;
    int t = N;
    for (int i = 0; i < N; i++) {
        cin >> height;
        a[height] = i;
    }
    while (M--) {
        cin >> findnum;
        map<int, int> ::iterator itr;
        itr = a.find(findnum);
        if (itr != a.end()) cout << a[findnum] << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
