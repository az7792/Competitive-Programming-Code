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
    int n, m;
    cin >> n >> m;
    vector<int> G(n + 10, 0);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u]++;
        G[v]++;
    }
    set<int> S;
    for (int i = 1; i <= n; ++i)
    {
        S.emplace(G[i]);
    }
    S.erase(1);
    int x = *S.begin();
    int ct = count(all(G), x);
    if (ct == 1)
    {
        cout << x << ' ' << *S.rbegin() - 1 << endl;
    }
    else
    {
        cout << *S.rbegin() << ' ' << x - 1 << endl;
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