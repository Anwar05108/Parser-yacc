#include "SymbolInfo.h"
#include <bits/stdc++.h>





SymbolInfo::SymbolInfo(string name,string type)
{
    
    this->next = NULL;
    this -> name = name;
    this -> type = type;

}

SymbolInfo::~SymbolInfo()
{
    
    // this->next = NULL;
}

void SymbolInfo::setNext(SymbolInfo* next)
{
    
    this->next = next;
}

SymbolInfo* SymbolInfo::getNext()
{
    
    return this->next;
}

string SymbolInfo::getName()
{
    
    return this->name;
}

string SymbolInfo::getType()
{
    
    return this->type;
}

void SymbolInfo::setName(string name)
{
    
    this->name = name;
}

void SymbolInfo::setType(string type)
{
    
    this->type = type;
}


void SymbolInfo::setArraySize(int arraySize)
{
    
    this->arraySize = arraySize;
}


int SymbolInfo::getArraySize()
{
    
    return this->arraySize;
}


void SymbolInfo::setDefined(bool defined)
{
    
    this->defined = defined;
}


bool SymbolInfo::getDefined()
{
    
    return this->defined;
}


void SymbolInfo::setFunction(string name,string type,vector<nodeParam> paramList)
{
    
    this->name = name;
    this->type = type;
    this->paramList = paramList;
}

vector<struct SymbolInfo::nodeParam> SymbolInfo::getParamList()
{
    
    return this->paramList;
}


void SymbolInfo::insertParameter(string name,string type)
{
    
    struct nodeParam tempNodeParam;
    tempNodeParam.name = name;
    tempNodeParam.type = type;
    this->paramList.push_back(tempNodeParam);
}




string SymbolInfo::getParameterName(int index)
{
    
    return this->paramList[index].name;
}


string SymbolInfo::getParameterType(int index)
{
    
    return this->paramList[index].type;
}

int SymbolInfo::getParamSize()
{
    
    return this->paramList.size();
}



