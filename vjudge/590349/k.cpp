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
    ll n, a, b;
    cin >> n >> a >> b;
    ll sum = (n + 1) * n / 2;
    ll L = lcm(a, b);
    ll a1 = n / a;
    ll a2 = n / b;
    ll a3 = n / L;
    ll SUM = (a + a1 * a) * a1 / 2 + (b + a2 * b) * a2 / 2;
    SUM -=(L + a3 * L) * a3 / 2;
    cout << sum - SUM;
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