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
    str = "*" + str;
    vector<int> l, e, t, c, o, d;
    for (int i = str.size() - 1; i >= 1; --i)
    {
        if (str[i] == 'l')
            l.push_back(i);
        if (str[i] == 'e')
            e.push_back(i);
        if (str[i] == 't')
            t.push_back(i);
        if (str[i] == 'c')
            c.push_back(i);
        if (str[i] == 'o')
            o.push_back(i);
        if (str[i] == 'd')
            d.push_back(i);
    }
    vector<int> L(str.size(), 0);
    for (int i = 1; i < str.size(); ++i)
    {
        while (!l.empty() && l.back() < i)
        {
            l.pop_back();
        }
        while (!e.empty() && e.back() < i)
        {
            e.pop_back();
        }
        while (!t.empty() && t.back() < i)
        {
            t.pop_back();
        }
        while (!c.empty() && c.back() < i)
        {
            c.pop_back();
        }
        while (!o.empty() && o.back() < i)
        {
            o.pop_back();
        }
        while (!d.empty() && d.back() < i)
        {
            d.pop_back();
        }
        int pos = i - 1;

        if (str[i] == 'l')
        {
            bool ok = 0;
            for (int j = l.size() - 1; j >= 0; --j)
                if (l[j] > pos)
                {
                    pos = l[j];
                    ok = 1;
                    break;
                }
            if (!ok)
                continue;

            ok = 0;
            for (int j = e.size() - 1; j >= 0; --j)
                if (e[j] > pos)
                {
                    pos = e[j];
                    ok = 1;
                    break;
                }
            if (!ok)
                continue;

            ok = 0;
            for (int j = e.size() - 1; j >= 0; --j)
                if (e[j] > pos)
                {
                    pos = e[j];
                    ok = 1;
                    break;
                }
            if (!ok)
                continue;

            ok = 0;
            for (int j = t.size() - 1; j >= 0; --j)
                if (t[j] > pos)
                {
                    pos = t[j];
                    ok = 1;
                    break;
                }
            if (!ok)
                continue;

            ok = 0;
            for (int j = c.size() - 1; j >= 0; --j)
                if (c[j] > pos)
                {
                    pos = c[j];
                    ok = 1;
                    break;
                }
            if (!ok)
                continue;

            ok = 0;
            for (int j = o.size() - 1; j >= 0; --j)
                if (o[j] > pos)
                {
                    pos = o[j];
                    ok = 1;
                    break;
                }
            if (!ok)
                continue;

            ok = 0;
            for (int j = d.size() - 1; j >= 0; --j)
                if (d[j] > pos)
                {
                    pos = d[j];
                    ok = 1;
                    break;
                }
            if (!ok)
                continue;

            ok = 0;
            for (int j = e.size() - 1; j >= 0; --j)
                if (e[j] > pos)
                {
                    pos = e[j];
                    ok = 1;
                    break;
                }
            if (!ok)
                continue;
            L[i] = pos;
        }
    }
    for (int i = str.size() - 2; i >= 1; --i)
    {
        if (L[i] == 0)
            L[i] = L[i + 1];
    }
    for (int i = 1; i < L.size(); ++i)
        cout << L[i] << " ";
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
