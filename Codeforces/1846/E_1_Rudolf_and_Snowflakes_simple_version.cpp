#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool f[MAX];
void init()
{
    for (ll k = 2; k <= 1e6; ++k)
    {
        ll la = k;
        ll sum = 1 + k;
        while (true)
        {
            la *= k;
            sum += la;
            if (sum <= 1e6)
                f[sum] = true;
            else
                break;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    if (f[n])
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}