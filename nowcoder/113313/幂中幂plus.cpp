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
ll MOD = 1e9 + 7;
class Solution
{
public:
     int beautifulSplits(vector<int> &nums)
     {
          return 1;
     }
};
// leetcode--------end
// void solve()
// {
//     int n = 0;
//     int k = 0;
//     int q = 0;
//     vector<int> A = make1("[1,2,3,1,2,3,1,2,3]");
//     vector<int> B = make1("");
//     vector<vector<int>> AA = make2("[[1,2],[2,5],[3,9],[1,15]]");
//     vector<vector<int>> BB = make2("");
//     Solution t;
//     // cout << t.beautifulSplits(A);
// }

ll mod;

ll POW(ll a, ll b)
{
     a %= mod;
     if (b == 0)
          return 1;
     if (b % 2 == 0)
          return POW((a * a) % mod, b / 2) % mod;
     else
          return (POW((a * a) % mod, b / 2) % mod * a) % mod;
}

void solve()
{
     ll base, c0, k;
     cin >> base >> c0 >> mod;
     vector<ll> c(mod + 1);
     vector<ll> cw(mod + 1);
     vector<ll> sum(mod + 1, 0);
     vector<bool> vis(mod + 1, 0);
     c[0] = c0;
     ll sum0 = 0;
     ll sum1 = 0;
     ll tmpC = 0;
     ll tmpi = 0;
     for (int i = 1; i <= mod; ++i)
     {
          c[i] = POW(base, c[i - 1]);
          sum[i] = sum[i - 1] + c[i];
          if (vis[c[i]] == 0)
               vis[c[i]] = 1;
          else
          {
               sum1 = cw[c[i]] - c[i];
               sum0 -= sum1;
               tmpC = c[i];
               tmpi = i;
               break;
          }
          sum0 += c[i];
          cw[c[i]] = sum0;
     }

     int Min = -1e9;

     vector<ll> sumla(mod + 1, 0);
     for (int i = 1; i <= mod; ++i)
     {
          if (c[i] == tmpC)
          {
               Min = i - 1;
               break;
          }
     }
     ll num = tmpi - Min - 1;

     for (int i = Min + 1; i <= tmpi; ++i)
     {
          sumla[i - Min] = sumla[i - Min - 1] + c[i];
     }

     int q;
     cin >> q;
     sum1 %= mod;
     sum0 %= mod;
     for (int i = 0; i < q; ++i)
     {
          cin >> k;
          if (k <= Min)
          {
               cout << sum[k] % mod << endl;
          }
          else
          {
               cout << (sum1 + ((((k - Min) / num) % mod) * sum0) % mod + sumla[((k - Min) % num)] % mod) % mod << endl;
          }
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
