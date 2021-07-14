//https://www.geeksforgeeks.org/trie-insert-and-search/
#include <bits/stdc++.h>
using namespace std;
    
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (52)
  
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) (26+(int)c - (int)'a')
#define CHAR_TO_INDEXUP(c) ((int)c - (int)'A')
  
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
  
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
  
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;
  
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
  
    if (pNode)
    {
        int i;
  
        pNode->isEndOfWord = false;
  
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
  
    return pNode;
}
  
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
  
    struct TrieNode *pCrawl = root;
  
    for (level = 0; level < length; level++)
    {
        if(key[level] >= 65 && key[level] <= 90)
            index = CHAR_TO_INDEXUP(key[level]);
        else
            index = CHAR_TO_INDEX(key[level]);
  
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
  
        pCrawl = pCrawl->children[index];
    }
  
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
  
// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
  
    for (level = 0; level < length; level++)
    {
        if(key[level] >= 65 && key[level] <= 90)
            index = CHAR_TO_INDEXUP(key[level]);
        else
            index = CHAR_TO_INDEX(key[level]);
  
        if (!pCrawl->children[index])
            return false;
  
        pCrawl = pCrawl->children[index];
    }
  
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

bool isLeafNode(struct TrieNode* root)
{
    return root->isEndOfWord != false;
}

int ind=0;
char last[1001];
void display(struct TrieNode* root, char str[], int level, int what)
{
    if (isLeafNode(root)) 
    {
        if (what==0)
        {    
            str[level] = '\0';
            cout <<++ind<<". "<< str << endl;
            strcpy(last, str);
        }
        if (what==1)
        {    
            str[level] = '\0';
            cout << str;
            if(strcmp(str, last)!=0)
                cout<<"--<3--";
        }
    }
  
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) 
    {
        if (root->children[i]) 
        {
            // cout<<i<<endl;
            if(i >= 0 && i <= 25)
                str[level] = i + 'A';
            else
                str[level] = i + 'a' - 26;
            // cout<<" -O- "<<str[level]<<endl;
            display(root->children[i], str, level + 1, what);
        }
    }
}

int main()
{
    struct TrieNode *root = getNode();    
  
    int n;
    cin>>n;
    char keys[1001];
 
    while(scanf("%s", keys) != EOF)
    {
        if(strcmp(keys," ")==0)
            continue;
        else
            insert(root, keys);
    }

    int level = 0;
    char str[10001];
    display(root, str, level, 0);
    display(root, str, level, 1);
    return 0;
}