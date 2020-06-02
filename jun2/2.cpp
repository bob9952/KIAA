#include <bits/stdc++.h>

using namespace std;

void lsp(const string& s, vector<int>& b)
{
    int m = (int)s.size();
    int j = -1;
    int i = 0;
    
    b[i] = j;
    
    while(i < m)
    {
        while(j >= 0 && s[i] != s[j])
            j = b[j];
        i++;
        j++;
        b[i] = j;
    }
}

int solve(const string& s, vector<int>& b, int br)
{
    int maks_sp = *max_element(b.begin()+1, b.end());
    int n = (int)s.size();
    
    return br * n - (br-1)*maks_sp;
}

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int br;
    cin >> br;
    
    vector<int> b(s.size() + 1);
    lsp(s, b);
    
    cout << solve(s, b, br) << endl;
    
    return 0;
}
