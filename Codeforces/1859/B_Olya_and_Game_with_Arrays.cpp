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
    ll n,min1,min2;
    min1 = min2 = 1e9 + 10;
    cin >> n;
    vector<vector<ll>> G(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            int tmp;
            cin >> tmp;
            G[i].eb(tmp);
        }
        sort(all(G[i]));
        ans += G[i][1];
        min1 = min(G[i][0], min1);
        min2 = min(G[i][1], min2);
    }
    
    cout << ans + min1 - min2 << endl;
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