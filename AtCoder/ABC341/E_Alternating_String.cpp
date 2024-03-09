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
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    int L = 1;
    set<pii> s;
    int f = str[0] - '0';
    for (int i = 1; i < str.size(); ++i)
    {
        if (str[i] - '0' == f)
        {
            s.insert({L, i});
            L = i + 1;
            f = str[i] - '0';
        }
        else
        {
            if (f == 1)
                f = 0;
            else
                f = 1;
        }
    }
    if (L <= n)
        s.insert({L, n});

    while (q--)
    {
        int op, l, r, tl, tr;
        cin >> op >> l >> r;
        set<pii>::iterator it1, it2;
        it1 = s.upper_bound({l, 1e9});
        it2 = s.upper_bound({r, 1e9});
        it1 = prev(it1);
        it2 = prev(it2);

        if (op == 1)
        {
            pii ttt = *it1;
            if (it1 == it2)
            {
                if (ttt.first == l && ttt.second == r)
                {
                    if (it1 != s.begin())
                    {
                        l = (*prev(it1)).first;
                        s.erase(prev(it1));
                    }
                    if (next(it1) != s.end())
                    {
                        r = (*next(it1)).second;
                        s.erase(next(it1));
                    }
                    s.erase(it1);
                    s.insert({l, r});
                }
                else if (ttt.first == l)
                {
                    if (it1 != s.begin())
                    {
                        l = (*prev(it1)).first;
                        s.erase(prev(it1));
                    }
                    s.erase(it1);
                    s.insert({l, r});
                    s.insert({r + 1, ttt.second});
                }
                else if (ttt.second == r)
                {
                    if (next(it1) != s.end())
                    {
                        r = (*next(it1)).second;
                        s.erase(next(it1));
                    }
                    s.erase(it1);
                    s.insert({l, r});
                    s.insert({ttt.first, l - 1});
                }
                else
                {
                    s.erase(it1);
                    s.insert({ttt.first, l - 1});
                    s.insert({l, r});
                    s.insert({r + 1, ttt.second});
                }
            }
            else
            {
                pii t1 = *it1;
                pii t2 = *it2;
                if (t1.first == l)
                {
                    if (it1 != s.begin())
                    {
                        int lll = (*prev(it1)).first;
                        s.erase(prev(it1));
                        s.erase(it1);
                        s.insert({lll, t1.second});
                    }
                }
                else
                {
                    s.erase(it1);
                    s.insert({t1.first, l - 1});
                    s.insert({l, t1.second});
                }

                if (t2.second == r)
                {
                    if (next(it2) != s.end())
                    {
                        int rrr = (*next(it2)).second;
                        s.erase(next(it2));
                        s.erase(it2);
                        s.insert({t2.first, rrr});
                    }
                }
                else
                {
                    s.erase(it2);
                    s.insert({t2.first, r});
                    s.insert({r + 1, t2.second});
                }
            }
        }
        else
        {
            if (it1 == it2)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
