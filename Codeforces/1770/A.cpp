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
vector<ll>B;
multiset<ll>A;
void solve()
{
    A.clear();
    B.clear();
    int n,m;
    cin>>n>>m;
    for(ll i=1,tmp;i<=n;++i)
    {
        cin>>tmp;
        A.emplace(tmp);
    }
    for(ll i=1,tmp;i<=m;++i)
    {
        cin>>tmp;
        A.erase(A.begin());
        A.emplace(tmp);
    }
    ll ans=0;
    for(auto v:A)
        ans+=v;
    cout<<ans<<endl;
    
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