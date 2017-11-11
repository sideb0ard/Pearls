#include <iostream>
#include <set>
#include <random>
#include <ctime>

//////////////////////////////////////////////////////////////////////////////
class IntSet
{
public:
    virtual void insert(int t) = 0;
    virtual int size() = 0;
    virtual void report(int *v) = 0;
};

//////////////////////////////////////////////////////////////////////////////
class IntSetSTL : public IntSet
{
public:
    IntSetSTL(int maxelements, int maxval)
    { }
    void insert(int t) override
    {
        S.insert(t);
    }
    int size() override
    { return S.size(); }
    void report(int *v) override
    {
        int j = 0;
        for (auto const &i : S)
            v[j++] = i;
    }
private:
    std::set<int> S;
};

//////////////////////////////////////////////////////////////////////////////
class IntSetArray : public IntSet
{
public:
    IntSetArray(int maxelements, int maxval)
    {
        elements = new int[1 + maxelements];
        num_elements = 0;
        elements[0] = maxval;
    }
    int size() override
    {
        return num_elements;
    }
    void insert(int num) override
    {
        int i, j = 0;
        for (i = 0; elements[i] < num; ++i)
            ;
        if (elements[i] == num)
            return;
        for (j = num_elements; j >= i; j--)
            elements[j+1] = elements[j];
        elements[i] = num;
        num_elements++;
    }
    void report(int *v) override
    {
        for (int i = 0; i < num_elements; ++i)
            v[i] = elements[i];
    }

private:
    int num_elements;
    int *elements;
};

//////////////////////////////////////////////////////////////////////////////
class IntSetList : public IntSet
{
private:
    int num_elements;
    struct node {
        int val;
        node *next;
        node(int v, node *p)
        {
            val = v; next = p;
        }
    };
    node *head, *sentinel;
    node *rinsert(node *p, int t)
    {
        if (p->val < t)
            p->next = rinsert(p->next, t);
        else if (p->val > t)
        {
            p = new node(t, p);
            num_elements++;
        }
        return p;
    }
public:
    IntSetList(int maxelements, int maxval)
    {
        sentinel = head = new node(maxval, NULL);
        num_elements = 0;
    }
    int size() override
    {
        return num_elements;
    }
    void insert(int num) override
    {
        head = rinsert(head, num);
    }
    void report(int *num) override
    {
        int j = 0;
        for (node *p = head; p != sentinel; p = p->next)
            num[j++] = p->val;
    }
};

//////////////////////////////////////////////////////////////////////////////
class IntSetBST : public IntSet
{
private:
    int n, *v, vn;
    struct node {
        int val;
        node *left, *right;
        node(int i) { val = i; left = right = 0; }
    };
    node *root;
    node *rinsert(node *p, int t)
    {
        if ( p == 0 )
        {
            p = new node(t);
            n++;
        }
        else if ( t < p->val)
            p->left = rinsert(p->left, t);
        else if ( t > p->val)
            p->right = rinsert(p->right, t);
        // do nothing if p->val == t
        return p;
    }
    void traverse(node *p)
    {
        if (p == 0)
            return;
        traverse(p->left);
        v[vn++] = p->val;
        traverse(p->right);
    }
public:
    IntSetBST(int maxelements, int maxval)
    {
        root = 0; n = 0;
    }
    int size() override
    {
        return n;
    }
    void insert(int t) override
    {
        root = rinsert(root, t);
    }
    void report(int *x) override
    {
        v = x; vn = 0; traverse(root);
    }
};

//////////////////////////////////////////////////////////////////////////////

void gensets(int m, int maxval)
{
    srand(time(NULL));
    int *v = new int[m];
    //IntSetSTL S(m, maxval);
    //IntSetArray S(m, maxval);
    //IntSetList S(m, maxval);
    IntSetBST S(m, maxval);
    while (S.size() < m)
        S.insert(rand() % maxval);
    S.report(v);
    for (int i = 0; i < m; ++i)
        std::cout << v[i] << "\n";
}

int main()
{
    gensets(100, 1000);

}
