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
    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    map<pll, int> mp;
    int num = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        if (b[i] == 0)
        {
            if (a[i] != 0)
                mp[{0, 0}]++;
            else
                num++;
        }
        else if (a[i] != 0)
        {
            if (a[i] < 0)
                a[i] *= -1, b[i] *= -1;
            ll g = gcd(abs(a[i]), abs(b[i]));
            a[i] /= g, b[i] /= g;
            mp[{b[i], a[i]}]++;
        }
    }
    int ans = 0;
    for (auto &[x, y] : mp)
        ans = max(ans, y);
    cout << ans + num;
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