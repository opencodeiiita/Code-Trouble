#include "bits/stdc++.h"
using namespace std;
#define ll long long
vector<ll> dp(1000001, 0);
void factorial(ll mod) // finding factorial of i
{
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<1000001;i++){
        dp[i] = (dp[i-1]*i)%mod; 
    }
}

long long binpow(ll a, ll b, ll mod) // (finding a^b)%mod
{
    ll res = 1;
    a = a % mod;
    while (b > 0) {
        if (b%2){
            res = (res * a) % mod;
            b--;
        }
        else{
        a = (a*a) % mod;
        b/=2;
        }
    }
    return res%mod;
}

long long combitorics(ll n, ll r, ll mod) // finging combinations (nCr)%mod
{
    ll numerator = dp[n];
    ll denominator = (dp[r]* dp[n-r]) % mod;
    ll expo = binpow(denominator, mod-2, mod);
    expo = (expo * numerator) % mod; // finging inverse
    return expo;
}

int main() {
    ll t; cin >> t;
    ll mod = 1000000007;
    factorial(mod);
    while (t--) {
        ll k;
        cin >> k;
        ll ans = 0;
       // cout << dp[2*k] << endl;
        cout << combitorics(2*k,k,mod) << endl;
    }
}