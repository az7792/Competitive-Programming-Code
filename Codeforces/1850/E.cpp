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
ll n,c;
int ok(ll mid)
{
    ll sum=0;
    for(auto v:G){
        ll tmp =  (v+2ll*mid)*(v+2ll*mid);
        if(tmp>1e18+10)
        return 1;
        sum+=tmp;
        if(sum>c)
        return 1;
        if(sum>1e18)
        return 1;
    }
    if(sum==c)
    return 0;
    if(sum<c)
    return -1;
    return 1;
}
void solve()
{
    G.clear();    
    cin>>n>>c;
    for(ll i=1,tmp;i<=n;++i)
    {
        cin>>tmp;
        G.emplace_back(tmp);
    }
    ll L=0,R=1e9,mid;
    while (L<R)
    {
        mid = (L+R)/2;
        int f = ok(mid);
        if(f==0)
        {
            cout<<mid<<endl;
            return;
        }
        else if(f<0)
        {
            L = mid+1;
        }
        else{
            R = mid-1;
        }
    }
    cout<<L<<endl;
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