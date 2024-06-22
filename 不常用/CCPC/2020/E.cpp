#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
int sg(int x)
{
    int ans = 0;
    int X = x;
    while (x % 2 == 0)
    {
        x /= 2;
        ans++;
    }
    ans = min(ans, 1);
    for (int i = 3; i <= x / i; ++i)
    {
        while (x % i == 0)
        {
            x /= i;
            ans++;
        }
    }
    if (x > 1)
        return ans + 1;
    else
        return ans;
}
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int tmp;
        cin >> tmp;
        ans ^= sg(tmp);
    }
    if (ans == 0)
        cout << "L\n";
    else
        cout << "W\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
