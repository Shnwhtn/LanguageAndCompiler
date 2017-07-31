/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "spl.y" /* yacc.c:339  */

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

#line 155 "spl.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON_T = 258,
    ASSIGNS_T = 259,
    COLON_T = 260,
    FULLSTOP_T = 261,
    COMMA_T = 262,
    ARROW_T = 263,
    BRA_T = 264,
    KET_T = 265,
    LESS_THAN_T = 266,
    LESS_GREATER_T = 267,
    GREATER_THAN_T = 268,
    LESS_THAN_EQUALS_T = 269,
    GREATER_THAN_EQUALS_T = 270,
    EQUALS_T = 271,
    TYPE_T = 272,
    APOST_T = 273,
    ENDP_T = 274,
    DECLARATIONS_T = 275,
    CODE_T = 276,
    OF_T = 277,
    CHARACTER_T = 278,
    INTEGER_T = 279,
    REAL_T = 280,
    IF_T = 281,
    THEN_T = 282,
    ENDIF_T = 283,
    ELSE_T = 284,
    DO_T = 285,
    WHILE_T = 286,
    ENDWHILE_T = 287,
    ENDDO_T = 288,
    FOR_T = 289,
    IS_T = 290,
    BY_T = 291,
    TO_T = 292,
    ENDFOR_T = 293,
    WRITE_T = 294,
    NEWLINE_T = 295,
    READ_T = 296,
    AND_T = 297,
    OR_T = 298,
    TERM_VALUE_T = 299,
    NUMBER_T = 300,
    CHARACTER_CONSTANT_T = 301,
    IDENTIFIER_T = 302,
    NOT_T = 303,
    FLOAT_NUMBER_T = 304,
    PLUS_T = 305,
    MINUS_T = 306,
    MULTIPLY_T = 307,
    DIVISION_T = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 101 "spl.y" /* yacc.c:355  */

    int iVal;
    TERNARY_TREE  tVal;

#line 251 "spl.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 268 "spl.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   132,   136,   142,   146,   150,   156,   162,
     166,   170,   179,   183,   189,   193,   197,   201,   205,   209,
     213,   219,   225,   229,   235,   241,   254,   260,   266,   270,
     276,   282,   286,   292,   296,   300,   307,   311,   317,   321,
     325,   329,   333,   337,   343,   347,   351,   357,   361,   365,
     371,   375,   379,   385,   389,   396,   401,   405,   409
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON_T", "ASSIGNS_T", "COLON_T",
  "FULLSTOP_T", "COMMA_T", "ARROW_T", "BRA_T", "KET_T", "LESS_THAN_T",
  "LESS_GREATER_T", "GREATER_THAN_T", "LESS_THAN_EQUALS_T",
  "GREATER_THAN_EQUALS_T", "EQUALS_T", "TYPE_T", "APOST_T", "ENDP_T",
  "DECLARATIONS_T", "CODE_T", "OF_T", "CHARACTER_T", "INTEGER_T", "REAL_T",
  "IF_T", "THEN_T", "ENDIF_T", "ELSE_T", "DO_T", "WHILE_T", "ENDWHILE_T",
  "ENDDO_T", "FOR_T", "IS_T", "BY_T", "TO_T", "ENDFOR_T", "WRITE_T",
  "NEWLINE_T", "READ_T", "AND_T", "OR_T", "TERM_VALUE_T", "NUMBER_T",
  "CHARACTER_CONSTANT_T", "IDENTIFIER_T", "NOT_T", "FLOAT_NUMBER_T",
  "PLUS_T", "MINUS_T", "MULTIPLY_T", "DIVISION_T", "$accept", "program",
  "block", "declaration_block", "type_block", "type", "statement_list",
  "statement", "assignment_statement", "if_statement", "do_statement",
  "while_statement", "for_statement", "forcheck", "write_statement",
  "read_statement", "output_list", "conditional", "conditional_statement",
  "comparator", "expression", "term", "value", "constant",
  "number_constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -50

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -25,    14,    28,   -13,   -50,     3,    46,    15,    -2,    24,
      60,    -5,    46,    -5,     4,    43,   -50,    44,   -50,   -50,
     -50,   -50,   -28,   -50,    51,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,    49,   -24,   -23,   -50,   -50,    11,     3,    47,
       3,    46,    53,    -5,    34,   -11,    -1,    40,    48,    54,
      52,    60,    32,   -50,   -50,    46,    36,    60,    60,    60,
      60,    75,   -50,     0,   -50,   -50,   -50,   -50,    46,    -5,
      -5,   -50,   -50,   -50,   -50,   -50,   -50,    60,    -5,    46,
      60,    46,    74,    81,    80,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,    91,     8,   -50,   -50,   -50,
      63,    66,    64,    61,   -50,    60,   -50,   -50,   -50,    46,
     -50,   -50,    60,   -50,   -50,    73,    67,   -50,    60,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,    55,    54,
      50,    56,     0,     4,    12,    14,    15,    16,    17,    18,
      19,    20,     0,    44,    47,    51,    53,     0,     0,     0,
       5,     0,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,    57,    58,     0,     0,     0,     0,     0,
       0,     0,     7,     0,     6,     3,    52,    37,     0,     0,
       0,    40,    39,    41,    42,    43,    38,     0,     0,     0,
       0,     0,     0,    31,     0,    13,    21,    45,    46,    48,
      49,     2,     9,    10,    11,     0,     0,    34,    35,    36,
       0,     0,     0,     0,    28,     0,    30,     8,    22,     0,
      24,    25,     0,    26,    32,     0,     0,    23,     0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -50,   -22,   -50,   -50,    -6,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,     5,    -4,    69,   -50,
     -10,   -21,   -49,   -50,   -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     9,    40,    95,    23,    24,    25,    26,
      27,    28,    29,    50,    30,    31,    82,    44,    45,    77,
      32,    33,    34,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    46,    83,    46,    10,    38,    47,     5,     6,    48,
      71,    72,    73,    74,    75,    76,    62,    53,    64,     3,
      39,    54,     1,    92,    93,    94,    57,    58,     4,    59,
      60,    69,    70,    46,    37,    65,   108,   109,    89,    90,
      18,    19,    20,    43,    21,    41,    22,    87,    88,    85,
       8,    49,    51,    52,    55,    10,    83,    56,    61,    46,
      46,    68,    96,    66,    63,    97,    98,    99,    46,    10,
     102,    78,    11,   101,   100,   103,    12,    13,    79,    84,
      14,    91,    81,    86,   104,    15,    16,    17,   105,    80,
     106,    18,    19,    20,   107,    21,   110,    22,   111,   113,
     112,   117,   116,   115,   118,    18,    19,    20,   119,    21,
     114,    22,    67
};

static const yytype_uint8 yycheck[] =
{
      10,    11,    51,    13,     9,     7,    12,    20,    21,    13,
      11,    12,    13,    14,    15,    16,    38,    45,    40,     5,
      22,    49,    47,    23,    24,    25,    50,    51,     0,    52,
      53,    42,    43,    43,    19,    41,    28,    29,    59,    60,
      45,    46,    47,    48,    49,    21,    51,    57,    58,    55,
      47,    47,     9,     9,     3,     9,   105,     8,    47,    69,
      70,    27,    68,    10,    17,    69,    70,    77,    78,     9,
      80,    31,    26,    79,    78,    81,    30,    31,    30,    47,
      34,     6,    30,    47,    10,    39,    40,    41,     7,    35,
      10,    45,    46,    47,     3,    49,    33,    51,    32,    38,
      36,    28,   112,   109,    37,    45,    46,    47,   118,    49,
     105,    51,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    55,     5,     0,    20,    21,    56,    47,    57,
       9,    26,    30,    31,    34,    39,    40,    41,    45,    46,
      47,    49,    51,    60,    61,    62,    63,    64,    65,    66,
      68,    69,    74,    75,    76,    77,    78,    19,     7,    22,
      58,    21,    74,    48,    71,    72,    74,    60,    71,    47,
      67,     9,     9,    45,    49,     3,     8,    50,    51,    52,
      53,    47,    57,    17,    57,    60,    10,    72,    27,    42,
      43,    11,    12,    13,    14,    15,    16,    73,    31,    30,
      35,    30,    70,    76,    47,    60,    47,    74,    74,    75,
      75,     6,    23,    24,    25,    59,    60,    71,    71,    74,
      71,    60,    74,    60,    10,     7,    10,     3,    28,    29,
      33,    32,    36,    38,    70,    60,    74,    28,    37,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    58,    59,
      59,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    62,    63,    63,    64,    65,    66,    67,    68,    68,
      69,    70,    70,    71,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    74,    74,    74,    75,    75,    75,
      76,    76,    76,    77,    77,    78,    78,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     4,     2,     2,     3,     3,     4,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     5,     7,     5,     5,     5,     7,     4,     1,
       4,     1,     3,     1,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       1,     1,     3,     1,     1,     1,     1,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 122 "spl.y" /* yacc.c:1646  */
    { TERNARY_TREE ParseTree;
                  ParseTree = create_node((yyvsp[-5].iVal), PROGRAM, (yyvsp[-3].tVal), NULL, NULL) ;
#ifdef DEBUG				
				PrintTree(ParseTree,0);
#endif
				AssignType(ParseTree);
				/*	Code Generator */
				WriteCode(ParseTree);
               }
#line 1439 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 133 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL) ;
               }
#line 1447 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 137 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1455 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 143 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[-1].iVal), DECLARATION_BLOCK, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1463 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 147 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[-2].iVal), DECLARATION_BLOCK_T, (yyvsp[-1].tVal), (yyvsp[0].tVal), NULL) ;
               }
#line 1471 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 151 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[-2].iVal), DECLARATION_BLOCK_COMMA, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1479 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 157 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, TYPE_BLOCK, (yyvsp[-1].tVal), NULL, NULL) ;
               }
#line 1487 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 163 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(CHARACTER_T, TYPE, NULL, NULL, NULL) ;
               }
#line 1495 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 167 "spl.y" /* yacc.c:1646  */
    {
                  (yyval.tVal) = create_node(INTEGER_T, TYPE, NULL, NULL, NULL) ;
               }
#line 1503 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 171 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(REAL_T, TYPE, NULL, NULL, NULL) ;
               }
#line 1511 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 180 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1519 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 184 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL) ;
               }
#line 1527 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 190 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1535 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 194 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1543 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 198 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1551 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1559 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 206 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1567 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 210 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1575 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 214 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, STATEMENT, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1583 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 220 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[0].iVal), ASSIGNMENT_STATEMENT, (yyvsp[-2].tVal), NULL, NULL) ;
               }
#line 1591 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 226 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, IF_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL) ;
               }
#line 1599 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 230 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, IF_ELSE_STATEMENT, (yyvsp[-5].tVal), (yyvsp[-3].tVal), (yyvsp[-1].tVal)) ;
               }
#line 1607 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 236 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, DO_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL) ;
               }
#line 1615 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 242 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, WHILE_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL) ;
               }
#line 1623 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 255 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, FOR_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL) ;
               }
#line 1631 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 261 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[-6].iVal), FORCHECK, (yyvsp[-4].tVal), (yyvsp[-2].tVal), (yyvsp[0].tVal)) ;
               }
#line 1639 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 267 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, WRITE_STATEMENT, (yyvsp[-1].tVal), NULL, NULL) ;
               }
#line 1647 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 271 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, DO_NEWLINE, NULL, NULL, NULL) ;
               }
#line 1655 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 277 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[-1].iVal), READ_STATEMENT, NULL, NULL, NULL) ;
               }
#line 1663 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 283 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, OUTPUT_LIST, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1671 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 287 "spl.y" /* yacc.c:1646  */
    {
                  (yyval.tVal) = create_node(NOTHING, OUTPUT_LIST_COMMA, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL) ;
               }
#line 1679 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 293 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, CONDITIONAL, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1687 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 297 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(AND_T, CONDITIONAL, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL) ;
               }
#line 1695 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 301 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(OR_T, CONDITIONAL, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL) ;
               }
#line 1703 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 308 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, CONDITIONAL_STATEMENT, (yyvsp[-2].tVal), (yyvsp[-1].tVal), (yyvsp[0].tVal)) ;
               }
#line 1711 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 312 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[-1].iVal), CONDITIONAL_STATEMENT, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1719 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 318 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(EQUALS_T,COMPARATOR,NULL, NULL, NULL) ;
               }
#line 1727 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 322 "spl.y" /* yacc.c:1646  */
    {
                  (yyval.tVal) = create_node(LESS_GREATER_T,COMPARATOR,NULL, NULL, NULL) ;
               }
#line 1735 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 326 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(LESS_THAN_T,COMPARATOR,NULL, NULL, NULL) ;
               }
#line 1743 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 330 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(GREATER_THAN_T,COMPARATOR ,NULL, NULL, NULL) ;
               }
#line 1751 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 334 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(LESS_THAN_EQUALS_T,COMPARATOR,NULL, NULL, NULL) ;
               }
#line 1759 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 338 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(GREATER_THAN_EQUALS_T, COMPARATOR,NULL, NULL, NULL) ;
               }
#line 1767 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 344 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, EXPRESSION, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1775 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 348 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[-1].iVal), EXPRESSION_PLUS, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL) ;
               }
#line 1783 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 352 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[-1].iVal), EXPRESSION_MINUS, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL) ;
               }
#line 1791 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 358 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, TERM, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1799 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 362 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[-1].iVal), MULTIPLY_TERM, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL) ;
               }
#line 1807 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 366 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[-1].iVal), DIVISION_TERM, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL) ;
               }
#line 1815 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 372 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[0].iVal), VALUE, NULL, NULL, NULL) ;
               }
#line 1823 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 376 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, VALUE_CONSTANT, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1831 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 380 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, VALUE_BRACKETS, (yyvsp[-1].tVal), NULL, NULL) ;
               }
#line 1839 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 386 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node(NOTHING, CONSTANT, (yyvsp[0].tVal), NULL, NULL) ;
               }
#line 1847 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 390 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[0].iVal), CONSTANT_VALUE, NULL, NULL, NULL) ;
               }
#line 1855 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 397 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node((yyvsp[0].iVal), NUMBER_CONSTANT, NULL, NULL, NULL) ;
				}
#line 1863 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 402 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node((yyvsp[0].iVal), FLOAT_NUMBER_CONSTANT, NULL, NULL, NULL) ;
				}
#line 1871 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 406 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[0].iVal), MINUS_NUMBER_CONSTANT, NULL, NULL, NULL) ;
                }
#line 1879 "spl.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 410 "spl.y" /* yacc.c:1646  */
    { 
                  (yyval.tVal) = create_node((yyvsp[0].iVal), MINUS_FLOAT_NUMBER_CONSTANT, NULL, NULL, NULL) ;
                }
#line 1887 "spl.tab.c" /* yacc.c:1646  */
    break;


#line 1891 "spl.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 415 "spl.y" /* yacc.c:1906  */

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
