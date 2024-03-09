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
    ll n;
    cin >> n;
    ll L = 2, R = 2e9, mid;
    while (L < R)
    {
        mid = (L + R + 1) / 2;
        ll tmp = (mid * mid - mid) / 2;
        if (tmp > n)
            R = mid - 1;
        else if (tmp == n)
        {
            cout << mid << endl;
            return;
        }
        else
        {
            L = mid;
        }
    }
    cout << L + (n - (L * L - L) / 2) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}