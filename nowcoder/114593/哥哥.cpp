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
     int n;
     cin >> n;
     string str;
     cin >> str;
     int num = 0;
     for (int i = 1; i < str.size(); ++i)
     {
          if (str[i - 1] == '0' && str[i] == '1')
               num++;
          else if (str[i - 1] == '1' && str[i] == '0')
               num++;
     }
     if (num >= 3)
     {
          cout << "0\n";
     }
     else if (num == 0)
     {
          cout << "2\n";
     }
     else if (num == 1)
     {
          int c0 = count(all(str), '0');
          int c1 = count(all(str), '1');
          if (c0 >= 3 || c1 >= 3)
               cout << "1\n";
          else
               cout << "2\n";
     }
     else
     {
          int c0 = count(all(str), '0');
          int c1 = count(all(str), '1');
          if (c0 == 1 || c1 == 1)
          {
               cout << "1\n";
          }
          else
          {
               if (str.size() == 4)
                    cout << "2\n";
               else
                    cout << "1\n";
          }
     }
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
