#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, m, r;
    double p;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ll End = 0;
    for (int i = n; i >= 1; --i)
    {
        if (a[i] != i)
        {
            End = i;
            break;
        }
    }
    // cerr << "End:" << End << Endl;
    double ans = 1;
    for (int i = 1; i <= m; ++i)
    {
        cin >> r >> p;
        if (r >= End)
        {
            ans *= (1 - p);
        }
    }
    if (End == 0)
    {
        printf("1.0000000\n");
        return;
    }
    printf("%.7lf\n", 1 - ans);
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