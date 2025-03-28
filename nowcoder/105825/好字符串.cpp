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
#define tiii tuple<int, int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 1e9 + 7;
// leetcode--------end
// void solve()
// {
//     int n, q, k;
//     n = q = k = 0;
//     vector<int> A = make1("[4,2,5]");
//     vector<int> B = make1("[3,5,4]");
//     vector<vector<int>> AA = make2("[[1,101,10],[2,102,20],[3,103,15]]");
//     vector<vector<int>> BB = make2("[[3,0,49],[8,12,19]]");
//     vector<vector<int>> CC = make2("[[8,10,1],[1,3,2],[5,6,4]]");
//     Solution t;
//     cout << t.numOfUnplacedFruits(A, B);
// }
void solve()
{
     int n;
     cin >> n;
     string s;
     cin >> s;
     int sum = 0;
     for (int i = 1; i < s.size(); i++)
     {
          if (s[i] == s[i - 1])
          {
               sum++;
          }
     }
     if (sum == 0)
          cout << "YES\n";
     else if (sum == 1)
          cout << "YES\n";
     else
          cout << "NO\n";
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
