#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
int ct = 0, B, f = 1;
vector<vector<int>> G;
vector<ll> sum;
void dfs(int p)
{
    if (p == B)
    {
        ct++;
        return;
    }
    if (G[p].size() == 0)
    {
        f = 0;
        return;
    }
    for (auto v : G[p])
    {
        if (sum[v] != -1)
            ct += sum[v];
        else
        {
            int tmpct = ct;
            dfs(v);
            sum[v] = ct - tmpct;
        }
    }
}
void solve()
{
    sum.clear();
    G.clear();
    int n, m, s1, s2, A;
    cin >> n >> m;
    G.resize(n + 1);
    sum.resize(n + 1, -1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> s1 >> s2;
        G[s1].push_back(s2);
    }
    cin >> A >> B;
    dfs(A);
    cout << ct << " " << (f == 1 ? "Yes" : "No");
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
