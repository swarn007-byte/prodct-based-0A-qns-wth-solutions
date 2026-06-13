#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b, n;
        cin >> a >> b >> n;
        
        vector<long long> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        
        long long time = b; 
        
        for (int i = 0; i < n; i++) {
            // Add min(x[i], a-1) to the time
            time += min(x[i], a - 1);
        }
        
        cout << time << "\n";
    }
    
    return 0;
}