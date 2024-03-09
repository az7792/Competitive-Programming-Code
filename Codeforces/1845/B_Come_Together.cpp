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
bool ok(ll b, ll a, ll c)
{
    if ((b <= a && a <= c) || (c <= a && a <= b))
        return true;
    return false;
}
void solve()
{
    int a1, a2, b1, b2, c1, c2, ans;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    if (ok(b1, a1, c1) && ok(b2, a2, c2))
        ans = 1;
    else if (ok(b1, a1, c1) == false && ok(b2, a2, c2) == false)
    {
        ll x, y;
        if (abs(a1 - b1) < abs(a1 - c1))
            x = b1;
        else
            x = c1;
        if (abs(a2 - b2) < abs(a2 - c2))
            y = b2;
        else
            y = c2;
        ans = 1 + abs(a1 - x) + abs(a2 - y);
    }
    else if (ok(b1, a1, c1))
        ans = 1 + min(abs(a2 - b2), abs(a2 - c2));
    else
        ans = 1 + min(abs(a1 - b1), abs(a1 - c1));
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}