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
string S = "()";
void solve()
{
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    ll ct = m / k;
    if (ct <= ak)
    {
        cout << max((m - ct * k) - a1, 0ll) << endl;
    }
    else
    {
        m -= ak * k;
        if (a1 >= m)
        {
            cout << 0 << endl;
        }
        else
        {
            // m - xk <= a1
            if (m < k)
            {
                cout << m - a1 << endl;
            }
            else
            {
                //(m - a1)/k <=x
                ll x = (m - a1 + k - 1) / k;
                if (x * k > m)
                {
                    m = m - (x - 1) * k;
                    cout << (x - 1) + max(m - a1, 0ll) << endl;
                }
                else
                {
                    cout << x << endl;
                }
            }
        }
    }
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