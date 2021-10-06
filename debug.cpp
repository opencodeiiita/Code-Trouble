#include "bits/stdc++.h"
using namespace std;
#define ll long long
vector<ll> dp(400001, 1);
ll factorial(ll i, ll mod) // finding factorial of i
{
    return dp[i]%mod;
}
ll binpow(ll a, ll b, ll mod) // (finding a^b)%mod
{
    ll res = 1;
    a = a % mod;
    while (b > 0) {
       
       if (b & 1)
            res = (res * a) % mod;
        b = b>>1; 
       a = (a * a) % mod;
    }
    return res;
}
ll combitorics(ll n, ll r, ll mod) // finding combinations (nCr)%mod
{
    if (n < r)  return 0;
    if (r == 0) return 1;
    ll numerator = factorial(n, mod);
    ll denominator = ((factorial(r , mod)) * (factorial(n - r, mod))) % mod;
    ll expo = binpow(denominator, mod-2, mod)%mod;
    expo = (expo * numerator) % mod; // finding inverse
    return expo;
}
int main() {
    ll t; cin >> t;
    ll mod = 1000000007;
    dp[0]=1;
    for (ll i = 1; i < 400001; i++) {
        dp[i] = (dp[i - 1] * i) % mod;
    }
    while (t--) {
        ll k;
        cin >> k;
        // cout<<k<<" ";
        ll ans = 0;
          for (ll i = 0; i <= 2 * k; i++) {

            if (i - (k-1) >= k || i - (k - 1) < 0)continue;
            ans= (ans+combitorics(i, k-1 , mod)) % mod; // if poosible, let 1st person wins the game with his/her kth match be (i+1)th of the tournament
        }
        ans *= 2; // possiblities are equal for both the teams
        ans %= mod;
        cout << ans << endl;
    }
}
