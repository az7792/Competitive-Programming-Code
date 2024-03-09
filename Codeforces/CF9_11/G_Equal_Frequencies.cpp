#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    map<char, int> mp;
    map<char, vector<int>> mpp;
    for (int i = 0; i < n; ++i)
    {
        char v = s[i];
        mp[v]++;
        mpp[v].push_back(i);
    }
    int Min = 1e9, ct = 1e9;
    for (int i = 1; i <= 26; ++i)
    {
        ll tmp = 0;
        if (n % i == 0)
        {
            int num = n / i;
            vector<int> g;
            for (auto v : mp)
            {
                g.push_back(v.second);
                if (v.second > num)
                    tmp += v.second - num;
            }
            sort(all(g));
            for (int j = 0; j < (int)g.size() - i; ++j)
                tmp += g[j];
            if (tmp < ct)
            {
                ct = tmp;
                Min = i;
            }
        }
    }
    cout << ct << endl;
    int num = n / Min;
    vector<pair<char, int>> get, use, g;
    set<char> S;
    for (auto [x, y] : mp)
        S.insert(x);
    for (auto v : mp)
        g.push_back(v);
    sort(all(g), [](pair<char, int> a, pair<char, int> b)
         { return a.second < b.second; });
    for (int j = 0; j < (int)g.size() - Min; ++j)
        use.push_back(g[j]);
    for (int i = max(0, (int)g.size() - Min); i < g.size(); ++i)
    {
        if (g[i].second < num)
            get.push_back(g[i]);
        else if (g[i].second > num)
            use.push_back(g[i]);
    }
    for (char i = 'a'; i <= 'z'; ++i)
    {
        if (S.size() >= Min)
            break;
        if (S.find(i) == S.end())
            S.insert(i), get.push_back({i, 0});
    }
    for (auto v : use)
    {
        int geshu = (v.second > num ? v.second - num : v.second);
        for (int i = 0; i < geshu; ++i)
        {
            // mmp[v.first]
            s[mpp[v.first][i]] = get.back().first;
            get.back().second++;
            if (get.back().second == num)
                get.pop_back();
        }
    }
    cout << s << endl;
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