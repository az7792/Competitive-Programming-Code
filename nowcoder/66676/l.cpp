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
void solve()
{
    ll n, h;
    cin >> n >> h;
    vector<pll> G(n);
    vector<pll> g;
    ll sum = 0;
    ll Max = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> G[i].first >> G[i].second;
        Max = max(Max, G[i].first);
    }
    for (auto &[a, b] : G)
        if (b > Max)
            g.push_back({a, b});
    for (int i = 0; i < g.size(); ++i)
    {
        sum += g[i].second;
        if (sum >= h)
        {
            cout << i + 1;
            return;
        }
    }
    cout << g.size() + (h - sum + Max - 1) / Max;
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