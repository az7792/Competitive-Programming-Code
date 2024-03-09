// 未完成
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
ll Get(ll n)
{
    if (n < 5)
        return 0;
    return n / 5 + Get(n / 5);
}
void solve()
{
    ll n, ans = 0;
    cin >> n;
    ll s = n % 2 == 0 ? 2 : 1;
    for (ll i = s; i <= n; i += 2)
        ans += Get(i);
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}