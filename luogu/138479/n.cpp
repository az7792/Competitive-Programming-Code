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
    char a, b;
    cin >> a >> b;
    int c = a - 'A' + b - 'A';
    for (int i = 0; i <= 25; ++i)
        for (int j = 0; j <= 25; ++j)
        {
            if (i * 26 + j == c)
            {
                if (i != 0)
                    cout << char(i + 'A') << char(j + 'A');
                else
                    cout << char(j + 'A');
                return;
            }
        }
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