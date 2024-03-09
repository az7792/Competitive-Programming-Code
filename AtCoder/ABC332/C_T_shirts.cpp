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
    ll n, m;
    string s;
    cin >> n >> m >> s;
    int a = m, b = 0;
    int A = m, B = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
            A = a, B = b;
        else if (s[i] == '1')
        {
            if (A == 0 && B == 0)
                b++;
            else if (A == 0)
                B--;
            else
                A--;
        }
        else
        {
            if (B == 0)
                b++;
            else
                B--;
        }
    }
    cout << a - m + b;
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
