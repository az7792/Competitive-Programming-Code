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
template <typename T>
T gcd(T a, T b)
{
     while (b != 0)
     {
          T temp = b;
          b = a % b;
          a = temp;
     }
     return a;
}
struct pair_hash
{
     size_t operator()(const pii &p) const noexcept
     {
          return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
     }
};
// leetcode--------end
void solve()
{
     int n;
     cin >> n;
     vector<pii> pos(n);
     for (int i = 0; i < n; ++i)
          cin >> pos[i].first >> pos[i].second;
     unordered_map<pii, unordered_map<ll, int>, pair_hash> mp;
     unordered_map<pii, int, pair_hash> numMp;
     for (int i = 0; i < n; ++i)
          for (int j = i + 1; j < n; ++j)
          {
               int tx = pos[j].first - pos[i].first;
               int ty = pos[j].second - pos[i].second;
               pii tmp;
               if (tx == 0)
               {
                    tmp = {1, 0};
               }
               else
               {
                    int tg = gcd(abs(tx), abs(ty));
                    if (tx < 0)
                         tx = -tx, ty = -ty;
                    tx /= tg, ty /= tg;
                    tmp = {ty, tx};
               }
               ll len = 1ll * abs(pos[j].second - pos[i].second) + abs(pos[j].first - pos[i].first);
               mp[tmp][len]++;
               numMp[tmp]++;
          }
     ll ans = 0;
     ll ans1 = 0;
     for (auto &v : mp)
     {
          int sum = numMp[v.first];
          for (auto &&vv : v.second)
          {
               ans += vv.second * (sum - vv.second);
               ans1 += vv.second * (vv.second - 1ll);
          }
     }
     cout << ans / 2 + ans1 / 4;
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
