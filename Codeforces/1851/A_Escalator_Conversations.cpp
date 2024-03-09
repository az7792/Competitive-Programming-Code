#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<ll, ll> mp;
vector<int> G(MAX, 0);
void solve()
{
    ll n, m, k, h;
    cin >> n >> m >> k >> h;
    for (int i = 1; i <= n; ++i)
        cin >> G[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int l = 1; l <= m; ++l)
        {
            bool f = 1;
            for (int r = l; r <= m; ++r)
            {
                if (l == r)
                    continue;
                if (abs(h - G[i]) == k * abs(r - l))
                {
                    ans++;
                    f = 0;
                    break;
                }
                
            }
            if (!f)
                    break;
        }        
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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