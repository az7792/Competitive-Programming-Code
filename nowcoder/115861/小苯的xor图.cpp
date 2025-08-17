#include <bits/stdc++.h>
using namespace std;
vector<int> make1(string strArr);
vector<vector<int>> make2(string strArr);
#define endl '\n'
// leetcode--------start
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 998244353;
class Solution
{
public:
     int beautifulSplits(vector<int> &nums)
     {
          return 1;
     }
};
// leetcode--------end
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
     int n, m;
     cin >> n >> m;
     vector<ll> w(n + 1);
     for (int i = 1; i <= n; ++i)
          cin >> w[i];
     vector<vector<int>> g(n + 1);
     for (int i = 0, u, v; i < m; ++i)
     {
          cin >> u >> v;
          g[v].push_back(u);
          g[u].push_back(v);
     }
     ll ans = 0;
     for (int i = 1; i <= n; ++i)
     {
          vector<ll> tmp(g[i].size());
          for (int j = 0; j < tmp.size(); ++j)
               tmp[j] = w[i] ^ w[g[i][j]];
          vector<int> b0(32, 0);
          vector<int> b1(32, 0);
          for (int j = 0; j < 32; ++j)
               for (int k = 0; k < g[i].size(); ++k)
               {
                    if (w[g[i][k]] >> j & 1)
                         b1[j]++;
                    else
                         b0[j]++;
               }
          for (int j = 0; j < tmp.size(); ++j)
          {
               for (int k = 0; k < 32; ++k)
               {
                    ll t0 = b0[k], t1 = b1[k];
                    if (w[g[i][j]] >> k & 1)
                         t1--;
                    else
                         t0--;
                    if (tmp[j] >> k & 1)
                    {
                         ans += (t0 * (1ll << k)) % MOD;
                    }
                    else
                    {
                         ans += (t1 * (1ll << k)) % MOD;
                    }
                    ans %= MOD;
               }
          }
     }
     cout << (ans * POW(2, MOD - 2)) % MOD;
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

vector<int> make1(string strArr)
{
     vector<int> result;
     if (strArr.empty())
          return result;
     string item;
     strArr = strArr.substr(1, strArr.size() - 2);
     stringstream stream(strArr);
     while (getline(stream, item, ','))
     {
          result.push_back(stoi(item));
     }
     return result;
}
vector<vector<int>> make2(string strArr)
{
     vector<vector<int>> result;
     if (strArr.empty())
          return result;
     string item;
     strArr = strArr.substr(2, strArr.size() - 4);
     stringstream stream(strArr);
     bool first = true;
     while (getline(stream, item, ']'))
     {
          if (!item.empty())
          {
               if (!first)
                    item = item.substr(2);
               vector<int> innerResult = make1("[" + item + "]");
               result.push_back(innerResult);
               first = false;
          }
     }
     return result;
}
