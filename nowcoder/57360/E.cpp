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
    ll n, q, l, r, k;
    cin >> n >> q;
    vector<ll> G(n + 10, 0);
    vector<ll> sum(n + 10, 0);
    vector<pll> ct(n + 10, {0, 0});
    for (int i = 1; i <= n; ++i)
        cin >> G[i], sum[i] = sum[i - 1] + G[i];
    for (int i = 1; i <= n; ++i)
    {
        ct[i] = ct[i - 1];
        if (sum[i] % 2 == 0)
            ct[i].second++;
        else
            ct[i].first++;
    }
    while (q--)
    {
        cin >> l >> r >> k;
        if (r - l + 1 < k)
            cout << "NO\n";
        else if ((sum[r] - sum[l - 1]) % 2 != 0)
            cout << "NO\n";
        else if (sum[l - 1] % 2 == 1)
        {
            ll ctk = ct[r].first - ct[l - 1].first;
            cout << (ctk >= k ? "YES" : "NO") << endl;
        }
        else
        {
            ll ctk = ct[r].second - ct[l - 1].second;
            cout << (ctk >= k ? "YES" : "NO") << endl;
        }
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