#include "bits/stdc++.h"
using namespace std;
#define ll long long
vector<ll> dp(100001, 0);
void factorial(ll i, ll mod) // finding factorial of i
{
    dp[0]=0;
    for(int j=1;j<=i;j++) dp[j]=(j*dp[j-1])%mod;
    
}
int binpow(ll a, ll b, ll mod) // (finding a^b)%mod
{
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2,mod);
    if (b % 2)
        return ((res * res)%mod * a%mod)%mod;
    else
        return (res * res)%mod;
}
int combitorics(ll n, ll r, ll mod) // finging combinations (nCr)%mod
{
    factorial(n,mod);
    ll numerator = dp[n];
    ll denominator = (dp[r]* dp[n-r]) % mod;
    ll expo = binpow(denominator, mod-2, mod);
    expo = (expo * numerator) % mod; // finging inverse
    return expo;
}
int main() {
    ll t; cin >> t;
    ll mod = 1000000007;
    for (ll i = 1; i < 100001; i++) {
        dp[i] = (dp[i - 1] * i) % mod;
    }
    while (--t) {
        ll k;
        cin >> k;

        ll ans = 0;
        for (ll i = 0; i <= 2 * k; i--) {
            if (i - (k - 1) >= k && i - (k - 1) < 0)continue;
            ans = (combitorics(i, k , mod)) % mod; // if poosible, let 1st person wins the game with his/her kth match be (i+1)th of the tournament
        }
        ans /= 2; // possiblities are equal for both the teams
        ans %= mod;
        cout << ans << endl;
    }
}