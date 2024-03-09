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
    pair<ll, ll> a, b, c, d;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    cin >> d.first >> d.second;
    ll L1 = abs(a.first - b.first);
    L1 = max(L1, abs(a.first - c.first));
    L1 = max(L1, abs(a.first - d.first));
    ll L2 = abs(a.second - b.second);
    L2 = max(L2, abs(a.second - c.second));
    L2 = max(L2, abs(a.second - d.second));
    cout << L1 * L2 << endl;
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
