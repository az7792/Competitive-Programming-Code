#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    string str;
    cin >> str;
    bool f1 = 0, f2 = 1;
    if (str[0] <= 'Z' && str[0] >= 'A')
        f1 = 1;
    for (int i = 1; i < str.size(); ++i)
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            f2 = 0;
            break;
        }
    if(f1&&f2)
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
