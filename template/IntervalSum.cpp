#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

//TODO 离散树状数组动态求区间和
struct IntervalSum
{
    // 先插入
    // 然后build
    // 之后才能查询
    map<int, long long> mp;
    map<int, long long> tmp;

    void addVal(int l, int r, long long value)
    {
        mp[l] += value;
        mp[r + 1] -= value;
    }

    void build()
    {
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it == mp.begin())
                continue;
            auto pit = prev(it);
            (*it).second += (*pit).second;
        }

        tmp = mp;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it == mp.begin())
                continue;
            auto pit = prev(it);
            (*it).second += (*pit).second + tmp[(*pit).first] * ((*it).first - (*pit).first - 1);
        }
    }

    long long get(int l, int r)
    {
        long long A, B;
        l--;
        auto it = prev(mp.upper_bound(r));
        B = (*it).second + (r - (*it).first) * (tmp[(*it).first]);

        if (l < mp.begin()->first)
            A = 0;
        else
        {
            it = prev(mp.upper_bound(l));
            A = (*it).second + (l - (*it).first) * (tmp[(*it).first]);
        }
        return B - A;
    }
};