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
vector<int>G[MAX];
bool f[MAX];
stack<int>S;
int dfs(int p)
{
    if(f[p])
        return p;
    f[p]=1;
    for(auto v:G[p])
    {
        int tmp = dfs(v);
        if(tmp == p)
        {
            cout<<1+S.size()<<endl;
            while (!S.empty())
            {
                cout<<S.top()<<" ";
                S.pop();
            }
            cout<<p<<endl;
            exit(0);
        }
        else if(tmp!=-1)
        {
            S.push(p);
            return tmp;
        }
    }
return -1;
}
void solve()
{        
    int n;
    cin>>n;
    for(int i=1,tmp;i<=n;++i)
    {
        cin>>tmp;
        G[i].emplace_back(tmp);
    }
    for(int i=1;i<=n;++i)
    {
        if(!f[i])
           dfs(i);
    }
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