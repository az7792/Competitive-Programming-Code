#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
ll g(ll a, ll b, char ch)
{
    if (ch == '+')
        return a + b;
    if (ch == '-')
        return a - b;
    if (ch == '*')
        return a * b;
    if (ch == '/')
        if (b == 0)
        {
            cout << "ERROR: " << a << "/0";
            exit(0);
        }
        else
            return a / b;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<char> b(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int j = 0; j < n - 1; ++j)
        cin >> b[j];
    while (1)
    {
        if (a.size() == 1)
        {
            cout << *a.begin();
            return;
        }
        ll tmp = a.back();
        a.pop_back();
        char ch = b.back();
        b.pop_back();
        a.back() = g(a.back(), tmp, ch);
    }
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
