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
    int ct = 0;
    vector<vector<int>> b(n, vector<int>(n));
    vector<int> a;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> b[i][j];
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; ++j)
                a.push_back(b[i][j]);
        }
        else
        {
            for (int j = n - 1; j >= 0; --j)
                a.push_back(b[i][j]);
        }
    }
    int u, d;
    u = d = 0;
    for (int i = 0; i < n * n - 1; ++i)
    {
        if (a[i] > a[i + 1])
            d++;
        else
            u++;
    }
    if (d >= u)
    {
        for (int i = 0; i < n * n; ++i)
            cout << a[i] << " \n"[i == n * n - 1];
    }
    else
    {
        reverse(all(a));
        for (int i = 0; i < n * n; ++i)
            cout << a[i] << " \n"[i == n * n - 1];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
