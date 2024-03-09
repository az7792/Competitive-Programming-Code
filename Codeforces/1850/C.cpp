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
    char num[10][10];
    for(int i=1;i<=8;++i)
    {
        for(int j=1;j<=8;++j)
        {
            cin>>num[i][j];
        }
    }
    for(int i=1;i<=8;++i)
    {
        num[9][i]='.';
    }
    for(int i=1;i<=8;++i)
    {
        for(int j=1;j<=8;++j)
        {
            if(num[i][j]!='.')
            {                
                for(int k=i;k<=9;++k)
                {
                    if(num[k][j]=='.')
                    {
                        cout<<endl;
                        return;
                    }
                    cout<<num[k][j];
                }
            }
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*




*/