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
     int n;
     cin >> n;
     vector<ll> a(n);
     ll sum = 0;
     for (int i = 0; i < n; ++i)
     {
          cin >> a[i];
          sum += a[i];
     }
     set<ll> s;
     for (int i = 0; i < n; ++i)
     {
          vector<ll> tmp;
          for (auto v : s)
               tmp.push_back(v);
          s.insert(a[i]);
          for (auto v : tmp)
          {
               s.insert(v + a[i]);
          }
     }
     ll Min = 1e18;
     for (auto v : s)
     {
          Min = min(Min, max(v, sum - v));
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
