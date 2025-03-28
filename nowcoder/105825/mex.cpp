#include <bits/stdc++.h>
using namespace std;
vector<int> make1(string strArr);
vector<vector<int>> make2(string strArr);
#define endl '\n'
//  leetcode--------start
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

ll getMex(vector<ll> &a)
{
     sort(all(a));
     ll mex = 0;
     for (int i = 0; i < a.size(); i++)
     {
          if (a[i] > mex)
          {
               break;
          }
          else if (a[i] < mex)
               continue;
          mex++;
     }
     return mex;
}
ll get(vector<ll> a)
{
     int n = a.size();
     sort(all(a));
     if (a[0] == a[n - 1])
          return 0;
     else if (a[0] != 0)
          return -1;
     ll ans = 0;
     while (true)
     {
          sort(all(a));
          if (a[0] == a[n - 1])
               break;
          ll mex = getMex(a);
          for (auto &v : a)
               v = max(0ll, v - mex);
          ans++;
     }
     return ans;
}

void solve()
{
     ll n, testAns;
     cin >> n;
    // n = 10;
     ll ji = 0, mex = 0;
     vector<ll> a(n, 0);
     for (int j = 0; j < n; j++)
     {
          cin >> a[j];
          //a[j] = rand() % 10;
     }
     //testAns = get(a);
     mex = getMex(a);
     if (a[0] == a.back())
     {
          cout << "0" << endl;
          return;
     }
     else if (mex == 0)
     {
          cout << -1 << endl;
          return;
     }
     ll ans = 1;
     {
          ji += mex;
     }
     ll i = 0;
     while (i < n && a[i] - ji <= 0)
     {
          i++;
     }
     ll tmp = 0;
     while (i < n)
     {
          if (a[i] - ji > 1)
          {
               tmp = a[i] - ji - 1;
               ans += tmp;
               ji += tmp;
          }
          mex = 1;
          while (i < n)
          {
               if (a[i] - ji > mex)
                    break;
               else if (a[i] - ji < mex)
               {
                    i++;
               }
               else
               {
                    mex++;
                    i++;
               }
          }
          ji += mex;
          ans++;
     }
     // if(ans != testAns)
     // {
     //      cout << "error" << endl;
     // }
     cout << ans << endl;
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
