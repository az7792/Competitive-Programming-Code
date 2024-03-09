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
    ll n, m, xa, ya, xb, yb;
    cin >> n >> m >> xa >> ya >> xb >> yb;
    if (xa >= xb)
    {
        cout << "Draw\n";
        return;
    }
    if ((xb - xa) % 2 == 0) // a一定赢不了
    {
        if (ya == yb)
        {
            cout << "Bob\n";
            return;
        }
        if (yb < ya)
        {
            ll Mya = min(ya + (xb - xa) / 2, m);
            ll Myb = min(yb + (xb - xa) / 2, m);
            if (Mya > Myb)
                cout << "Draw\n";
            else
                cout << "Bob\n";
            return;
        }
        ll Mya = max(ya - (xb - xa) / 2, 1ll);
        ll Myb = max(yb - (xb - xa) / 2, 1ll);
        if (Mya < Myb)
            cout << "Draw\n";
        else
            cout << "Bob\n";
        return;
    }
    else // b一定赢不了
    {
        if (ya == yb)
        {
            cout << "Alice\n";
            return;
        }
        if (yb > ya)
        {
            ll Mya = min(ya + (xb - xa + 1) / 2, m);
            ll Myb = min(yb + (xb - xa) / 2, m);
            if (Mya < Myb)
                cout << "Draw\n";
            else
                cout << "Alice\n";
            return;
        }
        ll Mya = max(ya - (xb - xa + 1) / 2, 1ll);
        ll Myb = max(yb - (xb - xa) / 2, 1ll);
        if (Mya > Myb)
            cout << "Draw\n";
        else
            cout << "Alice\n";
        return;
    }
    cout << "Draw\n";
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
