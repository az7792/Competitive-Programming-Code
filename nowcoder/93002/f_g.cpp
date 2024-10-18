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

struct BIT
{
     int n;        // 数组长度[1,n]
     vector<ll> D; // 维护前缀和
     BIT(int N)
     {
          n = N;
          D.resize(n + 2);
     }
     int lowbit(int x)
     {
          return x & (-x);
     }
     void add(int x, ll v) // 在[x]加上v
     {
          while (x <= n)
          {
               D[x] += v;
               D[x] %= MOD;
               x += lowbit(x);
          }
     }
     ll query(int x) // 查询[1,x]的值
     {
          ll res = 0;
          while (x)
          {
               res += D[x];
               res %= MOD;
               x -= lowbit(x);
          }
          return res;
     }
};

void solve()
{
     ll n, q;
     cin >> n >> q;
     vector<ll> f(n + 1), g(n + 1);
     BIT sumf(n), sumg(n);
     ll ans = 0;
     for (int i = 1; i <= n; ++i)
     {
          cin >> f[i];
          sumf.add(i, f[i]);
     }
     for (int i = 1; i <= n; ++i)
     {
          cin >> g[i];
          sumg.add(i, g[i]);
          ans += (f[i] * g[i]) % MOD;
          ans %= MOD;
     }
     for (int i = 1; i < n; ++i)
     {
          ans += (((2ll * f[i]) % MOD) * (((sumg.query(n) - sumg.query(i)) % MOD + MOD) % MOD)) % MOD;
          ans %= MOD;
     }

     while (q--)
     {
          ll op, p, x;
          cin >> op >> p >> x;
          if (op == 1) // f
          {
               ans += ((x - f[p]) % MOD * g[p]) % MOD;
               ans %= MOD;

               ans += ((2 * (x - f[p]) % MOD) % MOD * (sumg.query(n) - sumg.query(p)) % MOD) % MOD;
               ans %= MOD;
               sumf.add(p, x - f[p]);
               f[p] = x;
          }
          else
          {
               ans += (f[p] * (x - g[p]) % MOD) % MOD;
               ans %= MOD;

               ans += ((2 * (x - g[p]) % MOD) % MOD * sumf.query(p - 1) % MOD) % MOD;
               ans %= MOD;
               sumg.add(p, x - g[p]);
               g[p] = x;
          }
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
