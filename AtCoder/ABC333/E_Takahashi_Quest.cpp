#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 3e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<int> G[MAX];
vector<bool> vis(MAX, 0);
vector<int> num(MAX, 0);
vector<int> e(MAX, 0);
void solve()
{
    int n;
    cin >> n;
    vector<int> t(n), x(n);
    vector<bool> vis(n, 0);
    vector<set<int>> G(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i] >> x[i];
        if (t[i] == 1)
        {
            G[x[i]].insert(i);
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (t[i] == 2)
        {
            while (!G[x[i]].empty() && *G[x[i]].rbegin() >= i)
            {
                G[x[i]].erase(prev(G[x[i]].end()));
            }
            if (G[x[i]].empty())
            {
                cout << -1;
                exit(0);
            }

            vis[*G[x[i]].rbegin()] = 1;
            G[x[i]].erase(prev(G[x[i]].end()));
        }
    }
    multiset<int> S;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (vis[i])
        {
            S.insert(x[i]);
            ans = max(ans, (int)S.size());
        }
        if (t[i] == 2)
        {
            S.erase(S.find(x[i]));
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i)
    {
        if (t[i] == 1)
            cout << (vis[i] ? 1 : 0) << ' ';
    }
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
