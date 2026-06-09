#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        long long n, x, y, z;
        cin >> n >> x >> y >> z;
        
        long long t1 = (n + x + y - 1) / (x + y);
        
        long long t2;
        long long during = (n + x - 1) / x; 
        if(during <= z) {
            t2 = during;
        } else {
            long long num = n + z * 10 * y;
            long long denom = x + 10 * y;
            t2 = (num + denom - 1) / denom;
        }
        
        cout << min(t1, t2) << "\n";
    }
}