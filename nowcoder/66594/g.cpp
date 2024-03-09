#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<pii, ll> mp;
vector<int> a;
vector<ll> jc(100010);
ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return POW((a * a) % MOD, b / 2) % MOD;
    else
        return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}
ll dfs(int n, int k)
{
    // if (mp.find({n, k}) != mp.end())
    //     return mp[{n, k}];
    // if (n <= 0)
    //     return 0;
    // if (k == 1)
    // {
    //     ll a = n % MOD;
    //     mp[{n, k}] = a;
    //     return a;
    // }
    // if (n < k)
    //     return 0;
    // ll b = dfs(n - 1, k);
    // ll a = dfs(n - 1, k - 1);
    // mp[{n, k}] = (a + b) % MOD;
    // return (a + b) % MOD;
    if (k > n)
        return 0;
    // return dfs(n - 1, k) + dfs(n - 1, k - 1);
    return (jc[n] * POW((jc[k] * jc[n - k]) % MOD, MOD - 2)) % MOD;
}
void solve()
{
    ll n, k;
    a.clear();
    cin >> n >> k;
    int num = -1;
    a.resize(n + 1, 0);
    set<int> S;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l, r;
    for (int i = 1; i <= n; ++i)
    {
        S.insert(a[i]);
        if (S.size() != i)
        {
            num = a[i];
            r = i + 1;
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (a[i] == num)
        {
            l = i - 1;
            break;
        }
    ll ans = dfs(n, k) % MOD;
    if (num == -1)
        cout << ans << endl;
    else
    {
        ll Ans = dfs(l + n - r + 1, k - 1) % MOD; // n = l+n-r+1;
        cout << (ans - Ans + MOD) % MOD << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    // vector<vector<int>> aans(30, vector<int>(30, -1));
    // for (int i = 1; i <= 25; ++i)
    //     for (int j = 1; j <= i; ++j)
    //     {
    //         aans[i][j] = dfs(i, j);
    //     }
    // return 0;
    jc[0] = 1;
    for (int i = 1; i <= 1e5; ++i)
    {
        jc[i] = (jc[i - 1] * i) % MOD;
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}