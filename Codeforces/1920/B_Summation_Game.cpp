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
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n + 1), b(n + 1);
    vector<ll> suma(n + 1), sumb(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; ++i)
        b[i] = -a[i];
    for (int i = 1; i <= n; ++i)
    {
        suma[i] += suma[i - 1] + a[i];
        sumb[i] += sumb[i - 1] + b[i];
    }
    ll ans = -1e18;
    for (int i = 0; i <= k; ++i)
    {
        int len = n - i;
        ans = max(ans, suma[max(0, len - x)] + sumb[len] - sumb[max(0, len - x)]);
    }
    cout << ans << endl;
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
