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
string A, B;
bool ok(int a, int b)
{
    A = to_string(a);
    B = to_string(b);
    A = A + B;
    if (A.size() == 1)
        return true;
    for (int i = 0; i < A.size() - 1; ++i)
        if (A[i] != A[i + 1])
            return false;
    return true;
}
void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<int> d(n+1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
        for (int j = 1; j <= d[i]; ++j)
        {
            if (ok(i, j))
                ans++;
        }
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