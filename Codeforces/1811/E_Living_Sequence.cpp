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
int ans[] = {0, 1, 2, 3, 5, 6, 7, 8, 9};
void solve()
{
    ll k;
    cin >> k;
    vector<ll> G;
    while (k != 0)
    {
        G.eb(k % 9);
        k /= 9;
    }
    for (int i = G.size() - 1; i >= 0; --i)
        cout << ans[G[i]];
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        solve();
    }
    return 0;
}