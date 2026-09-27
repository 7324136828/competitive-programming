#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
int edges[110][110];
int dist[110];
int pre[110];

int main(){
    while(true){
        if(cin.eof()){
            break;
        }
        int N, M; cin >> N;
        if(N < 0) break;
        cin >> M;
        for(int i = 0; i < N+5; ++i)
            for(int j = 0; j < N + 5; ++j) 
                edges[i][j] = 0;
        int tsum = 0;
        for(int i = 0; i < M; ++i){
            int a, b, c; cin >> a >> b >> c; --a; --b;
            edges[a][b] = edges[b][a] = c;
            tsum += c; 
        }
        vector<int> ans;
        int best = -1;
        for(int i = 0; i < N; ++i){
            if(edges[0][i] == 0) continue;
            priority_queue<pair<int,int>> pq;
            edges[0][i] = - edges[0][i];
            edges[i][0] = - edges[i][0];
            for(int i = 0; i < N; ++i){
                dist[i] = tsum;
                pre[i] = N;
            }
            pre[0] = -1;
            dist[0] = 0;
            pq.push(make_pair(0, 0));
            while(!pq.empty()){
                pair<int,int> tp = pq.top(); pq.pop();
                int len = -tp.first;
                int vx = tp.second;
                if(len != dist[vx]) continue;
                for(int j = 0; j < N; ++j){
                    int cur = edges[vx][j];
                    if(cur <= 0) continue; 
                    int tt = dist[vx] + cur;
                    if(dist[j] > tt){
                        dist[j] = tt;
                        pq.push(make_pair(-dist[j], j));
                        pre[j] = vx;
                    }
                }
            }
            if(pre[i] == N) continue;
            if(best == -1 || best > dist[i]){
                int p = i;
                best = dist[i];
                ans.clear();
                while(p >= 0){
                    ans.push_back(p);
                    p = pre[p];
                }
            }
            edges[0][i] = - edges[0][i];
            edges[i][0] = - edges[i][0];
        }
        if(best < 0){
            cout << "No solution." <<endl;
            continue;
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < ans.size() - 1; ++i){
            cout << (ans[i] + 1) << ' ';
        }
        cout << (ans[ans.size() - 1] + 1) << endl;
    }
    return 0;
}