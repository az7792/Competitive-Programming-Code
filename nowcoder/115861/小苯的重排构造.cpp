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
     int n, k;
     cin >> n >> k;
     vector<int> a(n + 1);
     int ct[3] = {0};
     for (int i = 1; i <= n; ++i)
     {
          cin >> a[i];
          if (a[i] == 1)
               ct[1]++;
          else
               ct[2]++;
     }
     int n2 = k - n + 1;
     if (n2 < 0)
     {
          cout << -1;
          return;
     }
     if (n2 != 0 && ct[2] < n2 + 1)
     {
          cout << -1;
          return;
     }
     vector<int> ans;
     if (n2 != 0)
     {
          for (int i = 0; i <= n2; ++i)
          {
               ans.push_back(2);
               ct[2]--;
               if (ct[2] < 0)
               {
                    cout << -1;
                    return;
               }
          }
     }
     int n1 = k - n2 * 2;
     // cout << n1 << " " << n2 << endl;
     // for (auto v : ans)
     //      cout << v << " ";
     while (1)
     {
          if (ct[1] == 0 && ct[2] > 0)
          {
               cout << -1;
               return;
          }
          if (ct[1] == 0)
          {
               break;
          }
          ans.push_back(1);
          ct[1]--;
          if (ct[2] >= 1)
          {
               ans.push_back(2);
               ct[2]--;
          }
     }
     for (auto v : ans)
          cout << v << " ";
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
