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
    vector<vector<int>> a(9, vector<int>(9, 0));
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> a[i][j];
    set<int> s1, s2, s3;
    for (int i = 0; i < 9; ++i)
    {
        s1.clear();
        s2.clear();
        for (int j = 0; j < 9; ++j)
        {
            s1.insert(a[i][j]);
            s2.insert(a[j][i]);
        }
        if (s1.size() != 9 || s2.size() != 9)
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < 9; i += 3)
        for (int j = 0; j < 9; j += 3)
        {
            s3.clear();
            for (int I = i; I < i + 3; ++I)
                for (int J = j; J < j + 3; ++J)
                    s3.insert(a[I][J]);
            if (s3.size() != 9)
            {
                cout << "NO\n";
                return;
            }
        }
    cout << "YES\n";
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
