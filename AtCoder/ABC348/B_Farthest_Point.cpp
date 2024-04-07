#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> g(n);
    for (int i = 0; i < n; ++i)
        cin >> g[i].first >> g[i].second;
    for (int i = 0; i < n; ++i)
    {
        ll len = 0, pos;
        for (int j = n - 1; j >= 0; --j)
        {
            if (j != i)
            {
                ll tmp = (g[i].first - g[j].first) * (g[i].first - g[j].first) + (g[i].second - g[j].second) * (g[i].second - g[j].second);
                if (tmp >= len)
                {
                    len = tmp;
                    pos = j;
                }
            }
        }
        cout << pos + 1 << endl;
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
