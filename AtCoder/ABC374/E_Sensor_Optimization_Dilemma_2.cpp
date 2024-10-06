#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
     ll n, x;
     cin >> n >> x;
     vector<ll> a(n), p(n), b(n), q(n);
     for (int i = 0; i < n; ++i)
     {
          cin >> a[i] >> p[i] >> b[i] >> q[i];
          if (a[i] * q[i] <= b[i] * p[i])
          {
               swap(a[i], b[i]);
               swap(p[i], q[i]);
          }
     }

     function<bool(ll)> ok = [&](ll num) -> bool
     {
          ll sum = 0;
          for (int i = 0; i < n; ++i)
          {
               ll tot = 1e17;
               for (int j = 0; j <= 100; ++j)
               {
                    ll needB = j, needA = 0;
                    ll needNum = num - (needB * b[i]);
                    if (needNum >= 0)
                         needA = (needNum + a[i] - 1) / a[i];
                    tot = min(tot, needA * p[i] + needB * q[i]);
               }
               sum += tot;
               if (sum > x)
                    break;
          }

          return sum <= x;
     };

     ll L = 0, R = 1e10, mid;
     while (L < R)
     {
          mid = (L + R + 1) / 2;
          if (ok(mid))
               L = mid;
          else
               R = mid - 1;
     }
     cout << L;
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
