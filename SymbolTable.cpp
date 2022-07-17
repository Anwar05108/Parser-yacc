#include "SymbolTable.h"
// #include "SymbolInfo.h"
#include <string>
#include <iostream>
// #include "ScopeTable.h"

SymbolTable::SymbolTable(int n)
{
    this->scopeTable = new ScopeTable(0,n, NULL);
}


SymbolTable::~SymbolTable()
{
    delete this->scopeTable;

    
}

bool SymbolTable::insert(string name, string type)
{
    return scopeTable->insert(name, type);
}

// bool SymbolTable::delete(SymbolInfo info)
// {
//     return scopeTable->deleteSymbol(info.getName());
// }

void SymbolTable::enterScope(int size)
{
    int noChild = scopeTable -> getChild();
    scopeTable -> setChild(noChild + 1);
    // cout << "scope with id " << scopeTable-> getShowId() << " created" << endl;
    ScopeTable *newScopeTable = new ScopeTable(noChild, size, this->scopeTable);
    // scopeTable = new ScopeTable(id, size, scopeTable);


    // newScopeTable-> setParentScope(scopeTable);
    // newScopeTable -> setLevel(scopeTable->getLevel() + 1);
    // newScopeTable -> setMaxLevel(scopeTable->getMaxLevel());
    this->scopeTable = newScopeTable;

    // cout << "scope with " << id <<" created" << endl;
}

void SymbolTable:: exitScope()
{       
    // cout << "scope with id " << scopeTable->getShowId() <<" removed" << endl;
    // ScopeTable *nextScope = 
    ScopeTable *temp = scopeTable;
     scopeTable = temp->getParentScope();
}

SymbolInfo* SymbolTable::search(string name)
{
    return scopeTable->search(name);
}

void SymbolTable::printCurrentScope()
{
    cout << "printing current scope" << endl;
    scopeTable->print();
}

void SymbolTable::printAllScopes()

{
    // cout << "print all scopes" << endl;
    ScopeTable *temp = scopeTable;
    

    //temp = scopeTable;
    
    while (temp != NULL)
    {
        cout <<" ScopeTable: " << temp->getShowId() << endl;
        temp->print();
        temp = temp->getParentScope();
        cout<<endl;
    }
    // while (scopeTable != NULL)
    // {
    //     scopeTable->print();
    //     scopeTable = scopeTable->getParentScope();
    // }
    // {
    //     /* code */
    // }
    
    // scopeTable->printAllScopes();
}


void SymbolTable::printAllScopesInFile(ofstream &file)
{
    ScopeTable *temp = scopeTable;
    file << "print all scopes" << endl;
    
    while (temp != NULL)
    {
        file <<" ScopeTable: " << temp->getShowId() << endl;

        temp->printInFile(file);
        temp = temp->getParentScope();
        file<<endl;
    }
}


bool SymbolTable::deletef(string name)
{
    return scopeTable->deleteSymbol(name);
}


ScopeTable* SymbolTable::getParentScope()
{
    return scopeTable->getParentScope();
}

ScopeTable* SymbolTable::getScopeTable()
{
    return scopeTable;
}


SymbolInfo* SymbolTable::searchInGlobalScope(string name)
{
    ScopeTable *temp = scopeTable;
    while (temp != NULL)
    {
        SymbolInfo *info = temp->search(name);
        if (info != NULL)
        {
            return info;
        }
        temp = temp->getParentScope();
    }
    return NULL;
}
