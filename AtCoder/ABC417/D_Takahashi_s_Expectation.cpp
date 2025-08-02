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
void solve()
{
     // dp[i][j] x,[j,n]
     int n;
     cin >> n;
     vector<int> p(n), a(n), b(n);
     vector<vector<int>> dp(501, vector<int>(n + 1, 0));
     vector<int> sum(n, 0);
     for (int i = 0; i < n; ++i)
     {
          cin >> p[i] >> a[i] >> b[i];
          sum[i] = i == 0 ? b[i] : sum[i - 1] + b[i];
     }

     for (int i = 0; i <= 500; ++i)
     {
          dp[i][n - 1] = i > p[n - 1] ? max(0, i - b[n - 1]) : i + a[n - 1];
     }

     for (int j = n - 2; j >= 0; --j)
     {
          for (int i = 0; i <= 500; ++i)
          {
               if (i > p[j]) //-
                    dp[i][j] = dp[max(0, i - b[j])][j + 1];
               else // i <= p[j]
               {
                    //+
                    if (i + a[j] <= 500)
                         dp[i][j] = dp[i + a[j]][j + 1];
                    else
                    {
                         int tmp = i + a[j];
                         int P = lower_bound(sum.begin() + j + 1, sum.begin() + n, tmp - 500 + sum[j]) - sum.begin();
                         if (P == n)
                              dp[i][j] = max(0, i + a[j] - (sum[n - 1] - sum[j]));
                         else if (P + 1 == n)
                              dp[i][j] = max(0, i + a[j] - (sum[P] - sum[j]));
                         else
                              dp[i][j] = dp[max(0, i + a[j] - (sum[P] - sum[j]))][P + 1];
                    }
               }
               // cout << i << " " << j << endl;
          }
     }

     int q;
     ll x;
     cin >> q;
     while (q--)
     {
          cin >> x;
          if (x <= 500)
               cout << dp[x][0] << endl;
          else
          {
               int tmp = x;
               int P = lower_bound(sum.begin(), sum.begin() + n, tmp - 500) - sum.begin();
               if (P == n)
                    cout << tmp - sum[n - 1] << endl;
               else if (P + 1 == n)
                    cout << max(0, tmp - sum[P]) << endl;
               else
                    cout << dp[max(0, tmp - sum[P])][P + 1] << endl;
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
