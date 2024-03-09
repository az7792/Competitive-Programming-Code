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
string str = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
void solve()
{
    int n;
    cin >> n;
    cout << "3.";
    vector<char> ans;
    for (int i = 0; i < n; ++i)
        ans.eb(str[i]);
    // while (ans.back()==0)
    // {
    //     ans.pop_back();
    // }
    for (auto v : ans)
        cout << v;
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