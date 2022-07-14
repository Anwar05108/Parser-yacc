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
%token COMMA SEMICOLON COLON
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

                        for(int i = 0; i < parameter_list.size(); i++)
                        {
                            string parameterName = parameter_list[i].name;
                            string parameterType = parameter_list[i].type;
                            temp->insertParameter(parameterName, parameterType);
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


function_definition : type_specifier ID LPAREN parameter_list RPAREN  compound_statement
                        
                        {
                        $$ = new SymbolInfo($1->getName()+" "+$2->getName()+" ( " +$4->getName()+" ) "+$6->getName() + "\n"  , "SYMBOL_FUNCTION");
                        string functionName = $2->getName();
                        string functionType = $1->getName();
                        SymbolInfo* function = symbolTable.search(functionName);
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            $$->setDefined(true);
                        }
                        else
                        {
                            if(function->getDefined() == false)
                            {
                                symbolTable.insert(functionName, functionType);
                                $$->setDefined(true);
                            }
                            else
                            {
                                errorCount++;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "error: function "<<functionName<<" already defined\n\n";
                                errorFile << "error: function "<<functionName<<" already defined\n";
                            }
                        }

                        SymbolInfo *temp = symbolTable.search(functionName);

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
                            symbolTable.insert(definedParameterName, definedParameterType);
                            }
                        }
                        parameter_list.clear();
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement";
                        logFile <<$$->getName()<< endl<<endl;
                        


                        }
                    |
                    type_specifier ID LPAREN RPAREN compound_statement
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
                        $$ = new SymbolInfo($1->getName()+" "+$2->getName()+" ( ) "+$5->getName() + "\n"  , "SYMBOL_FUNCTION");
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
                                    symbolTable.insert(variable_list[i].name, variable_list[i].type);
                                }
                            }

                            variable_list.clear();

                       
                        
                        $$ = new SymbolInfo($1->getName() + " " +$2->getName()+";", "SYMBOL_VARIABLE");
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "variable_declaration: type_specifier declaration_list SEMICOLON \n\n" << $$->getName() << endl<<endl;

                        }
                   
                    ;

                    type_specifier : INT
                {
                $$ = new SymbolInfo("int", "INT");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : INT"<<endl<<endl ;
                }
            | FLOAT
                {
                $$ = new SymbolInfo("float", "FLOAT");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : FLOAT"<<endl<<endl ;
                }
            | DOUBLE
                {
                $$ = new SymbolInfo("double", "DOUBLE");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : DOUBLE"<<endl<<endl ;
                }
            | VOID
                {
                $$ = new SymbolInfo("void", "VOID");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : VOID"<<endl<<endl ;
                }
            ;






declaration_list : declaration_list COMMA ID

            {
$$ = new SymbolInfo($1->getName() + "," +$3->getName(), "SYMBOL_VARIABLE");
   tempNodeVar.name = $3->getName();
    // tempNodeVar.type = $1->getName();
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
$$ = new SymbolInfo($1->getName() + "," +$3->getName()+"["+$5->getName()+"]", "SYMBOL_VARIABLE");
    tempNodeVar.name = $3->getName();
    // tempNodeVar.type = "array";

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
$$ = new SymbolInfo($1->getName(), "SYMBOL_VARIABLE");
    tempNodeVar.name = $1->getName();
    tempNodeVar.type = "SYMBOL_VARIABLE";
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
    $$ = new SymbolInfo($1->getName() + " [" + $3->getName()+"]", "SYMBOL_VARIABLE");
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
        | compound_statement
            {
            $$ = $1;
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
            $$ = new SymbolInfo ("return"+$2->getName()+";", "SYMBOL_RETURN_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : RETURN expression"<<endl<<endl ;
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
    $$ = new SymbolInfo($1->getName(), "SYMBOL_VARIABLE");
    logFile << "line number" << lineCount << ": " ;
    logFile << "variable : ID"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;

}
| ID LTHIRD expression RTHIRD{
    $$ = new SymbolInfo($1->getName()+"["+$3->getName()+"]", "SYMBOL_VARIABLE");
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
    $$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), "SYMBOL_LOGIC_EXPRESSION");
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
    $$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), "SYMBOL_REL_EXPRESSION");
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
    if($1->getType() == "INT" && $3->getType() == "INT")
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
    $$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), "SYMBOL_MUL_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "term : term MULOP unary_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

unary_expression: ADDOP unary_expression
{
    $$ = new SymbolInfo($1->getName()+$2->getName(), "SYMBOL_UNARY_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : ADDOP unary expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| NOT unary_expression
{
    $$ = new SymbolInfo(" !"+$2->getName(), "SYMBOL_UNARY_EXPRESSION");
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
    logFile << "factor : variable"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
 | ID LPAREN argument_list RPAREN
{
    $$ = new SymbolInfo($1->getName()+" ( "+$3->getName()+" )", "SYMBOL_FUNCTION_CALL");
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : ID LPAREN argument_list RPAREN"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| LPAREN expression RPAREN
{
    $$ = new SymbolInfo(" ( "+$2->getName()+" ) ", "SYMBOL_EXPRESSION");
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
    $$ = new SymbolInfo($1->getName()+"++", "SYMBOL_INC_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable INCOP"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}

| variable DECOP
{
    $$ = new SymbolInfo($1->getName()+"--", "SYMBOL_DEC_EXPRESSION");
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
    $$ = new SymbolInfo($1->getName()+$3->getName(), "SYMBOL_ARGUMENTS");
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : arguments COMMA logic_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| logic_expression
{
    $$ = $1;
    $$ = new SymbolInfo($1->getName(), "SYMBOL_ARGUMENTS");
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

    

    // symbolTable.printAllScopesInFile(logFile);


	yyin = fin;
    yyparse();
    symbolTable.printAllScopesInFile(logFile);
    logFile << "total no. of errors: " << errorCount << endl;
    logFile << "total no. of lines" << lineCount << endl;
   
    logFile.close();
    errorFile.close();
    
    return 0;
}