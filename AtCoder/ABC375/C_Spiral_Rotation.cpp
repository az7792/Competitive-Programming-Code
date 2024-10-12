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
     int L = 0, R = 1;
     vector<vector<vector<char>>> g(2, vector<vector<char>>(n + 2, vector<char>(n + 2, 0)));
     for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= n; ++j)
               cin >> g[L][i][j];
     function<void(int, int)> z90 = [&](int p, int k)
     {
          int sx, sy, ax, ay;
          if (k == 0)
          {
               sx = ax = sy = ay = p;
               for (int i = 0; i < n + 2 - p * 2; ++i)
               {
                    g[R][ax][ay] = g[L][sx][sy];
                    sy++;
                    ay++;
               }
               sy--, ay--;
               for (int i = 0; i < n + 2 - p * 2; ++i)
               {
                    g[R][ax][ay] = g[L][sx][sy];
                    sx++;
                    ax++;
               }
               sx--, ax--;
               for (int i = 0; i < n + 2 - p * 2; ++i)
               {
                    g[R][ax][ay] = g[L][sx][sy];
                    sy--;
                    ay--;
               }
               sy++, ay++;
               for (int i = 0; i < n + 2 - p * 2; ++i)
               {
                    g[R][ax][ay] = g[L][sx][sy];
                    sx--;
                    ax--;
               }
               sx++, ax++;
          }
          else
          {
               sx = sy = p;
               ax = p, ay = n + 1 - p;
               for (int i = 0; i < n + 2 - p * 2; ++i)
               {
                    g[R][ax][ay] = g[L][sx][sy];
                    sy++;
                    ax++;
               }
               sy--, ax--;
               for (int i = 0; i < n + 2 - p * 2; ++i)
               {
                    g[R][ax][ay] = g[L][sx][sy];
                    sx++;
                    ay--;
               }
               sx--, ay++;
               for (int i = 0; i < n + 2 - p * 2; ++i)
               {
                    g[R][ax][ay] = g[L][sx][sy];
                    sy--;
                    ax--;
               }
               sy++, ax++;
               for (int i = 0; i < n + 2 - p * 2; ++i)
               {
                    g[R][ax][ay] = g[L][sx][sy];
                    sx--;
                    ay++;
               }
               sx++, ay--;
          }
     };

     int quan = 0;
     vector<vector<char>> ans(n + 2, vector<char>(n + 1, ' '));
     for (int i = 1; i <= n / 2; ++i)
     {

          int xp = 0;
          L = 0, R = 1;
          quan++;
          // 选择i圈
          if (quan % 4 == 0)
          {
               z90(i, 0);
               swap(L, R);
               xp = (xp + 1) % 2;
          }
          else
          {
               for (int j = 1; j <= quan % 4; ++j)
               {
                    z90(i, 1);
                    swap(L, R);
                    xp = (xp + 1) % 2;
               }
          }
          //----
          {
               int sx, sy, ax, ay;
               sx = ax = sy = ay = i;
               for (int jj = 0; jj < n + 2 - i * 2; ++jj)
               {
                    ans[ax][ay] = g[xp][sx][sy];
                    sy++;
                    ay++;
               }
               sy--, ay--;
               for (int jj = 0; jj < n + 2 - i * 2; ++jj)
               {
                    ans[ax][ay] = g[xp][sx][sy];
                    sx++;
                    ax++;
               }
               sx--, ax--;
               for (int jj = 0; jj < n + 2 - i * 2; ++jj)
               {
                    ans[ax][ay] = g[xp][sx][sy];
                    sy--;
                    ay--;
               }
               sy++, ay++;
               for (int jj = 0; jj < n + 2 - i * 2; ++jj)
               {
                    ans[ax][ay] = g[xp][sx][sy];
                    sx--;
                    ax--;
               }
               sx++, ax++;
          }

          // for (int i = 1; i <= n; ++i)
          // {
          //      for (int j = 1; j <= n; ++j)
          //           cout << ans[i][j];
          //      cout << endl;
          // }
     }

     for (int i = 1; i <= n; ++i)
     {
          for (int j = 1; j <= n; ++j)
               cout << ans[i][j];
          cout << endl;
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
