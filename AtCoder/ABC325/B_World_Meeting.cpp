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
    int n;
    cin >> n;
    vector<int> w(n + 1), x(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> x[i];
    int ans = 0;
    for (int i = 0; i <= 23; ++i)
    {
        // i - i+1
        int tmp = 0;
        for (int j = 1; j <= n; ++j)
        {
            int L = (x[j] + i) % 24;
            int R = (x[j] + 1 + i) % 24;
            if(L<=R&&L>=9&&R<=18)
                tmp += w[j];
        }
        ans = max(ans, tmp);
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}