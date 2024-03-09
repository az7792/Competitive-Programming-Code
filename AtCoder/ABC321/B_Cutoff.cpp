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
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n, 0);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= 100; ++i)
    {
        vector<int> tmp = a;
        tmp[n - 1] = i;
        sort(all(tmp));
        ll sum = 0;
        for (int i = 1; i < n - 1; ++i)
        {
            sum += tmp[i];
        }
        if (sum >= x)
        {
            cout << i;
            return;
        }
    }
    cout << -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}