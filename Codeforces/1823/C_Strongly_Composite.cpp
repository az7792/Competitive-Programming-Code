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
    int n;
    cin >> n;
    vector<ll> G(n + 10);
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> G[i];
        for (int j = 2; j <= G[i] / j; ++j)
        {
            while (G[i] % j == 0)
            {
                mp[j]++;
                G[i] /= j;
            }
        }
        if (G[i] > 1)
            mp[G[i]]++;
    }
    int ct = 0, ans = 0;
    for (auto &[x, y] : mp)
    {
        ans += y / 2;
        ct += y % 2;
    }
    cout << ans + ct / 3 << endl;
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