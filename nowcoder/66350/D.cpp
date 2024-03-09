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
ll n, m;
bool check(vector<ll> &df)
{
    for (int i = 1; i <= n; ++i)
        if (df[i] < 0)
            return false;
    return true;
}
void solve()
{
    cin >> n >> m;
    vector<ll> r(n + 2), d(m + 1), s(m + 1), t(m + 1), df(n + 2, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> d[i] >> s[i] >> t[i];
    }
    int L = 1, R = m, mid;
    while (L < R)
    {
        mid = (L + R) / 2;
        for (int i = 1; i <= n; ++i)
            df[i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            df[i] += r[i];
            df[i + 1] -= r[i];
        }
        for (int i = 1; i <= mid; ++i)
        {
            df[s[i]] -= d[i];
            df[t[i] + 1] += d[i];
        }
        for (int i = 1; i <= n; ++i)
            df[i] += df[i - 1];
        if (check(df))
            L = mid + 1;
        else
            R = mid;
    }
    for (int i = 1; i <= n; ++i)
        df[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        df[i] += r[i];
        df[i + 1] -= r[i];
    }
    for (int i = 1; i <= L; ++i)
    {
        df[s[i]] -= d[i];
        df[t[i] + 1] += d[i];
    }
    if (check(df))
        cout << 0;
    else
        cout << -1 << endl
             << L;
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