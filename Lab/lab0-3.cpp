#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    int Q;
    cin>>Q;

    cout<<"Q"<<Q<<endl;


    vector<vector<int>> vec;
    int tp,a,day;
    int max=0;
    //cout<<"ww\n";
    while(Q--){
        //cout<<Q<<endl;
        cin>>tp;
        
        if(tp==1){
          //  cout<<"re\n";
           cin>>a>>day;
           //cout<<"pp\n";
           if(a>=max) {
             //  cout<<"nn\n";
                max=a;
               // cout<<"qq\n";
                vec.resize(max);
                //cout<<"mm\n";
            }
           vec[a].push_back(day);
           sort(vec[a].begin(),vec[a].end());

        }else{
            cin>>a;
            if(vec[a].size()==0) cout<<"-1\n";
            else cout<<vec[a].front()<<"\n";
        }     
        
    }

//    system("pause");




    return 0;
}
