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
    ll x, y, l;
};
vector<Node> ans;
void dfs(ll sx, ll sy, ll n, ll m)
{
    if (n == m)
    {
        ans.push_back({sx, sy, n});
        return;
    }
    if (n < m)
    {
        ans.push_back({sx, sy, n});
        dfs(sx, sy + n, n, m - n);
    }
    else
    {
        ans.push_back({sx, sy, m});
        dfs(sx + m, sy, n - m, m);
    }
}

void solve()
{
    ans.clear();
    ll n, m;
    cin >> n >> m;
    cout << "YES\n";
    dfs(0, 0, n, m);
    cout << ans.size() << endl;
    for (auto &[x, y, l] : ans)
    {
        cout << x << ' ' << y << ' ' << l << endl;
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