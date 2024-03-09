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
    int n, d;
    string str;
    cin >> n >> d>>str;
    d += '0';
    for (int i = 0; i < str.size(); ++i)
    {
        if(d>str[i])
        {
            cout << (char)d;
            for (int j = i; j < str.size();++j)
                cout << str[j];
            cout << endl;
            return;
        }
        else
            cout << str[i];
    }
    cout << (char)d << endl;
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