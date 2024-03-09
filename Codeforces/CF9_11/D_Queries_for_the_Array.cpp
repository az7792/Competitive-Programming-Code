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
    string str;
    cin >> str;
    int one = 0, zero = 0, ct = 0;
    for (auto v : str)
    {
        if (v == '+')
        {
            ct++;
            if (one == 0)
                one = 1;
        }
        else if (v == '-')
        {
            ct--;
            if (ct < one)
                one--;
            if (ct < zero)
                zero = 0;
        }
        else if (v == '1')
        {
            one = ct;
            if (zero <= one && zero != 0)
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            if (zero == 0)
                zero = ct;
            if (zero <= one)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
