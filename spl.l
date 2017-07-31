%{
#ifdef PRINT
#define TOKEN(t) printf("Token: " #t "\n");
#define NUMBER_TOKEN(t) printf("Number %d Token: " #t "\n", atoi(yytext));
#define ID_TOKEN(t) printf("ID %s Token: " #t "\n", yytext);
#define FLOAT_TOKEN(t) printf("Float %d Token:" #t "\n", atof(yytext));
#else
#define TOKEN(t) return(t);
#define NUMBER_TOKEN(t) yylval.iVal = installId(yytext);return(t);
#define FLOAT_TOKEN(t) yylval.iVal = installId(yytext);return(t);
#define ID_TOKEN(t) yylval.iVal = installId(yytext); return(t);
/* Declare Symbol Table Type and Array as imported types */
#include <string.h>
#include <stdlib.h>
extern SYMTABNODEPTR symTab[SYMTABSIZE];
extern int currentSymTabSize;
int installId(char *);
#endif
%}
delim [ \t\n\r]
ws	{delim}+
digit	[0-9]
letter	[a-zA-z]
number	{digit}+
id	{letter}({letter}|{digit})*
char "'"{letter}"'"
realNo {number}+\.{number}+
%%
";"	TOKEN(SEMICOLON_T)
":="	TOKEN(ASSIGNS_T)
":"	TOKEN(COLON_T)
"."	TOKEN(FULLSTOP_T)
","	TOKEN(COMMA_T)
"->"	TOKEN(ARROW_T)
"("	TOKEN(BRA_T)
")"	TOKEN(KET_T)
"="	TOKEN(EQUALS_T)
"<>"	TOKEN(LESS_GREATER_T)
"<"	TOKEN(LESS_THAN_T)
">"	TOKEN(GREATER_THAN_T)
"<="	TOKEN(LESS_THAN_EQUALS_T)
">="	TOKEN(GREATER_THAN_EQUALS_T)
"+"	TOKEN(PLUS_T)
"-"	TOKEN(MINUS_T)
"*"	TOKEN(MULTIPLY_T)
"/"	TOKEN(DIVISION_T)
"'"	TOKEN(APOST_T)
ENDP	TOKEN(ENDP_T)
DECLARATIONS	TOKEN(DECLARATIONS_T)
CODE	TOKEN(CODE_T)
OF	TOKEN(OF_T)
TYPE	TOKEN(TYPE_T)
CHARACTER	TOKEN(CHARACTER_T)
INTEGER	TOKEN(INTEGER_T)
REAL	TOKEN(REAL_T)
IF	TOKEN(IF_T)
THEN	TOKEN(THEN_T)
ENDIF	TOKEN(ENDIF_T)
ELSE	TOKEN(ELSE_T)
DO	TOKEN(DO_T)
WHILE	TOKEN(WHILE_T)
ENDWHILE	TOKEN(ENDWHILE_T)
ENDDO	TOKEN(ENDDO_T)
FOR	TOKEN(FOR_T)
IS	TOKEN(IS_T)
BY	TOKEN(BY_T)
TO	TOKEN(TO_T)
ENDFOR	TOKEN(ENDFOR_T)
WRITE	TOKEN(WRITE_T)
NEWLINE	TOKEN(NEWLINE_T)
READ	TOKEN(READ_T)
NOT	TOKEN(NOT_T)
AND	TOKEN(AND_T)
OR	TOKEN(OR_T)
{id}	ID_TOKEN(IDENTIFIER_T)
{number} ID_TOKEN(NUMBER_T)
{char}    ID_TOKEN(CHARACTER_CONSTANT_T) 
{realNo}	FLOAT_TOKEN(FLOAT_NUMBER_T)
{ws}             ; /* Nothing */
.		 fprintf(stderr, "Error: Unexpected symbol found: %s (%d)\n", yytext, yytext[0]);
%%
#ifndef PRINT
SYMTABNODEPTR newSymTabNode()
{
    return ((SYMTABNODEPTR)malloc(sizeof(SYMTABNODE)));
}


/* Look up an identifier in the symbol table, if its there return
   its index.  If its not there, put it in the end position,
   as long as the table isn't full, and return its index.
*/

int lookup(char *s)
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE];
    extern int currentSymTabSize;
    int i;

    for(i=0; i<currentSymTabSize; i++)
    {
        if(strncmp(s,symTab[i]->identifier,IDLENGTH) == 0)
        {
            return (i);
        }
    }
    return (-1);    
}

int installId(char *id) 
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE]; 
    extern int currentSymTabSize;
    int index;

    index = lookup(id);
    if (index >= 0)
    {
        return (index);
    }
    else 
       if (currentSymTabSize >= SYMTABSIZE) 
          /* SYMTAB is full */
          return (NOTHING) ;
    else
    {
       symTab[currentSymTabSize] = newSymTabNode();
       /* Recommended code for preventing buffer overrun on bounded strings */
       strncpy(symTab[currentSymTabSize]->identifier,id,IDLENGTH);
       symTab[currentSymTabSize]->identifier[IDLENGTH-1] = '\0';
       return(currentSymTabSize++);
    }
}
#endif
