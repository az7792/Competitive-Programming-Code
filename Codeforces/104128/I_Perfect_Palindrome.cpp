#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
void solve()
{
    string str;
    cin >> str;
    vector<int> a(26, 0);
    for (auto v : str)
        a[v - 'a']++;
    cout << str.size() - *max_element(all(a)) << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}