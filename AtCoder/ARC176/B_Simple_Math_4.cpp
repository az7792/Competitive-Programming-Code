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
int ans[4] = {2, 4, 8, 6};
int Get(ll n)
{
    if (n == 0)
        return 1;
    n--;
    return ans[n % 4];
}
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if (n < m)
    {
        if (m - 1 == k && n == k)
            cout << 0 << endl;
        else
            cout << Get(n) << endl;
    }
    else
    {
        ll x = (n - m) % (m - k) == 0 ? (n - m) / (m - k) + 1 : (n - k - 1) / (m - k);
        n = n - x * (m - k);
        if (m - k == 1 && n == k)
            cout << 0 << endl;
        else
            cout << Get(n) << endl;
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
