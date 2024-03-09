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
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll L = lcm(b, d);
    a *= L / b;
    c *= L / d;
    if(a<c)
    {
        cout << "Y\n";
    }
    else
    {
        cout << "S\n";
    }
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
