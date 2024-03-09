#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
#define fi first
#define se second
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, k;
    cin >> n >> k;
    if (n == 1 || n + n - 1 < k)
        cout << "0\n";
    else
    {
        if (n >= k)
            cout << (k + 1) / 2 - 1 << endl;
        else
            cout << (2 * n - k + 1) / 2 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/