#include<iostream>
#include<vector>

using namespace std;

vector<int> yr;
vector<int> inod;
vector<int> psod;
vector<int*> inodpos;
//inodpos[4]=&inod[0]

int find(int* inbg,int *inend,int* psbg,int* psend){
	if (inend - inbg < 1)return 0;
	int* rt = inodpos[*psend];
	int ans = 0,a=0,b=0;

	bool lft = 0;
	bool rgt = 0;
	
	if (inodpos[*psend] != inbg) {
		lft = 1;
		if (yr[*rt] < yr[*(psbg + (inodpos[*psend] - 1 - inbg))])
			ans++;
	}
	
	if (inend-rt>0) { 
		rgt = 1;
		if (yr[*rt] < yr[*(psend - 1)])
			ans++;
	}

	if(lft)a = find(inbg, inodpos[*psend] - 1, psbg, psbg + (inodpos[*psend] - 1 - inbg));
	if(rgt)b = find(inodpos[*psend] + 1, inend, psbg + (inodpos[*psend] - inbg), psend - 1);

	return ans + a + b;
}


int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;
	inodpos.resize(N + 1);
	yr.resize(N + 1);
	inod.resize(N);
	psod.resize(N);
	int tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		yr[i]=tmp;
	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		inod[i] = tmp;
		inodpos[tmp] = &inod[i];

	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		psod[i] = tmp;
	}

	int* inodbegin=&inod.front();
	int* inodend = &inod.back();
	int* psodbegin = &psod.front();
	int* psodend = &psod.back();
	cout << find(inodbegin, inodend, psodbegin, psodend);


	return 0;
}
