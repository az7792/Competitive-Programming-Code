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
    int n;
    string str;
    cin >> n >> str;
    str = "*" + str;
    vector<int> ans;
    int l0, l1, r0, r1;
    l0 = l1 = r0 = r1 = 0;
    for (auto v : str)
        if (v == '0')
            r0++;
        else if (v == '1')
            r1++;
    for (int i = 0; i <= n; ++i) // i后面
    {
        //[1-i][i+1,n];
        if (i >= 1)
        {
            if (str[i] == '0')
            {
                r0--;
                l0++;
            }
            else
            {
                r1--;
                l1++;
            }
        }
        // cout << l0 << " " << r1 << endl;
        if (l0 >= (i + 1) / 2 && r1 >= (n - i + 1) / 2)
        {
            ans.push_back(i);
        }
    }
    sort(all(ans), [=](int A, int B)
         { return fabs(fabs(n / 2.0 - A) - fabs(n / 2.0 - B)) <= 1e-6 ? A < B : fabs(n / 2.0 - A) < fabs(n / 2.0 - B); });
    cout << *ans.begin() << endl;
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
