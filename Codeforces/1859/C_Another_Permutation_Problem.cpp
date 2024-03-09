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
    ll n, ans = 0;
    cin >> n;
    for (int i = 0; i <= n; ++i)
    {
        ll tmp = 0, Max = 0, N = n;
        for (int j = 1; j <= i; ++j)
        {
            tmp += 1ll * j * j;
            Max = max(Max, 1ll * j * j);
        }
        for (int j = i + 1; j <= n; ++j)
        {
            tmp += j * N;
            Max = max(Max, N * j);
            N--;
        }
        ans = max(ans, tmp - Max);
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