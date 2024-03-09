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
    ll n;
    cin >> n;
    vector<ll> G(n + 10, 0);
    vector<ll> D(n + 10, 0);
    for (int i = 1; i <= n; ++i)
        cin >> G[i];
    if (n % 2 == 1)
    {
        cout << "YES\n";
        return;
    }

    for (int i = 1; i < n; ++i)
    {
        if (G[i - 1] <= G[i])
        {
            G[i] -= G[i - 1];
            G[i - 1] = 0;
        }
        else
        {
            G[i + 1] += G[i - 1];
            G[i - 1] = 0;
        }
    }
    if (G[n] >= G[n - 1])
        cout << "YES\n";
    else
        cout << "NO\n";
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