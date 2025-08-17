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
template <class T>
T gcd(T a, T b)
{
     return b == 0 ? a : gcd(b, a % b);
}
void solve()
{
     int n, m, x;
     cin >> n >> m >> x;
     if (x < n)
     {
          cout << "-1\n";
          return;
     }
     vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(m + 1, vector<bool>(n * m + 1, 0)));
     vector<vector<vector<pii>>> path(n + 1, vector<vector<pii>>(m + 1, vector<pii>(n * m + 1, {0, 0})));
     vector<vector<vector<int>>> what(n + 1, vector<vector<int>>(m + 1, vector<int>(n * m + 1, 0)));

     // 前i,gcd(1,2,3...i) = j,sum = k
     // 从前面dp[i-1][j][k]过来的
     for (int i = 1; i <= m; ++i)
     {
          dp[1][i][i] = 1;
          what[1][i][i] = i;
     }
     for (int i = 2; i <= n; ++i)
          for (int j = 1; j <= m; ++j)      // 当前选择
               for (int k = 1; k <= m; ++k) // 前一个gcd(1,2,3...i-1)
               {
                    int now = gcd(k, j);
                    for (int l = 1; l <= x; ++l) // 前一个sum
                         if (dp[i - 1][k][l] && l + now <= x)
                         {
                              dp[i][now][l + now] = 1;
                              path[i][now][l + now] = {k, l};
                              what[i][now][l + now] = j;
                         }
               }
     int ans = -1;
     for (int i = 1; i <= m; ++i)
          if (dp[n][i][x])
          {
               ans = i;
               break;
          }
     if (ans == -1)
     {
          cout << "-1\n";
          return;
     }
     vector<int> vec;
     int tmpx = x;
     for (int i = n; i >= 1; --i)
     {
         // cout << i << " " << ans << " " << tmpx<<" "<<what[i][ans][tmpx]<<endl;
          vec.push_back(what[i][ans][tmpx]);

          int AA = path[i][ans][tmpx].first;
          int BB = path[i][ans][tmpx].second;
          ans = AA;
          tmpx = BB;
     }
     for (int i = n - 1; i >= 0; --i)
          cout << vec[i] << ' ';
}
int main()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     srand(time(nullptr));
     int t = 1;
     cin >> t;
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
