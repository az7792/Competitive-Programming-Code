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
vector<ll> x, t;
ll n;
double check(double p)
{
    double tim = -1e18;
    for (int i = 1; i <= n; ++i)
        tim = max(1.0 * t[i] + fabs(p - x[i]), tim);
    return tim;
}
void solve()
{
    // ll n;
    // cin >> n;
    // x.clear();
    // x.resize(n + 1, 0);
    // for (int i = 1; i <= n; ++i)
    //     cin >> x[i];
    // double Max = -1e9, Min = 1e9;
    // for (int i = 1; i <= n; ++i)
    // {
    //     double t;
    //     cin >> t;
    //     Max = max(Max, x[i] + t);
    //     Min = min(Min, x[i] - t);
    // }
    // cout << fixed << (Max + Min) / 2 << endl;
    x.clear(), t.clear();
    cin >> n;
    x.resize(n + 1, 0), t.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    double L = 0, R = 1e8, mid, midmid;
    while (R - L > 0.00000001)
    {
        mid = (L + R) / 2.0;
        midmid = (mid + R) / 2.0;
        if (check(mid) < check(midmid))
            R = midmid;
        else
            L = mid;
    }
    cout << fixed << L << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}