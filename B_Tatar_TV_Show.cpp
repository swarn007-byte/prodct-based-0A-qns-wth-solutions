#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        
        bool drug = true;
        
        for(int i = 0; i < k; i++) {
            int count = 0;
            
            for(int pos = i; pos < n; pos += k) {
                if(s[pos] == '1') {
                    count++;
                }
            }
            
            if(count % 2 == 1) {
                drug = false;
                break;
            }
        }
        
        if(drug) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}