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
const int inf = 0x7fffffff;
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    map<pii, int> mp;
    int D = 0, K = 0;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == 'D')
            D++;
        else
            K++;
        int d = D, k = K;
        if (d == 0)
            k = 0;
        else if (k == 0)
            d = inf;
        else
        {
            int g = gcd(d, k);
            k /= g;
            d /= g;
        }
        mp[{d, k}]++;
        cout << mp[{d, k}] << " \n"[i == n - 1];
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