#include <bits/stdc++.h>

using namespace std;

void create_segment_tree(vector<int>& a, vector<int>& t, int v, int tl, int tr, int operation)
{
    if(tl == tr)
    {
        t[v] = a[tl];
        return;
    }

    int tm = tl + (tr - tl)/2;
    create_segment_tree(a, t, 2 * v + 1, tl, tm, !operation);
    create_segment_tree(a, t, 2 * v + 2, tm+1, tr, !operation);

    if(operation == 1)
        t[v] = t[2 * v + 1] | t[2 * v + 2];
    else
        t[v] = t[2 * v + 1] ^ t[2 * v + 2];

}

void update(vector<int>& a, vector<int>& t, int v, int tl, int tr, int p, int b, int operation)
{
    if(tl == tr)
    {
        t[v] = b;
        return;
    }

    int tm = tl + (tr - tl)/2;

    if(p <= tm)
        update(a, t, 2 * v + 1, tl, tm, p, b, !operation);
    else
        update(a, t, 2 * v + 2, tm + 1, tr, p, b, !operation);

    if(operation == 1)
        t[v] = t[2 * v + 1] | t[2 * v + 2];
    else
        t[v] = t[2 * v + 1] ^ t[2 * v + 2];

}

int main()
{
    //freopen("4_in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    int nn = (n << 1);
    vector<int> a(nn);
    for(int i = 0; i < nn; i++)
        cin >> a[i];

    int height = (int)ceil(log2(nn));
    int tSize = 2 * pow(2, height) - 1;
    vector<int> t(tSize);

    int operation = (height % 2 == 0) ? 0 : 1;
    create_segment_tree(a, t, 0, 0, nn-1, operation);

    for(int i = 0; i < q; i++)
    {
        int p, b;
        cin >> p >> b;
        --p;
        update(a, t, 0, 0, nn-1, p, b, operation);                    
        printf("%d\n", t[0]);
    }

    return 0;
}
