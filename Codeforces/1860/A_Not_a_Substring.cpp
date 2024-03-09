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
string S = "()";
void solve()
{
    int n, p;
    string str;
    cin >> str;
    if (str == "()")
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (str[0] == '(')
        p = 0;
    else
        p = 1;
    bool f = true;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] != S[p])
        {
            f = false;
            break;
        }
        p = (p + 1) % 2;
    }
    if (!f)
    {
        for (int i = 1; i <= str.size(); ++i)
        {
            cout << "()";
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= str.size(); ++i)
            cout << "(";
        for (int i = 1; i <= str.size(); ++i)
            cout << ")";
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}