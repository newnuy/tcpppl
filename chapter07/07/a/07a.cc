#include <iostream>
#include <string>

using namespace std;

struct Tnode {
    string word;
    int count;
    Tnode *left;
    Tnode *right;
};

Tnode *insertWord(Tnode *p, const string &word)
{
    if (p == 0) {
        p = new Tnode;
        p->word = word;
        p->count = 1;
        p->left = 0;
        p->right = 0;
    }
    else if (word < p->word)
        p->left = insertWord(p->left, word);
    else if (word > p->word)
        p->right = insertWord(p->right, word);
    else
        ++(p->count);

    return p;
}

void printWord(Tnode *p)
{
    if (p == 0)
        return;
    printWord(p->left);
    cout << p->word << "  " << p->count << endl;
    printWord(p->right);
}

int main()
{
    Tnode *root = 0;

    string word;
    while (cin >> word)
        root = insertWord(root, word);

    printWord(root);

    return 0;
}
