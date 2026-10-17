#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 1e9 + 7;
// ll MOD = 998244353;

template <typename T>
std::istream &operator>>(std::istream &_in, std::vector<T> &_a)
{
    for (auto &v : _a)
        _in >> v;
    return _in;
}

template <typename T>
std::ostream &operator<<(std::ostream &_out, std::vector<T> &_a)
{
    if (!_a.empty())
        _out << _a[0];
    for (size_t i = 1; i < _a.size(); ++i)
        _out << " " << _a[i];
    return _out;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    set<string> s;
    map<string, int> mp;
    vector<string> strs(n);
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i)
    {
        strs[i];
        cin >> strs[i];
        s.insert(strs[i]);
        mp[strs[i]] = i;
    }

    for (int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;
        if (s.find(str) != s.end())
        {
            ans[mp[str]] += 1;
        }
        else
        {
            int ct = 0;
            string name;
            for (int j = 0; j < str.size(); ++j)
            {
                char old = str[j];
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    str[j] = ch;
                    if (s.find(str) != s.end())
                    {
                        ct++;
                        name = str;
                    }
                }
                str[j] = old;
            }
            if (ct == 1)
            {
                ans[mp[name]] += 1;
            }
        }
    }

    for (auto v : ans)
    {
        cout << v << "\n";
    }
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