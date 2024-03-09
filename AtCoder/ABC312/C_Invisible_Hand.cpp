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
vector<ll> A(MAX, 0);
vector<ll> B(MAX, 0);
ll n, m;
bool ok(ll mid)
{
    ll a = 0, b = 0;
    for (int i = 1; i <= n; ++i)
        if (mid >= A[i])
            a++;
    for (int i = 1; i <= m; ++i)
        if (mid <= B[i])
            b++;
    if (a >= b)
        return true;
    return false;
}
void solve()
{

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    for (int i = 1; i <= m; ++i)
        cin >> B[i];
    ll L = 1, R = 1e9+1, mid;
    while (L < R)
    {
        mid = (L + R) / 2ll;
        if (ok(mid))
        {
            R = mid;
        }
        else
        {
            L = mid + 1;
        }
    }
    cout << L;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}