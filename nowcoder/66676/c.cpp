#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
set<int> G[MAX];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j <= i / j; ++j)
            if (i % j == 0)
            {
                G[i].insert(j);
                G[i].insert(i / j);
            }
    ll ans = 0;
    for (int i = 1; i < n; ++i)
        ans += 1ll * G[i].size() * G[n - i].size();
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