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
    vector<pair<int, char>> A, a;
    for (int i = 0; i < str.size(); ++i)
    {
        char v = str[i];
        if ('a' <= v && v <= 'z')
        {
            if (v == 'b')
            {
                if (a.size() != 0)
                    a.pop_back();
            }
            else
            {
                a.push_back({i, v});
            }
        }
        else
        {
            if (v == 'B')
            {
                if (A.size() != 0)
                    A.pop_back();
            }
            else
            {
                A.push_back({i, v});
            }
        }
    }
    for (auto v : a)
        A.push_back(v);
    sort(all(A));
    for (auto v : A)
        cout << v.second;
    cout << endl;
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
