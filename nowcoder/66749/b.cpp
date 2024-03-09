#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct Node
{
    unsigned int ct, val;
    Node *L, *R; // 0 1
};
unsigned int num = 1 << 31;
Node *add(Node *head, unsigned int x, int ct, int st)
{
    if (ct == 32)
        return NULL;
    if (head == NULL)
    {
        head = (Node *)malloc(sizeof(Node));
        head->L = NULL;
        head->R = NULL;
        head->ct = 1;
        head->val = (num & x) == 0 ? 0 : 1;
    }
    else
        head->ct += st;
    x = x << 1;
    if ((x & num) == 0)
        head->L = add(head->L, x, ct + 1, st);
    else
        head->R = add(head->R, x, ct + 1, st);
    if (head->ct == 0)
    {
        free(head);
        return NULL;
    }
    return head;
}
unsigned int query(Node *head, unsigned int x, unsigned int h)
{
    if (head == NULL)
        return 0;
    int p1 = (x & num) == 0 ? 0 : 1;
    int p2 = (h & num) == 0 ? 0 : 1;
    if (p1 == 0 && p2 == 0)
    {
        if (head->val == 1)
            return head->ct;
        else
            return query(head->L, x << 1, h << 1) + query(head->R, x << 1, h << 1);
    }
    else if (p1 == 0 && p2 == 1)
    {
        if (head->val == 0)
            return 0;
        else
            return query(head->L, x << 1, h << 1) + query(head->R, x << 1, h << 1);
    }
    else if (p1 == 1 && p2 == 0)
    {
        if (head->val == 0)
            return head->ct;
        else
            return query(head->L, x << 1, h << 1) + query(head->R, x << 1, h << 1);
    }
    else // 1 1
    {
        if (head->val == 1)
            return 0;
        else
            return query(head->L, x << 1, h << 1) + query(head->R, x << 1, h << 1);
    }
}
void solve()
{
    Node *head = NULL;
    unsigned int n, hp;
    cin >> n >> hp;
    while (n--)
    {
        unsigned int op, x, h;
        cin >> op;
        if (op == 0)
        {
            cin >> x;
            head = add(head, x, 0, 1);
        }
        else if (op == 1)
        {
            cin >> x;
            head = add(head, x, 0, -1);
        }
        else
        {
            cin >> x >> h;
            unsigned int ct = query(head, x, h);
            if (ct == 0)
                hp--;
            cout << ct << endl;
        }
    }
    cout << hp;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(NULL));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}