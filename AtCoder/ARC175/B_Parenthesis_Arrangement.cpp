#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    string str;
    cin >> str;
    vector<char> ch;
    for (auto v : str)
        if (ch.empty() || v == '(')
            ch.push_back(v);
        else if (ch.back() == '(')
            ch.pop_back();
        else
            ch.push_back(v);
    // for (auto v : ch)
    //     cout << v;
    ll L = count(all(ch), '(');
    ll R = count(all(ch), ')');

    ll ans = 0;
    while (L > 0 && R > 0)
    {
        if (L == 1 && R == 1)
        {
            ans += min(a, 2 * b);
            L = R = 0;
            break;
        }
        // huanB
        ll L1 = 0, R1 = 0, L2 = 1, R2 = 1;
        if (L >= R)
        {
            L1 = 2;
        }
        else
        {
            R1 = 2;
        }

        // huanA
        if (R - 1 >= 1 && L - 1 >= 1)
            L2 = R2 = 2;

        if (L2 + R2 == 2)
        {
            if (a <= b)
            {
                ans += a;
                L--, R--;
            }
            else
            {
                ans += b;
                L -= L1, R -= R1;
            }
        }
        else
        {
            if (a <= 2 * b)
            {
                ans += a;
                L -= 2, R -= 2;
            }
            else
            {
                ans += b;
                L -= L1, R -= R1;
            }
        }
    }
    if (L > 0)
    {
        ans += b * (L / 2);
    }
    if (R > 0)
    {
        ans += b * (R / 2);
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
