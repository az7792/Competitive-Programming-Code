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
    ll n, f, a, b;
    cin >> n >> f >> a >> b;
    vector<ll> num(n + 1);
    num[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> num[i];
    for (int i = 1; i <= n; ++i)
    {
        ll ti = (num[i] - num[i - 1]) * a;
        if (ti >= b)
        {
            f -= b;
        }
        else
        {
            f -= ti;
        }
        if (f <= 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
