#include <bits/stdc++.h>

using namespace std;

void compute_preffix_table(string &s,vector<int> &preffix_table)
{
  int n = s.size();

  preffix_table[0] = 0;

  int i = 1;
  int j = 0;

  while (i < n) 
  {
    if (s[i] == s[j]) 
    {
      preffix_table[i] = j + 1;
      i++;
      j++;
    }
    else 
    {
      if (j != 0)
        j = preffix_table[j - 1];
      else 
      {
        preffix_table[i] = 0;
        i++;
      }
    }
  }
}

//void kmp(string& t,string& p)
//{
    //int n = (int)t.size();
    //int m = (int)p.size();
    
    //vector<int> preffix_table(m);
    //compute_preffix_table(p, preffix_table);
    
    //int i = 0;
    //int j = 0;
    
    //while(i < n)
    //{
        //if(t[i] != p[j])
        //{
            //if(j == 0)
                //i += 1;
            //else
                //j = preffix_table[j - 1];
        //}
        //else
        //{
            //i += 1;
            //j += 1;
            //if(j == m)
            //{
                //cout << i - j << " ";
                //j = preffix_table[j - 1];
            //}
        //}
    //}
//}

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //string t, p;
    //cin >> t >> p;
    //kmp(t, p);
    string s; 
    cin >> s;
    int n = (int)s.size();
    
    string rev(s);
    reverse(rev.begin(), rev.end());
    
    string t = s + "#" + rev;
    int tSize = (int)t.size();
    
    vector<int> preffix_table(tSize);
    compute_preffix_table(t, preffix_table);
    cout << n + (n - preffix_table[tSize - 1]) << endl;
    
    return 0;
}
