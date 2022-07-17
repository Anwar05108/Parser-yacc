%{
#include<stdio.h>
#include<string.h>
#include"SymbolTable.cpp"
#include<fstream>
#include<iostream>
#include<bits/stdc++.h>
#include"Parameter.h"

int lineCount = 1;
int errorCount = 0;
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

struct nodeVar{
    string name;
    string type;
    int arraySize;
}tempNodeVar;

struct nodeParam{
    string name;
    string type;
}tempNodeParam;


vector<nodeVar> variable_list;
vector<nodeParam> parameter_list;

SymbolTable symbolTable(30);

// FILE *errorFile, *logFile;
ofstream errorFile, logFile;

extern FILE *yyin;
// extern ifstream yyin;

int yyparse(void);
int yylex(void);

void yyerror(const char* str) {
}
    
%}


%union {
    SymbolInfo *symbolInfo;
}


%token VOID NEWLINE NUMBER LESS GREATER EQUAL IF FOR ELSE WHILE BREAK CONTINUE CASE DEFAULT SWITCH DO RETURN
%token INCOP DECOP ASSIGNOP LOGICNOT NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD
%token COMMA SEMICOLON COLON PRINTLN
%token INT FLOAT DOUBLE CHAR 
%token PLUS MINUS SLASH ASTERISK

%token<symbolInfo>ADDOP 
%token<symbolInfo>MULOP
%token<symbolInfo>RELOP
%token<symbolInfo>BITOP
%token<symbolInfo>LOGICOP



%token<symbolInfo>ID
%token<symbolInfo>CONST_CHAR
%token<symbolInfo>CONST_INT
%token<symbolInfo>CONST_FLOAT

%type <symbolInfo> start program unit 

%type <symbolInfo> variable_declaration function_declaration function_definition declaration_list

%type <symbolInfo> statement_list  parameter_list 
%type <symbolInfo> expression compound_statement logic_expression rel_expression simple_expression term factor
%type <symbolInfo> type_specifier
%type<symbolInfo> unary_expression variable argument_list arguments
%type <symbolInfo> statement expression_statement

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%


start: program
    {
     $$ = $1;
     logFile << "line number" << lineCount << ": " ;

    logFile << "start: program" << endl;
    // symbolTable.printAllScopes();
    
    }
    
    ;

program : program unit
            {
            $$ = new SymbolInfo( $1->getName() +"\n" +$2->getName(),"SYMBOL_PROGRAM");
            logFile << "line number" << lineCount << ": " ;
            logFile << "program: program unit \n\n" << $$->getName() << endl<<endl;
            }
        | unit
            {
            $$ = $1;
            logFile << "line number" << lineCount << ": " ;
            logFile << "program:  unit \n\n" << $$->getName() << endl<<endl;
            }
            
            
        ;

unit : variable_declaration
        {
        $$ = $1;
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: variable_declaration \n\n" << $$->getName() << endl<<endl;
        // symbolTable.printAllScopesInFile(logFile);

        }
    | function_declaration
        {
        $$ = $1;
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: function_declaration \n\n" << $$->getName() << endl<<endl;

        }
    | function_definition
        {
        $$ = $1;
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: function_definition \n\n" << $$->getName() << endl<<endl;


        }
    ;

function_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
                        {
                        
                      $$ = new SymbolInfo($1->getName()+" "+ $2->getName()+"("+$4->getName()+");", "function_declaration");
                        string functionName = $2->getName();
                        string functionType = $1->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            $$->setDefined(false);
                        }
                        else
                        {
                            errorCount++;
                        logFile << "line number" << lineCount << ": " ;
                            
                            logFile << "error: function "<<functionName<<" already declared\n\n";
                            errorFile << "error: function "<<functionName<<" already declared\n";
                        }
                        // symbolTable.printCurrentScope();
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
                        logFile << endl<<endl;
                        logFile << $$->getName();
                        logFile << endl << endl;

                        SymbolInfo *temp = symbolTable.search(functionName);
                        if(temp == NULL)
                        {
                            errorFile<<"error: function "<<functionName<<" not found\n";
                        }
                        else
                        {

                        for(int i = 0; i < parameter_list.size(); i++)
                        {
                            string parameterName = parameter_list[i].name;
                            string parameterType = parameter_list[i].type;
                            temp->insertParameter(parameterName, parameterType);
                        }
                        }

                      
                       
                        parameter_list.clear();
                        
                        }
                    |   type_specifier ID LPAREN  RPAREN SEMICOLON
                    {
                        $$ = new SymbolInfo($1->getName()+" "+ $2->getName()+"();", "SYMBOL_FUNCTION");
                        string functionName = $2->getName();
                        string functionType = $1->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            $$->setDefined(false);
                        }
                        else
                        {
                            errorCount++;
                        logFile << "line number" << lineCount << ": " ;
                            
                            logFile << "error: function "<<functionName<<" already declared\n\n";
                            errorFile << "error: function "<<functionName<<" already declared\n";
                        }
                        parameter_list.clear();
                        // symbolTable.printCurrentScope();
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
                        logFile << endl<<endl;
                        logFile << $$->getName();
                        logFile << endl << endl;

                        }                                   
                    ;


function_definition : type_specifier ID LPAREN parameter_list RPAREN  
                        
                        {
                        string functionName = $2->getName();
                        string functionType = $1->getName();
                        SymbolInfo* function = symbolTable.search(functionName);
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            // $$->setDefined(true);
                            symbolTable.enterScope(30);
                            // logFile << "size of parameter list: " << parameter_list.size() << endl;
                            for(int i = 0; i < parameter_list.size(); i++)
                            {
                                // logFile << "parameter_list: " << parameter_list[i].name << " " << parameter_list[i].type << endl;
                                string parameterName = parameter_list[i].name;
                                string parameterType = parameter_list[i].type;
                                symbolTable.insert(parameterName, parameterType);
                            }
                        }
                        else
                        {
                            if(function->getDefined() == false)
                            {
                                symbolTable.insert(functionName, functionType);
                                // $$->setDefined(true);
                            }
                            else
                            {
                                errorCount++;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "error: function "<<functionName<<" already defined\n\n";
                                errorFile << "error: function "<<functionName<<" already defined\n";
                            }
                        

                        SymbolInfo *temp = symbolTable.search(functionName);
                       symbolTable.enterScope(30);

                       if(temp != NULL){

                        for(int i = 0; i < temp->getParamSize(); i++ ){
                            string declaredParameterName = temp->getParameterName(i);
                            string declaredParameterType = temp->getParameterType(i);

                            
                       
                            string definedParameterName = parameter_list[i].name;
                            string definedParameterType = parameter_list[i].type;
                            if(declaredParameterType != definedParameterType ){
                                errorCount++;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "error: parameter "<<definedParameterName<<" has wrong type as declared\n\n";
                                errorFile << "error: parameter "<<definedParameterName<<" has wrong type as declared\n";
                            }else{
                            cout << symbolTable.insert(definedParameterName, definedParameterType);
                            }
                        }}
                    }
                        // symbolTable.printAllScopesInFile(logFile);
                        logFile<<"enterScope";
                        parameter_list.clear();
                        // logFile << "line number" << lineCount << ": " ;
                        // logFile << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl<<endl;
                        // logFile <<$$->getName()<< endl<<endl;
                        


                        }
                        compound_statement{
                        $$ = new SymbolInfo($1->getName()+" "+$2->getName()+" ( " +$4->getName()+" ) "+$7->getName() + "\n"  , "SYMBOL_FUNCTION");

                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl<<endl;
                        logFile <<$$->getName()<< endl<<endl;
                        }
                    |
                    type_specifier ID LPAREN RPAREN 
                    {
                        string functionName = $2->getName();
                        string functionType = $1->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {

                            symbolTable.insert(functionName, functionType);

                        }
                        else
                        {

                        }
                        symbolTable.enterScope(30);
                        
                    }
                    compound_statement{
                        $$ = new SymbolInfo($1->getName()+" "+$2->getName()+" ( ) "+$6->getName() + "\n"  , "SYMBOL_FUNCTION");
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_definition : type_specifier ID LPAREN RPAREN compound_statement"<<endl<<endl;
                        logFile <<$$->getName()<< endl<<endl;
                    }
                    ;


parameter_list : parameter_list COMMA type_specifier ID
                    
                    {
                    $$ = new SymbolInfo($1->getName() + "," + $3->getName() + " " + $4->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : parameter_list COMMA type_specifier ID"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    tempNodeParam.name = $4->getName();
                    tempNodeParam.type = $3->getName();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
                | parameter_list COMMA type_specifier
                    {
                    $$ = new SymbolInfo($1->getName() + "," + $3->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : parameter_list COMMA type_specifier"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    tempNodeParam.name = "";
                    tempNodeParam.type = $3->getName();
                    parameter_list.push_back(tempNodeParam);


                    }
                | type_specifier ID
                    {
                    $$ = new SymbolInfo($1->getName() + " " + $2->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : type_specifier ID"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    tempNodeParam.name = $2->getName();
                    tempNodeParam.type = $1->getName();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
                | type_specifier
                    {
                    $$ = new SymbolInfo($1->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : type_specifier"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;

                    tempNodeParam.name = "";
                    tempNodeParam.type = $1->getType();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
                ;







compound_statement : LCURL statement_list RCURL{
    $$ = new SymbolInfo("{\n"+$2->getName()+"\n}", "SYMBOL_COMPOUND_STATEMENT");
    logFile << "line number" << lineCount << ": " ;
    logFile << "compound_statement : LCURL statement_list RCURL"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
    symbolTable.printAllScopesInFile(logFile);
    symbolTable.exitScope();
    
}
| LCURL RCURL {
    $$ = new SymbolInfo("{\n}", "SYMBOL_COMPOUND_STATEMENT");
    logFile << "line number" << lineCount << ": " ;
    logFile << "compound_statement : LCURL RCURL"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

variable_declaration : type_specifier declaration_list SEMICOLON
                        {

                            string variable_name = $2->getName();
                            string variable_type = $1->getName();
                            if(variable_type == "void"){
                                errorCount++;
                                errorFile << "line number" << lineCount << ": " ;
                                errorFile << "variable_declaration: void type is not allowed" << endl;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "variable_declaration: void type is not allowed" << endl;
                            }
                            else{
                                for(int i = 0;i < variable_list.size();i++){
                                    symbolTable.insert(variable_list[i].name, $1->getName());
                                    if(variable_list[i].arraySize > 0){
                                        SymbolInfo *temp = symbolTable.search(variable_list[i].name);
                                        if(temp != NULL){
                                            temp->setArraySize(variable_list[i].arraySize);
                                        }
                                        // temp->setArraySize(variable_list[i].arraySize);
                                        logFile << "array size of " << variable_list[i].name << " is " << temp->getArraySize() << endl;
                                    }
                                }
                            }

                            variable_list.clear();

                       
                        
                        $$ = new SymbolInfo($1->getName() + " " +$2->getName()+";", $1->getType());
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "variable_declaration: type_specifier declaration_list SEMICOLON \n\n" << $$->getName() << endl<<endl;

                        }
                   
                    ;

                    type_specifier : INT
                {
                $$ = new SymbolInfo("int", "int");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : INT"<<endl<<endl ;
                logFile << $$->getName() << endl<<endl;

                }
            | FLOAT
                {
                $$ = new SymbolInfo("float", "float");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : FLOAT"<<endl<<endl ;
                logFile << $$->getName() << endl<<endl;

                }
            | DOUBLE
                {
                $$ = new SymbolInfo("double", "double");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : DOUBLE"<<endl<<endl ;
                logFile << $$->getName() << endl<<endl;

                }
            | VOID
                {
                $$ = new SymbolInfo("void", "VOID");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : VOID"<<endl<<endl ;
                logFile << $$->getName() << endl<<endl;

                }
            ;






declaration_list : declaration_list COMMA ID

            {
$$ = new SymbolInfo($1->getName() + "," +$3->getName(), $3->getType());
   tempNodeVar.name = $3->getName();
    tempNodeVar.type = $3->getType();
    tempNodeVar.arraySize = -1;
    variable_list.push_back(tempNodeVar);
    if(symbolTable.search($3->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $3->getName() << " already declared" << endl;
        errorCount++;
    }
    
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: declaration_list COMMA ID \n\n" << $$->getName() << endl<<endl;
            }
| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
{
$$ = new SymbolInfo($1->getName() + "," +$3->getName()+"["+$5->getName()+"]", $3->getType());
    tempNodeVar.name = $3->getName();
    tempNodeVar.type = "array";

    tempNodeVar.arraySize = stoi($5->getName());
    variable_list.push_back(tempNodeVar);
    if(symbolTable.search($3->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $3->getName() << " already declared" << endl;
        errorCount++;
    }
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: declaration_list COMMA ID LTHIRD CONST INT RTHIRD \n\n" << $$->getName() << endl<<endl;
}
| ID
{
$$ = new SymbolInfo($1->getName(), $1->getType());
    tempNodeVar.name = $1->getName();
    // SymbolInfo *temp; 
    // temp = symbolTable.search($1->getName());
    string type = "";
    //  type =  temp->getType();
    tempNodeVar.type = type;
    tempNodeVar.arraySize = -1;
        variable_list.push_back(tempNodeVar);
    if(symbolTable.search($1->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " already declared" << endl;
        errorCount++;
    }
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: ID \n\n" << $$->getName() << endl<<endl;
}
| ID LTHIRD CONST_INT RTHIRD{
    $$ = new SymbolInfo($1->getName() + " [" + $3->getName()+"]", $1->getType());
    tempNodeVar.name = $1->getName();
    tempNodeVar.type = "array";
    tempNodeVar.arraySize = stoi($3->getName());
    

    variable_list.push_back(tempNodeVar);
    if(symbolTable.search($1->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " already declared" << endl;
        errorCount++;
    }

   
    
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: ID LTHIRD CONST INT RTHIRD \n\n" << $$->getName() << endl<<endl;
}
;


statement_list : statement
                    {
                    $$ = $1;
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "statement_list : statement"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    }
                | statement_list statement
                    {
                    $$ = new SymbolInfo($1->getName() + "\n" + $2->getName(), "SYMBOL_STATEMENT_LIST");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "statement_list : statement_list statement"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    }
                ;

statement : variable_declaration
            {
            $$ = $1;
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : variable_declaration"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;

            }
        | expression_statement
            {
            $$ = $1;
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : expression_statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | {symbolTable.enterScope(30);}compound_statement
            {
            $$ = $2;
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : compound_statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | FOR LPAREN expression_statement expression_statement expression
    RPAREN statement
    {
    $$ = new SymbolInfo("for"+$3->getName()+$4->getName()+$5->getName(), "SYMBOL_FOR_STATEMENT");
    logFile << "line number" << lineCount << ": " ;
    logFile << "statement : FOR LPAREN expression statement expression statement expression RPAREN statement"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
    }
        | WHILE LPAREN expression RPAREN statement
            {
            $$ = new SymbolInfo("while("+$3->getName()+")"+$5->getName(), "SYMBOL_WHILE_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : WHILE LPAREN expression RPAREN statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
            {
            $$ = new SymbolInfo("if("+$3->getName()+")"+$5->getName(), "SYMBOL_IF_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : IF LPAREN expression RPAREN statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | IF LPAREN expression RPAREN statement ELSE statement
            {
            $$ = new SymbolInfo("if("+$3->getName()+")"+$5->getName()+"else"+$7->getName(), "SYMBOL_IF_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | RETURN expression SEMICOLON
            {
            $$ = new SymbolInfo ("return "+$2->getName()+";", "SYMBOL_RETURN_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : RETURN expression"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }   
        | PRINTLN LPAREN ID RPAREN SEMICOLON
            {
                SymbolInfo *temp = symbolTable.search($3->getName());
            if(symbolTable.search($3->getName()) == NULL)
            {
                errorFile << "line number" << lineCount << ": " ;
                errorFile << "error: variable " << $3->getName() << " not declared" << endl;
                errorCount++;
            }
            else
            {
                if(temp != NULL){
               if(temp->getArraySize() == -2){
                    errorFile << "line number" << lineCount << ": " ;
                    errorFile << "error: variable " << $3->getName() << " is a function" << endl;
                    errorCount++;
                }
               }}
            
            $$ = new SymbolInfo ("printf("+$3->getName()+");", "statement");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : PRINTLN LPAREN expression RPAREN SEMICOLON"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }   
        ;



expression_statement :  SEMICOLON
                        {
                        $$ = new SymbolInfo(";", "SYMBOL_EXPRESSION_STATEMENT");
                        
                        }
            | expression SEMICOLON
                        {
                        $$ = new SymbolInfo($1->getName()+";", "SYMBOL_EXPRESSION_STATEMENT");
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "expression_statement : expression SEMICOLON"<<endl<<endl ;
                        logFile<< $$->getName() << endl<<endl;
                        }
                    ;

variable : ID{
    SymbolInfo *temp = symbolTable.search($1->getName());
    if(temp != NULL){

    $$ = new SymbolInfo($1->getName(), temp->getType());
    }
    else{
        $$ = new SymbolInfo($1->getName(), "undeclared");
    }
    logFile << "line number" << lineCount << ": " ;
    logFile << "variable : ID"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;

}
| ID LTHIRD expression RTHIRD{
    SymbolInfo *currentId = symbolTable.search($1->getName());
    if(currentId == NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " not declared" << endl;
        errorCount++;
    }
    else{
     if(currentId->getArraySize() < 0)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " is not an array" << endl;
        errorCount++;
    }
    else{
     if(currentId->getArraySize() <= stoi($3->getName()))
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " is out of range. array size: " << currentId->getArraySize() << endl;
        errorCount++; 
    }
     if($3->getType() != "int")
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: index of variable " << $1->getName() << " is not of type INT" << endl;
        errorCount++;
    }}}
    
    $$ = new SymbolInfo($1->getName()+"["+$3->getName()+"]", $1->getType());
    logFile << "line number" << lineCount << ": " ;
    logFile << "variable : ID LTHIRD expression RTHIRD"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
};


expression : logic_expression{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : logic expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}

| variable ASSIGNOP logic_expression{
    logFile << $1->getType()<< $3->getType() << endl;
    logFile << $3->getName() << endl;
    logFile << $3->getArraySize() << endl;
    logFile << $3->getArraySize() << endl;
    // SymbolInfo *leftVar = symbolTable.search($1->getName());
    // SymbolInfo *rightVar = symbolTable.search($3->getName());
    if(($1->getType() == "int") || ($3->getType() == "float")){
        if($1->getArraySize()>0){
        if($3 -> getArraySize() == -1){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: variable " << $1->getName()<<" "<<$1->getType() << " is an array and cannot be assigned to a variable" << endl;
            errorCount++;
        }
    }
    else if($1->getType() != $3->getType())
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName()<<" "<<$1->getType() << " is not of type " << $3->getType() << endl;
        errorCount++;
    }
    }
    else{
    if($1->getType() == "undeclared"){
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " not declared" << endl;
        errorCount++;
    }
    if($3->getType() == "undeclared"){
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $3->getName() << " not declared" << endl;
        errorCount++;
    }}
   
    
    
    // if($1->getArraySize() != -1 && $3->getArraySize() == -1)
    // {
    //     errorFile << "line number" << lineCount << ": " ;
    //     errorFile << "error: variable " << $1->getName() << " is an array and cannot be assigned to" << endl;
    //     errorCount++;
    // }
    // if($1->getArraySize() == -1 && $3->getArraySize() != -1)
    // {
    //     errorFile << "line number" << lineCount << ": " ;
    //     errorFile << "error: variable " << $1->getName() << " is not an array and cannot be assigned to" << endl;
    //     errorCount++;
    // }
   
    $$ = new SymbolInfo($1->getName()+"="+$3->getName(), "SYMBOL_ASSIGNMENT_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : variable ASSIGNOP logic expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

logic_expression : rel_expression {
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "logic_expression : rel_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| rel_expression LOGICOP rel_expression {
    string type = "int";
    if($1->getType() != "int" || $3->getType() != "int")
    {
        type = "error";
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: operands of logical operator are not of type INT" << endl;
        errorCount++;
    }
   
    $$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), type);
    logFile << "line number" << lineCount << ": " ;
    logFile << "logic_expression : logic_expression AND rel_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
};



rel_expression : simple_expression
{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : simple expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| simple_expression RELOP simple_expression{
    $$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), $1->getType());
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : simple_expression RELOP simple_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
};

simple_expression : term{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "simple_expression : term"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
|simple_expression ADDOP term
{
    //problem in getting the plus and minus
    string type;
    if($1->getType() == "int" && $3->getType() == "int")
    {
        type = "int";
    }
    else
    {
        type = "float";
    }
    $$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), type);
    logFile << "line number" << lineCount << ": " ;
    logFile << "simple_expression : simple_expression ADDOP term"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

term : unary_expression {
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "term : unary_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
 | term MULOP unary_expression{

    string leftType = $1->getType();
    string rightType = $3->getType();
    string mulOperator = $2->getName();
    string type;
    if(mulOperator == "%"){
        if(leftType != "int" || rightType != "int"){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: modulo mulOperator can only be used with ints" << endl;
            errorCount++;
        }
    }
    else if(mulOperator == "*" || mulOperator == "/"){
        if(leftType != "int" || rightType != "int"){
            type = "float";
            
        }
    }

    if(mulOperator == "/" ){
        if($3->getName() == "0"){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: division by zero" << endl;
            errorCount++;
        }
    }

    if( mulOperator == "%"){
        if($3->getName() == "0"){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: modulo by zero" << endl;
            errorCount++;
        }
    }
    
    


    $$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), type);
    logFile << "line number" << lineCount << ": " ;
    logFile << "term : term MULOP unary_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

unary_expression: ADDOP unary_expression
{
    $$ = new SymbolInfo($1->getName()+$2->getName(), $2->getType());
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : ADDOP unary expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| NOT unary_expression
{
    $$ = new SymbolInfo(" !"+$2->getName(), $2->getType());
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : NOT unary_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| factor
{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "unary_expression : factor"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;


factor : variable
{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable\n\n" ;
    logFile<< $$->getName() << "\n\n";
}
 | ID LPAREN argument_list RPAREN
{
    cout << "factor : ID LPAREN argument_list RPAREN"<<endl;
    SymbolInfo *func = symbolTable.search($1->getName());
    string type = "";
    if(func == NULL){
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: function " << $1->getName() << " not declared" << endl;
        errorCount++;
        type = "undeclared";
    }
    else{
        type = func->getType();
        if(func->getArraySize() != -2){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: " << $1->getName() << " is not a function" << endl;
            errorCount++;
        }
        else{
            string argument_name_list = $3->getName();
            string argument_type_list = $3->getType();
            cout << "argument_name_list: " << argument_name_list << endl;
            cout << "argument_type_list: " << argument_type_list << endl;
            vector<string> argument_name_vector = split(argument_name_list, ",");
            vector<string> argument_type_vector = split(argument_type_list, ",");
           if(argument_name_vector.size() != func->getParamSize()){
                cout << "argument size:"<<argument_type_vector.size() << endl;
                cout << func->getParamSize() << endl;
                errorFile << "line number" << lineCount << ": " ;
                errorFile << "error: function " << $1->getName() << " expects " << func->getParamSize() << " arguments" << endl;
                errorCount++;
            }
            else{
                for(int i = 0; i < argument_name_vector.size(); i++){
                    cout << "argument_name_vector: " << argument_name_vector[i] << endl;
                    cout << "argument_type_vector: " << argument_type_vector[i] << endl;
                    cout << "func->getParameterName"<< func->getParameterName(i) << endl;
                    cout << "func->getParamType(i): " << func->getParameterType(i) << endl;

                    if(argument_type_vector[i] != func->getParameterType(i)){
                        errorFile << "line number" << lineCount << ": " ;
                        errorFile << "error: function " << $1->getName() << " expects " << func->getParameterType(i) << " as argument " << i+1 << endl;
                        errorCount++;
                    }
                }
            }
           }
        }
        
    

    $$ = new SymbolInfo($1->getName()+" ( "+$3->getName()+" )",type );
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : ID LPAREN argument_list RPAREN"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| LPAREN expression RPAREN
{
    $$ = new SymbolInfo(" ( "+$2->getName()+" ) ", $2->getType());
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : LPAREN expression RPAREN"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| CONST_INT
{
    $$ = yylval.symbolInfo;
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : CONST_INT"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| CONST_FLOAT{
    $$ = yylval.symbolInfo;
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : CONST_FLOAT"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}

| variable INCOP
{
    $$ = new SymbolInfo($1->getName()+"++", $1->getType());
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable INCOP"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}

| variable DECOP
{
    $$ = new SymbolInfo($1->getName()+"--", $1->getType());
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable DECOP"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}


;



argument_list : arguments{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : arguments"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| 
{
    $$ = new SymbolInfo("", "SYMBOL_ARGUMENT_LIST");
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list :"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

 arguments: arguments COMMA logic_expression
{
    $$ = new SymbolInfo($1->getName()+","+$3->getName(), $1->getType()+","+$3->getType());
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : arguments COMMA logic_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| logic_expression
{
    $$ = $1;
    // $$ = new SymbolInfo($1->getName(), "SYMBOL_ARGUMENTS");
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : logic_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;










%%

int main(int argc, char *argv[]) {
    	if(argc!=2){
		return 0;
	}
	

    FILE *fin = fopen(argv[1], "r");
	if(fin==NULL){
		return 0;
	}
	
    errorFile.open("1805108_error.txt");
    if(!errorFile){
        return 0;
    }

    logFile.open("1805108_log.txt");
    if(!logFile){
        return 0;
    }

    



	yyin = fin;
    yyparse();
    symbolTable.printAllScopesInFile(logFile);
    logFile << "total no. of errors: " << errorCount << endl;
    logFile << "total no. of lines" << lineCount << endl;
   
    logFile.close();
    errorFile.close();
    
    return 0;
}