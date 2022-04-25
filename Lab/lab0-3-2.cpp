#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
 
    

    cin.tie(0);
    cin.sync_with_stdio(0);

    int Q;
    cin>>Q;
    int tp,a,day;
    map<int , priority_queue <int, vector<int>,greater<int>>> m;//key==type value==day
    while(Q--){
        cin>>tp;
        if(tp==1){
            cin>>a>>day;
            m[a].push(day);

        }else{
            cin>>a;
            if(!m.count(a)) cout<<"-1\n";
            else if(m[a].empty()) cout<<"-1\n";
            else{
                cout<< m[a].top() <<"\n";
                //map<int , set<int>>::iterator itr;
                //itr=m[a].begin();
                m[a].pop();
            }
        }
    }


    //system("pause");

    return 0;
}
