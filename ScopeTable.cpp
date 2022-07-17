#include "ScopeTable.h"

ScopeTable::ScopeTable(int sibling, int n, ScopeTable *parentScope)
{

    // this-> level = ;
    this->id = sibling + 1;
    this->child = 0;

    this->size = n;
    this->parentScope = parentScope;
    // cout<<this->parentScope<<endl;
    this->bucket = new SymbolInfo *[n];
    for (int i = 0; i < n; i++)
    {

        this->bucket[i] = NULL;
    }
    // cout << "scope with id " << getShowId()<< " created" << endl;
    // " created and parentScope is"<< parentScope << endl;
}

ScopeTable::~ScopeTable()
{

    for (int i = 0; i < this->size; i++)
    {

        SymbolInfo *temp = this->bucket[i];
        while (temp != NULL)
        {

            SymbolInfo *temp2 = temp;
            temp = temp->getNext();
            delete temp2;
        }
    }
    delete[] this->bucket;
}

bool ScopeTable::insert(string name, string type)
{

    // string name = symbol.getName();
    // string type = symbol.getType();

    int index = smdbHash(name) % this->size;
    SymbolInfo *temp = bucket[index];
    while (temp != NULL)
    {

        if (temp->getName() == name)
        {

            return false;
        }
        temp = temp->getNext();
    }
    SymbolInfo *newSymbol = new SymbolInfo(name, type);
    newSymbol->setNext(this->bucket[index]);
    this->bucket[index] = newSymbol;
    // cout << "Inserted " << name << " " << type << " in scope " << getShowId() <<" in index "<<  index << endl;
    // cout << "in bucket " << index << endl;
    return true;
}

bool ScopeTable::deleteSymbol(string name)
{

    int index = smdbHash(name) % this->size;
    SymbolInfo *temp = this->bucket[index];
    SymbolInfo *prev = NULL;
    while (temp != NULL)
    {

        if (temp->getName() == name)
        {

            if (prev == NULL)
            {

                this->bucket[index] = temp->getNext();
            }
            else
            {

                prev->setNext(temp->getNext());
            }
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->getNext();
    }
    return false;
}

SymbolInfo *ScopeTable::search(string name)
{

    int index = smdbHash(name) % this->size;
    SymbolInfo *temp = this->bucket[index];
    while (temp != NULL)
    {

        if (temp->getName() == name)
        {

            //  cout << "in bucket " << index ;
            // cout << "found in scope " << getShowId() <<" in index "<< index<< endl;
            return temp;
        }
        temp = temp->getNext();
    }
    // if (this->parentScope != NULL)
    // {

    //     // cout << "Searching in parent scope" << endl;
    //     // cout << "in bucket " << index ;
    //     // cout << "in scope " << this->id ;
    //     return this->parentScope->search(name);
    // }
    return NULL;
}
// {
//
//     int index = smdbHash(symbol.getName()) % this->size;
//     SymbolInfo *temp = this->bucket[index];
//     while (temp != NULL)
//     {
//
//         if (temp->getName() == symbol.getName())
//         {
//
//             return temp;
//         }
//         temp = temp->getNext();
//     }
//     return NULL;
// }

void ScopeTable::print()
{

    // cout << "bucket " <<  << ": ";
    // cout << "Scope Table " << this->id << " show id "<< this->getShowId() << endl;
    for (int i = 0; i < this->size; i++)
    {

        SymbolInfo *temp = this->bucket[i];
        cout << i << "--> ";
        if (temp == NULL)
        {

            cout << endl;
        }

        while (temp != NULL)
        {

            cout << "< " << temp->getName() << " ," << temp->getType() << " >";
            // cout << temp->getName() << " " << temp->getType() << endl;
            temp = temp->getNext();
            // cout << temp;
        }
        cout << endl;
    }
}

// void ScopeTable::printAllScopes()
// {
//
//     cout << "Scope " << this->id << endl;
//     this->print();
//     if (this->parentScope != NULL)
//     {
//
//         this->parentScope->printAllScopes();
//     }
// }

ScopeTable *ScopeTable::getParentScope()
{

    // cout << "exit from scope " << this->id << endl;
    return this->parentScope;
}

int ScopeTable::getId()
{

    return this->id;
}

int ScopeTable::getLevel()
{

    return this->level;
}

int ScopeTable::getMaxLevel()
{

    return this->maxLevel;
}

void ScopeTable::setMaxLevel(int maxLevel)
{

    this->maxLevel = maxLevel;
}

void ScopeTable::setLevel(int level)
{

    this->level = level;
}

void ScopeTable::setParentScope(ScopeTable *parentScope)
{

    this->parentScope = parentScope;
}

int ScopeTable::getChild()
{

    return this->child;
}

void ScopeTable::setChild(int child)
{

    this->child = child;
}

int ScopeTable::getSibling()
{

    return this->sibling;
}

void ScopeTable::setSibling(int sibling)
{

    this->sibling = sibling;
}

string ScopeTable::getShowId()
{

    string str = to_string(this->id);
    ScopeTable *temp = this->parentScope;

    while (temp != NULL)
    {

        str = to_string(temp->getId()) + "." + str;
        temp = temp->getParentScope();
    }
    // cout << "show id " << str << endl;
    // {
    //
    // }

    // return "Scope " + to_string(this->id);
    return str;
}

void ScopeTable::printInFile(ofstream &outFile)
{

    // outFile << "Scope " << this->showId << endl;
    for (int i = 0; i < this->size; i++)
    {

        SymbolInfo *temp = this->bucket[i];

       
        if (temp != NULL)
        {
            if (temp->getName() != "")
            {   outFile << endl;
                outFile << i << "--> ";
               
            }
        }

        while (temp != NULL)
        {
            if (temp->getName() != "")
            {
                outFile << "< " << temp->getName() << " ," << "ID" << " >";
            }
            temp = temp->getNext();
        }
       
    }
    // outFile << endl;
}
// {

//     for (int i = 0; i < this->size; i++)
//     {

//         SymbolInfo *temp = this->bucket[i];
//         while (temp != NULL)
//         {

//             fprintf(fp, "%d --> < %s : %s >\n", i, temp->getName().c_str(), temp->getType().c_str());
//             temp = temp->getNext();
//         }
//     }
// }
