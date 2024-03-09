#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
// const ll MOD = 998244353;
ll MOD;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll dfs(ll n)
{
    if (n == 1)
        return 4;
    ll res = dfs(n - 1);
    return (res % MOD * res % MOD) % MOD;
}
void solve()
{
    ll n;
    cin >> n >> MOD;
    // pow(2,pow(2,n))
    cout << dfs(n);
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