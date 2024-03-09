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
vector<ll>G;
void solve()
{
    G.clear();
    ll n,k,ct=0;
    ll L=0,R=0;
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        ll tmp;
        cin>>tmp;
        G.emplace_back(tmp);
    }
    G.emplace_back(1e18+10);
    sort(G.begin(),G.end());
    for(int i=1;i<=n;++i)
    {
        if(G[i]-G[i-1]>k)
        {
            ct = max(ct,R-L+1);
            L=i,R=i;
            
        }
        else{
            R++;
        }
    }
    cout<<n-ct<<endl;
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