#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
string a = "12345678";
string b = "abcdefgh";
void solve()
{
    string str;
    cin >> str;
    for (int i = 0; i < 8; ++i)
        if (a[i] != str[1])
            cout << str[0] << a[i] << endl;
    for (int i = 0; i < 8; ++i)
        if (b[i] != str[0])
            cout << b[i] << str[1] << endl;
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
