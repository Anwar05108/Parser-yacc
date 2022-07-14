// #include "SymbolTable.cpp"
#include "SymbolInfo.cpp"

using namespace std;

class ScopeTable
{
private:
    /* data */
    SymbolInfo **bucket;
    int id;
    int size;
    int level = 0;
    int maxLevel;
    int child, sibling;
    string showId;

    // int

    ScopeTable *parentScope;
    // int smdbHash(string);
    int smdbHash(string str)
    {
        int hash = 0;
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            hash = (hash << 4) + str[i];
            int x = hash & 0xF0000000;
            if (x != 0)
            {
                hash ^= (x >> 24);
            }
            hash &= ~x;
        }
        return hash;
    }

public:
    ScopeTable(int, int, ScopeTable *);
    ~ScopeTable();
    bool insert(string, string);
    SymbolInfo *search(string);
    void print();
    // void print(int);
    // void print(int,int);
    void printAllScopes();
    bool deleteSymbol(string);
    ScopeTable *getParentScope();
    void setParentScope(ScopeTable *);
    int getId();
    int getLevel();
    int getMaxLevel();
    void setMaxLevel(int);
    void setLevel(int);
    int getChild();
    int getSibling();
    void setChild(int);
    void setSibling(int);
    string getShowId();
    void printInFile(ofstream &);
};