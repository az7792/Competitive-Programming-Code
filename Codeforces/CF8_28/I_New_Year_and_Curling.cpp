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
    double r;
    cin >> n >> r;
    vector<int> num(n);
    vector<double> ans(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
        double tmp = r;
        for (int j = 0; j < i; ++j)
        {
            if (abs(num[i] - num[j]) <= 2 * r)
            {
                double y = 4 * r * r - 1.0 * (num[i] - num[j]) * (num[i] - num[j]);
                y = sqrt(y);
                y += ans[j];
                tmp = max(tmp, y);
            }
        }
        ans[i] = tmp;
        printf("%.8lf ", tmp);
    }
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