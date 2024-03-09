#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> Q(n), A(n), B(n), MA(n), MB(n);
    for (int i = 0; i < n; ++i)
        cin >> Q[i];
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < n; ++i)
        cin >> B[i];
    for (int i = 0; i < n; ++i)
    {
        if (A[i] == 0)
            MA[i] = 1e9;
        else
            MA[i] = Q[i] / A[i];
    }
    int Min = *min_element(all(MA));
    int ans = 0;
    for (int i = 0; i <= Min; ++i)
    {
        for (int j = 0; j < n; ++j)
            Q[j] -= i * A[j];
        for (int j = 0; j < n; ++j)
            if (B[j] == 0)
                MB[j] = 1e9;
            else
                MB[j] = Q[j] / B[j];
        for (int j = 0; j < n; ++j)
            Q[j] += i * A[j];
        int mmin = *min_element(all(MB));
        ans = max(ans, i + mmin);
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
