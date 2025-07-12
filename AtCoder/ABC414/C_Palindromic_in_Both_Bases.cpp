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
     ll n;
     ll num;
     cin >> n >> num;
     vector<vector<ll>> a0(13);
     vector<vector<ll>> a(13);
     a0[1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
     a[1] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

     for (ll i = 0; i <= 9; ++i)
          a0[2].push_back(i * 10ll + i);

     for (ll i = 1; i <= 9; ++i)
          a[2].push_back(i * 10ll + i);

     ll shi[20];
     shi[0] = 1;
     for (ll i = 1; i <= 15; ++i)
     {
          shi[i] = shi[i - 1] * 10ll;
     }

     for (ll i = 3; i <= 12; ++i)
     {
          if (i % 2 == 0)
          {
               for (ll j = 0; j <= 9; ++j)
               {
                    for (auto &v : a0[i - 2])
                    {
                         a0[i].push_back(j * shi[i - 1] + v * 10 + j);
                    }
               }
               for (ll j = 1; j <= 9; ++j)
               {
                    for (auto &v : a0[i - 2])
                    {
                         a[i].push_back(j * shi[i - 1] + v * 10 + j);
                    }
               }
          }
          else
          {
               for (ll j = 0; j <= 9; ++j)
               {
                    for (auto &v : a0[i - 2])
                    {
                         a0[i].push_back(j * shi[i - 1] + v * 10 + j);
                    }
               }
               for (ll j = 1; j <= 9; ++j)
               {
                    for (auto &v : a0[i - 2])
                    {
                         a[i].push_back(j * shi[i - 1] + v * 10 + j);
                    }
               }
          }
     }

     ll sum = 0;
     for (ll i = 1; i <= 12; ++i)
     {
          for (auto &v : a[i])
          {
               if (v > num)
               {
                    continue;
               }

               vector<ll> str;
               ll tmp = v;
               while (tmp != 0)
               {
                    str.push_back(tmp % n);
                    tmp /= n;
               }
               bool ok = 1;
               ll l = 0, r = str.size() - 1;
               while (l <= r)
               {
                    if (str[l] != str[r])
                    {
                         ok = false;
                         break;
                    }
                    l++, r--;
               }

               if (ok)
                    sum += v;
          }
     }
     cout << sum;
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
