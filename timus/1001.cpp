#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main(){
    double a;
    vector<double> result;
    while(!cin.eof()){
        cin >> a;
        result.push_back(sqrt(a));
    }
    int n = result.size();
    for(int i = 0; i < n; ++i){
        printf("%.4f\n", result[n - i - 1]);
    }
    return 0;
}