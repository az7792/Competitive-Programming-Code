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
set<char>ch;
void solve()
{        
    int n;
    string str;
    cin>>n>>str;
    for(int i=0;i<str.size();++i)
    {
        ch.emplace(str[i]);
        if(ch.size()==3)
            {
                cout<<i+1<<endl;
                return;
            }
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