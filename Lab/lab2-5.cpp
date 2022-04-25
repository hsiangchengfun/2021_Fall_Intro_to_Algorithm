#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define MOD 1000000007

using namespace std;


int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	long long a, b, N;
	cin >> a >> b >> N;
	//f1=1
	//f2=a*f1+b
	//f3=a*f2+b=a^2*f1+ab+b
	//f4=a*f3+b=a^3*f1+a^2b+ab+b
	//fn=a^(n-1)*f1+a^(n-2)*b

	vector<long long > vec(64);
	vec[0] = a;
	
	for (int i = 1; i < 64; i++) {
		vec[i] = vec[i-1]*vec[i-1]%MOD;
	}
	for (int i = 1; i <= N; i++) {
		long long ans=1, j;
		cin >> j;
		long long sr = 0;
		int time = 0;
		j--;
		while (j > 0) {
			if (j % 2)ans *= vec[time];
			ans %= MOD;
			j = j / 2;
			time++;
		}
		//sr = (1 - ans) / (1 - a);
		ans += (ans-1)* b/(a-1)%MOD;
		ans = ans % MOD;
		if (ans < 0)ans = ans + MOD;

		cout << ans << "\n";
	}

	return 0;
}