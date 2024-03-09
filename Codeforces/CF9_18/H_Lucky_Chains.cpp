#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e7 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool nisp[3300];
vector<int> isp;
void init()
{
    for (int i = 2; i <= 3200; ++i)
    {
        if (!nisp[i])
            isp.push_back(i);
        for (int j = 0; j < isp.size() && i * isp[j] <= 3200; ++j)
        {
            nisp[i * isp[j]] = true;
            if (i % isp[j] == 0)
                break;
        }
    }
}
void solve()
{
    int x, y;
    cin >> x >> y;
    if (y - x == 1)
        cout << "-1\n";
    else if (gcd(x, y) > 1)
        cout << "0\n";
    else
    {
        int tmp = y - x, Min = 1e9;
        for (int i = 0; i < isp.size() && isp[i] <= sqrt(tmp); ++i)
        {
            if (tmp % isp[i] == 0)
            {
                Min = min(Min, isp[i] - x % isp[i]);
            }
            while (tmp % isp[i] == 0)
            {
                tmp /= isp[i];
            }
        }
        if (tmp > 1)
            Min = min(Min, tmp - x % tmp);
        cout << Min << endl;
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