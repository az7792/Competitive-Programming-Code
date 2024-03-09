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
    vector<ll> a(n + 1);
    vector<ll> sum(n + 1,0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    vector<char> s(n + 1);
    ll zero = 0, one = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        if (s[i] == '1')
            one ^= a[i];
        else
            zero ^= a[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            ll tmp = sum[r] ^ sum[l - 1];
            zero ^= tmp;
            one ^= tmp;
        }
        else
        {
            int g;
            cin >> g;
            cout << (g == 1 ? one : zero) << ' ';
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