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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<char> str(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> str[i];

    vector<int> Palindrome;
    for (int i = 0; i < (1 << k); ++i)
    {
        bool f = 1;
        bitset<10> tmp(i);
        for (int l = 0, r = k - 1; l <= r; ++l, --r)
        {
            if (tmp[l] != tmp[r])
            {
                f = 0;
                break;
            }
        }
        if (!f)
            Palindrome.push_back(i);
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(1 << k, 0));
    for (auto i : Palindrome)
    {
        bitset<10> tmp(i);
        bool f = 1;
        for (int j = 0; j < k; ++j)
        {
            if (str[j + 1] == 'A' && tmp[j] == 1)
            {
                f = 0;
                break;
            }
            if (str[j + 1] == 'B' && tmp[j] == 0)
            {
                f = 0;
                break;
            }
        }
        if (f)
            dp[k][i] = 1;
    }
    for (int i = k + 1; i <= n; ++i)
    {
        for (auto it : Palindrome)
        {
            bitset<10> tmp(it);
            int sum = 0;
            for (int j = 0; j < k - 1; ++j)
            {
                sum += (1 << j) * tmp[j];
            }
            sum = (sum << 1);
            bool f = 1;
            for (int j = i - k + 1; j <= i; ++j)
            {
                if (str[j] == 'A' && tmp[j - (i - k + 1)] == 1)
                {
                    f = 0;
                    break;
                }
                if (str[j] == 'B' && tmp[j - (i - k + 1)] == 0)
                {
                    f = 0;
                    break;
                }
            }
            if (f)
            {
                dp[i][it] = dp[i - 1][sum] + dp[i - 1][sum + 1];
                dp[i][it] %= MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < (1 << k); ++i)
    {
        ans += dp[n][i];
        ans %= MOD;
    }
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
