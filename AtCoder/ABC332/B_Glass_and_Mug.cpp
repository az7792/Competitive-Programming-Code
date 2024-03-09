#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll k, m, g;
    cin >> k >> g >> m;
    ll a = 0, b = 0;
    while (k--)
    {
        if (a == g)
            a = 0;
        else if (b == 0)
            b = m;
        else
        {
            int tmp = min(b, g - a);
            a += tmp;
            b -= tmp;
        }
    }
    cout << a << " " <<b;
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
