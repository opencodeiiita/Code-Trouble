// Final code

#include "bits/stdc++.h"
using namespace std;
#define ll long long
vector<ll> dp(400001, -1);
ll solve(ll i, ll mod) {
    return dp[i] % mod;
}
ll binpow(ll a, ll b, ll mod) {
    ll res = 1;
    a = a % mod;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
ll combitorics(ll n, ll r, ll mod) {
    ll denominator = ((solve(r, mod)) * (solve(n - r, mod))) % mod;
    ll numerator = solve(n, mod);
    ll expo = binpow(denominator, mod - 2, mod);
    expo = (expo * numerator) % mod;
    return expo;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t; cin >> t;
    ll mod = 1000000007;
    dp[0] = 1;
    for (ll i = 1; i < 400001; i++)dp[i] = (dp[i - 1] * i) % mod;
    while (t--) {
        ll k;
        cin >> k;

        ll ans = 0;
        for (ll i = 0; i <= 2 * k; i++) {
            if (i - (k - 1) >= k || i - (k - 1) < 0)continue;
            ans = (ans + combitorics(i, k - 1, mod)) % mod;
        }
        ans *= 2;
        ans %= mod;
        cout << ans << endl;
    }
}
