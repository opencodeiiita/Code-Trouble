#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
ll n,c=0;
vector<ll>adj[100001];
vector<ll>type(100001),coun(100001,0),dis(100001,0);
void dfs(ll node, ll p){
    for(auto child:adj[node]){
        if(child!=p){
            dfs(child,node);
            coun[node]+=coun[child];
            dis[node] += dis[child]+coun[child];
        }
    }
}
void dfs1(ll node, ll p){
    for(auto child:adj[node]){
        if(child!=p){
            dis[child]=dis[node]-coun[child]+c-coun[child];
            dfs1(child,node);
        }
    }
}
int main(){
    cin>>n;
    for(ll i=0;i<n-1;i++){
        ll a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(ll i=1;i<=n;i++){
        cin>>type[i];
        if(type[i]==1){
            coun[i]=1;
            c++;
        }
    }
    dfs(1,-1);
    dfs1(1,-1);
    ll sod=LLONG_MAX,ans=-1;
    for(ll i=1;i<=n;i++){
        if(sod>dis[i]){
            sod=dis[i];
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}