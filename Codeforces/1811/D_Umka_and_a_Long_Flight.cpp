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
ll F[50];
void init()
{
    F[0] = F[1] = 1;
    for (int i = 2; i <= 45; ++i)
        F[i] = F[i - 1] + F[i - 2];
}
bool ok(int n, int n1, int x, int y)
{
    if(n==1)
        return true;
    if (F[n] < y)
        return ok(n - 1, n, F[n1] - y + 1, x);
    else if (y <= F[n-1])
        return ok(n - 1, n, y, F[n] - x + 1);
    return false;
}
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    if (ok(n, n + 1, x, y))
        cout << "YES\n";
    else
        cout << "NO\n";
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