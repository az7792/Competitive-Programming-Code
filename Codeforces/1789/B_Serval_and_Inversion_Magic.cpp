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
map<ll, ll> mp;
vector<int> G(MAX, 0);
void solve()
{
    int n;
    string str;
    cin >> n >> str;
    int ct = 0, f = 1;
    for (int i = 0; i < n - i - 1; ++i)
    {
        if (str[i] != str[n - i - 1])
        {
            if (f)
                ct++, f = 0;
        }
        else
        {
            if (!f)
                f = 1;
        }
    }
    // cerr << ct << endl;
    if (ct <= 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/