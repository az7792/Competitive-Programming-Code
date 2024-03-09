#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
string str = "ABCED";
void solve()
{
    string a, b;
    cin >> a >> b;
    int l1, l2;
    sort(all(a));
    sort(all(b));
    if (a[0] == 'A' && a[1] == 'E' || a[0] + 1 == a[1])
        l1 = 1;
    else
        l1 = 2;
    if (b[0] == 'A' && b[1] == 'E'||b[0] + 1 == b[1])
        l2 = 1;
    else
        l2 = 2;
    if (l1 == l2)
        cout << "Yes";
    else
        cout << "No";
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
