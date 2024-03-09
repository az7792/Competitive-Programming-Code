#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
struct midnum
{
    // 默认*L.rbegin()为中位数
    multiset<int> L, R;
    void insert(int num)
    {
        if (L.size() == R.size())
        {
            if (L.size() == 0 || num <= *R.begin())
                L.insert(num);
            else
            {
                L.insert(*R.begin());
                R.erase(R.begin());
                R.insert(num);
            }
        }
        else
        {
            if (*L.rbegin() <= num)
                R.insert(num);
            else
            {
                R.insert(*L.rbegin());
                L.erase(prev(L.end()));
                L.insert(num);
            }
        }
    }

    void erase(int num)
    {
        if (L.size() == R.size())
        {
            if (num >= *R.begin())
                R.erase(R.find(num));
            else
            {
                L.erase(L.find(num));
                L.insert(*R.begin());
                R.erase(R.begin());
            }
        }
        else
        {
            if (num <= *L.rbegin())
            {
                L.erase(L.find(num));
            }
            else
            {
                R.erase(R.find(num));
                R.insert(*L.rbegin());
                L.erase(prev(L.end()));
            }
        }
    }

    int getnum()
    {
        if (L.empty())
            return 0;
        return *L.rbegin();
    }

    bool empty()
    {
        return L.empty();
    }
};

vector<int> st;
midnum S;
void solve()
{
    string str;
    cin >> str;
    if (str == "Push")
    {
        int key;
        cin >> key;
        st.push_back(key);
        S.insert(key);
    }
    else if (str == "Pop")
    {
        if (st.empty())
            cout << "Invalid\n";
        else
        {
            S.erase(st.back());
            cout << st.back() << endl;
            st.pop_back();
        }
    }
    else
    {
        if (st.empty())
            cout << "Invalid\n";
        else
        {
            cout << S.getnum() << endl;
        }
    }
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
