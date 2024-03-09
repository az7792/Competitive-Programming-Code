#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool nisp[10000010]; // false 是质数
vector<int> isp;
void init(int n) // 1-n的素数
{
    for (int i = 2; i <= n; ++i)
    {
        if (!nisp[i])
            isp.push_back(i);
        for (int j = 0; j < isp.size() && isp[j] * i <= n; ++j)
        {
            nisp[isp[j] * i] = true;
            if (i % isp[j] == 0)
                break;
        }
    }
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    if (r >= 4)
    {
        if (r - l + 1 >= 2)
        {
            for (ll i = r; i >= l; --i)
            {
                if (i % 2 == 0)
                {
                    cout << 2 << ' ' << i - 2 << endl;
                    return;
                }
            }
        }
        else
        {
            if (l % 2 == 0)
            {
                cout << l / 2 << ' ' << l / 2 << endl;
            }
            else
            {
                for (ll i = 2; i <= l / i; ++i)
                {
                    if(l%i==0)
                    {
                        cout << i << ' ' << l - i << endl;
                        return;
                    }
                }
                cout << -1 << endl;
            }
        }
    }
    else
    {
        cout << -1 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    // init(10000005);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}