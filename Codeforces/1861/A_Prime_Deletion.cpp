#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 1e7 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool nisp[MAX];  // false 是质数
void init(int n) // 1-n的素数
{
    vector<int> isp;
    for (int i = 2; i <= n; ++i)
    {
        if (!nisp[i])
            isp.push_back(i);
        for (int j = 0; j < isp.size() && isp[j] * i <= n; ++j)
        {
            nisp[isp[j] * i] = true;
            if (i % isp[j] == 0)
                break;
        }
    }
}
string n;
int ans;
bool ok(ll n)
{
    for (int i = 2; i <= n / i; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void dfs(int p, ll now)
{
    if(ans!=-1)
        return;
    if (p == 9)
    {
        if (now * 10 >= 100)
        {
            if (p <= 1e7)
            {
                if (!nisp[now])
                    ans = now;
            }
            else
            {
                if (ok(now))
                    ans = now;
            }
        }
        return;
    }
    dfs(p + 1, now);
    now = now * 10 + (n[p] - '0');
    dfs(p + 1, now);
}
void solve()
{
    ans = -1;
    cin >> n;
    dfs(0, 0);
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    init(MAX - 10);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}