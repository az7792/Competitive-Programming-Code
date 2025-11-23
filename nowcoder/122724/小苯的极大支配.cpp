#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 998244353;

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

template <typename T>
class AVLSet
{
protected:
    struct Node
    {
        T key;
        Node *left, *right;
        int height, size, sum;

        Node(const T &k) : key(k), left(nullptr), right(nullptr),
                           height(1), size(1), sum(k) {}
    };

    Node *root = nullptr;

    inline int h(Node *t) const { return t ? t->height : 0; }
    inline int sz(Node *t) const { return t ? t->size : 0; }
    inline int sm(Node *t) const { return t ? t->sum : 0; }

    void update(Node *t)
    {
        t->height = max(h(t->left), h(t->right)) + 1;
        t->size = sz(t->left) + sz(t->right) + 1;
        t->sum = sm(t->left) + sm(t->right) + t->key;
    }

    // 平衡因子
    inline int balanceFactor(Node *t)
    {
        return h(t->left) - h(t->right);
    }

    // 左旋
    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;
        y->left = x;
        update(x);
        update(y);
        return y;
    }

    // 右旋
    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        y->left = x->right;
        x->right = y;
        update(y);
        update(x);
        return x;
    }

    // 平衡节点t
    Node *balance(Node *t)
    {
        update(t);
        int bf = balanceFactor(t);

        if (bf > 1) // 左边失衡
        {
            if (balanceFactor(t->left) < 0)
                t->left = rotateLeft(t->left);
            return rotateRight(t);
        }
        else if (bf < -1) // 右边失衡
        {
            if (balanceFactor(t->right) > 0)
                t->right = rotateRight(t->right);
            return rotateLeft(t);
        }
        return t;
    }

    // 插入
    virtual Node *insert(Node *t, const T &key)
    {
        if (!t)
            return new Node(key);
        if (key < t->key) // key < t->key
            t->left = insert(t->left, key);
        else if (t->key < key) // key > t->key
            t->right = insert(t->right, key);
        else          // key == k->key
            return t; // 已存在
        return balance(t);
    }

    // 最小
    Node *findMin(Node *t)
    {
        return t->left ? findMin(t->left) : t;
    }

    // 移除最小的节点，但不删除
    Node *removeMin(Node *t)
    {
        if (!t->left)
            return t->right;
        t->left = removeMin(t->left);
        return balance(t);
    }

    // 删除节点
    Node *erase(Node *t, const T &key)
    {
        if (!t)
            return nullptr;
        if (key < t->key) // <
            t->left = erase(t->left, key);
        else if (t->key < key) // >
            t->right = erase(t->right, key);
        else // ==
        {
            Node *L = t->left;
            Node *R = t->right;
            delete t;
            if (!R)
                return L;
            Node *m = findMin(R);
            m->right = removeMin(R);
            m->left = L;
            return balance(m);
        }
        return balance(t);
    }

    // 第k大 (0-index)
    Node *kth(Node *t, int k) const
    {
        if (!t)
            return nullptr;
        int leftSize = sz(t->left);
        if (k < leftSize)
            return kth(t->left, k);
        if (k == leftSize)
            return t;
        return kth(t->right, k - leftSize - 1);
    }

    // 存在
    bool contains(Node *t, const T &key) const
    {
        if (!t)
            return false;
        if (key < t->key) // <
            return contains(t->left, key);
        else if (t->key < key) // >
            return contains(t->right, key);
        else //==
            return true;
    }

    // 找 >= key 的最小节点，同时携带当前节点在树中的排名
    // @param base 之前的节点个数
    pair<Node *, int> lower_bound_with_rank(Node *t, const T &key, int base) const
    {
        if (!t)
            return {nullptr, base}; // 路径走到底，排名就是 base

        if (t->key < key)
        {
            // 只能向右走
            // 右子树中的元素排名起点 = base + leftSize + 1
            return lower_bound_with_rank(t->right, key, base + sz(t->left) + 1);
        }
        else
        { // 左子树可能更优，基准排名不变
            auto res = lower_bound_with_rank(t->left, key, base);
            if (res.first)
                return res;

            // 左子树没找到，这个节点就是答案，
            // 它的 rank = base + 左子树大小
            return {t, base + sz(t->left)};
        }
    }

    pair<Node *, int> upper_bound_with_rank(Node *t, const T &key, int base) const
    {
        if (!t)
            return {nullptr, base};

        if (key < t->key)
        {
            auto res = upper_bound_with_rank(t->left, key, base);
            if (res.first)
                return res;

            return {t, base + sz(t->left)};
        }
        else
        {
            return upper_bound_with_rank(t->right, key, base + sz(t->left) + 1);
        }
    }

    int _get(Node *t, const T &key)
    {
        if (t == nullptr)
            return 0;
        if (t->key < key)
            return _get(t->right, key);
        //>=
        return sm(t->right) + t->key + _get(t->left, key);
    }

public:
    int get(const T &key)
    {
        return _get(root, key);
    }
    void insert(const T &key) { root = insert(root, key); }
    void erase(const T &key) { root = erase(root, key); }
    bool contains(const T &key) const { return contains(root, key); }
    int size() const { return sz(root); }

    // lower_bound(x) → (>=x 的节点, 它的排名)
    // 找不到时 → (nullptr, size())
    pair<const T *, int> lower_bound(const T &key) const
    {
        auto res = lower_bound_with_rank(root, key, 0);
        if (!res.first)
            return {nullptr, size()};
        return {&(res.first->key), res.second};
    }

    pair<const T *, int> upper_bound(const T &key) const
    {
        auto res = upper_bound_with_rank(root, key, 0);
        if (!res.first)
            return {nullptr, size()};
        return {&(res.first->key), res.second};
    }

    // ==
    pair<const T *, int> find(const T &key) const
    {
        auto res = lower_bound_with_rank(root, key, 0);
        if (!res.first || res.first->key < key || key < res.first->key)
            return {nullptr, size()};
        return {&(res.first->key), res.second};
    }

    const T &operator[](int k) const
    {
        Node *n = kth(root, k);
        if (!n)
            throw out_of_range("index out of range");
        return n->key;
    }
};

template <typename T>
class AVLMultiSet : public AVLSet<T>
{
protected:
    using Node = typename AVLSet<T>::Node;
    using AVLSet<T>::root;
    using AVLSet<T>::balance;

    // 重写 insert，让重复元素也插入
    Node *insert(Node *t, const T &key) override
    {
        if (!t)
            return new Node(key);
        if (key < t->key)
            t->left = insert(t->left, key);
        else // key >= t->key，重复放右边
            t->right = insert(t->right, key);
        return balance(t);
    }

public:
    void insert(const T &key) { root = insert(root, key); }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    map<int, int> mp;
    for (auto v : a)
        mp[v]++;

    vector<pii> key(mp.begin(), mp.end()); // key
    vector<int> sum(key.size());
    sum[0] = key[0].second;
    for (int i = 1; i < sum.size(); ++i)
    {
        sum[i] = sum[i - 1] + key[i].second;
    }

    AVLMultiSet<int> s;
    for (auto v : key)
    {
        s.insert(v.second);
    }
    int ans = 1e9;
    for (int i = key.size() - 1; i >= 0; --i)
    {
        int tmpA = sum.back() - sum[i];
        s.erase(key[i].second);
        // >=key[i].second的 和 以及 个数
        int pos = s.lower_bound(key[i].second).second;
        int ct = s.size() - pos;
        int SUM = s.get(key[i].second);
        tmpA += SUM - (key[i].second - 1) * ct;
        ans = min(ans, tmpA);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}