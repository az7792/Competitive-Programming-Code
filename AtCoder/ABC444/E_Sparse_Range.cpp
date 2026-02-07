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

#define MAX 4e5 + 100
vector<int> num(MAX, 0); // i点的值
vector<int> Max(MAX, 0); // i点维护区间的最值
int N = 8;
int lowbit(int x)
{
     return x & (-x);
}
int q(int l, int r) // max[l,r]
{
     int res = 0;
     while (r >= l)
     {
          if (r - lowbit(r) + 1 >= l)
          {
               res = max(res, Max[r]);
               r -= lowbit(r);
          }
          else
          {
               res = max(res, num[r]);
               r--;
          }
     }
     return res;
}
void add(int p, int x) // updata( num[p] -> x)
{
     num[p] = x;
     // 更新当前结点维护的区间
     Max[p] = x;
     for (int j = 1; j < lowbit(p); j <<= 1)
          Max[p] = max(Max[p], Max[p - j]);
     // 用当前结点去更新包含当前结点的区间
     int tmp = p;
     p += lowbit(p);
     for (; p <= N; p += lowbit(p))
     {
          Max[p] = max(Max[p], Max[tmp]);
     }
}

const int MAXN = 4e5 + 5;
const int LOGN = 20;

int st_max[MAXN][LOGN];
int st_min[MAXN][LOGN];
int lg2[MAXN];

void st(int n, const vector<int> &a)
{
     lg2[1] = 0;
     for (int i = 2; i <= n; i++)
          lg2[i] = lg2[i / 2] + 1;

     for (int i = 1; i <= n; i++)
     {
          st_max[i][0] = a[i];
          st_min[i][0] = a[i];
     }

     for (int j = 1; j < LOGN; j++)
     {
          for (int i = 1; i + (1 << j) - 1 <= n; i++)
          {
               st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
               st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
          }
     }
}

int qmax(int l, int r)
{
     int k = lg2[r - l + 1];
     return max(st_max[l][k], st_max[r - (1 << k) + 1][k]);
}

int qmin(int l, int r)
{
     int k = lg2[r - l + 1];
     return min(st_min[l][k], st_min[r - (1 << k) + 1][k]);
}

void solve()
{
     int n, d;
     cin >> n >> d;
     vector<int> a(n + 1);
     for (int i = 1; i <= n; ++i)
     {
          cin >> a[i];
     }
     ll ans = 0;
     set<int> s;

     for (int R = 1, L = 1; R <= n; ++R)
     {
          while (!s.empty())
          {
               auto it = s.lower_bound(a[R]);
               bool ok = false;
               if (it != s.end() && *it - a[R] < d)
                    ok = true;
               if (it != s.begin() && a[R] - *prev(it) < d)
                    ok = true;

               if (!ok)
                    break;

               s.erase(a[L++]);
          }
          s.insert(a[R]);
          ans += (R - L + 1);
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