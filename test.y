%{
#include<stdio.h>
#include<string.h>
#include"SymbolTable.cpp"
#include<fstream>
#include<iostream>

int lineCount = 1;
int errorCount = 0;

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
%token INCOP DECOP ASSIGNOP ADDOP MULOP RELOP BITOP LOGICOP LOGICNOT NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD
%token COMMA SEMICOLON COLON
%token INT FLOAT DOUBLE CHAR 
%token PLUS MINUS SLASH ASTERISK

%token<symbolInfo>ID
%token<symbolInfo>CONST_CHAR
%token<symbolInfo>CONST_INT
%token<symbolInfo>CONST_FLOAT

%type <symbolInfo> start program unit 

%type <symbolInfo> variable_declaration function_declaration function_definition declaration_list

%type <symbolInfo> statement_list  parameter_list 
%type <symbolInfo> expression compound_statement logic_expression rel_expression simple_expression term factor
%type <symbolInfo> type_specifier unary_expression variable argument_list arguments
%type <symbolInfo> statement 

%%


start: program
    {
     $$ = $1;
     logFile << "line number" << lineCount << ": " ;

    logFile << "start: program" << endl;
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

                        if(symbolTable.search(variable_name) != NULL)
                        {
                            errorFile << "line number" << lineCount << ": " ;
                            errorFile << "error: variable " << variable_name << " already declared" << endl;
                            errorCount++;
                        }
                        else
                        {
                            symbolTable.insert(variable_name,variable_type);
                            logFile << "line number" << lineCount << ": " ;
                            logFile << "variable_declaration: type_specifier declaration_list SEMICOLON \n\n" << variable_type << " " << variable_name << endl<<endl;
                        }
                        
                        $$ = new SymbolInfo($1->getName() + " " +$2->getName()+";", "SYMBOL_VARIABLE");
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "variable_declaration: type_specifier declaration_list SEMICOLON \n\n" << $$->getName() << endl<<endl;

                        }
                   
                    ;



declaration_list : declaration_list COMMA ID
{
$$ = new SymbolInfo($1->getName() + "," +$3->getName(), "SYMBOL_VARIABLE");
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: declaration_list COMMA ID \n\n" << $$->getName() << endl<<endl;
}
| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
{
$$ = new SymbolInfo($1->getName() + "," +$3->getName(), "SYMBOL_VARIABLE");
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: declaration_list COMMA ID LTHIRD CONST INT RTHIRD \n\n" << $$->getName() << endl<<endl;
}
| ID
{
$$ = new SymbolInfo($1->getName(), "SYMBOL_VARIABLE");
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: ID \n\n" << $$->getName() << endl<<endl;
}
| ID LTHIRD CONST_INT RTHIRD{
$$ = new SymbolInfo($1->getName() + " [" + $3->getName()+"]", "SYMBOL_VARIABLE");
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: ID LTHIRD CONST INT RTHIRD \n\n" << $$->getName() << endl<<endl;
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
                        
                        }
                    |   type_specifier ID LPAREN  RPAREN SEMICOLON
                    {
                        $$ = new SymbolInfo($1->getName()+" "+ $2->getName()+"();", "SYMBOL_FUNCTION");
                        string functionName = $2->getName();
                        string functionType = $1->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
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
                        }                                   
                    ;


function_definition : type_specifier ID LPAREN parameter_list RPAREN LCURL statement_list RCURL
                        {
                        $$ = new SymbolInfo($2->getName(), "SYMBOL_FUNCTION");
                       


                        }
                    
                    ;

parameter_list : parameter_list COMMA type_specifier ID
                    
                    {
                    $$ = new SymbolInfo($1->getName() + "," + $3->getName() + " " + $4->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : parameter_list COMMA type_specifier ID"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    
                    }
                | parameter_list COMMA type_specifier
                    {
                    $$ = new SymbolInfo($1->getName() + "," + $3->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : parameter_list COMMA type_specifier"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    

                    }
                | type_specifier ID
                    {
                    $$ = new SymbolInfo($1->getName() + " " + $2->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : type_specifier ID"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    
                    }
                | type_specifier
                    {
                    $$ = new SymbolInfo($1->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : type_specifier"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    
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
            $$ = $2;
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : compound_statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | FOR LPAREN expression_statement expression_statement expression
    RPAREN statement
    {
    $$ = new SymbolInfo("for("+$2->getName()+";"+$3->getName()+";"+$5->getName()+")"+$7->getName(), "SYMBOL_FOR_STATEMENT");
    logFile << "line number" << lineCount << ": " ;
    logFile << "statement : FOR LPAREN expression statement expression statement expression RPAREN statement"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
    }
        | WHILE LPAREN expression RPAREN statement
            {
            $$ = new SymbolInfo("while("+$2->getName()+")"+$4->getName(), "SYMBOL_WHILE_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : WHILE LPAREN expression RPAREN statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | IF LPAREN expression RPAREN statement
            {
            $$ = new SymbolInfo("if("+$2->getName()+")"+$4->getName(), "SYMBOL_IF_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : IF LPAREN expression RPAREN statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | IF LPAREN expression RPAREN statement ELSE statement
            {
            $$ = new SymbolInfo("if("+$2->getName()+")"+$4->getName()+"else"+$6->getName(), "SYMBOL_IF_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | RETURN expression SEMICOLON
            {
            $$ = new SymbolInfo ("return"+$2->getName(), "SYMBOL_RETURN_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : RETURN expression"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }      
        ;

expression : logic_expression{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : logic expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}

| variable ASSIGNOP logic_expression{
    $$ = new SymbolInfo($1->getName()+$3->getName(), "SYMBOL_ASSIGNMENT_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : variable ASSIGNOP logic expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

expression_statement : expression SEMICOLON
                        {
                        $$ = new SymbolInfo($1->getName()+";", "SYMBOL_EXPRESSION_STATEMENT");
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "expression_statement : expression SEMICOLON"<<endl<<endl ;
                        logFile<< $$->getName() << endl<<endl;
                        }
                    | SEMICOLON
                        {
                        $$ = new SymbolInfo(";", "SYMBOL_EXPRESSION_STATEMENT");
                       
                        }
                    ;

variable : ID{
    $$ = new SymbolInfo($1->getName(), "SYMBOL_VARIABLE");
    logFile << "line number" << lineCount << ": " ;
    logFile << "variable : ID"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;

}
| ID LTHIRD expression RTHIRD{
    $$ = new SymbolInfo($1->getName()+$3->getName(), "SYMBOL_VARIABLE");
    logFile << "line number" << lineCount << ": " ;
    logFile << "variable : ID LTHIRD expression RTHIRD"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
};


logic_expression : rel_expression {
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "logic_expression : rel_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| rel_expression LOGICOP rel_expression {
    $$ = new SymbolInfo($1->getName()+"&&"+$3->getName(), "SYMBOL_LOGIC_EXPRESSION");
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
    logFile << "expression : term"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
|simple_expression ADDOP term
{
    $$ = new SymbolInfo($1->getName()+$3->getName(), "SYMBOL_ADD_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : simple_expression ADDOP term"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

term : unary_expression {
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : unary expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
 | term MULOP unary_expression{
    $$ = new SymbolInfo($1->getName()+$3->getName(), "SYMBOL_MUL_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : term MULOP unary expression"<<endl<<endl ;
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
    $$ = new SymbolInfo($1->getName()+$2->getName(), "SYMBOL_UNARY_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : NOT unary expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| factor
{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : factor"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;


factor : variable
{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : variable"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
 | ID LPAREN argument_list RPAREN
{
    $$ = new SymbolInfo($1+$3->getName(), "SYMBOL_FUNCTION_CALL");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : ID LPAREN argument_list RPAREN"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| LPAREN expression RPAREN
{
    $$ = $2;
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : LPAREN expression RPAREN"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| CONST_INT
{
    $$ = new SymbolInfo($1, "SYMBOL_CONST_INT");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : CONST_INT"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| CONST_FLOAT
{
    $$ = new SymbolInfo($1, "SYMBOL_CONST_FLOAT");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : CONST_FLOAT"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}

| variable INCOP
{
    $$ = new SymbolInfo($1->getName()+"++", "SYMBOL_INC_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : variable INCOP"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}

| variable DECOP
{
    $$ = new SymbolInfo($1->getName()+"--", "SYMBOL_DEC_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : variable DECOP"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;



argument_list : arguments{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : arguments"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}

| arguments: arguments COMMA logic_expression
{
    $$ = new SymbolInfo($1->getName()+$3->getName(), "SYMBOL_ARGUMENTS");
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : arguments COMMA logic_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| logic_expression
{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : logic_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;










type_specifier : INT
                {
                $$ = new SymbolInfo("int", "INT");
                }
            | FLOAT
                {
                $$ = new SymbolInfo("float", "FLOAT");
                }
            | DOUBLE
                {
                $$ = new SymbolInfo("double", "DOUBLE");
                }
            | VOID
                {
                $$ = new SymbolInfo("void", "VOID");
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
    // fclose(logFile);
    logFile.close();
    errorFile.close();
    // fclose(errorFile);
    return 0;
}