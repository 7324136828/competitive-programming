#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
int codes[300];
vector<string> clist;
int f[200];
string idx[200];
int main(){
    clist.push_back("oqz"); //0
    clist.push_back("ij"); //1
    clist.push_back("abc"); //2
    clist.push_back("def"); //3
    clist.push_back("gh"); //4 
    clist.push_back("kl"); //5
    clist.push_back("mn"); //6
    clist.push_back("prs"); //7
    clist.push_back("tuv"); //8
    clist.push_back("wxy"); //9
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < clist[i].size(); ++j){
            codes[clist[i][j]] = i;
        }
    }
    while(true){
        if(cin.eof()) break;
        string s;
        int n, m;
        set<string> ss;
        cin >> s;
        if(s == "-1") break;
        cin >> m;
        n = s.size();
        map<string, string> rmap;
        while(m--){
            string ts;
            cin >> ts;
            string tmp; 
            for(int i = 0; i < ts.size(); ++i){
                tmp += ('0'+codes[ts[i]]);
            }
            rmap[tmp] = ts;
            ss.insert(tmp);
        }
        for(int i = 0; i < n + 2; ++i){
            f[i] = 0;
            idx[i] = "";
        } 
        f[n] = 1;
        idx[n] = "";
        for(int i = n - 1; i >= 0; --i){
            string cur;
            for(int j = i; j < n; ++j){
                cur += s[j];
                if(ss.find(cur) != ss.end()){
                    f[i] = max(f[i], f[i+cur.size()]);
                    if (f[i] > 0){
                        idx[i] = cur; 
                        break;
                    }
                }
            }
        }
        int ci = 0;
        if(f[ci] < 1){
            cout << "No solution." << endl;
            continue;
        }
        while(ci < n){
            int w = idx[ci].size();
            if(ci + w >= n){
                cout << rmap[idx[ci]];
            } else {
                cout << rmap[idx[ci]] <<' ';
            }
            ci += idx[ci].size();
        }
        cout << endl;
    }
    return 0;
}