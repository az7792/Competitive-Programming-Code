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
    ll n, m;
    cin >> n >> m;
    if (n % 2 == 0)
    {
        vector<ll> a(n, 0);
        ll Max = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            Max ^= a[i];
        }
        ll Min = 0, b;
        for (int i = 0; i < m; ++i)
        {
            cin >> b;
            Min |= b;
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            a[i] |= Min;
            ans ^= a[i];
        }
        cout << ans << ' ' << Max << endl;
    }
    else
    {
        vector<ll> a(n, 0);
        ll Min = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            Min ^= a[i];
        }
        ll Max = 0, b;
        for (int i = 0; i < m; ++i)
        {
            cin >> b;
            Max |= b;
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            a[i] |= Max;
            ans ^= a[i];
        }
        cout << Min << ' ' << ans << endl;
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