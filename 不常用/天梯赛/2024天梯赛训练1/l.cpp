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
    int n, m, k, op, p;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> k;
        a[i] = vector<int>(k + 1);
        for (int j = 1; j <= k; ++j)
            cin >> a[i][j];
    }
    vector<int> dang(101);
    int now = 1;
    while (m--)
    {
        cin >> op >> p;
        if (op == 0)
        {
            now = a[now][p];
        }
        else if (op == 1)
        {
            dang[p] = now;
            cout << now << endl;
        }
        else
        {
            now = dang[p];
        }
    }
    cout << now;
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
