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
void solve()
{
    vector<int>ans;
    int n,k;
    cin>>n>>k;
    int Max=n,Min=1,ct=1;
    while (Min<=Max)
    {
        if(ct==k)
            ans.emplace_back(Min++),ct=1;
        else
            ans.emplace_back(Max--),ct++;
    }
    for(auto v:ans)
        cout<<v<<" ";
    cout<<endl;       
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