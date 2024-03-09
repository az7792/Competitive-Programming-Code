#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool num[200][200];
void solve()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int x = a; x <= b-1;++x)
            for (int y = c; y <= d-1;++y)
                num[x][y] = true;
    }
    int ans = 0;
    for (int i = 0; i <= 100;++i)
        for (int j = 0; j <= 100;++j)
            if(num[i][j])
                ans++;
    cout << ans;
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