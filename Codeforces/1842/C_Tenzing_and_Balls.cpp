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
int G[MAX];
int dp[MAX];
map<int, int> mp;
void solve()
{
    mp.clear();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> G[i];
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        int Min = (mp.find(G[i]) == mp.end()) ? 1e8 : mp[G[i]];
        dp[i] = min(dp[i], Min);
        mp[G[i]] = (mp.find(G[i]) == mp.end()) ? dp[i - 1] : min(mp[G[i]], dp[i - 1]);
    }
    cout << n - dp[n] << endl;
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
/*




*/