#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 1e7 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool nisp[MAX]; // false 是质数
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
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    init(MAX - 1);
    nisp[0] = nisp[1] = true;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}