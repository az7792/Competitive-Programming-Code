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
vector<ll> G[MAX];
void solve()
{
    ll n, m, h;
    cin >> n >> m >> h;
    vector<pll> ans;
    pll Rud;
    for (int i = 1; i <= n; ++i)
    {
        G[i].clear();
        for (int j = 1, a; j <= m; ++j)
        {
            cin >> a;
            G[i].eb(a);
        }
        sort(all(G[i]));
        ll H = 0;
        ll sc = 0, t = 0;
        for (auto v : G[i])
        {
            if (v + H <= h)
            {
                sc++;
                t += H + v;
                H += v;
            }
            else
                break;
        }
        ans.eb(sc, t);
        if (i == 1)
        {
            Rud = pll(sc, t);
        }
    }
    sort(all(ans), [](pll a, pll b)
         {
        if(a.first==b.first)
            return a.second < b.second;
        return a.first > b.first; });
    for (int i = 0; i < ans.size(); ++i)
    {
        if (ans[i] == Rud)
        {
            cout << i + 1 << endl;
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}