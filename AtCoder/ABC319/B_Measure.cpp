#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    string str = "";
    for (int i = 0; i <= n; i++)
    {
        bool f = false;
        for (int j = 1; j <= 9; j++)
        {
            if (n % j == 0 && i % (n / j) == 0)
            {
                str += to_string(j);
                f = true;
                break;
            }
        }
        if (!f)
            str += "-";
    }
    cout << str << endl;
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