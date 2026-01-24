#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 1e9 + 7;
// ll MOD = 998244353;

template <typename T>
std::istream &operator>>(std::istream &_in, std::vector<T> &_a)
{
     for (auto &v : _a)
          _in >> v;
     return _in;
}

template <typename T>
std::ostream &operator<<(std::ostream &_out, std::vector<T> &_a)
{
     if (!_a.empty())
          _out << _a[0];
     for (size_t i = 1; i < _a.size(); ++i)
          _out << " " << _a[i];
     return _out;
}
struct Node
{
     pair<ll, ll> point;
     int pos;
};
int getIdx(pair<ll, ll> pll)
{
     if (pll.first >= 0 && pll.second >= 0)
          return 0;
     else if (pll.first <= 0 && pll.second >= 0)
          return 1;
     else if (pll.first <= 0 && pll.second <= 0)
          return 2;
     else
          return 3;
}

bool cmp(const Node &a, const Node &b)
{
     return a.point.second * b.point.first > b.point.second * a.point.first;
}

void solve()
{
     int n, q;
     cin >> n >> q;
     vector<pair<ll, ll>> a(n + 1);
     vector<vector<Node>> arr(4);
     for (int i = 1; i <= n; i++)
     {
          cin >> a[i].first >> a[i].second;
          arr[getIdx(a[i])].push_back({a[i], i});
     }

     for (int i = 0; i < 4; ++i)
          sort(all(arr[i]), cmp);

     while (q--)
     {
          int s, e;
          cin >> s >> e;
          pair<ll, ll> p1 = a[s];
          pair<ll, ll> p2 = a[e];
          int idx1 = getIdx(p1);
          int idx2 = getIdx(p2);
          int pos1 = lower_bound(all(arr[idx1]), Node{p1, 0}, cmp) - arr[idx1].begin();
          int pos2 = upper_bound(all(arr[idx2]), Node{p2, 0}, cmp) - arr[idx2].begin() - 1;
          if (idx1 == idx2)
          {
               if (pos1 <= pos2)
                    cout << pos2 - pos1 + 1 << endl;
               else
               {
                    ll ans = pos2 + 1 + (arr[idx1].size() - pos1);
                    for (int j = 0; j < 4; ++j)
                    {
                         if (j != idx1)
                              ans += arr[j].size();
                    }
                    cout << ans << endl;
               }
               continue;
          }
          ll ans = 0;
          // p1 p1 + 1 ... p2
          ll sum = arr[idx1].size() - pos1;
          ll sum1 = pos2 + 1;
          ans += sum + sum1;
          for (int j = (idx1 - 1 + 8) % 4; j != idx2; j = ((j - 1) % 4 + 4) % 4)
          {
               ans += arr[j].size();
          }
          cout << ans << endl;
     }
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