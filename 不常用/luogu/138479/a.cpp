#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 5e6 + 1;
ll dp[MAX];
int main()
{
    ll y, n, m, ttt;
    scanf("%lld %lld %lld", &y, &n, &m);
    vector<ll> b(m);
    for (ll i = 0; i < m; ++i)
        scanf("%lld", &b[i]);
    deque<ll> Q;
    for (ll i = 1; i <= n; ++i)
        dp[i] = 1;
    dp[0] = 1e18;
    Q.push_back(n); // 下标
    for (ll i = n + 1; i <= y; ++i)
    {
        dp[i] = dp[Q.front()] + 1;
        for (ll &v : b)
            if (i % v == 0)
                dp[i] = min(dp[i], dp[i / v] + 1);
        // ——————————————————————————————————————————
        while (!Q.empty() && dp[i] <= dp[Q.back()])
            Q.pop_back();
        while (!Q.empty() && Q.front() < i - n)
            Q.pop_front();
        Q.push_back(i);
        // ——————————————————————————————————————————
    }
    printf("%lld", dp[y]);
    return 0;
}