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
     int n, m;
     cin >> n >> m;
     vector<string> str(n);
     for (int i = 0; i < n; ++i)
          cin >> str[i];
     vector<int> s(n, 0);
     for (int i = 0; i < m; ++i)
     {
          int c1 = 0, c0 = 0;
          for (int j = 0; j < n; ++j)
               if (str[j][i] == '1')
                    c1++;
          c0 = n - c1;
          if (c1 == 0 || c0 == 0)
               continue;
          if (c1 < c0)
          {
               for (int j = 0; j < n; ++j)
                    if (str[j][i] == '1')
                         s[j]++;
          }
          else
          {
               for (int j = 0; j < n; ++j)
                    if (str[j][i] == '0')
                         s[j]++;
          }
     }
     int Max = *max_element(all(s));
     vector<int> ans;
     for (int i = 0; i < n; ++i)
          if (s[i] == Max)
               ans.push_back(i + 1);
     for (auto v : ans)
          cout << v << ' ';
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
