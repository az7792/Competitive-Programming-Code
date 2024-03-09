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
    int n;
    cin >> n;
    vector<int> G(n + 10, 0);
    int tmp = 0, p = 1;
    vector<pii> ans;
    for (int i = 1; i <= n; ++i)
    {
        cin >> G[i];
        if (abs(G[i]) >= abs(tmp))
        {
            tmp = G[i];
            p = i;
        }
    }

    if (tmp >= 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (G[i] <= 0)
            {
                ans.eb(i, p);
                G[i] += tmp;
            }
        }
        for (int i = 2; i <= n; ++i)
        {
            ans.eb(i, i - 1);
            G[i] += G[i - 1];
        }
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (G[i] >= 0)
            {
                ans.eb(i, p);
                G[i] += tmp;
            }
        }
        for (int i = n - 1; i >= 1; --i)
            ans.eb(i, i + 1), G[i] += G[i + 1];
    }
    // for (int i = 1; i <= n;++i)
    //     cerr << G[i] << ' ';
    // cerr << endl;
    cout << ans.size() << endl;
    for (auto &[x, y] : ans)
        cout << x << ' ' << y << endl;
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