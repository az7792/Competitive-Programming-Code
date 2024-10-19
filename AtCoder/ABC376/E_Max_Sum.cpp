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
     int n, k;
     cin >> n >> k;
     vector<pair<ll, ll>> ab(n + 1);
     for (int i = 1; i <= n; ++i)
          cin >> ab[i].first;
     for (int i = 1; i <= n; ++i)
          cin >> ab[i].second;
     sort(ab.begin() + 1, ab.end());
     ll ans = 1e18;
     if (k == 1)
     {
          for (int i = 1; i <= n; ++i)
          {
               ans = min(ans, ab[i].first * ab[i].second);
          }
          cout << ans << endl;
          return;
     }
     multiset<ll> sum;
     ll tot = 0;
     for (int i = 1; i < k; ++i)
     {
          sum.insert(ab[i].second);
          tot += ab[i].second;
     }
     for (int i = k; i <= n; ++i)
     {
          ans = min(ans, ab[i].first * (tot + ab[i].second));
          ll Max = *sum.rbegin();
          if (ab[i].second < Max)
          {
               sum.erase(sum.find(Max));
               sum.insert(ab[i].second);
               tot -= Max;
               tot += ab[i].second;
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
