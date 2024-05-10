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
void solve()
{
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    str = "*" + str;
    vector<ll> a(n + 2, 0), b(n + 2, 0);
    vector<pair<ll, ll>> num(n + 2, {0, 0});
    for (int i = n; i >= 1; --i)
    {
        num[i].first = num[i + 1].first + (str[i] == '0' ? 1 : 0);   // 0
        num[i].second = num[i + 1].second + (str[i] == '1' ? 1 : 0); // 1
    }
    for (int i = n; i >= 1; --i)
    {
        a[i] = (a[i + 1] + num[i + 1].second) % MOD; // 0-1
        b[i] = (b[i + 1] + num[i + 1].first) % MOD;  // 1-0
    }
    vector<ll> AA(n + 2), BB(n + 2), p0(n + 2), p1(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        AA[i] = AA[i - 1];
        BB[i] = BB[i - 1];
        p1[i] = p1[i - 1];
        p0[i] = p0[i - 1];
        if (str[i] == '0')
        {
            AA[i] += a[i];
            p0[i] += i;
        }
        else
        {
            BB[i] += b[i];
            p1[i] += i;
        }
        AA[i] %= MOD;
        BB[i] %= MOD;
        p1[i] %= MOD;
        p0[i] %= MOD;
    }
    while (m--)
    {
        int l, r;
        ll ans = 0;
        cin >> l >> r;
        ans += ((AA[r] - AA[l - 1]) % MOD + MOD) % MOD;
        ans %= MOD;
        ans += ((BB[r] - BB[l - 1]) % MOD + MOD) % MOD;
        ans %= MOD;
        ll zero = ((num[l].first - num[r + 1].first) % MOD + MOD) % MOD;
        ll one = ((num[l].second - num[r + 1].second) % MOD + MOD) % MOD;
        ll AAA = (a[r + 1] * zero) % MOD;
        ll BBB = (b[r + 1] * one) % MOD;
        ll AAAA = (zero * (r + 1)) % MOD;
        ll BBBB = (one * (r + 1)) % MOD;
        ll aaa = ((p0[r] - p0[l - 1]) % MOD + MOD) % MOD;
        ll bbb = ((p1[r] - p1[l - 1]) % MOD + MOD) % MOD;
        ans -= ((AAA + ((AAAA - aaa) % MOD + MOD) % MOD * num[r + 1].second % MOD) % MOD) % MOD;
        ans = (ans % MOD + MOD) % MOD;
        ans -= ((BBB + ((BBBB - bbb) % MOD + MOD) % MOD * num[r + 1].first % MOD) % MOD) % MOD;
        ans = (ans % MOD + MOD) % MOD;
        cout << ans << endl;
    }
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
