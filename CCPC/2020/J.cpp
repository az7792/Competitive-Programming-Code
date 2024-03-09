#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n, la;
    cin >> n;
    vector<int> A(n + 1);
    A[0] = 1111;
    for (int i = 1; i <= n; ++i)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (A[i] == A[i - 1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
