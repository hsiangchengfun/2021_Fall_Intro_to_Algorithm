#include<iostream>
#include<vector>
#include<map>
#define MOD 1000000007
using namespace std;

class node {
public:
	long long weight = 0;
	node* child1 = NULL;
	node* child2 = NULL;
	node* dad = NULL;
	int state = 0;
};


long long calcu(node tmp) {
	
	
	if (tmp.child1==NULL) return  tmp.weight;
	else return tmp.weight * (calcu(*tmp.child1) + calcu(*tmp.child2))%MOD;

}



int main() {


	cin.tie(0);
	cin.sync_with_stdio(0);

	long long N;
	cin >> N;
	vector<node> vec(N + 1);


	for (long long i = 1; i <= N; i++) {
		//node tmp;
		cin >> vec[i].weight;

	}//ai


	for (long long i = 2; i <= N; i++) {
		
		long long dad;
		cin >> dad;
		
		vec[i].dad = &vec[dad];
		if (vec[dad].child1 == NULL) {
			vec[dad].child1 = &vec[i];
			vec[dad].state = 2;
		}
		else if(vec[dad].child2 == NULL){
			vec[dad].child2 = &vec[i];
			vec[dad].state = 2;
		}

	}//qi

	long long ans = 0;

	ans = calcu(vec[1]);

	cout << "ans : "<<ans<<endl;

	return 0;
}