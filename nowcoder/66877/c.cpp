#include <bits/stdc++.h>//ji
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
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(-1);
    set<int> s;
    for (int i = 1; i <= n; ++i)
    {
        int tmp;
        cin >> tmp;
        if (a.empty())
            a.push_back(tmp);
        else if (a.back() != tmp)
            a.push_back(tmp);
    }
    n = a.size() - 1;
    vector<int> num(n + 2, 0);
    for (int i = n; i >= 1; --i)
    {
        if (s.find(a[i]) != s.end())
            num[i] = num[i + 1];
        else
        {
            s.insert(a[i]);
            for (int t = num[i + 1]; t <= n + 1; ++t)
            {
                if (s.find(t) == s.end())
                {
                    num[i] = t;
                    break;
                }
            }
        }
    }
    set<int> S0, S1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
            S0.insert(i);
        if (a[i] == 1)
            S1.insert(i);
    }
    int Max = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!S0.empty())
        {
            if (!S1.empty())
            {
            }
            else
            {
                //[i,*S0.begin()-1]
            }
        }
        S0.erase(i);
        S1.erase(i);
    }
    cout << Max;
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