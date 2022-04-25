#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<locale>
#include<stack>
#include<map>

using namespace std;




void calcu(string str) {
    map<string, int> mp;
    stack<int> accumfac;
    string element;
    accumfac.push(1);
    long long fac = 1;
    string strfac;

    reverse(str.begin(), str.end());

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (isdigit(c)) {

            int val = 0, time = 1;
            do {
                val += (c - '0') * time;
                i++; 
                time *= 10;
            } while (isdigit(c = str[i]));
            
            fac = val;

            i--;
            
            
        }
        else if (c == ')') {
            accumfac.push(fac * accumfac.top());
            fac = 1;
        }
        else if (c <= 'z' && c >= 'a') {
            element += c;
        }
        else if (c <= 'Z' && c >= 'A') {
            element += c;
            reverse(element.begin(), element.end());
            mp[element] += fac * accumfac.top();
            fac = 1;
            element = "";
        }
        else {
            accumfac.pop();
        }

    }

    long long one = 0;
    long long two = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->first.length() == 1)one++;
        if (itr->first.length() == 2)two++;
    }
    
    
    cout << one << "\n";
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->first.length() == 1) {
            cout << itr->first << ":" << itr->second << "\n";
        }
    }

    cout << two << "\n";
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->first.length() == 2) {
            cout << itr->first << ":" << itr->second << "\n";
        }
    }


}



int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	string str;

	getline(cin, str);
	

    calcu(str);



	return 0;
}
