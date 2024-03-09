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
    ll n;
    cin >> n;
    vector<ll> a(n + 10), b(n + 10), ans(n + 10, 0), ct(n + 10, 0), sum(n + 10, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        sum[i] = b[i] + sum[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        int p = upper_bound(sum.begin() + i, sum.begin() + n + 1, a[i] + sum[i - 1]) - sum.begin();
        if (p <= n)
            ans[p] += a[i] + sum[i - 1] - sum[p - 1];
        ct[i]++;
        ct[p]--;
    }
    for (int i = 1; i <= n; ++i)
        ct[i] += ct[i - 1];
    for (int i = 1; i <= n; ++i)
    {
        ans[i] += b[i] * ct[i];
        cout << ans[i] << ' ';
    }
    cout << endl;
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