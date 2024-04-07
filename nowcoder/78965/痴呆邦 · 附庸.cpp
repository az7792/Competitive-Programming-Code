#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll POW(ll a, ll b)
{
    a %= MOD;
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return POW((a * a) % MOD, b / 2) % MOD;
    else
        return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}
ll ttt = POW(2, MOD - 2);
void solve()
{
    int n;
    cin >> n;
    vector<ll> dp1(n, 0), dp2(n, 0);
    dp1[0] = dp1[1] = 1;
    dp2[0] = dp2[1] = 1;
    for (int i = 2; i < n; ++i)
    {
        int R = i / 2;
        dp1[i] = (dp1[i - 1] + dp2[i - 2]) % MOD;
        for (int j = 0; j <= R; ++j)
        {
            if (j < i - j)
                dp2[i] += (dp1[j] * dp1[i - j]) % MOD;
            else
                dp2[i] += (dp1[j] * (1 + dp1[j])) % MOD * ttt;
            dp2[i] %= MOD;
        }
    }
    cout << dp1[n - 1] << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
