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

vector<int> sum0(600, 0);
vector<int> sum1(600, 0);

int G1(int l, int r)
{
     if (l == 0)
          return sum1[r];
     return sum1[r] - sum1[l - 1];
}
int G0(int l, int r)
{
     if (l == 0)
          return sum0[r];
     return sum0[r] - sum0[l - 1];
}

int get01(string &str, int l, int r)
{
     int ans = 1e9;
     for (int i = l; i < r; ++i)
     {
          ans = min(ans, G1(l, i) + G0(i + 1, r));
     }
     return ans;
}

int get10(string &str, int l, int r)
{
     int ans = 1e9;
     for (int i = l; i < r; ++i)
     {
          ans = min(ans, G0(l, i) + G1(i + 1, r));
     }
     return ans;
}

void solve()
{
     int n;
     cin >> n;
     string str;
     cin >> str;
     if (str[0] == '1')
          sum1[0] = 1;
     else
          sum0[0] = 1;

     for (int i = 1; i < str.size(); ++i)
     {
          if (str[i] == '1')
          {
               sum1[i] = sum1[i - 1] + 1;
               sum0[i] = sum0[i - 1];
          }
          else
          {
               sum0[i] = sum0[i - 1] + 1;
               sum1[i] = sum1[i - 1];
          }
     }

     // 1010
     // 0101
     int ans = INT_MAX;
     for (int i = 0; i < str.size() - 2; ++i)
     {
          int ans1 = get10(str, 0, i);
          int ans2 = get10(str, i + 1, str.size() - 1);
          ans = min(ans, ans1 + ans2);
     }

     for (int i = 0; i < str.size() - 2; ++i)
     {
          int ans1 = get01(str, 0, i);
          int ans2 = get01(str, i + 1, str.size() - 1);
          ans = min(ans, ans1 + ans2);
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
