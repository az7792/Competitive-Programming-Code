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
     string a, b;
     cin >> a >> b;
     if (a == b)
     {
          cout << "0";
          return;
     }
     else
     {
          for (int i = 0; i < min(a.size(), b.size()); ++i)
          {
               if (a[i] != b[i])
               {
                    cout << i + 1;
                    return;
               }
          }
     }
     cout << min(a.size(), b.size()) + 1;
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
