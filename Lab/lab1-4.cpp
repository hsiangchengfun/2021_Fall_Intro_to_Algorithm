#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class student {
public:
    string name, label;
    vector<int> score;
    long long   gscore, hscore, rscore, sscore;

    void add() {
        score.push_back(gscore);
        score.push_back(hscore);
        score.push_back(rscore);
        score.push_back(sscore);
    }
    
};

bool cmp(const student& fst, const student& sec) {
    int scr0, scr1, scr2, scr3;
    for (int i = 0; i < 4; ++i) {
        if (fst.label[i] == 'G') {
            if (i == 0) scr0 = 0;
            else if (i == 1) scr1 = 0;
            else if (i == 2) scr2 = 0;
            else if (i == 3) scr3 = 0;
 
        }
        else if (fst.label[i] == 'H') {
            if (i == 0)scr0 = 1;
            else if (i == 1)scr1 = 1;
            else if (i == 2)scr2 = 1;
            else if (i == 3)scr3 = 1;
        }
        else if (fst.label[i] == 'R') {
            if (i == 0)scr0 = 2;
            else if (i == 1)scr1 = 2;
            else if (i == 2)scr2 = 2;
            else if (i == 3)scr3 = 2;

        }
        else if (fst.label[i] == 'S') {
            if (i == 0)scr0 = 3;
            else if (i == 1)scr1 = 3;
            else if (i == 2)scr2 = 3;
            else if (i == 3)scr3 = 3;
        }
    }
    if (fst.score[scr0] != sec.score[scr0])return fst.score[scr0] > sec.score[scr0];
    else if (fst.score[scr1] != sec.score[scr1])return fst.score[scr1] > sec.score[scr1];
    else if (fst.score[scr2] != sec.score[scr2])return fst.score[scr2] > sec.score[scr2];
    else if (fst.score[scr3] != sec.score[scr3])return fst.score[scr3] > sec.score[scr3];
    else if (fst.name != sec.name)return fst.name < sec.name;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    vector <vector<student>> a;
    vector <string> label_stndard;
    a.resize(4);

    cin >> n;
    for (int i = 0; i < 4; ++i) {
        string temp_label;
        cin >> temp_label;
        label_stndard.push_back(temp_label);
    }
    for (int i = 0; i < n; ++i) {
        
        student b;
        cin >> b.name >> b.gscore >> b.hscore >> b.rscore >> b.sscore;
        b.add();

        long long  Max = std::max({ b.gscore , b.hscore , b.rscore , b.sscore });
        if (b.gscore == Max) {
            
            b.label = label_stndard[0];
            a[0].push_back(b);
        }
        else if (b.hscore == Max) {
            b.label = label_stndard[1];
            a[1].push_back(b);
            
        }
        else if (b.rscore == Max) {
            b.label = label_stndard[2];

            a[2].push_back(b);
        }
        else if (b.sscore == Max) {
            b.label = label_stndard[3];

            a[3].push_back(b);
        }

    }

    for (int i = 0; i < 4; ++i) {
        sort(a[i].begin(), a[i].end(), cmp);
    }
    for (int i = 0; i < 4; ++i) {
        if (i == 0) {
            cout << "GRYFFINDOR: ";
        }
        else if (i == 1) {
            cout << "HUFFLEPUFF: ";
        }
        else if (i == 2) {
            cout << "RAVENCLAW: ";
        }
        else if (i == 3) {
            cout << "SLYTHERIN: ";
        }
        if (a[i].size() == 0) {
            cout << "NO NEW STUDENTS\n";
            continue;
        }
        cout << "\n";
        for (int j = 0; j < a[i].size(); ++j) {
            cout << a[i][j].name << "\n";
        }
    }
    return 0;
}