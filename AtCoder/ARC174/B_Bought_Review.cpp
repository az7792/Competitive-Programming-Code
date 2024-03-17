#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    ll sum = 0, ct = 0;
    vector<ll> a(6), p(6);
    for (int i = 1; i <= 5; ++i)
    {
        cin >> a[i];
        ct += a[i];
        sum += a[i] * i;
    }
    for (int i = 1; i <= 5; ++i)
        cin >> p[i];
    ll SS = 3 * ct - sum;
    if (SS <= 0)
    {
        cout << 0 << endl;
        return;
    }
    // x+2*y>=sum  x*p[4]+y*p[5]
    ll A = p[4], B = p[5];
    if (B - 2 * A >= 0)
    {
        ll x = SS;
        cout << x * A << endl;
        return;
    }
    ll l = 0, r = (A * SS) / (2 * A - B), y;
    while (l < r)
    {
        y = (l + r + 1) / 2;
        ll x = SS - 2 * y;
        if (x >= 0)
            l = y;
        else
            r = y - 1;
    }
    ll x = SS - 2 * l;
    ll tmp = (SS + 1) / 2;
    cout << min(A * x + B * l, tmp * B) << endl;
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
