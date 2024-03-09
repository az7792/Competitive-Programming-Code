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
    vector<int> a(n + 1), sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    string s;
    cin >> s;
    int q;
    cin >> q;
    int zero = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
            zero ^= a[i + 1];
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            zero ^= (sum[r] ^ sum[l - 1]);
        }
        else
        {
            int g;
            cin >> g;
            if (g == 0)
                cout << zero << ' ';
            else
                cout << (zero ^ sum[n]) << ' ';
        }
    }
    cout << endl;
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