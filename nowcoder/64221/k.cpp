#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool nisp[MAX + 10];
vector<int> isp;
void init(int n)
{
    for (int i = 2; i <= n; ++i)
    {
        if (!nisp[i])
            isp.push_back(i);
        for (int j = 0; j < isp.size() && i * isp[j] <= n; ++j)
        {
            nisp[i * isp[j]] = true;
            if(i%isp[j]==0)
                break;
        }
    }
}

void solve()
{
    int l, r;
    cin >> l >> r;
    int L = lower_bound(all(isp), l) - isp.begin();
    int R = upper_bound(all(isp), r) - isp.begin();
    cout << R - L << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    init(MAX);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}