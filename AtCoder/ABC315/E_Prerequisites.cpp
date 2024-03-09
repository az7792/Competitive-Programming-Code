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
ll n;
vector<vector<ll>> P;
vector<bool> f;
vector<ll> ans;
void dfs(int p)
{
    if (P[p].size() == 0)
    {
        f[p] = true;
        ans.emplace_back(p);
        return;
    }
    for (auto v : P[p])
    {
        if (f[v] == false)
        {
            dfs(v);
        }
    }
    ans.emplace_back(p);
    f[p] = true;
}
void solve()
{
    cin >> n;
    f.resize(n + 1, false);
    f[1] = true;
    P.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        ll c;
        cin >> c;
        P[i].resize(c);
        for (int j = 0; j < c; ++j)
            cin >> P[i][j];
    }
    dfs(1);
    ans.pop_back();
    for (auto v : ans)
    {
        cout << v << ' ';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}