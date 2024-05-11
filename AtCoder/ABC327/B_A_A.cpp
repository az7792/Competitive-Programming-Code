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
    ll n;
    cin >> n;
    for (ll i = 1; i <= 15; ++i)
    {
        ll tmp = n;
        for (int j = 1; j <= i; ++j)
        {
            if (tmp % i == 0)
                tmp /= i;
            else
            {
                tmp = 2;
                break;
            }
        }
        if (tmp == 1)
        {
            cout << i;
            return;
        }
    }
    cout << -1;
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
