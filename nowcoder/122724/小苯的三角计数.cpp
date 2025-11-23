#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 998244353;

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

ll POW(ll a, ll b)
{
     a %= MOD;
     if (b == 0)
          return 1;
     if (b % 2 == 0)
          return POW((a * a) % MOD, b / 2) % MOD;
     else
          return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}

void solve()
{
     int n;
     cin >> n;
     vector<pair<ll, ll>> a(n);
     vector<ll> sum(n);

     ll ans = 0;

     for (int i = 0; i < n; ++i)
     {
          cin >> a[i].first >> a[i].second;
          if (a[i].second >= 3)
          {
               ans++; // 1
          }
     }

     sort(all(a), [&](const pair<ll, ll> &p, const pair<ll, ll> &q)
          { return p.first < q.first; });

     // sum[0] = a[0].second;
     // for (int i = 1; i < n; ++i)
     // {
     //      sum[i] = sum[i - 1] + a[i].second;
     // }

     for (int i = 0; i < n; ++i)
     {
          for (int j = i + 1; j < n; ++j)
          {
               // 2 2 1
               if (a[i].second >= 2 && a[j].first < 2 * a[i].first)
               {
                    ans++;
               }
               // 1 2 2
               if (a[j].second >= 2 && 2 * a[j].first > a[i].first)
               {
                    ans++;
               }
               // 1 2 3
               // a[i].first + a[j].first > a[k].first
               // (a[j].firsr , a[i].first + a[j].first)
               int pl = upper_bound(all(a), pair<ll, ll>{a[j].first, 1e10}) - a.begin();
               int pr = lower_bound(all(a), pair<ll, ll>{a[i].first + a[j].first, 0}) - a.begin();
               pr--;

               if(pl <= pr){
                    ans += pr - pl + 1;
               }

          }
     }

     cout << ans << endl;
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