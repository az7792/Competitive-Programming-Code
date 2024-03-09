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
vector<int> G[100];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[b].emplace_back(a);
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i)
    {
        if (G[i].size() == 0)
            ans.eb(i);
    }
    if(ans.size()>1)
        cout << -1;
    else
        cout << ans.back();
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