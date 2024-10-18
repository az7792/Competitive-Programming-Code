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
     ll n, k, h, L, R;
     cin >> n >> k >> h >> L >> R;
     vector<ll> ans(n + 1, 0);
     ll Max = h + k * R, Min = h + k * L;
     if (0 < Min || 0 > Max)
     {
          cout << "impossible\n";
          return;
     }

     if (L < 0 && R < 0)
     {
          swap(L, R);
          L = -L, R = -R;
          vector<ll> tmp(k, L);
          ll tmpH = L * k;
          for (int i = 0; i < k; ++i)
          {
               tmp[i] += min((h - tmpH), (R - L));
               tmpH += tmp[0] - L;
               ans[i + 1] = -tmp[i];
          }
     }
     else
     {
          for (int i = 1; i <= k; ++i)
          {
               if (i == k)
                    ans[i] = -min((h), (-L));
               else
                    ans[i] = -min((h - 1), (-L));
               h += ans[i];
          }
     }
     for (int i = 1; i <= n; ++i)
          cout << ans[i] << " ";
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
