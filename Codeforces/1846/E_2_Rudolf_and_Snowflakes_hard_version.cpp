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
unordered_map<ll, bool> f;
ll ct = 0;
void init()
{
    for (ll k = 2; k <= 1e6; ++k)
    {
        ll la = k;
        ll sum = 1ll + k;
        while (true)
        {
            ct++;
            if (la <= (ll)1e18 / k)
                la *= k;
            else
                break;
            sum += la;
            if (sum <= 1e18)
                f[sum] = true;
            else
                break;
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    if (n < 7)
        cout << "NO\n";
    else if (f[n])
        cout << "YES\n";
    else
    {
        ll L = 2, R = 1e9, k;
        n--;
        while (L <= R)
        {
            k = (L + R) / 2;
            if (k * k + k == n)
            {
                cout << "YES\n";
                return;
            }
            else if (k * k + k > n)
            {
                R = k - 1;
            }
            else
            {
                L = k + 1;
            }
        }
        cout << "NO\n";
    }
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