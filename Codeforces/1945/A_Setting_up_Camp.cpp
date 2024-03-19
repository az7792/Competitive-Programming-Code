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
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    ans = a + (b / 3);
    if (b % 3 != 0)
    {
        if (3 - (b % 3) > c)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            cout << ans + 1 + (c - (3 - (b % 3)) + 2) / 3 << endl;
        }
    }
    else
    {
        cout << ans + (c + 2) / 3 << endl;
    }
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
