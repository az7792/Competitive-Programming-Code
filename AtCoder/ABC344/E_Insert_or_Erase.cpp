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
struct Node
{
    int val;
    Node *L, *R;
};
void Print(Node *head)
{
    Node *tmp = head->R;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->R;
    }
}
void solve()
{
    int n;
    int a;
    cin >> n;
    map<int, Node *> mp;
    Node *head = (Node *)malloc(sizeof(Node));
    head->val = 0;
    head->R = nullptr;
    mp[0] = head;
    int la = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        Node *tmp = (Node *)malloc(sizeof(Node));
        tmp->val = a;
        tmp->L = mp[la];
        tmp->R = nullptr;
        mp[a] = tmp;
        mp[la]->R = tmp;
        la = a;
    }
    // Print(head);
    int q;
    cin >> q;
    while (q--)
    {
        int op, x, y;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y;

            Node *tmp = (Node *)malloc(sizeof(Node));
            mp[y] = tmp;
            tmp->val = y;

            tmp->R = mp[x]->R;
            tmp->L = mp[x];

            if (mp[x]->R != nullptr)
                mp[x]->R->L = tmp;
            mp[x]->R = tmp;
        }
        else
        {
            cin >> x;
            mp[x]->L->R = mp[x]->R;
            if (mp[x]->R != nullptr)
                mp[x]->R->L = mp[x]->L;
            mp.erase(x);
        }
        // cout << endl;
    }
    Print(head);
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
