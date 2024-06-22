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
ll sumY[MAX];
ll sumM1[15];
ll sumM2[15];
int mm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isl(ll y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
void solve()
{
    ll Y, M, D, h, m, s;
    cin >> Y >> M >> D >> h >> m >> s;
    ll ans = sumY[Y];
    if (isl(Y))
        ans += sumM1[M];
    else
        ans += sumM2[M];
    ans += (D - 1) * 24 * 3600 + h * 3600 + m * 60 + s;
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    sumY[1970] = 0;
    for (int i = 1971; i <= 9999; ++i)
    {
        if (isl(i - 1))
            sumY[i] += sumY[i - 1] + 365 * 24 * 3600;
        else
            sumY[i] += sumY[i - 1] + 366 * 24 * 3600;
    }
    sumM1[1] = sumM2[1] = 0;
    sumM1[2] = sumM2[2] = sumM1[1] + 31 * 24 * 3600ll;
    sumM1[3] = sumM1[2] + 28 * 24 * 3600ll; // 28
    sumM2[3] = sumM2[2] + 29 * 24 * 3600ll; // 29
    for (int i = 4; i <= 12; ++i)
    {
        sumM1[i] += sumM1[i - 1] + mm[i - 1] * 24 * 3600ll;
        sumM2[i] += sumM2[i - 1] + mm[i - 1] * 24 * 3600ll;
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
