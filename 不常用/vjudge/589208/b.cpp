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
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w,0));
    for (int i = 0; i < h;++i)
        for (int j = 0; j < w;++j)
            cin >> a[i][j];
    bool f = true;
    for (int i = 0; i < h;++i)
        for (int j = 0; j < w;++j)
            for (int k = i + 1; k < h;++k)
                for (int l = j + 1; l < w;++l)
                    if(a[i][j]+a[k][l]>a[k][j]+a[i][l])
                        f = false;
    cout << (f ? "Yes" : "No");
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