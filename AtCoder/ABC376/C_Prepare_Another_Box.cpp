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
     ll n;
     cin >> n;
     vector<ll> a(n);
     multiset<ll> b;
     for (int i = 0; i < n; ++i)
          cin >> a[i];
     for (ll i = 0, tmp; i < n - 1; ++i)
     {
          cin >> tmp;
          b.insert(tmp);
     }
     sort(all(a));
     int L = 0, R = 1e10, mid;
     while (L < R)
     {
          mid = (L + R) / 2;
          bool ok = true;
          b.insert(mid);
          int sp = 0;
          for (auto &v : b)
          {
               if (v < a[sp])
               {
                    ok = false;
                    break;
               }
               sp++;
          }
          if (ok)
               R = mid;
          else
               L = mid + 1;
          b.erase(b.find(mid));
          if (L > 1e9 + 10)
               break;
     }
     if (L > 1e9 + 10)
          cout << -1;
     else
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
