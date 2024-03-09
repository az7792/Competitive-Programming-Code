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
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == b[i])
        {
            if (a[i] != c[i])
            {
                cout << "YES\n";
                return;
            }
        }
        else
        {
            if (a[i] != c[i] && b[i] != c[i])
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
