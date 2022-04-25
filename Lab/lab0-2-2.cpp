#include <iostream>
#include <vector>

using namespace std;


int main(){
    
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n,q;
    cin>>n>>q;

    int tp,a,x,y,day,ind;

    vector<vector<int>> vec;

    vec.resize(n);
    while(q--){
        
        cin>>tp;
        if(tp==1){
           cin>>a>>day;
           vec[a].push_back(day);

        }else{
            cin>>a>>ind;
            if(ind>=vec[a].size()) cout<<"-1\n";
            //if(ind>vec[a].size()-1) cout<<"-1\n";
            else cout<<vec[a][ind]<<"\n";
        }     
        
    }

    system("pause");
    
    return 0;
}