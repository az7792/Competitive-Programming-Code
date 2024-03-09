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
    int n, p[4];
    cin >> n;
    for (int i = 0; i < 4; ++i)
    {
        cin >> p[i];
        if (p[i] > n / 2)
            p[i] = n / 2 - (p[i] - (n / 2 + 1));
    }
    int a = min(p[0], p[1]);
    int b = min(p[2], p[3]);
    cout << abs(a - b) << endl;
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