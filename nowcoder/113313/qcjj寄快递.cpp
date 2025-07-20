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

void solve()
{
     int n;
     cin >> n;
     vector<double> a(n), b(n), e(n);
     for (int i = 0; i < n; ++i)
     {
          cin >> a[i] >> b[i];
     }
     double tmp = log(2.0);
     for (int i = 1; i < n; ++i)
     {
          e[i] = sqrt((a[i] - a[i - 1]) * (a[i] - a[i - 1]) + (b[i] - b[i - 1]) * (b[i] - b[i - 1]));
     }

     double ans = 0;
     for (int i = 1; i < n; ++i)
     {
          double x = log2(e[i] * tmp);
          if (x <= 0.0)
               ans += 2 * e[i];
          else
               ans += 2.0 * (x + e[i] / pow(2.0, x));
     }

     printf("%.7lf", ans);
}

int main()
{
     // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
