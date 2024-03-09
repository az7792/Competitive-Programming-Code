#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, N;
    cin >> n;
    if (n == 1)
        cout << 3 << endl;
    else if (n == 2)
        cout << 5 << endl;
    else
    {
        n -= 2;
        N = (n + 2) / 3;
        cout << 4 * N + 3 + (n - 1) % 3 << endl;
    }
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