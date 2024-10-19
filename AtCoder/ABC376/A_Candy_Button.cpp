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
     ll n, c;
     cin >> n >> c;
     ll ans = 1;
     ll la = 0;
     cin >> la;
     ll tmp;
     for (int i = 2; i <= n; ++i)
     {
          cin >> tmp;
          if (tmp - la >= c)
          {
               ans++;
               //cout << la << " " << tmp << endl;
               la = tmp;
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
