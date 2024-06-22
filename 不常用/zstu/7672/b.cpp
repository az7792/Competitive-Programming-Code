#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<bool> ok(MAX);
void init()
{
    for (int i = 0; i <= 9; ++i)
        ok[i] = 1;
    for (int i = 10; i <= 1e6; ++i)
    {
        int tmp = i, sum = 0;
        while (tmp != 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        //[1 , sum]
        for (int j = 1; j <= sum; ++j)
        {
            if (!ok[i - j])
            {
                ok[i] = 1;
                break;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << (ok[n] ? "A" : "B") << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
