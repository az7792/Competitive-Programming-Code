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
    double a, c;
    int b;
    cin >> a >> b >> c;
    if (b == 0)
    {
        a *= 2.455;
    }
    else
    {
        a *= 1.26;
    }
    printf("%.2lf ", a);
    if (a > c)
        cout << "T_T";
    else
        cout << "^_^";
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
