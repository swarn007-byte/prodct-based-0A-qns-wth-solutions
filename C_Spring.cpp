#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;

ll gcd(ll a, ll b){ return b ? gcd(b, a%b) : a; }

// Returns lcm(a,b), or m+1 if it overflows above m
ll safe_lcm(ll a, ll b, ll m){
    ll g = gcd(a, b);
    // a/g * b can overflow; use __int128
    lll val = (lll)(a/g) * b;
    if(val > (lll)m) return m+1; // floor(m / anything > m) = 0
    return (ll)val;
}

ll floor_div(ll m, ll x){
    if(x > m) return 0;
    return m / x;
}

void solve(){
    ll a, b, c, m;
    cin >> a >> b >> c >> m;

    ll ab  = safe_lcm(a, b, m);
    ll ac  = safe_lcm(a, c, m);
    ll bc  = safe_lcm(b, c, m);
    ll abc = (ab > m) ? m+1 : safe_lcm(ab, c, m);

    ll fa   = floor_div(m, a);
    ll fb   = floor_div(m, b);
    ll fc   = floor_div(m, c);
    ll fab  = floor_div(m, ab);
    ll fac  = floor_div(m, ac);
    ll fbc  = floor_div(m, bc);
    ll fabc = floor_div(m, abc);

    ll alice = 6*fa - 3*fab - 3*fac + 2*fabc;
    ll bob   = 6*fb - 3*fab - 3*fbc + 2*fabc;
    ll carol = 6*fc - 3*fac - 3*fbc + 2*fabc;

    cout << alice << " " << bob << " " << carol << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}