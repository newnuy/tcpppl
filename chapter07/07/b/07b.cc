#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Tnode {
    char *word;
    int count;
    Tnode *left;
    Tnode *right;
};

Tnode *insertWord(Tnode *p, const char *word)
{
    if (p == 0) {
        p = new Tnode;
        p->word = new char[strlen(word)+1];
        strcpy(p->word, word);
        p->count = 1;
        p->left = 0;
        p->right = 0;
    }
    else {
        int result = strcmp(word, p->word);
        if (result < 0)
            p->left = insertWord(p->left, word);
        else if (result > 0)
            p->right = insertWord(p->right, word);
        else
            ++(p->count);
    }

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
    while (cin >> word) {
        root = insertWord(root, word.c_str());
    }

    printWord(root);

    return 0;
}
