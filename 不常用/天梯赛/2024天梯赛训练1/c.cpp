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
    if (str.size() == 6)
    {
        for (int i = 0; i < 4; ++i)
            cout << str[i];
        cout << '-';
        for (int i = 4; i < 6; ++i)
            cout << str[i];
    }
    else
    {
        int t = (str[0] - '0') * 10 + str[1] - '0';
        if(t<22)
            cout << 20;
        else
            cout << 19;
        cout << str[0] << str[1] << "-" << str[2] << str[3];
    }
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
