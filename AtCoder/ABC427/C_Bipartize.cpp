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

void solve()
{
     int n, m;
     cin >> n >> m;
     int g[10][10]{0};
     for (int i = 0; i < m; i++)
     {
          int u, v;
          cin >> u >> v;
          u--, v--;
          g[u][v] = 1;
          g[v][u] = 1;
     }
     int Min = 1e9;
     for (int i = 0; i < (1 << n); ++i)
     {
          bitset<10> bit(i);
          int ct=0;

          for(int j=0;j<n;++j){
               for(int k=0;k<n;++k){
                   if(g[j][k] && bit[j] == bit[k])ct++; 
               }
          }
          Min = min(Min, ct/2);
     }
     cout << Min;
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