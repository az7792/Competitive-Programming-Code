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
void solve()
{
    ll n;
    cin >> n;
    if (n < 7)
        cout << "NO\n";
    else if (n % 3 != 0)
        cout << "YES\n1 2 " << n - 3 << endl;
    else
    {
        if ((n / 3) % 3 == 0)
        {
            if (n / 3 == 3)
                cout << "NO\n";
            else
                cout << "YES\n"
                     << 1 << " " << n / 3 - 2 << " " << 2 * n / 3 + 1 << endl;
        }
        else
        {
            cout << "YES\n";
            cout << n / 3 << ' ';
            n = 2 * n / 3;
            if ((n - 1) % 3 == 0)
                cout << 2 << " " << n - 2 << endl;
            else
                cout << 1 << ' ' << n - 1 << endl;
        }
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