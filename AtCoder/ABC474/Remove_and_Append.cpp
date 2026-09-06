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

struct Node
{
    int num;
    Node *next;
    Node *prev;
};

void solve()
{
    int n, q;
    cin >> n >> q;
    Node head{};
    Node *tail = &head;
    map<int, Node *> mp;
    for (int i = 0; i < n; ++i)
    {
        Node *temp = new Node;
        cin >> temp->num;
        temp->next = NULL;
        temp->prev = tail;

        tail->next = temp;
        tail = temp;

        mp[temp->num] = temp;
    }
    for (int i = 0; i < q; ++i)
    {
        int num;
        cin >> num;
        Node *temp = mp[num];
        if (temp == tail)
            continue;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = tail;

        tail->next = temp;

        tail = temp;
    }

    Node *pos = head.next;
    while (pos != NULL)
    {
        cout << pos->num << " ";
        pos = pos->next;
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