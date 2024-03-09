#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define FAST                         \
    {                                \
        ios::sync_with_stdio(false); \
        cin.tie(nullptr);            \
        cout.tie(nullptr);           \
    }
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<ll,ll>mp[5];
void solve()
{    
    ll n,m,k,t,ans=0;
    for(int i=1;i<=4;++i)
        mp[i].clear();
    cin>>n;
    for(ll i=0,x,y;i<n;i++)
    {
        cin>>x>>y;
        mp[1][x]++,mp[2][y]++;
        mp[3][x+y]++,mp[4][x-y]++;
    }
    for(int i=1;i<=4;++i)
        for(auto [x,y]:mp[i])
            ans+=y*(y-1);
    cout<<ans<<endl;
    return;
}
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    FAST;
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