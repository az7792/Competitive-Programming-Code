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
ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return POW((a * a) % MOD, b / 2) % MOD;
    else
        return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}
void solve()
{
    ll n;
    cin >> n;
    vector<pair<int, ll>> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i].second, a[i].first = i;
    sort(a.begin() + 1, a.end(), [](pair<int, ll> a, pair<int, ll> b)
         { return a.second > b.second; });
    ll ans = 0;
    set<ll> S;
    for (int i = 1; i <= n; ++i)
        S.insert(i);
    for (int i = 1; i <= n; ++i)
    {
        int N = a[i].first;
        set<int> s;
        for (int j = 1; j <= N / j; ++j)
        {
            if (N % j == 0)
            {
                s.insert(j);
                s.insert(N / j);
            }
        }
        ll ct = s.size();
        for (auto &v : s)
        {
            if (S.find(v) == S.end())
                ct--;
        }
        ll tmp = ((POW(2, ct) - 1 + MOD) % MOD * POW(2, S.size() - ct)) % MOD;
        ans = (ans + (tmp * a[i].second) % MOD) % MOD;
        for (auto v : s)
            S.erase(v);
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