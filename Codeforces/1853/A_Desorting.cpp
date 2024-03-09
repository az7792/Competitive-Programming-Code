#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
#define fi first
#define se second
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<ll, ll> mp;
void solve()
{
    
    int n;
    cin>>n;
    vector<int>G(n+10,0);
    int ans=1e9,f=0;
    for(int i=1;i<=n;++i)
    {
        cin>>G[i];
    }
    for(int i=2;i<=n;++i){
        if(G[i]<G[i-1])
            {cout<<0<<endl;return;}
    }
    for(int i=1;i<n;++i)
    {
        ans = min(ans,G[i+1]-G[i]);
    }
    cout<<ans/2 + 1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/