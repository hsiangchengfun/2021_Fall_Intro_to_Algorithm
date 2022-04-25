#include<iostream>
#include<vector>

using namespace std;



int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	/*
	long long N;//num of process
	long long C;//num of cores
	long long q;//nim of tasks
	*/
	//n cores => find if [i,i+n] can match
	long long T, N;
	cin >> T;
	//long long sum, th, fh, h, ft, ten, ff, one;
	long long sum;
	
	
	vector<int> c = { 1000, 500, 100, 50, 10, 5, 1 };
	vector<long long> money(7);

	long long ans=0;
	
	
	for (long long i = 0; i < T; i++) {
		ans=0;
		cin >> N;
		bool q=1;
		vector<long long> vsum(N, 0);

		vector<long long>  vc(7,0);
		for (int j = 0; j < N; j++) {
			cin >> sum;
			for (int k = 0; k < 7; k++) {
				cin >> money[k];
				vsum[j] += c[k] * money[k];
				vc[k] += money[k];
			}
			vsum[j] -= sum;
			
		}

		for (int j = 0; j < N; j++) {
				 
			for (int k = 0; k < 7; k++) {
				long long  tmp = vsum[j] / c[k];
				if (tmp > vc[k]) {
					vsum[j] -= c[k] * vc[k];
					ans+=vc[k];
					vc[k] = 0;
				}
				else {
					vc[k] -= tmp;
					ans+=tmp;
					vsum[j] -= tmp * c[k];
				}
				
			}
			if (vsum[j] != 0) {
				q = 0; 
				break; 
			}
		}
		if (q)cout << "Yes" << endl;
		else cout << "No" << endl;

		
//		cout<<ans<<"\n";
	}

	return 0;
}