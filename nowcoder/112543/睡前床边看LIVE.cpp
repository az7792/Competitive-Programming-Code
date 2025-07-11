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
bool ok(vector<int> &a, int l, int r)
{
     for (int i = l + 1; i <= r; ++i)
     {
          if (a[i] != a[i - 1])
               return false;
     }
     return true;
}

void solve()
{
     int n;
     cin >> n;
     vector<int> a(n + 1, 0), b(n + 1, n - 1);
     map<int, int> mp;
     for (int i = 1; i <= n; ++i)
     {
          cin >> a[i];
          mp[a[i]]++;
     }
     if (mp.size() >= 3)
     {
          cout << "Lie\n";
          return;
     }
     b[0] = 0;
     if (a == b) // n个n-1
     {
          cout << "Other\n";
          return;
     }

     sort(a.begin() + 1, a.end());
     int Max = *a.rbegin();

     if (Max + 1 <= n && Max >= 1 && ok(a, Max + 1, n))
     {
          if (a[1] >= Max - 1 && a[1] <= max(Max - 1, n - Max) && ok(a, 1, Max))
          {
               cout << "Other\n";
               return;
          }
     }
     cout << "Lie\n";
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
