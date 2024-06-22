#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    ll ans = 0;
    sort(all(a));
    for (int i = 0; i < n; ++i)
    {
        ll p = upper_bound(all(a), 2 * a[i]) - a.begin();
        p--;
        ans += p - i;
    }
    cout << ans;
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