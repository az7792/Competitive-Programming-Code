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
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (n % 2 == 0)
    {
        int l = 0, r = n - 1;
        int ct1 = 0, ct2 = 0;
        while (l < r)
        {
            if (str[l] == str[r])
                ct2++;
            else
                ct1++;
            l++, r--;
        }
        for (int i = 0; i <= n; ++i)
        {
            if (i < ct1)
                cout << 0;
            else
            {
                if ((i - ct1) % 2 == 0 && (i - ct1) <= 2 * ct2)
                    cout << 1;
                else
                    cout << 0;
            }
        }
    }
    else
    {
        int l = 0, r = n - 1;
        int ct1 = 0, ct2 = 0;
        while (l < r)
        {
            if (str[l] == str[r])
                ct2++;
            else
                ct1++;
            l++, r--;
        }
        for (int i = 0; i <= n; ++i)
        {
            if (i < ct1)
                cout << 0;
            else
            {
                if ((i - ct1) <= 2 * ct2 + 1)
                    cout << 1;
                else
                    cout << 0;
            }
        }
    }
    cout << endl;
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