#include <bits/stdc++.h>

using namespace std;

const int mxN = 500000;

struct Node{
    bool is_leaf;
    string word;
    unordered_map<char, Node*> nodes;
};

Node* createNode()
{
    Node* new_node = new Node();
    new_node->is_leaf = false;
    new_node->word = "";
    return new_node;
}

void add_word(Node* root, string& word, int i)
{
    if(i == (int)word.size())
    {
        root->is_leaf = true;
        root->word = word;
        return;
    }
    
    auto it = root->nodes.find(word[i]);
    if(it == root->nodes.end())
        root->nodes[word[i]] = createNode();

    add_word(root->nodes[word[i]], word, i+1);
}

void free_tree(Node* root)
{
    if(root == nullptr)
        return;
    
    for(auto& p : root->nodes)
        free_tree(p.second);
    
    delete root;
}


Node* solve(Node* root, string& word,int i)
{
    if(i == (int)word.size())
        return root;
    
    auto it = root->nodes.find(word[i]);
    if(it == root->nodes.end())
        return nullptr;
    return solve(root->nodes[word[i]], word, i + 1);
}

void print_words(Node* root)
{
    if(root->is_leaf)
    {
        cout << root->word << endl;
        return;
    }
    
    auto begin = root->nodes.begin();
    auto end = root->nodes.end();
    while(begin != end)
    {
        print_words(begin->second);
        begin++;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> reci(n);
    Node *root = createNode();
    
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        add_word(root, tmp, 0);
    }
    
    string s;
    cin >> s;
    
    Node* it = solve(root, s, 0);
    print_words(it);
    
    return 0;
}
