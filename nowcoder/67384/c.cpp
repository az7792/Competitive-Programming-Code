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
struct Node
{
    ll x, y;
};
void solve()
{
    Node a[6];
    vector<ll> g;
    for (int i = 0; i < 6; i += 2)
    {
        cin >> a[i].x >> a[i].y;
        cin >> a[i + 1].x >> a[i + 1].y;
        g.push_back(a[i].x);
        g.push_back(a[i + 1].x);
    }
    sort(all(g));
    ll ans = 0;
    for (int i = 0; i < 5; ++i)
    {
        ll L = g[i], R = g[i + 1];
        if (L != R)
        {
            ll U = -1e18, D = 1e18;
            for (int j = 0; j < 6; j += 2)
            {
                if (!(a[j].x >= R || a[j + 1].x <= L))
                {
                    U = max(U, a[j + 1].y);
                    D = min(D, a[j].y);
                }
            }
            if(!(U==-1e18&&D==1e18))
                ans += (R - L) * (U - D);
        }
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}