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
     unsigned long long x, y;
     cin >> x >> y;
     if (x == y)
     {
          cout << "0\n";
          return;
     }
     bitset<63> a(x);
     bitset<63> b(y);
     int aa = 0, bb = 0;
     for (int i = 0; i < 63; ++i)
     {
          if (a[i] == 0 && b[i] == 1)
               aa++;
          if (a[i] == 1 && b[i] == 0)
               bb++;
     }
     if (aa > 0 && bb > 0)
          cout << "2\n";
     else
          cout << "1\n";
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
