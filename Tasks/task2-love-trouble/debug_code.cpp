#include "bits/stdc++.h"
using namespace std;
#define ll long long
vector<ll> dp(400010, 0);
ll factorial(ll i, ll mod) // finding factorial of i
{
    return dp[i]%mod;
}
ll binpow(ll a, ll b, ll mod) // (finding a^b)%mod
{
    if(a==0||a==1) return a;
    if(b==0) return 1;
    ll ret= binpow(a,b/2,mod);
    if(b%2) return (((ret*ret)%mod)*a)%mod;
    else return (ret*ret)%mod;
}
ll combitorics(ll n, ll r, ll mod) // finding combinations (nCr)%mod
{
    ll numerator = factorial(n, mod);
    ll denominator = ((factorial(r , mod)) * (factorial(n - r, mod))) % mod;
    ll expo = binpow(denominator, mod-2, mod)%mod;
    expo = (expo * numerator) % mod; // finding inverse
    return expo;
}
int main() {
    ll t; cin >> t;
    dp[0]=1;
    ll mod = 1000000007;
    for (ll i = 1; i < 400010; i++) {
        dp[i] = (dp[i - 1] * i) % mod;
    }
    while (t--) {
        ll k;
        cin >> k;

        ll ans= combitorics(2*k, k, mod)%mod;
        ans %= mod;
        cout << ans << "\n";
    }
}
