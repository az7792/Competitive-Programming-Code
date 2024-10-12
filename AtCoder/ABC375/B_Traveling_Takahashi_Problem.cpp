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
     vector<pair<double, double>> node;
     for (int i = 1; i <= n; ++i)
     {
          double a, b;
          cin >> a >> b;
          node.push_back({a, b});
     }
     double xx = 0, yy = 0, ans = 0;
     for (auto &[x, y] : node)
     {
          ans += sqrt(pow((x - xx), 2) + pow((y - yy), 2));
          xx = x, yy = y;
     }
     ans += sqrt(pow((xx), 2) + pow((yy), 2));
     printf("%.8lf", ans);
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
