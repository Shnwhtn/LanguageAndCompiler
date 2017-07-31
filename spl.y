					/*		Headers		*/
%{
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
				/* 		Constants		*/

#define SYMTABSIZE     50
#define IDLENGTH       15
#define NOTHING        -1
#define INDENTOFFSET    2

  enum ParseTreeNodeType 
{ 
PROGRAM,BLOCK,DECLARATION_BLOCK,TYPE_BLOCK, TYPE,STATEMENT_LIST, STATEMENT,
ASSIGNMENT_STATEMENT, IF_STATEMENT, DO_STATEMENT, WHILE_STATEMENT, FOR_STATEMENT,
WRITE_STATEMENT, DO_NEWLINE,READ_STATEMENT, OUTPUT_LIST, CONDITIONAL, CONDITIONAL_STATEMENT,
COMPARATOR, EXPRESSION, TERM, VALUE, CONSTANT, VALUE_CONSTANT, VALUE_BRACKETS,
NUMBER_CONSTANT,FORCHECK, CONSTANT_VALUE,IF_ELSE_STATEMENT,STATEMENT_LIST_END, NUMBER_CONSTANT_POSITIVE , NUMBER_CONSTANT_NEGATIVE,
FLOAT_NUMBER_CONSTANT,OUTPUT_LIST_COMMA,EXPRESSION_MINUS,EXPRESSION_PLUS,MULTIPLY_TERM,DIVISION_TERM,DECLARATION_BLOCK_COMMA,DECLARATION_BLOCK_T,
MINUS_NUMBER_CONSTANT, MINUS_FLOAT_NUMBER_CONSTANT
} ;  
                          /* 	Tree Nodes 		*/

char *NodeName[] = { "PROGRAM", "BLOCK", "DECLARATION_BLOCK","TYPE_BLOCK","TYPE","STATEMENT_LIST", 
"STATEMENT", "ASSIGNMENT_STATEMENT", "IF_STATEMENT", "DO_STATEMENT", "WHILE_STATEMENT", "FOR_STATEMENT",
"WRITE_STATEMENT", "DO_NEWLINE", "READ_STATEMENT", "OUTPUT_LIST", "CONDITIONAL", "CONDITIONAL_STATEMENT",
"COMPARATOR", "EXPRESSION", "TERM", "VALUE", "CONSTANT", "VALUE_CONSTANT","VALUE_BRACKETS", 
 "NUMBER_CONSTANT" ,"FORCHECK", "CONSTANT_VALUE", "IF_ELSE_STATEMENT", "STATEMENT_LIST_END","NUMBER_CONSTANT_POSITIVE" ,"NUMBER_CONSTANT_NEGATIVE",
 "FLOAT_NUMBER_CONSTANT", "OUTPUT_LIST_COMMA", "EXPRESSION_MINUS","EXPRESSION_PLUS","MULTIPLY_TERM","DIVISION_TERM","DECLARATION_BLOCK_COMMA","DECLARATION_BLOCK_T",
 "MINUS_NUMBER_CONSTANT", "MINUS_FLOAT_NUMBER_CONSTANT"
 };


#
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

/* ------------- parse tree definition --------------------------- */

struct treeNode {
    int  item;
    int  nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
    struct treeNode *third;
  };

typedef  struct treeNode TREE_NODE;
typedef  TREE_NODE        *TERNARY_TREE;

/* ------------- forward declarations --------------------------- */

TERNARY_TREE create_node(int,int,TERNARY_TREE,TERNARY_TREE,TERNARY_TREE);
#ifdef DEBUG
void PrintTree(TERNARY_TREE, int);
#endif
void yyerror(char *);
int yylex (void);
void WriteCode(TERNARY_TREE);
void AssignType(TERNARY_TREE);

/* ------------- symbol table definition --------------------------- */

struct symTabNode {
    char identifier[IDLENGTH];
	char type;
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;
int WriteCase = 0;
char decType;
int typeSwitch = 0;
int forLoops = 1;
%}

/****************/
/* Start symbol */
/****************/

%start  program

/**********************/
/* Action value types */
/**********************/

%union {
    int iVal;
    TERNARY_TREE  tVal;
}

/* tokens */

%token SEMICOLON_T ASSIGNS_T COLON_T FULLSTOP_T COMMA_T ARROW_T BRA_T KET_T LESS_THAN_T LESS_GREATER_T GREATER_THAN_T
LESS_THAN_EQUALS_T GREATER_THAN_EQUALS_T EQUALS_T TYPE_T
APOST_T ENDP_T DECLARATIONS_T CODE_T OF_T CHARACTER_T INTEGER_T REAL_T IF_T THEN_T ENDIF_T ELSE_T
DO_T WHILE_T ENDWHILE_T ENDDO_T FOR_T IS_T BY_T TO_T ENDFOR_T WRITE_T NEWLINE_T READ_T AND_T OR_T TERM_VALUE_T

%token<iVal> NUMBER_T CHARACTER_CONSTANT_T IDENTIFIER_T NOT_T FLOAT_NUMBER_T 
%token<iVal> PLUS_T MINUS_T MULTIPLY_T DIVISION_T
%type<tVal> program block declaration_block type_block type statement_list statement assignment_statement
if_statement do_statement while_statement for_statement write_statement read_statement
output_list conditional conditional_statement comparator expression 
term value constant  number_constant forcheck
%%

program : IDENTIFIER_T COLON_T block ENDP_T IDENTIFIER_T FULLSTOP_T 
               { TERNARY_TREE ParseTree;
                  ParseTree = create_node($1, PROGRAM, $3, NULL, NULL) ;
#ifdef DEBUG				
				PrintTree(ParseTree,0);
#endif
				AssignType(ParseTree);
				/*	Code Generator */
				WriteCode(ParseTree);
               }

block : DECLARATIONS_T declaration_block CODE_T statement_list 
               { 
                  $$ = create_node(NOTHING, BLOCK, $2, $4, NULL) ;
               }
			   | CODE_T statement_list 
               { 
                  $$ = create_node(NOTHING, BLOCK, $2, NULL, NULL) ;
               }
;

declaration_block : IDENTIFIER_T type_block
               { 
                  $$ = create_node($1, DECLARATION_BLOCK, $2, NULL, NULL) ;
               }
			   | IDENTIFIER_T type_block declaration_block
               { 
                  $$ = create_node($1, DECLARATION_BLOCK_T, $2, $3, NULL) ;
               }
			   | IDENTIFIER_T COMMA_T declaration_block 
               { 
                  $$ = create_node($1, DECLARATION_BLOCK_COMMA, $3, NULL, NULL) ;
               }
;

type_block : OF_T TYPE_T type SEMICOLON_T 
               { 
                  $$ = create_node(NOTHING, TYPE_BLOCK, $3, NULL, NULL) ;
               }
;

type : CHARACTER_T 
               { 
                  $$ = create_node(CHARACTER_T, TYPE, NULL, NULL, NULL) ;
               }
			   | INTEGER_T
               {
                  $$ = create_node(INTEGER_T, TYPE, NULL, NULL, NULL) ;
               }
			   | REAL_T 
               { 
                  $$ = create_node(REAL_T, TYPE, NULL, NULL, NULL) ;
               }
;


/* List of all statements */

statement_list : statement
               { 
                  $$ = create_node(NOTHING, STATEMENT_LIST, $1, NULL, NULL) ;
               }
			   | statement SEMICOLON_T statement_list
               { 
                  $$ = create_node(NOTHING, STATEMENT_LIST, $1, $3, NULL) ;
               }
;

statement : assignment_statement
               { 
                  $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL) ;
               }
			   | if_statement
               { 
                  $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL) ;
               }
			   | do_statement
               { 
                  $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL) ;
               }
			   | while_statement
               { 
                  $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL) ;
               }
			   | for_statement
               { 
                  $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL) ;
               }
			   | write_statement
               { 
                  $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL) ;
               }
			   | read_statement
               { 
                  $$ = create_node(NOTHING, STATEMENT, $1, NULL, NULL) ;
               }
;

assignment_statement : expression ARROW_T IDENTIFIER_T
               { 
                  $$ = create_node($3, ASSIGNMENT_STATEMENT, $1, NULL, NULL) ;
               }
;

if_statement : IF_T conditional THEN_T statement_list ENDIF_T
               { 
                  $$ = create_node(NOTHING, IF_STATEMENT, $2, $4, NULL) ;
               }
			   | IF_T conditional THEN_T statement_list ELSE_T statement_list ENDIF_T
               { 
                  $$ = create_node(NOTHING, IF_ELSE_STATEMENT, $2, $4, $6) ;
               }
;

do_statement : DO_T statement_list WHILE_T conditional ENDDO_T
               { 
                  $$ = create_node(NOTHING, DO_STATEMENT, $2, $4, NULL) ;
               }
;

while_statement : WHILE_T conditional DO_T statement_list ENDWHILE_T
               { 
                  $$ = create_node(NOTHING, WHILE_STATEMENT, $2, $4, NULL) ;
               }
;

/*
Split for statement up because of number of expressions
Original Statement:
for_statement : FOR IDENTIFIER IS expression BY expression TO expression DO
	           statement_list ENDFOR
*/

for_statement : FOR_T forcheck DO_T statement_list ENDFOR_T
               { 
                  $$ = create_node(NOTHING, FOR_STATEMENT, $2, $4, NULL) ;
               }
;

forcheck : IDENTIFIER_T IS_T expression BY_T expression TO_T expression
               { 
                  $$ = create_node($1, FORCHECK, $3, $5, $7) ;
               }
;

write_statement : WRITE_T BRA_T output_list KET_T
               { 
                  $$ = create_node(NOTHING, WRITE_STATEMENT, $3, NULL, NULL) ;
               }
			   | NEWLINE_T
               { 
                  $$ = create_node(NOTHING, DO_NEWLINE, NULL, NULL, NULL) ;
               }
;

read_statement : READ_T BRA_T IDENTIFIER_T KET_T
               { 
                  $$ = create_node($3, READ_STATEMENT, NULL, NULL, NULL) ;
               }
;

output_list : value
               { 
                  $$ = create_node(NOTHING, OUTPUT_LIST, $1, NULL, NULL) ;
               }
			   | value COMMA_T output_list
               {
                  $$ = create_node(NOTHING, OUTPUT_LIST_COMMA, $1, $3, NULL) ;
               }
;

conditional : conditional_statement
               { 
                  $$ = create_node(NOTHING, CONDITIONAL, $1, NULL, NULL) ;
               }
			   | conditional_statement AND_T conditional
               { 
                  $$ = create_node(AND_T, CONDITIONAL, $1, $3, NULL) ;
               }
			   | conditional_statement OR_T conditional
               { 
                  $$ = create_node(OR_T, CONDITIONAL, $1, $3, NULL) ;
               }
;


conditional_statement : expression comparator expression 
               { 
                  $$ = create_node(NOTHING, CONDITIONAL_STATEMENT, $1, $2, $3) ;
               }
               |NOT_T conditional_statement
               { 
                  $$ = create_node($1, CONDITIONAL_STATEMENT, $2, NULL, NULL) ;
               }
;

comparator : EQUALS_T
               { 
                  $$ = create_node(EQUALS_T,COMPARATOR,NULL, NULL, NULL) ;
               }
			   |LESS_GREATER_T
               {
                  $$ = create_node(LESS_GREATER_T,COMPARATOR,NULL, NULL, NULL) ;
               }
			   |LESS_THAN_T
               { 
                  $$ = create_node(LESS_THAN_T,COMPARATOR,NULL, NULL, NULL) ;
               }
			   |GREATER_THAN_T
               { 
                  $$ = create_node(GREATER_THAN_T,COMPARATOR ,NULL, NULL, NULL) ;
               }
			   |LESS_THAN_EQUALS_T
               { 
                  $$ = create_node(LESS_THAN_EQUALS_T,COMPARATOR,NULL, NULL, NULL) ;
               }
			   |GREATER_THAN_EQUALS_T
               { 
                  $$ = create_node(GREATER_THAN_EQUALS_T, COMPARATOR,NULL, NULL, NULL) ;
               }
;

expression : term
               { 
                  $$ = create_node(NOTHING, EXPRESSION, $1, NULL, NULL) ;
               }
			   | term PLUS_T expression
               { 
                  $$ = create_node($2, EXPRESSION_PLUS, $1, $3, NULL) ;
               }
			   | term MINUS_T expression
               { 
                  $$ = create_node($2, EXPRESSION_MINUS, $1, $3, NULL) ;
               }
;

term : value
               { 
                  $$ = create_node(NOTHING, TERM, $1, NULL, NULL) ;
               }
			   | value MULTIPLY_T term 
               { 
                  $$ = create_node($2, MULTIPLY_TERM, $1, $3, NULL) ;
               }
			   | value DIVISION_T term
               { 
                  $$ = create_node($2, DIVISION_TERM, $1, $3, NULL) ;
               }
;

value : IDENTIFIER_T
               { 
                  $$ = create_node($1, VALUE, NULL, NULL, NULL) ;
               }
	           | constant
               { 
                  $$ = create_node(NOTHING, VALUE_CONSTANT, $1, NULL, NULL) ;
               }
			   | BRA_T expression KET_T
               { 
                  $$ = create_node(NOTHING, VALUE_BRACKETS, $2, NULL, NULL) ;
               } 
;

constant : number_constant
               { 
                  $$ = create_node(NOTHING, CONSTANT, $1, NULL, NULL) ;
               }
			   | CHARACTER_CONSTANT_T
               { 
                  $$ = create_node($1, CONSTANT_VALUE, NULL, NULL, NULL) ;
               }
;


number_constant : NUMBER_T
				{
				$$ = create_node($1, NUMBER_CONSTANT, NULL, NULL, NULL) ;
				}
				|
				FLOAT_NUMBER_T
				{
				$$ = create_node($1, FLOAT_NUMBER_CONSTANT, NULL, NULL, NULL) ;
				}
				| MINUS_T NUMBER_T
                { 
                  $$ = create_node($2, MINUS_NUMBER_CONSTANT, NULL, NULL, NULL) ;
                }
				| MINUS_T FLOAT_NUMBER_T
                { 
                  $$ = create_node($2, MINUS_FLOAT_NUMBER_CONSTANT, NULL, NULL, NULL) ;
                }
;

%%
/* Code for routines for managing the Parse Tree */

TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
    return (t);
}


/* Put other auxiliary functions here */
#ifdef DEBUG
void PrintTree(TERNARY_TREE t, int indent)
{
int i;
	if (t== NULL) return;
	for (i=indent; i;i--) printf(" ");
	if (t-> nodeIdentifier == NUMBER_T)
		printf("Number: %d ", t->item);
	else if (t->nodeIdentifier == IDENTIFIER_T ||
			 t->nodeIdentifier == ASSIGNMENT_STATEMENT)
		if (t->item > 0 && t->item < SYMTABSIZE)
		printf("Identifier: %s ",symTab[t->item]->identifier);
		else printf("Unknown Identifier: %d ",t->item);
	else if (t->item != NOTHING) printf (" Item: %d ", t->item);
	if (t->nodeIdentifier < 0|| t->nodeIdentifier > sizeof(NodeName))
		printf("Unknown nodeIdentifier: %d\n", t->nodeIdentifier);
		else
		printf("nodeIndentifier: %s\n",NodeName[t->nodeIdentifier]);
   PrintTree(t->first,indent+3);
   PrintTree(t->second,indent+3);
   PrintTree(t->third,indent+3);
}
#endif


/* Assigns type by node identifer type */
void AssignType(TERNARY_TREE t)
{
	if(t==NULL) return;
	if(t->item != NOTHING)
	{
	if((t->nodeIdentifier == PROGRAM)||(t->nodeIdentifier == CHARACTER_CONSTANT_T)||(t->nodeIdentifier == CONSTANT_VALUE))
	{
	symTab[t->item]->type = 's'; 
	}
	else if((t->nodeIdentifier == FLOAT_NUMBER_CONSTANT)||(t->nodeIdentifier == MINUS_FLOAT_NUMBER_CONSTANT))
	{
	symTab[t->item]->type = 'f';
	}	
	else if((t->nodeIdentifier == NUMBER_CONSTANT)||(t->nodeIdentifier == NUMBER_T)||(t->nodeIdentifier == MINUS_NUMBER_CONSTANT)||(t->nodeIdentifier == VALUE_CONSTANT))
	{
	symTab[t->item]->type = 'i'; 
	}
	}
	AssignType(t -> first);
	AssignType(t -> second);
	AssignType(t -> third);
}



					/* WRITE CODE */

void WriteCode(TERNARY_TREE t)
{
	/* If nothing, return */
	if (t==NULL) return;
		switch(t->nodeIdentifier)
		{
					/*	Program */
	case (PROGRAM) :
			printf("#include <stdio.h>\n\n");
			printf("/* ");
			printf("Identifier: %s ",symTab[t->item]->identifier);
			printf(" */\n\n");
			printf("int main(void)\n {\n");
			WriteCode(t->first);
			printf("\nreturn 0;\n");
			printf("}\n");
			printf("/* End Program %s */",symTab[t->item]);
			printf("\n");
			return;
		
	case (BLOCK):
			printf("/* ");
			printf("Declarations");
			printf(" */\n");
			WriteCode(t->first);
			if(typeSwitch == 1)
			{
			printf(";");
			}
			printf("\n/* CODE */\n\n");
			WriteCode(t->second);
			WriteCode(t->third);
			return;

	case (DECLARATION_BLOCK):
			WriteCode(t->second);			
			WriteCode(t->first);
		    WriteCode(t->third);
			symTab[t->item]->type = decType;
			printf("%s",symTab[t->item]);
			return;
		
	case (DECLARATION_BLOCK_COMMA):
			WriteCode(t->second);
			WriteCode(t->first);
			printf(",");
			symTab[t->item]->type = decType;
			printf("%s",symTab[t->item]); 
			WriteCode(t->third);
			return;

	case (DECLARATION_BLOCK_T):
			WriteCode(t->second);
			printf(";");
			WriteCode(t->first);
		    WriteCode(t->third);
			symTab[t->item]->type = decType;
			printf("%s",symTab[t->item]);
			return;
			
	case (TYPE):
			typeSwitch = 1;
			printf("\n");
			/* Switch assigns type at declaration */
			switch(t->item)
			{		
				case CHARACTER_T:
					printf("char ");
					decType = 's';
					break;
				case REAL_T:
					printf("float ");
					decType = 'f';
					break;
				case INTEGER_T:
				printf("int ");
					decType = 'i';
					break;
				default:
				break;
			}
			return;
			
	case(ASSIGNMENT_STATEMENT):
			WriteCode(t->second);
			printf("%s",symTab[t->item]);
			printf(" = ");
			WriteCode(t->third);
			WriteCode(t->first);
			printf(";\n");
			return;
				
	case (IF_STATEMENT):
			printf("if (");
			WriteCode(t->first);
			printf(") {\n");
			WriteCode(t->second);
			WriteCode(t->third);
			printf("}\n");
			return;	
			
	case (IF_ELSE_STATEMENT):
			printf("if (");						
			WriteCode(t->first);
			printf("){\n");
			WriteCode(t->second);
			printf("} else {\n");
			WriteCode(t->third);
			printf("}\n");
			return;	
			
	case (DO_STATEMENT):
			printf("do {\n");
			WriteCode(t->first);
			printf("} while (");
			WriteCode(t->second);
			
			printf(");\n");
			WriteCode(t->third);
			
			return;
			
	case (WHILE_STATEMENT):
			printf("while (");
			WriteCode(t->first);
			
			printf(") {\n");
			WriteCode(t->second);
			printf("}");
			
			return;
			
	case (FOR_STATEMENT):
			WriteCode(t->first);
			printf("{\n");
			WriteCode(t->second);
			WriteCode(t->third);
			printf("}\n");
			return;
			
	/*	Forcheck is based on this formula on the ACWhelp */
	/*	for (i=is; _by=by, (i-to)*((_by > 0) - (_by < 0)) */
	/*	<= 0 ; i += _by) */
	
			
	case (FORCHECK):
	printf("register int _by");
	printf("%d",forLoops);
	printf(";\nfor (");
	printf("%s",symTab[t->item]->identifier);
	printf("=");
	WriteCode(t->first);
	printf(";");
	printf(" _by");
	printf("%d",forLoops);
	printf("=");
	WriteCode(t->second);
	printf(", (");
	printf("%s",symTab[t->item]->identifier);
	printf("-(");
	WriteCode(t->third);
	printf("))*((");
	printf("_by");
	printf("%d",forLoops);
	printf(" > 0)-(");
	printf("_by");
	printf("%d",forLoops);
	printf(" < 0))<= 0;");
	printf("%s",symTab[t->item]->identifier);
	printf(" += _by");
	printf("%d",forLoops);
	printf(")");
	forLoops++;
	return;

		
	case (WRITE_STATEMENT) :
			printf("printf(\"");
			WriteCase = 1;
			WriteCode(t->first);
			if(WriteCase == 2)
			{
			printf(");\n");
			}
			else
			{
			printf("\");\n");
			}
			WriteCase = 0;
			return;
			
	case(READ_STATEMENT):
			printf("scanf(\"");
			WriteCode(t->first);
			/* Selects datatype based on switch */
			switch(symTab[t->item]->type)
			{
			case 's':
			printf(" %%c");
			break;
			case 'i':
			printf(" %%d");
			break;
			case 'f':
			printf(" %%f");
			break;
			}
			printf("\",&");
			printf("%s",symTab[t->item]);
			printf(");\n");
			return;
			
	case (DO_NEWLINE):
			/* 		Windows uses carriage return over newline spacing than linux  */
			printf("printf(\"");
#ifdef LINUX
			printf("\\n");
			
#endif
#ifndef LINUX
			printf("\\r\\n");
#endif
			printf("\");\n");
			return;

	case (CONDITIONAL):
			WriteCode(t->first);
			if(t->item == AND_T)
			{
				printf(" && ");
				WriteCode(t->second);
			}
			else if (t->item == OR_T)
			{
				printf(" || ");
				WriteCode(t->second);
			}
			else
			{
			break;
			}
			return;
			
	case (CONDITIONAL_STATEMENT):
		if(t->item != NOTHING)
			{
			printf("!(");
			WriteCode(t->first);
			printf(")");
			
			return;
			}
			else
			{
			WriteCode(t->first);
			printf(" ");
			
			WriteCode(t->second);
			printf(" ");
			WriteCode(t->third);
			return;
			}

	case (COMPARATOR):
			switch(t->item)
			{
			case (EQUALS_T):
				printf("==");
				break;
			case(LESS_GREATER_T):
				printf("!=");
				break;
			case(LESS_THAN_T):
				printf("<");
				break;
			case(GREATER_THAN_T):
				printf(">");
				break;
			case(LESS_THAN_EQUALS_T):
				printf("<=");
				break;
			case(GREATER_THAN_EQUALS_T):
				printf(">=");
				break;
		 	}
		
	case(EXPRESSION):
			WriteCode(t->first);
			WriteCode(t->second);
			return;
		
	case CHARACTER_CONSTANT_T:
	
			printf("%s",symTab[t->item]->identifier);
			return;
			
			
		
	case(EXPRESSION_PLUS):
			WriteCode(t->first);
			printf(" + ");
			WriteCode(t->second);
			return;
		
	case(EXPRESSION_MINUS):
			WriteCode(t->first);
			printf(" - ");
			WriteCode(t->second);
			return;
		
	case(MULTIPLY_TERM):
			WriteCode(t->first);
			printf(" * ");
			WriteCode(t->second);
			return;
		
	case(DIVISION_TERM):
			WriteCode(t->first);
			printf(" / ");
			WriteCode(t->second);
			return;
	
	case (VALUE_BRACKETS):
			printf("(");
			WriteCode(t->first);
			printf(")");
			return;
			
	case (VALUE):
			if(WriteCase == 1)
			{
			switch(symTab[t->item]->type)
			{
			case 's':
			printf("%%c\",");
			break;
			case 'i':
			printf("%%d\",");
			break;
			case 'f':
			printf("%%f\",");
			break;
			}
			WriteCase = 2;
			}
			printf("%s",&symTab[t->item]->identifier);
			return; 

	
	case(MINUS_NUMBER_CONSTANT):
			printf("-");
			printf("%s",symTab[t->item]);
			return;
			
	case(NUMBER_CONSTANT):
			WriteCode(t->first);
			printf("%s",symTab[t->item]->identifier);
			return;
		
	case(FLOAT_NUMBER_CONSTANT):
			WriteCode(t->first);
			printf("%s",symTab[t->item]);		
			return;
			
	case(MINUS_FLOAT_NUMBER_CONSTANT):
			WriteCode(t->first);
			printf("-");
			printf("%s",symTab[t->item]);		
			return;

	case (OUTPUT_LIST_COMMA):
			WriteCode(t->first);
			printf(",");
			WriteCode(t->second);
			return;
	
	case(CONSTANT):
	WriteCode(t->first);
			return;
	
	case(VALUE_CONSTANT):
	WriteCode(t->first);
			return;
			
	case(CONSTANT_VALUE):
	WriteCode(t->first);
			printf("%s",symTab[t->item]->identifier);
			return;

	case(IDENTIFIER_T):
			printf("%s",symTab[t->item]->identifier);
			return;
			
				/*		Default Action   */			
	default:		
		    WriteCode(t->first);
			WriteCode(t->second);
			WriteCode(t->third);
			break;
		}


}


#include "lex.yy.c"
