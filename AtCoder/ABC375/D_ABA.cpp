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
     string str;
     cin >> str;
     int n = str.size();
     str = "*" + str;
     vector<vector<ll>> L(n + 10, vector<ll>(26, 0));
     vector<vector<ll>> R(n + 10, vector<ll>(26, 0));
     for (int i = 1; i <= n; ++i)
     {
          L[i] = L[i - 1];
          L[i][str[i] - 'A']++;
     }
     for (int i = n; i >= 1; --i)
     {
          R[i] = R[i + 1];
          R[i][str[i] - 'A']++;
     }
     ll ans = 0;
     for (int i = 1; i <= n; ++i)
     {
          for (int j = 0; j < 26; ++j)
          {
               ans += L[i - 1][j] * R[i + 1][j];
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
