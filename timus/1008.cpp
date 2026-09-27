#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;


typedef pair<int,int> pii;

const int dx[5] = {1, 0, -1, 0};
const int dy[5] = {0, 1, 0, -1};
const char dir[5] = "RTLB";

int main(){
    string ih;
    bool first = true;
    int type = 1; 
    while(!cin.eof()){
        string str;
        getline(cin, str);
        ih += str; 
        ih += "\n";
        if(first){
            for(int i = 0; i < str.size(); ++i){
                if(str[i] == ' '){
                    type = 2;
                }
            }
        }
        first = false;
    }
    istringstream is(ih);
    if(type == 1){
        int n; is >> n;
        set<pii> entries;
        bool first = true;
        int sx, sy;
        for(int i = 0; i < n; ++i){
            int x, y; is >> x >> y;
            if(first){
                sx = x;
                sy = y;
            }
            first = false;
            entries.insert(make_pair(x, y));
        }
        queue<pii> qpi; 
        qpi.push(make_pair(sx, sy));
        entries.erase(qpi.front());
        cout << sx << ' ' << sy << endl;
        while(!qpi.empty()){
            pii f = qpi.front(); qpi.pop();
            string row;
            for(int i = 0; i < 4; ++i){
                pii nf = make_pair(f.first + dx[i], f.second + dy[i]);
                if(entries.count(nf) > 0){
                    entries.erase(nf);
                    qpi.push(nf);
                    row += dir[i];
                }
            }
            if(qpi.empty()){
                cout << "." <<endl;
                continue;
            }
            cout << row << "," <<endl;
        }
    } else {
        int x, y; is >> x >> y;
        queue<pii> qpi; 
        qpi.push(make_pair(x, y));
        string direction = dir;
        set<pii> result;
        while(!qpi.empty()){
            pii f = qpi.front(); qpi.pop();
            result.insert(f);
            string row;
            is >> row; 
            for(int i = 0; i < row.size(); ++i){
                int idx = direction.find(row[i]);
                if(idx < 0) continue;
                pii nf = make_pair(f.first + dx[idx], f.second + dy[idx]);
                qpi.push(nf);
            }
        }
        cout << result.size() << endl;
        for(const pii& r: result){
            cout << r.first << ' ' << r.second << endl;
        }
    }
    return 0;
}