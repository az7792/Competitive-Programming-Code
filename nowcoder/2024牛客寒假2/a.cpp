#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    if (a == 150)
        ans += 1;
    else if (a == 200)
        ans += 2;
    if (b == 45)
        ans += 2;
    else if (b >= 34)
        ans += 1;
    if (c == 45)
        ans += 2;
    else if (c >= 34)
        ans += 1;
    cout << ans << endl;
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
