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
     ll a, b, c;
};
struct cmp
{
     bool operator()(const Node &a, const Node &b) const
     {
          return a.b > b.b;
     }
};
void solve()
{
     ll n, k;
     cin >> n >> k;
     vector<Node> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i].a >> a[i].b >> a[i].c;
     priority_queue<Node, vector<Node>, cmp> Q;
     int ct = 0;
     ll ti = 0;
     for (int i = 0; i < n; ++i)
     {
          ti = max(ti,a[i].a);
          if (Q.empty())
          {
               cout << a[i].a << endl;
               Q.push({0, ti + a[i].b, a[i].c});
               ct += a[i].c;
               continue;
          }
          while (1)
          {

               while (!Q.empty())
               {
                    if (Q.top().b <= ti)
                    {
                         ct -= Q.top().c;
                         Q.pop();
                    }
                    else
                         break;
               }

               if (ct + a[i].c <= k)
               {
                    cout << ti << endl;
                    Q.push({0, ti + a[i].b, a[i].c});
                    ct += a[i].c;
                    break;
               }
               else
               {
                    ti = Q.top().b;
                    ct -= Q.top().c;
                    Q.pop();
               }
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