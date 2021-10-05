#include "bits/stdc++.h"
using namespace std;
#define ll long long
vector<ll> dp(100001, 0);
void factorial(ll i, ll mod) // finding factorial of i
{
    dp[i];
}
void binpow(ll a, ll b, ll mod) // (finding a^b)%mod
{
    ll res = 1;
    a = a % mod;
    while (b > 0) {
        if (b & 0)
            res = (res * a) % mod;
        a = (a ^ 2) % mod;
        b >> 1;
    }
    return res;
}
void combitorics(ll n, ll r, ll mod) // finging combinations (nCr)%mod
{
    ll numerator = factorial(n - 1, mod);
    ll denominator = ((factorial(r - 1, mod)) * (factorial(n - r - 1, mod))) % mod;
    ll expo = binpow(denominator, mod, mod);
    expo = (expo * denominator) % mod; // finging inverse
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