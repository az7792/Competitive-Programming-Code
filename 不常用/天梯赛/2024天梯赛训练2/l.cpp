#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n, m, k;
    cin >> n >> m;
    vector<vector<ll>> G(n + 1, vector<ll>(n + 1, 1e18));
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = c;
        G[b][a] = c;
    }
    cin >> k;
    ll Min = 1e18, ct = 0, ans;
    for (int i = 1; i <= k; ++i)
    {
        int num, v, la = 0;
        cin >> num;
        ll sum = 0, f = 0;
        set<int> S;
        for (int i = 0; i < num; ++i)
        {
            cin >> v;
            S.insert(v);
            if (f)
                continue;
            if (G[la][v] != 1e18)
                sum += G[la][v];
            else
                f = 1;
            la = v;
        }
        if (f == 0 && num == n && S.size() == n && G[la][0] != 1e18)
        {
            ct++;
            sum += G[la][0];
            if (sum < Min)
            {
                Min = sum;
                ans = i;
            }
        }
    }
    cout << ct << endl
         << ans << " " << Min;
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
