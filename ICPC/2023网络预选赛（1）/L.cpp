#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    ll n, t, ans = 0;
    cin >> n >> t;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    ll Max = *max_element(all(a));
    cout << max(2ll, (Max + t - 1) / t);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}