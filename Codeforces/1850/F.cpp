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
map<ll,ll>mp;
void solve()
{        
    mp.clear();
    int n;
    cin>>n;
    vector<int>G(n+10,0);
    for(int i=1,tmp;i<=n;i++)
    {
        cin>>tmp;
        if(tmp<=n)
            mp[tmp]++;
    }
    for(auto [x,y]:mp)
        for(int i=x;i<=n;i+=x)
            G[i-1]+=y; 
    cout<<*max_element(G.begin(),G.end())<<endl;
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