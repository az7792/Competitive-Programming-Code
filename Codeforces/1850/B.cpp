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
vector<pii>G;
void solve()
{
    G.clear();
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int a,b;
        cin>>a>>b;
        if(a<=10)
            G.emplace_back(b,i);
    }
    sort(G.begin(),G.end(),[](pii a,pii b){return a.first>b.first;});
    cout<<G[0].second<<endl;
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