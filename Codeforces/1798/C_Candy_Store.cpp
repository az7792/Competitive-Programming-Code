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
    ll n, ans = 0, c1, c2, Max;
    cin >> n;
    vector<ll> a(n), b(n);
    cin >> a[0] >> b[0];
    c1 = a[0] * b[0];
    c2 = b[0];
    for (int i = 1; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        c1 = gcd(c1, a[i] * b[i]);
        c2 = lcm(c2, b[i]);
        if (c1 % c2 != 0)
        {
            ans++;
            c1 = a[i] * b[i];
            c2 = b[i];
        }
    }
    cout << ans + 1 << endl;
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