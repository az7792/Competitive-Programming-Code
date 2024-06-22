#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 20220911;
void solve()
{
    int n, q, ct = 0;
    cin >> n >> q;
    vector<char> str(n + 1);
    vector<int> sum(n + 1, 0);
    vector<int> L(n + 1, 0);
    vector<int> R(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> str[i];
        if (str[i] == '1')
        {
            ct++;
            L[i] = ct;
            if (ct % 2 == 1)
                sum[i] = sum[i - 1] + 1;
            else
                sum[i] = sum[i - 1];
        }
        else
        {
            L[i] = 0;
            ct = 0;
            sum[i] = sum[i - 1];
        }
    }
    ct = 0;
    for (int i = n; i >= 1; --i)
    {
        if (str[i] == '1')
        {
            ct++;
            R[i] = ct;
        }
        else
        {
            ct = 0;
            R[i] = 0;
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        ct = (R[l] + L[r] + 1) / 2 + sum[r - L[r]] - sum[l + R[l]];
        if (ct * 3 >= (r - l + 1))
            cout << 0 << endl;
        else
            cout << ((r - l + 1) - ct * 3) / 3 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}