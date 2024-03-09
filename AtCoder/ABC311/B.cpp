#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
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
vector<char>G(1000,'o');
bool ok(int l,int r)
{
    for(int i=l;i<=r;++i)
    {
        if(G[i]=='x')
            return 0;
    }
    return 1;
}
void solve()
{        
    int n,d;
    cin>>n>>d;
    string str;
    
    for(int i=1;i<=n;++i)
    {
        cin>>str;
        for(int j=0;j<str.size();++j)
        {
            if(G[j+1]=='o')
                G[j+1]=str[j];
        }
    }
    int ans=0;
    for(int i=1;i<=d;++i)
    {
        for(int j=i;j<=d;++j)
        {
            if(ok(i,j))
            {
                ans = max(ans,j-i+1);
            }
        }
    }
    cout<<ans;
}
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    FAST;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/