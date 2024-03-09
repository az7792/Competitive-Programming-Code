#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 4e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n, q, x, y;
    cin >> n;
    vector<ll> a(n + 2);
    vector<ll> up(n + 2);
    vector<ll> down(n + 2);
    a[0] = -1e18;
    a[n + 1] = 1e18;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    up[1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i + 1] - a[i] < a[i] - a[i - 1])
            up[i + 1] = up[i] + 1;
        else
            up[i + 1] = up[i] + a[i + 1] - a[i];
    }
    down[n] = 0;
    for (int i = n; i >= 1; --i)
    {
        if (a[i] - a[i - 1] < a[i + 1] - a[i])
            down[i - 1] = down[i] + 1;
        else
            down[i - 1] = down[i] + a[i] - a[i - 1];
    }
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        if (x < y)
            cout << up[y] - up[x];
        else
            cout << down[y] - down[x];
        cout << endl;
    }
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
