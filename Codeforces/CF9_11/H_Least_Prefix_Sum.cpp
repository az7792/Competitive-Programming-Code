#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), sum(n + 1, 0);
    priority_queue<ll> Q, q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    ll now = 0;
    for (int i = m; i >= 1; --i) //[i+1,m]
    {
        if (sum[i] < sum[m] - now)
        {
            while (!Q.empty())
            {
                now += 2 * Q.top();
                ans++;
                Q.pop();
                if (sum[m] - now <= sum[i])
                    break;
            }
        }
        if (a[i] > 0)
            Q.push(a[i]);
    }
    now = 0;
    for (int i = m + 1; i <= n; ++i) //[m+1,i]
    {
        if (a[i] < 0)
            q.push(-a[i]);
        if (sum[i] + now < sum[m])
        {
            while (!q.empty())
            {
                now += 2 * q.top();
                ans++;
                q.pop();
                if (sum[m] <= sum[i] + now)
                    break;
            }
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