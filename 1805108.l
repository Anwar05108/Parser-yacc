%option noyywrap

%{
#include "bits/stdc++.h"
// #include "SymbolTable.cpp"
#include "SymbolInfo.h"
#include "y.tab.h"
#define YYSTYPE SymbolInfo*

void yyerror(char*);

// extern FILE *logFile;
extern ofstream logFile;
extern ofstream errorFile;

extern int lineCount;
extern int errorCount;
// extern SymbolTable symbolTable;
// int lineCount = 0;



%}

/*operators*/
ADDOP [+-]
MULOP [*/%]
ASSIGNOP [=]
RELOP ("<="|">="|"<"|">"|"!="|"==")
LOGICOP ("&&"|"||")
BITOP [&|^~]
LOGICNOT [!]
INCOP ("++")
DECOP ("--")
/*PARENTHESIS*/
LPAREN [\(]
RPAREN [\)]
LCURL [\{]
RCURL [\}]
LTHIRD [\[]
RTHIRD [\]]

/*COMMA*/
COMMA [,]
SEMICOLON [;]
NEWLINE [\n]

EMPTY_CHARACTER_ERROR ('')
/*CHARS*/
SPECIAL_CHAR (\\['nt\\afrbv0\"])
NORMAL_CHAR [a-zA-Z0-9_#@%$&*+-/;]
CONST_CHAR  [']({NORMAL_CHAR}|{SPECIAL_CHAR})[']
CHAR_ERROR [']({NORMAL_CHAR}{NORMAL_CHAR}+)[']
/*comments*/
COMMENT "//".*
MULTI_COMMENT "/*"([^*]|\*+[^*/])*\*+"/"
UNFINISHED_CHAR_ERROR [']({NORMAL_CHAR}|{SPECIAL_CHAR})*
CHAR_GAP_ERROR [']({NORMAL_CHAR}|{SPECIAL_CHAR})*[ ]+[']
UNFINISHED_MULTI_COMMENT "/*"([^*]|\*+[^*/])*







/*keywords*/

IF "if"
ELSE "else"
WHILE "while"
RETURN "return"
INT "int"
VOID "void"
FLOAT "float"
CHAR "char"
FOR "for"
BREAK "break"
CONTINUE "continue"
CASE "case"
DEFAULT "default"
SWITCH "switch"
DO "do"
DOUBLE "double"

WHITESPACE [ \t\r]+


/*identifiers*/
ID [a-zA-Z_][a-zA-Z0-9_]*
INVALID_ID [0-9]*[a-zA-Z0-9]*

/*numbers*/



/*strings*/
STRING ["][^"]*["]
UNFINISHED_STRING_ERROR ["][^"]*



DIGIT [0-9]
NUMBER [0-9]+
EXP [eE][ +-]?[0-9]+
CONST_INT [0-9]+

FLOAT_NUM [0-9]+.[0-9]+
FLOAT_NUM_1 ({FLOAT_NUM})({EXP})
FLOAT_NUM_2 ({NUMBER})({EXP})
FLOAT_NUM_3 .({NUMBER})({FLOAT_NUM_1})
CONST_FLOAT ({FLOAT_NUM}|{FLOAT_NUM_2}|{FLOAT_NUM_3}|{FLOAT_NUM})
FLOAT_NUM_ERR1 [0-9]+.[.]+[0-9]+
FLOAT_NUM_ERR2 .[.]+[0-9]+
FLOAT_NUM_ERR3 [.]({CONST_FLOAT})
FLOAT_NUM_ERR4 [eE]({CONST_FLOAT})
FLOAT_NUM_ERR5 ([.]|({CONST_FLOAT}))*
FLOAT_ERR ({FLOAT_NUM_ERR1}|{FLOAT_NUM_ERR2}|{FLOAT_NUM_ERR3}|{FLOAT_NUM_ERR4}|{FLOAT_NUM_ERR5})
/*FLOATING POINTS
FRAC [0-9]+

/*constants*/















%%

{WHITESPACE}  {  }

{UNFINISHED_MULTI_COMMENT}  { }
{EMPTY_CHARACTER_ERROR}  {  }
{IF} { return IF;}
        
{ELSE} { return ELSE;}
        
        
{WHILE} {   return WHILE;}




        
{RETURN} {  }
        
        
{INT} { return INT; }
        
        
{VOID} { return VOID; }
        
        
{FLOAT} { return FLOAT;}
        
        
{CHAR} { return CHAR;}
        
        
{FOR} {  return FOR;}    
        
        
{BREAK} { return BREAK;}  
        
        
{CONTINUE} {   return CONTINUE;}
        
        
{CASE} { return CASE;}
        
        
{DEFAULT} { return DEFAULT;}
        
        
{SWITCH} { return SWITCH;}
        
        
{DO} { return DO;}
        
        
{DOUBLE} { return DOUBLE;}
        
{CONST_INT} {
        SymbolInfo *symbolInfo = new SymbolInfo(yytext,"CONST_INT");
        yylval.symbolInfo = (YYSTYPE)symbolInfo;

                return CONST_INT;}     

{CONST_FLOAT} {
        SymbolInfo *symbolInfo = new SymbolInfo(yytext,"CONST_FLOAT");
        yylval.symbolInfo = (YYSTYPE)symbolInfo;
                return CONST_FLOAT;}
        
        
{FLOAT_ERR} {errorCount++;}

{CONST_CHAR} {
        SymbolInfo *symbolInfo = new SymbolInfo(yytext, "CONST_CHAR");
        yylval.symbolInfo = (YYSTYPE)symbolInfo;
                return CONST_CHAR;}     
{CHAR_ERROR} {errorCount++;}
{UNFINISHED_CHAR_ERROR} {errorCount++;}
{CHAR_GAP_ERROR} { errorCount++;}
{MULTI_COMMENT}     {
                        
                        int i;
                        for(i = 0; i < strlen(yytext); i++)
                        {
                            if(yytext[i] == '\n')
                            {
                                lineCount++;
                            }
                        }
                        }

{COMMENT}  { }                      
{ADDOP} {
    
    SymbolInfo *symbolInfo = new SymbolInfo(yytext, "ADDOP");
    yylval.symbolInfo = (YYSTYPE)symbolInfo;

    return ADDOP;}
                    
{MULOP} { 
    SymbolInfo *symbolInfo = new SymbolInfo(yytext, "MULOP");
    yylval.symbolInfo = (YYSTYPE)symbolInfo;

    return MULOP;}
                                               
{ASSIGNOP} { 
    

    return ASSIGNOP;}
                    
{RELOP} { 
    SymbolInfo *symbolInfo = new SymbolInfo(yytext, "RELOP");
    yylval.symbolInfo = (YYSTYPE)symbolInfo;

    return RELOP;}
                    
                    
{BITOP} { 
    SymbolInfo *symbolInfo = new SymbolInfo(yytext, "BITOP");
    yylval.symbolInfo = (YYSTYPE)symbolInfo;

    return BITOP;}
                    
                    
{LOGICOP} { 
    SymbolInfo *symbolInfo = new SymbolInfo(yytext, "LOGICOP");
    yylval.symbolInfo = (YYSTYPE)symbolInfo;

    return LOGICOP;}
                    
                    

{LOGICNOT} { return LOGICNOT;}
                    
                    
{INCOP}  { return INCOP;}
                    
                    
{LPAREN} { return LPAREN;}
                    
                    
                    
{RPAREN} { return RPAREN;}
                    
                    
{LCURL} { return LCURL;}


{RCURL} { return RCURL;}
                    
{LTHIRD} { return LTHIRD;}

{RTHIRD} { return RTHIRD;}
                        
{COMMA} { return COMMA;}
                        
{SEMICOLON} { return SEMICOLON;}
                        
                        
{NEWLINE} {lineCount++;}


{ID}    {  
        SymbolInfo *temp = new SymbolInfo(yytext, "ID");
        yylval.symbolInfo = temp;
        // symbolTable.insert(temp->getName(), temp->getType());

        return ID;
        }

{INVALID_ID}  { errorCount++;}


{STRING} { yytext[0] = ' ';yytext[strlen(yytext)-1] = '\0';

                    
                    int i ;
                            for(i = 0; yytext[i] != '\0'; i++)
                            {

                                if(yytext[i] == '\n')
                                {
                                    lineCount++;
                                }
                            }
                            
                        }
{UNFINISHED_STRING_ERROR} {errorCount++;}
                        

. {}
%%
