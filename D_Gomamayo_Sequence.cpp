#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = "*" + str;
    vector<ll> c(n + 2, 0);
    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    vector<ll> ol(n + 2, 0), lo(n + 2, 0);

    for (int i = 1; i <= n; ++i)
    {
        char ch;
        // ol
        ch = (i % 2 == 1 ? '0' : '1');
        ol[i] = ol[i - 1] + (str[i] == ch ? 0 : c[i]);
        // lo
        ch = (i % 2 == 1 ? '1' : '0');
        lo[i] = lo[i - 1] + (str[i] == ch ? 0 : c[i]);
    }
    ll ans = 2e18;
    // for (int i = 1; i <= n; ++i)
    //     cout << ol[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; ++i)
    //     cout << lo[i] << " ";
    // cout << endl;
    for (int i = 1; i < n; ++i)
    {
        ll tmp = 0; // 00
        if (str[i] == '1')
            tmp += c[i];
        if (str[i + 1] == '1')
            tmp += c[i + 1];
        //[i i+1]
        //[1,i-1]
        tmp += ((i - 1) % 2 == 0 ? ol[i - 1] : lo[i - 1]);
        //[i+2,n]
        tmp += ((i + 2) % 2 == 0 ? ol[n] - ol[i + 1] : lo[n] - lo[i + 1]);
        ans = min(ans, tmp);

        tmp = 0; // 11
        if (str[i] == '0')
            tmp += c[i];
        if (str[i + 1] == '0')
            tmp += c[i + 1];
        tmp += ((i - 1) % 2 == 0 ? lo[i - 1] : ol[i - 1]);
        //[i+2,n]
        tmp += ((i + 2) % 2 == 0 ? lo[n] - lo[i + 1] : ol[n] - ol[i + 1]);
        ans = min(ans, tmp);
    }
    cout << ans;
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
