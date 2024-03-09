#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 5e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        return POW((a * a) % MOD, b / 2) % MOD;
    }
    else
    {
        return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> vis(MAX, 0);
    vector<ll> ct2(MAX, 0);
    for (int i = 1; i <= n; ++i)
    {
        ll l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2)
        {
            swap(l1, l2);
            swap(r1, r2);
        }
        if (r1 >= l2)
        {
            vis[l1]++;
            vis[max(r1, r2) + 1]--;

            ct2[l2]++;
            ct2[min(r1, r2) + 1]--;
        }
        else
        {
            vis[l1]++, vis[r1 + 1]--;
            vis[l2]++, vis[r2 + 1]--;
        }
    }
    for (int i = 1; i <= MAX; ++i)
    {
        vis[i] += vis[i - 1];
        ct2[i] += ct2[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= MAX; ++i)
    {
        if (vis[i] == n)
        {
            ans = (ans + POW(2ll, ct2[i])) % MOD;
        }
    }
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