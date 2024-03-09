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
    ll n, x, y;
    cin >> n >> x >> y;
    ll LCM = lcm(x, y);
    x = (n / x) - (n / LCM);
    y = (n / y) - (n / LCM);
    cout << (n + n - x + 1) * x / 2ll - (1 + y) * y / 2ll << endl;
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