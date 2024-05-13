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
    ll a, b, r, x, y, R;
    cin >> a >> b >> r >> x >> y >> R;
    ll len = (a - x) * (a - x) + (b - y) * (b - y);
    ll RR = (r + R) * (r + R);
    if (a == x && b == y && r == R)
        cout << -1;
    else if (len > RR)
        cout << 4;
    else if (len == RR)
        cout << 3;
    else if (len == (R - r) * (R - r))
        cout << 1;
    else if (len < (R - r) * (R - r))
        cout << 0;
    else
        cout << 2;
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
