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
    vector<ll> a(10), b(9);
    ll s1 = 0, s2 = 0;
    for (int i = 1; i <= 9; ++i)
    {
        cin >> a[i];
        s1 += a[i];
    }
    for (int i = 1; i <= 8; ++i)
    {
        cin >> b[i];
        s2 += b[i];
    }
    cout << max(0ll, s1 - s2 + 1);
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
