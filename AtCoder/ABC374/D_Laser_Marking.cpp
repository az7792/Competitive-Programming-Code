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
double Len(double d1, double d2, double d3, double d4)
{
     return std::sqrt(std::pow(d3 - d1, 2) + std::pow(d4 - d2, 2));
};
void solve()
{
     int n, s, t;
     cin >> n >> s >> t;
     vector<double> a(n), b(n), c(n), d(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i] >> b[i] >> c[i] >> d[i];
     vector<int> p(n);
     for (int i = 0; i < n; ++i)
          p[i] = i;
     vector<bool> LR(n, 0);
     double ans = 1e9;

     function<void(int)> dfs = [&](int inx)
     {
          if (inx == n)
          {
               double tmpans = 0;
               double x = 0, y = 0;
               double nx = 0, ny = 0;
               for (int i = 0; i < n; ++i) // p[i]
               {
                    if (LR[p[i]] == 0)
                    {
                         nx = a[p[i]], ny = b[p[i]];
                    }
                    else
                    {
                         nx = c[p[i]], ny = d[p[i]];
                    }
                    //
                    tmpans += Len(x, y, nx, ny) / s;
                    x = nx, y = ny;
                    //
                    if (LR[p[i]] == 1)
                    {
                         nx = a[p[i]], ny = b[p[i]];
                    }
                    else
                    {
                         nx = c[p[i]], ny = d[p[i]];
                    }
                    tmpans += Len(x, y, nx, ny) / t;
                    x = nx, y = ny;
               }
               ans = min(ans, tmpans);
               return;
          }
          // L
          LR[inx] = 0;
          dfs(inx + 1);

          // R
          LR[inx] = 1;
          dfs(inx + 1);
     };

     do
     {
          dfs(0);
     } while (next_permutation(all(p)));
     printf("%.10lf", ans);
}
int main()
{
     // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     srand(time(nullptr));
     int t = 1;
     // cin >> t;
     while (t--)
     {
          solve();
     }
     return 0;
}
