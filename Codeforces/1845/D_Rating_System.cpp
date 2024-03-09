#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 3e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    vector<ll> G(n + 10, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> G[i];
        G[i] += G[i - 1];
    }
    ll Maxsum = 0, ans = 0, Min = 1e18;
    for (int r = 1; r <= n; ++r)
    {
        Maxsum = max(Maxsum, G[r]);
        if (G[r] - Maxsum < Min)
        {
            Min = G[r] - Maxsum;
            ans = Maxsum;
        }
    }
    cout << ans << endl;
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