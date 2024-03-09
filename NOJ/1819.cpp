#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define FAST                         \
    {                                \
        ios::sync_with_stdio(false); \
        cin.tie(nullptr);            \
        cout.tie(nullptr);           \
    }
const ll MAX = 3e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
unordered_map<int, int> mp;
vector<pii> G;
ll sum[1000010];
void solve()
{
    ll n, h, l, r, ans = 1e18;
    cin >> n >> h;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> l >> r;
        l++, r++;
        sum[l]++;
        sum[r + 1]--;
    }
    for (ll i = 1; i <= n; ++i)
        sum[i] += sum[i - 1];
    for (ll i = 1; i <= n; ++i)
        sum[i] += sum[i - 1];
    for (ll i = 1; i + h - 1 <= n; ++i)
        ans = min(ans, h * n - (sum[i + h - 1] - sum[i - 1]));
    cout << ans;
}
int main()
{
    FAST;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
13
1 3 5 6 7 8 10 11 12 13 14 15 20

*/