#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    ll n, p, l, t;
    cin >> n >> p >> l >> t;
    ll ct = (n + 6) / 7;
    ll sum = n * l + t * ct;
    ll pu = n - ct;
    ll x = (sum - p) / l;
    if (x <= pu)
    {
        cout << x << endl;
    }
    else
    {
        n -= pu;
        sum -= pu * l;
        x = (sum - p) / l;
        if (x <= n / 2)
        {
            cout << pu + x << endl;
        }
        else
        {
            ll N = n;
            ll ans = (n / 2);
            sum -= l * (n / 2);
            n -= (n / 2);
            if (N % 2 == 1)
            {
                if (sum - l-t >= p)
                {
                    n--;
                    sum -= (l+t);
                    ans++;
                }
                else
                {
                    cout << pu + ans << endl;
                    return;
                }
            }

            x = (sum - p) / (2 * t + l);
            cout << pu + ans + x << endl;
        }
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
