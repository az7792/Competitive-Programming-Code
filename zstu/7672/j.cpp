#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n, m, l = 1, r, a, b;
    cin >> n >> m;
    r = 2 * n - 1;
    vector<int> ans(2 * n);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        int L = a, R = a + 2 * (n - a + 1) - 2;
        b = a + b - 1;
        ans[b] = 1;
        if (b + 1 == R || b == R)
            r = min(r, b - 1);
        if (b - 1 == L || b == L)
            l = max(l, b + 1);
    }
    if (l > r)
    {
        for (int i = 1; i <= 2 * n - 1; ++i)
            cout << 0;
    }
    else
    {
        for (int i = 1; i < l; ++i)
            cout << 0;
        for (int i = l; i <= r; ++i)
            cout << (ans[i] ^ 1);
        for (int i = r + 1; i <= 2 * n - 1; ++i)
            cout << 0;
    }
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
