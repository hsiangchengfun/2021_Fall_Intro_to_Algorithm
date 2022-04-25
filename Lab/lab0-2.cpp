#include <iostream>
#include <vector>

using namespace std;



int main(){
    
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,q;
    cin>>n>>q;
    int t=q;
    int tp,a,x,y;

    int arr[n][q]={0};
    int num[n]={0};
    int day,ind;
    while(q>0){
        
        cin>>tp>>a;
        if(tp==1){
            cin>>day;
            arr[a][num[a]]=day;
            num[a]++;
        }else if(tp==2){
            cin>>ind;
            if(arr[a][ind]==0) cout<<"-1"<<endl;
            else cout<<arr[a][ind]<<endl;
        }     
        
        q--;
    }


    
    return 0;
}