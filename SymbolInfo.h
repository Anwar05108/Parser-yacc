// #include<string>
#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class SymbolInfo
{
private:
    /* data */
    string name;
    string type;
    int arraySize;
    bool defined;

    

    SymbolInfo *next;

public:
struct nodeParam
    {
        string name;
        string type;
    } tempNodeParam;

    vector<nodeParam> paramList;
    SymbolInfo(string, string);
    ~SymbolInfo();
    SymbolInfo *getNext();
    void setNext(SymbolInfo *);
    string getName();
    string getType();
    void setName(string);
    void setType(string);
    void setArraySize(int);
    int getArraySize();
    void setDefined(bool);
    bool getDefined();

    void setFunction(string, string, vector<nodeParam>);
    vector<nodeParam> getParamList();
    void insertParameter(string, string);
    string getParameterName(int);
    string getParameterType(int);
    int getParamSize();
};
