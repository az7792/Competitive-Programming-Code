#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<ll, ll> mp;
int tx[] = {0, 0, -1, 1};
int ty[] = {-1, 1, 0, 0};
void solve()
{
    int n, m, x, y, x1, y1;
    cin >> n >> m;
    cin >> x >> y >> x1 >> y1;
    int a1 = 0, a2 = 0;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + tx[i];
        int ny = y + ty[i];
        if (nx <= n && nx >= 1 && ny <= m && ny >= 1)
            a1++;
    }
    for (int i = 0; i < 4; ++i)
    {
        int nx = x1 + tx[i];
        int ny = y1 + ty[i];
        if (nx <= n && nx >= 1 && ny <= m && ny >= 1)
            a2++;
    }
    cout << min(a1, a2) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/