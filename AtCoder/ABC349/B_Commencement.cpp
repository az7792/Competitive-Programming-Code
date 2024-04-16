#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    string str;
    cin >> str;
    vector<int> a(str.size() + 1);
    vector<int> num(26, 0);
    for (auto v : str)
        num[v - 'a']++;
    for (int i = 0; i < 26; ++i)
    {
        a[num[i]]++;
    }
    for (int i = 1; i <= str.size(); ++i)
    {
        if (a[i] == 0 || a[i] == 2)
            ;
        else
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
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
