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
    vector<int> a(n + 1);
    vector<int> b;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int N = sqrt(n);
    for (int i = 1; i <= N; ++i)
    {
        if (n % i == 0)
        {
            b.push_back(i);
            b.push_back(n / i);
        }
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    int ans = 0;
    for (auto len : b)
    {
        int col = n / len;
        int Gcd = 0;
        for (int i = 1; i <= len; ++i)
        {
            for (int j = 2; j <= col; ++j)
            {
                int p = (j - 2) * len + i;
                int pp = (j - 1) * len + i;
                Gcd = gcd(Gcd, abs(a[pp] - a[p]));
                if (Gcd == 1)
                    break;
            }
            if (Gcd == 1)
                break;
        }
        if (Gcd != 1)
            ans++;
    }
    cout << ans << endl;
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
