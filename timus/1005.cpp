#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

long long a[21];
long long tsum;
int N;

int main(){
    cin >> N;
    tsum = 0;
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
        tsum += a[i];
    }
    long long ans = -1;
    for(int i = 0; i < (1 << N); ++i){
        long long b = 0;
        for(int j = 0; j < N; ++j){
            if(i & (1 << j)) continue;
            b += a[j];
        }
        long long c = abs(tsum - 2 * b);
        if(ans < 0 || c < ans){
            ans = c;
        }
    }
    cout << ans << endl;

    return 0;
}