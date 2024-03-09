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
void solve()
{
    ll n, k;
    cin >> n >> k;
    if (k > 28)
    {
        cout << 0 << endl;
        return;
    }
    int num[30];
    num[0] = n;
    int ans = 0;
    for (int i = n; i >= 0; --i)
    {
        num[1] = i;
        bool f = 1;
        if (num[0] - num[1] > num[1])
            break;
        for (int j = 2; j < k; ++j)
        {
            num[j] = num[j - 2] - num[j - 1];
            if (num[j] > num[j - 1] || num[j] < 0)
            {
                f = 0;
                break;
            }
        }
        if (f)
            ans++;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/