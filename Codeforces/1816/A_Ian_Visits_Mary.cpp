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
void solve()
{
    ll x, y;
    cin >> x >> y;
    if (y == 1 || x == 1)
    {
        cout << 1 << endl
             << x << ' ' << y << endl;
    }
    else
    {
        cout << 2 << endl
             << x - 1 << ' ' << 1 << endl
             << x << ' ' << y << endl;
    }
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