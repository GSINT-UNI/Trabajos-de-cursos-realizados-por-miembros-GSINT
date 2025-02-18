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
#line 1 "free_bison.y" /* yacc.c:339  */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char lexema[255];
void yyerror(char *);

typedef struct {char nombre[255]; double valor; int token;}tipoTS;
tipoTS TablaSim[100];
int nSim=0;

#define totalFields 6
#define totalCodes 100
typedef struct{int op; int aArray[totalFields]}tipoCodigo;
tipoCodigo TCodigo[totalCodes];
int cx=-1;

int generaCodigo(int, int[], int);
int localizaSimb(char*, int);
void imprimeTablaSim();
int nVarTemp=0;
int GenVarTemp();

int* getElements(int*, int); // Genera arreglo de componentes para ser usados como argumentos
int evalCondition(int);
int evalFlag=1;

void evalLoop(int codeA, int codeB);
void duplicate(int codeA, int codeB);
int loopFlag=0;

char tokenList[15][30];

int iterationIndexA, iterationIndexB;

int evalBuffer[totalFields];
int bufferUsed = 0;
int* append(int, int*, int);

#line 107 "free_bison.tab.c" /* yacc.c:339  */

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
    ID = 258,
    NUM = 259,
    ENTER = 260,
    STRING = 261,
    COM = 262,
    IF = 263,
    IFELSE = 264,
    WHILE = 265,
    FOR = 266,
    DEF = 267,
    TRUEASSIGN = 268,
    ASSIGN = 269,
    SUM = 270,
    RES = 271,
    MUL = 272,
    DIV = 273,
    EVAL = 274,
    EQ = 275,
    NEQ = 276,
    LES = 277,
    MOR = 278,
    LEQ = 279,
    MEQ = 280,
    ITERLIMIT = 281,
    AND = 282,
    OR = 283,
    ALG = 284,
    INIALG = 285,
    FINALG = 286,
    THEN = 287,
    IFSTART = 288,
    IFEND = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 190 "free_bison.tab.c" /* yacc.c:358  */

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
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,     2,     2,     2,
      37,    38,    43,    41,     2,    39,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      44,    36,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    46,    48,    49,    51,    52,    53,    55,
      56,    58,    58,    60,    60,    62,    63,    64,    65,    66,
      68,    69,    70,    71,    73,    74,    75,    76,    77,    79,
      80,    82,    83,    85,    86,    87,    88,    90,    91,    93,
      94,    96,    97,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   109,   111,   111,   112,   112,   112,   113,   113,
     113,   113,   114,   113,   127,   127,   127,   127,   127,   127,
     128,   127,   147,   147
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "ENTER", "STRING", "COM",
  "IF", "IFELSE", "WHILE", "FOR", "DEF", "TRUEASSIGN", "ASSIGN", "SUM",
  "RES", "MUL", "DIV", "EVAL", "EQ", "NEQ", "LES", "MOR", "LEQ", "MEQ",
  "ITERLIMIT", "AND", "OR", "ALG", "INIALG", "FINALG", "THEN", "IFSTART",
  "IFEND", "';'", "'='", "'('", "')'", "'-'", "'!'", "'+'", "'/'", "'*'",
  "'<'", "'>'", "'{'", "'}'", "$accept", "root", "lines", "line", "exp",
  "assign", "@1", "call", "@2", "args", "element", "structure",
  "statement", "unitA", "unitB", "comparison", "comparisons", "operatorA",
  "operatorB", "compOperator", "ifStructure", "$@3", "ifElseStructure",
  "$@4", "$@5", "whileStructure", "@6", "@7", "$@8", "$@9", "$@10",
  "forStructure", "@11", "@12", "$@13", "@14", "@15", "$@16", "$@17",
  "functionStructure", "@18", YY_NULLPTR
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
     285,   286,   287,   288,   289,    59,    61,    40,    41,    45,
      33,    43,    47,    42,    60,    62,   123,   125
};
# endif

#define YYPACT_NINF -43

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define YYTABLE_NINF -14

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -13,    10,    22,    -3,   -43,   -13,    28,    -7,   -43,     4,
      -2,     8,    16,    31,    26,    28,    27,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,    30,    33,    -7,   -43,   -43,
      11,    63,    11,   -43,   -43,   -43,    24,   -17,   -43,   -43,
       4,   -43,    71,   -43,   -43,   -43,   -43,    15,    15,    37,
     -43,   -43,    44,   -43,   -43,    41,   -43,    42,   -43,    45,
      50,    15,    15,   -43,   -43,    15,   -43,     4,   -43,    54,
      43,    32,    83,    53,    85,   -16,    60,   -43,   -43,   -43,
     -43,   -17,   -43,   -43,   -43,    56,   -43,   -43,    15,    15,
     -43,    15,    58,    28,    52,   -43,     4,    61,   -43,   -43,
      11,    66,    28,    64,   -43,    55,    65,   -43,   -43,    62,
     -43,    28,   -43,    59,   -43,    74,    67,    70,    28,   -43,
     -43,    28,   -43,    71,    72,    73,   -43,   -43,   -43,    75,
      76,   -43,    28,   -43,    77,   -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     1,     2,     0,    11,     8,     0,
       0,     0,     0,     0,     0,     5,     0,     9,    10,     6,
      24,    25,    26,    27,    28,     0,     0,    20,    21,    23,
       0,     0,     0,    36,    35,    53,    38,    32,    40,    29,
       0,    58,     0,    72,     3,     4,     7,     0,    19,     0,
      22,    30,     0,    51,    52,     0,    42,     0,    41,    47,
      48,     0,     0,    43,    44,     0,    55,     0,    11,     0,
       0,    12,    18,     0,    16,     0,     0,    45,    46,    49,
      50,    31,    37,    34,    33,     0,    59,    64,    19,    19,
      14,    19,     0,     0,     0,    60,     0,     0,    17,    15,
       0,     0,     0,     0,    65,     0,     0,    54,    56,     0,
      66,     0,    39,     0,    61,     0,     0,     0,     0,    67,
      73,     0,    62,     0,     0,     0,    68,    57,    63,     0,
       0,    69,     0,    70,     0,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   105,   -14,   -43,   -43,   -39,   -43,    -6,   -43,   -33,
     -42,   -43,   -35,    78,    68,    49,   -28,   -43,   -43,    46,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    14,    15,    16,    17,    25,    33,    26,    73,
      34,    19,    35,    36,    37,    38,    39,    61,    65,    62,
      20,    52,    21,    85,   113,    22,    67,    95,   103,   118,
     125,    23,    96,   110,   115,   123,   129,   132,   134,    24,
      70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    45,    49,    69,    51,    66,    74,    27,    28,    18,
      29,    53,    54,     3,    27,    28,     1,    29,    27,    28,
      55,    29,     4,    84,    57,    63,    64,     5,    59,    60,
     -13,     7,    86,     8,    43,    40,     9,    10,    11,    12,
      13,    30,    72,    31,    32,    41,    74,    74,    30,    74,
      31,    53,    54,    42,    31,    97,    98,    44,    99,    83,
      55,   104,    46,    56,    57,    58,    47,    50,    59,    60,
      48,    56,   106,    58,    68,    75,    76,    77,    78,   101,
      88,    79,    72,    72,   126,    72,    80,    18,   108,    87,
      89,    90,    91,    93,    94,   100,    18,   116,   102,   105,
     107,   111,   109,   112,   122,    18,   117,   124,   114,   119,
       6,    82,    18,   130,   120,    18,   121,     0,   133,   127,
     128,    92,   131,     0,   135,    71,    18,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
       6,    15,    30,    42,    32,    40,    48,     3,     4,    15,
       6,    27,    28,     3,     3,     4,    29,     6,     3,     4,
      36,     6,     0,    65,    40,    42,    43,    30,    44,    45,
      37,     3,    67,     5,     3,    37,     8,     9,    10,    11,
      12,    37,    48,    39,    40,    37,    88,    89,    37,    91,
      39,    27,    28,    37,    39,    88,    89,    31,    91,    65,
      36,    96,    35,    39,    40,    41,    36,     4,    44,    45,
      37,    39,   100,    41,     3,    38,    32,    36,    36,    93,
      37,    36,    88,    89,   123,    91,    36,    93,   102,    35,
       7,    38,     7,    33,    38,    37,   102,   111,    46,    38,
      34,    46,    38,    38,   118,   111,    47,   121,    46,    35,
       5,    62,   118,    38,    47,   121,    46,    -1,   132,    47,
      47,    75,    46,    -1,    47,    47,   132,    -1,    -1,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    49,     3,     0,    30,    49,     3,     5,     8,
       9,    10,    11,    12,    50,    51,    52,    53,    55,    59,
      68,    70,    73,    79,    87,    54,    56,     3,     4,     6,
      37,    39,    40,    55,    58,    60,    61,    62,    63,    64,
      37,    37,    37,     3,    31,    50,    35,    36,    37,    64,
       4,    64,    69,    27,    28,    36,    39,    40,    41,    44,
      45,    65,    67,    42,    43,    66,    60,    74,     3,    53,
      88,    61,    55,    57,    58,    38,    32,    36,    36,    36,
      36,    62,    63,    55,    58,    71,    60,    35,    37,     7,
      38,     7,    67,    33,    38,    75,    80,    57,    57,    57,
      37,    50,    46,    76,    60,    38,    64,    34,    50,    38,
      81,    46,    38,    72,    46,    82,    50,    47,    77,    35,
      47,    46,    50,    83,    50,    78,    53,    47,    47,    84,
      38,    46,    85,    50,    86,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    51,    51,    51,    52,
      52,    54,    53,    56,    55,    57,    57,    57,    57,    57,
      58,    58,    58,    58,    59,    59,    59,    59,    59,    60,
      60,    61,    61,    62,    62,    62,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    69,    68,    71,    72,    70,    74,    75,
      76,    77,    78,    73,    80,    81,    82,    83,    84,    85,
      86,    79,    88,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     1,     1,     2,     1,     1,
       1,     0,     4,     0,     5,     3,     1,     3,     1,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     3,     3,     1,     1,     3,     1,     7,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     1,     1,     0,     7,     0,     0,    12,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     9
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
        case 5:
#line 49 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1364 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 52 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1370 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 55 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1376 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 56 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1382 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 58 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=localizaSimb(lexema, ID);}
#line 1388 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 58 "free_bison.y" /* yacc.c:1646  */
    {int elements[totalFields] = {(yyvsp[-2]), (yyvsp[0])};int i = generaCodigo(ASSIGN, elements,2); evalCodigo(i);(yyval)=i;}
#line 1394 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 60 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=localizaSimb(lexema, ID);}
#line 1400 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 60 "free_bison.y" /* yacc.c:1646  */
    {int *elements = append((yyvsp[-3]), evalBuffer, bufferUsed);bufferUsed=0;int i = generaCodigo(EVAL, elements,totalFields); (yyval)=evalCodigo(i);}
#line 1406 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 62 "free_bison.y" /* yacc.c:1646  */
    {evalBuffer[bufferUsed++]=(yyvsp[-2]);}
#line 1412 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 63 "free_bison.y" /* yacc.c:1646  */
    {evalBuffer[bufferUsed++]=(yyvsp[0]);}
#line 1418 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 66 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=-1;}
#line 1424 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 68 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=localizaSimb(lexema,ID);}
#line 1430 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 69 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=localizaSimb(lexema,NUM);}
#line 1436 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 70 "free_bison.y" /* yacc.c:1646  */
    {char str[255];strcpy(str, "-");strcat(str, lexema);(yyval)=localizaSimb(str, NUM);}
#line 1442 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 71 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=localizaSimb(lexema,STRING);}
#line 1448 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 79 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1454 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 80 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=!(yyvsp[0]);}
#line 1460 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 82 "free_bison.y" /* yacc.c:1646  */
    {int i=GenVarTemp();int elements[totalFields] = {i, (yyvsp[-2]), (yyvsp[0])};int j=generaCodigo((yyvsp[-1]), elements,3);evalCodigo(j);(yyval)=i;}
#line 1466 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 83 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1472 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 85 "free_bison.y" /* yacc.c:1646  */
    {int i=GenVarTemp();int elements[totalFields] = {i, (yyvsp[-2]), (yyvsp[0])};int j=generaCodigo((yyvsp[-1]), elements,3);evalCodigo(j);(yyval)=i;}
#line 1478 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 87 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1484 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 88 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1490 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 90 "free_bison.y" /* yacc.c:1646  */
    {int i=GenVarTemp();int elements[totalFields] = {i, (yyvsp[-2]), (yyvsp[0])};int j=generaCodigo((yyvsp[-1]), elements,3);evalCodigo(j);(yyval)=i;}
#line 1496 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 91 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1502 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 93 "free_bison.y" /* yacc.c:1646  */
    {int i=GenVarTemp();int elements[totalFields] = {i, (yyvsp[-5]), (yyvsp[-1])};int j=generaCodigo((yyvsp[-3]), elements,3);evalCodigo(j);(yyval)=i;}
#line 1508 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 94 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1514 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 96 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=SUM;}
#line 1520 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 97 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=RES;}
#line 1526 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 99 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=DIV;}
#line 1532 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 100 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=MUL;}
#line 1538 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 102 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=EQ;}
#line 1544 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 103 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=NEQ;}
#line 1550 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 104 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=LES;}
#line 1556 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 105 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=MOR;}
#line 1562 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 106 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=LEQ;}
#line 1568 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 107 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=MEQ;}
#line 1574 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 108 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=AND;}
#line 1580 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 109 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=OR;}
#line 1586 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 111 "free_bison.y" /* yacc.c:1646  */
    {evalFlag=evalCondition((yyvsp[0]));}
#line 1592 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 111 "free_bison.y" /* yacc.c:1646  */
    {evalFlag=1;}
#line 1598 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 112 "free_bison.y" /* yacc.c:1646  */
    {evalFlag=evalCondition((yyvsp[0]));}
#line 1604 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 112 "free_bison.y" /* yacc.c:1646  */
    {evalFlag=(evalFlag+1)%2;}
#line 1610 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 112 "free_bison.y" /* yacc.c:1646  */
    {evalFlag=1;}
#line 1616 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 113 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=cx+1;}
#line 1622 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 113 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=cx;}
#line 1628 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 113 "free_bison.y" /* yacc.c:1646  */
    {evalFlag=evalCondition((yyvsp[-1]));}
#line 1634 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 113 "free_bison.y" /* yacc.c:1646  */
    {evalFlag=0;}
#line 1640 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 114 "free_bison.y" /* yacc.c:1646  */
    {
						//printf("#REG%d#", $4);
						int A=(yyvsp[-7]);
						int B=(yyvsp[-5]);
						int C=cx; 
						duplicate(A, B);
						evalFlag=1;
						while(evalCondition((yyvsp[-6])))
						{
							evalLoop(A,C+B-A+1);
						}
					}
#line 1657 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 125 "free_bison.y" /* yacc.c:1646  */
    {evalFlag=1;}
#line 1663 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 127 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=cx+1;}
#line 1669 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 127 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=cx;}
#line 1675 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 127 "free_bison.y" /* yacc.c:1646  */
    {evalFlag=0;}
#line 1681 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 127 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=cx;}
#line 1687 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 127 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=cx;}
#line 1693 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 127 "free_bison.y" /* yacc.c:1646  */
    {evalFlag=0;}
#line 1699 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 128 "free_bison.y" /* yacc.c:1646  */
    {
						int A1=(yyvsp[-11]);
						int A2=(yyvsp[-9]);

						int B1=(yyvsp[-6])+1; 
						int B2=(yyvsp[-4]);

						int C1=B2+1;
						int C2=cx;

						duplicate(A1, A2);
						int CX=moveToEnd(B1, B2);
						evalFlag=1;
						while(evalCondition((yyvsp[-10])))
						{
							evalLoop(A1,CX);
						}
					}
#line 1722 "free_bison.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 147 "free_bison.y" /* yacc.c:1646  */
    {(yyval)=localizaSimb(lexema, ID);}
#line 1728 "free_bison.tab.c" /* yacc.c:1646  */
    break;


#line 1732 "free_bison.tab.c" /* yacc.c:1646  */
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
#line 148 "free_bison.y" /* yacc.c:1906  */


void yyerror(char *msg){
	printf("error: %s", msg);
}

int GenVarTemp(){
	char t[60];
	sprintf(t, "_T%d", nVarTemp++);
	return localizaSimb(t, ID);
}

int reservedWord(char lexema[])
{
	if(strcasecmp(lexema,"Si")==0) return IF;
	if(strcasecmp(lexema,"entonces")==0) return THEN;
	if(strcasecmp(lexema,"inicio")==0) return IFSTART;
	if(strcasecmp(lexema,"fin")==0) return IFEND;
	if(strcasecmp(lexema,"ifelse")==0) return IFELSE;
	if(strcasecmp(lexema,"while")==0) return WHILE;
	if(strcasecmp(lexema,"for")==0) return FOR;
	if(strcasecmp(lexema,"def")==0) return DEF;
	if(strcasecmp(lexema,"Algoritmo")==0) return ALG;
	if(strcasecmp(lexema,"inicioAlgoritmo")==0) return INIALG;
	if(strcasecmp(lexema,"finAlgoritmo")==0) return FINALG;
	return ID;
}

int* append(int a, int* b, int nb){
	int index = 0;
	int i, j;
	int *result = (int*)malloc(sizeof(int)*totalFields);
	for(i = 0; i < totalFields; i++){result[i]=-1;}
	result[index++] = a;
	for(j = 0; (j < nb) && (index < totalFields); j++){
		result[index++] = b[j];
	}
	return result;
}

int getTrueValue(int va, int op, int vb){
	int a = TablaSim[va].valor;
	int b = TablaSim[vb].valor;
	//printf("Evaluando:%s %d %s:", TablaSim[va].nombre, op, TablaSim[vb].nombre);

	if(op==EQ){return (a == b);}
	else if(op==NEQ){return (a != b);}
	else if(op==LES){return (a < b);}
	else if(op==MOR){return (a > b);}
	else if(op==LEQ){return (a <= b);}
	else if(op==MEQ){return (a >= b);}
	else if(op==AND){return (a && b);}
	else if(op==OR){return (a || b);}
}

int* getElements(int* elements, int totalElements){
	int resultElements[totalFields];
	int i;
	for(i = 0; i < totalFields; i++){
		if(i < totalElements){
			resultElements[i] = elements[i];
		} else {
			resultElements[i] = -1;
		}
	}
	return resultElements;
}

int localizaSimb(char *nom, int tok){
	int i;
	for(i = 0; i<nSim; i++){
		if(!strcasecmp(TablaSim[i].nombre, nom))
			return i;
	}
	strcpy(TablaSim[nSim].nombre, nom);
	TablaSim[nSim].token = tok;
	if(tok == ID) TablaSim[nSim].valor=0.0;
	if(tok == NUM) sscanf(nom, "%lf", &TablaSim[nSim].valor);
	nSim++;
	return nSim-1;
}

int generaCodigo(int op, int aArray[], int usefulFields){
	cx++;
	TCodigo[cx].op=op;
	int i;
	for(i = 0; i < totalFields; i++){
		if(i < usefulFields){
			//resultElements[i] = elements[i];
			TCodigo[cx].aArray[i] = aArray[i];
		} else {
			//resultElements[i] = -1;
			TCodigo[cx].aArray[i] = -1;
		}
	}
	return cx;
}

void evalCodigo(int index){
	if (!evalFlag)
		return;

	int operation = TCodigo[index].op;
	int *elementsArr = TCodigo[index].aArray;

	int element1 = elementsArr[0];
	int element2 = elementsArr[1];
	int element3 = elementsArr[2];

	if(operation==TRUEASSIGN){TablaSim[element1].valor = element2;}
	if(operation==ASSIGN){TablaSim[element1].valor = TablaSim[element2].valor;}
	if(operation==SUM){TablaSim[element1].valor = TablaSim[element2].valor + TablaSim[element3].valor;}
	if(operation==RES){TablaSim[element1].valor = TablaSim[element2].valor - TablaSim[element3].valor;}
	if(operation==MUL){TablaSim[element1].valor = TablaSim[element2].valor * TablaSim[element3].valor;}
	if(operation==DIV){TablaSim[element1].valor = TablaSim[element2].valor / TablaSim[element3].valor;}

	if(operation==EQ){TablaSim[element1].valor = TablaSim[element2].valor == TablaSim[element3].valor;}
	if(operation==NEQ){TablaSim[element1].valor = TablaSim[element2].valor != TablaSim[element3].valor;}
	if(operation==LES){TablaSim[element1].valor = TablaSim[element2].valor < TablaSim[element3].valor;}
	if(operation==MOR){TablaSim[element1].valor = TablaSim[element2].valor > TablaSim[element3].valor;}
	if(operation==LEQ){TablaSim[element1].valor = TablaSim[element2].valor <= TablaSim[element3].valor;}
	if(operation==MEQ){TablaSim[element1].valor = TablaSim[element2].valor >= TablaSim[element3].valor;}
	if(operation==AND){TablaSim[element1].valor = TablaSim[element2].valor && TablaSim[element3].valor;}
	if(operation==OR){TablaSim[element1].valor = TablaSim[element2].valor || TablaSim[element3].valor;}
	
	if(operation==EVAL){evalFunction(elementsArr);}
}

void duplicate(int codeA, int codeB){
	for(int i = codeA; i <= codeB; i++){
		int op = TCodigo[i].op;
		int* aArray = TCodigo[i].aArray;
		int usefulFields = 0;
		while(TCodigo[i].aArray[usefulFields] != -1){usefulFields++;}

		generaCodigo(op, aArray, usefulFields);
	}
}

void moveToEnd(int codeA, int codeB){
	int numCodes = codeB - codeA + 1;
	duplicate(codeA, codeB);
	int i;
	for(i = codeB+1; i <= cx; i++){
		TCodigo[i-numCodes] = TCodigo[i];
	}
	cx = cx - numCodes;
	return(cx);
}

void evalLoop(int codeA, int codeB){
	int j;
	//printf("[%d->%d]", codeA, codeB);
	for(j = codeA; j <= codeB; j++){
		evalCodigo(j);
	}
}

int evalCondition(int index){
	if(TablaSim[index].valor){
		return 1;
	} else {
		return 0;
	}
}

int evalFunction(int* fields){
	char* funName = TablaSim[fields[0]].nombre;
	if(strcasecmp(funName, "print")==0){
		for(int i = 1; i < totalFields; i++){
			if((fields[i] < nSim)&&(fields[i] != -1)){
				printf("%lf", TablaSim[fields[i]].valor);
			}
		}
	} else if(strcasecmp(funName, "println")==0){
		for(int i = 1; i < totalFields; i++){
			if((fields[i] < nSim)&&(fields[i] != -1)){
				printf("%lf", TablaSim[fields[i]].valor);
			}
		}
		printf("\n");
	} else if(strcasecmp(funName, "raiz")==0){
		double result = sqrt(TablaSim[fields[1]].valor);
		
		char milexema[50];
		snprintf(milexema, 50, "%lf", result);
		
		int indice_valor = localizaSimb(milexema, NUM);
		int indice_contenedor = GenVarTemp();
		int elements[totalFields] = {indice_contenedor, indice_valor};
		int j=generaCodigo(ASSIGN, elements,2);
		evalCodigo(j);
		return indice_contenedor;
	}
	return -1;
}

void imprimeTablaSim(){
	int i;
	for(i = 0; i < nSim; i++){
		printf("%d nombre=%-10s\ttok=%d | valor=%lf\n", i, TablaSim[i].nombre, TablaSim[i].token, TablaSim[i].valor);
	}
}

void imprimeTablaCod(){
	int i;
	for(i = 0; i <= cx; i++){
		printf("%d:", i);
		printf("%-20s\t", tokenList[TCodigo[i].op - 268]);
		printf("fields: [");
		int j;
		for(j = 0; j < totalFields; j++){printf("%d, ", TCodigo[i].aArray[j]);}
		printf("]\n");
		//printf("%d a1=%d a2=%d a3=%d\n", TCodigo[i].op, TCodigo[i].a1, TCodigo[i].a2, TCodigo[i].a3);
	}
}

int yylex(){
	char c;
	while(1){
		c = getchar();
		if (isspace(c)) continue;
		if (c == '\t') continue;
		if (c == ',') return COM;
		if (c == '&') return AND;
		if (c == '|') return OR;
		if (c == '\n') return ENTER;
		

		if (isalpha(c)) {
			int i = 0;
			do{
				lexema[i++]=c;
				c=getchar();
			}while(isalnum(c));

			ungetc(c, stdin);
			lexema[i] = 0;
			return reservedWord(lexema);
		}

		if (c == '"') {
			int i = 0;
			int closureQuote = 0;
			int closureQuoteConfirm = 0;
			do{
				if(closureQuote){closureQuoteConfirm = 1;}
				lexema[i++]=c;
				c=getchar();
				if(c == '"'){closureQuote = 1;}
			}while(!closureQuoteConfirm);

			ungetc(c, stdin);
			lexema[i] = 0;
			return STRING;
		}

		if (isdigit(c)){
			int decimalFlag = 0;
			int decimalReaded = 0;
			int i = 0;
			do{
				if (decimalFlag){decimalReaded = 1;}
				lexema[i++]=c;
				c=getchar();
				if( c == '.' || c == 'e' || c == 'E' ){decimalFlag = 1;}
			}while((isdigit(c)) || (( c == '.' || c == 'e' || c == 'E' )&&(!decimalReaded)));

			ungetc(c, stdin);
			lexema[i] = 0;
			return NUM;
		}
		return c;
	}
}

void initTokenStrings(){
	strcpy(tokenList[0], "TRUEASSIGN");
	strcpy(tokenList[1], "ASSIGN");
	strcpy(tokenList[2], "SUM");
	strcpy(tokenList[3], "RES");
	strcpy(tokenList[4], "MUL");
	strcpy(tokenList[5], "DIV");
	strcpy(tokenList[6], "EVAL");
	strcpy(tokenList[7], "EQ");
	strcpy(tokenList[8], "NEQ");
	strcpy(tokenList[9], "LES");
	strcpy(tokenList[10], "MOR");
	strcpy(tokenList[11], "LEQ");
	strcpy(tokenList[12], "MEQ");
	strcpy(tokenList[13], "ITERLIMIT");
	strcpy(tokenList[14], "AND");
	strcpy(tokenList[15], "OR");
}

int main(){
	initTokenStrings();
	int exe = yyparse(); // Ejecucion del compilador
	printf("\n==============================\n"); // Linea divisora de outputs
	if (!exe) printf("cadena valida \n");
	else printf(" cadena invalida");

	printf("Tabla de simbolos\n");
	imprimeTablaSim();
	printf("\nTabla de codigos\n");
	imprimeTablaCod();

	return 0;
}

/*
x = 10;
y = 12;
z = 1;

while((x <20)&(x > 1)){
	y = 1;
	print(y);
	z = 3;
	print(z);
}

ww = 123;

--

x = 1;

while(x < 3){
	x = x+1;
	print(x);
}

--

x = -2;
y = 3*x-1;

print(x, y);
*/
