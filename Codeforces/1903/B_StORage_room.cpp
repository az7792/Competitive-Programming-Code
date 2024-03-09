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
    int n;
    cin >> n;
    vector<vector<int>> m(n + 1, vector<int>(n + 1));
    vector<bitset<30>> a(n + 1, bitset<30>(1073741823));
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> m[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            bitset<30> tmp(m[i][j]);
            for (int k = 0; k < 30; ++k)
                if (tmp[k] == 0)
                    a[i][k] = tmp[k], a[j][k] = tmp[k];
        }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 30; ++j)
            if (a[i][j] == 1)
                ans[i] += (1 << j);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if ((ans[i] | ans[j]) != m[i][j])
            {
                cout << "NO\n";
                return;
            }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
