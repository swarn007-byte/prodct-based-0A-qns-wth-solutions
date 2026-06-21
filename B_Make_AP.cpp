#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, c;
        cin >> a >> b >> c;
        
        bool ok = false;
        
        long long need = 2*b - c;
        if(need > 0 && need % a == 0) ok = true;
        
        need = a + c;
        if(need % (2*b) == 0) ok = true;
        
        need = 2*b - a;
        if(need > 0 && need % c == 0) ok = true;
        
        cout << (ok ? "YES" : "NO") << "\n";
    }
}