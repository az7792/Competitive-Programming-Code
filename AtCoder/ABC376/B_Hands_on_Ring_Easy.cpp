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
ll n, q, t;

ll LL(ll L, ll R, ll p)
{
     ll sum = 0;
     while (1)
     {
          if (L == R)
               return 1e9;
          if (L == p)
               return sum;
          L = (L + 1) % n;
          sum++;
     }
}
ll RR(ll L, ll R, ll p)
{
     ll sum = 0;
     while (1)
     {
          if (L == R)
               return 1e9;
          if (L == p)
               return sum;
          L = (L - 1 + n) % n;
          sum++;
     }
}
void solve()
{
     ll L = 0, R = 1, ans = 0;
     cin >> n >> q;
     char h;

     while (q--)
     {
          cin >> h >> t;
          t--;
          if (h == 'L')
          {
               ans += min(LL(L, R, t), RR(L, R, t));
               L = t;
          }
          else
          {
               ans += min(LL(R, L, t), RR(R, L, t));
               R = t;
          }
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
