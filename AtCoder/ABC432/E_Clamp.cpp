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

struct BIT
{
     int n;
     vector<int> D;
     vector<ll> S;
     BIT(int N)
     {
          n = N;
          D.resize(n + 1);
          S.resize(n + 1);
     }
     int lowbit(int x)
     {
          return x & (-x);
     }
     void add(int x, int v)
     {
          ll tmp = 1ll * x * v;
          while (x <= n)
          {
               D[x] += v;
               S[x] += tmp;
               x += lowbit(x);
          }
     }

     pair<int, ll> query(int x) // 查询[1,x]的<数量，和>
     {
          pair<int, ll> res = {0, 0};
          while (x)
          {
               res.first += D[x];
               res.second += S[x];
               x -= lowbit(x);
          }
          return res;
     }
};
void solve()
{
     int n, q;
     cin >> n >> q;

     vector<int> a(n);
     cin >> a;

     BIT bit(5e5 + 10);
     for (auto v : a)
          bit.add(v + 1, 1);

     while (q--)
     {
          int op;
          cin >> op;

          if (op == 1)
          {
               int x, y;
               cin >> x >> y;
               bit.add(a[x - 1] + 1, -1);
               a[x - 1] = y;
               bit.add(a[x - 1] + 1, 1);
          }
          else
          {
               ll l, r;
               cin >> l >> r;
               if(l > r){
                    cout << n * l <<endl;
                    continue;
               }
               l++, r++;
               auto t1 = bit.query(r);     // 1-r
               auto t2 = bit.query(l - 1); // 1 - l-1
               ll s1 = (l - 1) * t2.first;
               ll s2 = (t1.second - t1.first) - (t2.second - t2.first);
               ll s3 = (r - 1) * (n - t1.first);
               cout << s1 + s3 + s2 << endl;
          }
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