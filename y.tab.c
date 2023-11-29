/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "jparser.y"

#include "tabsim.c"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void yyerror(char *);
int yylex(void);
void PrintError(int, char *);
int esNumero(char * s){
	int i=0;
	if (s[i] == '-') i++;
	for(; s[i] != 0; i++)
	if ((s[i]<'0') || (s[i]>'9')) return 0;
	return 1;
}
simbolo *t = NULL;

#line 90 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PRINT = 258,                   /* PRINT  */
    INTEGER = 259,                 /* INTEGER  */
    STRING = 260,                  /* STRING  */
    BOOLEAN = 261,                 /* BOOLEAN  */
    EXIT_COMMAND = 262,            /* EXIT_COMMAND  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    DO = 265,                      /* DO  */
    WHILE = 266,                   /* WHILE  */
    FOR = 267,                     /* FOR  */
    TAB = 268,                     /* TAB  */
    LLAVEAPER = 269,               /* LLAVEAPER  */
    LLAVECIE = 270,                /* LLAVECIE  */
    SWITCH = 271,                  /* SWITCH  */
    CASE = 272,                    /* CASE  */
    BREAK = 273,                   /* BREAK  */
    DEFAULT = 274,                 /* DEFAULT  */
    COMILLA = 275,                 /* COMILLA  */
    PUNCOMA = 276,                 /* PUNCOMA  */
    FINLINEA = 277,                /* FINLINEA  */
    AND = 278,                     /* AND  */
    OR = 279,                      /* OR  */
    MENOR_IGUAL = 280,             /* MENOR_IGUAL  */
    MAYOR_IGUAL = 281,             /* MAYOR_IGUAL  */
    COMPARISON1 = 282,             /* COMPARISON1  */
    COMPARISON2 = 283,             /* COMPARISON2  */
    DIFERENTE = 284,               /* DIFERENTE  */
    INCREMENTO = 285,              /* INCREMENTO  */
    DECREMENTO = 286,              /* DECREMENTO  */
    RETURN = 287,                  /* RETURN  */
    MENOS_IGUAL = 288,             /* MENOS_IGUAL  */
    MAS_IGUAL = 289,               /* MAS_IGUAL  */
    POR_IGUAL = 290,               /* POR_IGUAL  */
    ENTRE_IGUAL = 291,             /* ENTRE_IGUAL  */
    PARSEINT = 292,                /* PARSEINT  */
    TOSTRING = 293,                /* TOSTRING  */
    NUMERO = 294,                  /* NUMERO  */
    TRUE = 295,                    /* TRUE  */
    FALSE = 296,                   /* FALSE  */
    ID = 297,                      /* ID  */
    ID_MALO = 298,                 /* ID_MALO  */
    CADENA = 299                   /* CADENA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "jparser.y"

	char cadena[100];
	int numero;
	bool bolean;
	simbolo * ptr_simbolo;
	expresion valor;
	

#line 193 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PRINT = 3,                      /* PRINT  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_BOOLEAN = 6,                    /* BOOLEAN  */
  YYSYMBOL_EXIT_COMMAND = 7,               /* EXIT_COMMAND  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_DO = 10,                        /* DO  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_TAB = 13,                       /* TAB  */
  YYSYMBOL_LLAVEAPER = 14,                 /* LLAVEAPER  */
  YYSYMBOL_LLAVECIE = 15,                  /* LLAVECIE  */
  YYSYMBOL_SWITCH = 16,                    /* SWITCH  */
  YYSYMBOL_CASE = 17,                      /* CASE  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 19,                   /* DEFAULT  */
  YYSYMBOL_COMILLA = 20,                   /* COMILLA  */
  YYSYMBOL_PUNCOMA = 21,                   /* PUNCOMA  */
  YYSYMBOL_FINLINEA = 22,                  /* FINLINEA  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_MENOR_IGUAL = 25,               /* MENOR_IGUAL  */
  YYSYMBOL_MAYOR_IGUAL = 26,               /* MAYOR_IGUAL  */
  YYSYMBOL_COMPARISON1 = 27,               /* COMPARISON1  */
  YYSYMBOL_COMPARISON2 = 28,               /* COMPARISON2  */
  YYSYMBOL_DIFERENTE = 29,                 /* DIFERENTE  */
  YYSYMBOL_INCREMENTO = 30,                /* INCREMENTO  */
  YYSYMBOL_DECREMENTO = 31,                /* DECREMENTO  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_MENOS_IGUAL = 33,               /* MENOS_IGUAL  */
  YYSYMBOL_MAS_IGUAL = 34,                 /* MAS_IGUAL  */
  YYSYMBOL_POR_IGUAL = 35,                 /* POR_IGUAL  */
  YYSYMBOL_ENTRE_IGUAL = 36,               /* ENTRE_IGUAL  */
  YYSYMBOL_PARSEINT = 37,                  /* PARSEINT  */
  YYSYMBOL_TOSTRING = 38,                  /* TOSTRING  */
  YYSYMBOL_NUMERO = 39,                    /* NUMERO  */
  YYSYMBOL_TRUE = 40,                      /* TRUE  */
  YYSYMBOL_FALSE = 41,                     /* FALSE  */
  YYSYMBOL_ID = 42,                        /* ID  */
  YYSYMBOL_ID_MALO = 43,                   /* ID_MALO  */
  YYSYMBOL_CADENA = 44,                    /* CADENA  */
  YYSYMBOL_45_ = 45,                       /* '+'  */
  YYSYMBOL_46_ = 46,                       /* '-'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '/'  */
  YYSYMBOL_49_ = 49,                       /* '='  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* '<'  */
  YYSYMBOL_55_ = 55,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_programa = 57,                  /* programa  */
  YYSYMBOL_58_1 = 58,                      /* $@1  */
  YYSYMBOL_declaraciones = 59,             /* declaraciones  */
  YYSYMBOL_declara_multi = 60,             /* declara_multi  */
  YYSYMBOL_verifica_param = 61,            /* verifica_param  */
  YYSYMBOL_asig = 62,                      /* asig  */
  YYSYMBOL_bloque = 63,                    /* bloque  */
  YYSYMBOL_blo_condicional = 64,           /* blo_condicional  */
  YYSYMBOL_blo_else = 65,                  /* blo_else  */
  YYSYMBOL_sentencia_while = 66,           /* sentencia_while  */
  YYSYMBOL_blo_for = 67,                   /* blo_for  */
  YYSYMBOL_sentencia_switch = 68,          /* sentencia_switch  */
  YYSYMBOL_ejecucion = 69,                 /* ejecucion  */
  YYSYMBOL_sentencias = 70,                /* sentencias  */
  YYSYMBOL_imprimir = 71,                  /* imprimir  */
  YYSYMBOL_expr_comp = 72,                 /* expr_comp  */
  YYSYMBOL_expr = 73                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   423

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,    52,    47,    45,    50,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
      54,    49,    55,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    46,    47,    48,    49,    50,    50,    52,
      54,    55,    79,    80,    83,    92,    93,   102,   118,   124,
     125,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     142,   165,   185,   221,   245,   272,   273,   274,   275,   276,
     277,   278,   280,   281,   284,   285,   288,   291,   292,   295,
     302,   308,   309,   315,   317,   319,   320,   321,   322,   323,
     324,   333,   334,   347,   358,   365,   372,   379,   386,   391,
     396,   401,   405,   409,   411,   420,   421,   424,   428,   432,
     436,   440,   459,   484,   498,   513,   528,   537,   549
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PRINT", "INTEGER",
  "STRING", "BOOLEAN", "EXIT_COMMAND", "IF", "ELSE", "DO", "WHILE", "FOR",
  "TAB", "LLAVEAPER", "LLAVECIE", "SWITCH", "CASE", "BREAK", "DEFAULT",
  "COMILLA", "PUNCOMA", "FINLINEA", "AND", "OR", "MENOR_IGUAL",
  "MAYOR_IGUAL", "COMPARISON1", "COMPARISON2", "DIFERENTE", "INCREMENTO",
  "DECREMENTO", "RETURN", "MENOS_IGUAL", "MAS_IGUAL", "POR_IGUAL",
  "ENTRE_IGUAL", "PARSEINT", "TOSTRING", "NUMERO", "TRUE", "FALSE", "ID",
  "ID_MALO", "CADENA", "'+'", "'-'", "'*'", "'/'", "'='", "','", "'('",
  "')'", "';'", "'<'", "'>'", "$accept", "programa", "$@1",
  "declaraciones", "declara_multi", "verifica_param", "asig", "bloque",
  "blo_condicional", "blo_else", "sentencia_while", "blo_for",
  "sentencia_switch", "ejecucion", "sentencias", "imprimir", "expr_comp",
  "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     271,   -21,   -44,   -38,   -35,   112,   -23,    -6,    -2,    46,
      53,  -101,   113,  -101,   185,  -101,   297,   297,   -33,   303,
    -101,  -101,   316,   171,    33,   202,    42,   316,   359,   365,
    -101,    98,  -101,  -101,    85,  -101,    57,  -101,    -9,    -5,
    -101,  -101,   297,     2,   278,     7,     3,     8,    51,  -101,
    -101,  -101,   316,   128,   316,   229,   316,   316,   316,   316,
     316,  -101,  -101,  -101,   283,    61,    68,    73,    76,    78,
      83,  -101,    84,  -101,    94,   140,   171,  -101,    53,  -101,
     221,   238,   248,  -101,   316,    45,   263,   297,   297,    98,
     316,   316,   316,   316,   316,  -101,   316,   316,   316,   316,
     316,   316,    98,   316,    89,   316,    89,   297,   323,  -101,
     334,  -101,   248,   248,   248,   248,   248,   129,   379,   379,
     379,   379,   379,   379,   130,   131,   257,   248,   345,  -101,
    -101,    43,    43,  -101,    53,   248,   248,   248,   248,   248,
      13,    13,   119,   119,   248,   248,  -101,   248,   108,   109,
    -101,   248,  -101,    -3,   138,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,   297,    93,    98,  -101
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       4,     5,     0,     7,     0,     9,     0,     0,    10,     0,
      59,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    55,    43,    48,     0,    54,     0,    77,    79,    80,
      81,    78,     0,     0,    73,     0,    14,    15,     0,    13,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    62,    58,     0,    22,    26,    28,    18,    19,
      24,    50,     0,    51,     0,    55,    81,    44,    39,    40,
       0,     0,    38,     8,     0,     0,    73,     0,     0,    55,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,    61,
       0,    60,    31,    32,    33,    34,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    74,
      88,    75,    76,    42,    39,    66,    67,    69,    70,    68,
      82,    83,    84,    85,    64,    65,    46,    11,    14,    15,
      16,    12,    17,     0,    88,    49,    23,    27,    29,    20,
      21,    25,    52,    53,    87,     0,     0,    55,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -101,    22,  -101,  -101,  -100,   -27,  -101,   -78,   -26,  -101,
      -4,     1,  -101,  -101,    24,  -101,     0,   -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    62,    34,    48,    49,    72,    24,    77,    10,    32,
      11,    12,    13,    14,    81,    26,    43,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    15,    74,    55,   150,    78,   152,    16,    64,    46,
      47,   133,    82,    17,   -71,   -71,    18,    45,   -72,   -72,
      87,    88,     9,    86,   146,    87,    88,    79,    27,    25,
      87,    88,    80,   108,    33,   110,    35,   112,   113,   114,
     115,   116,    85,   -71,   -71,    28,    30,   -72,   -72,    29,
     165,    95,   103,   104,    89,    61,   127,   105,   106,   102,
      98,    99,    31,   134,    63,   128,    87,    88,    87,    88,
      82,   135,   136,   137,   138,   139,   134,   140,   141,   142,
     143,   144,   145,    82,   147,    79,   151,   131,   132,   168,
      80,   156,   157,   158,   159,   160,   161,   129,    79,   126,
      83,    19,    33,    80,   107,    20,     2,   153,    84,     3,
       4,   118,    75,    -6,     1,    19,    87,    88,   119,    20,
      21,     2,    -6,   120,     3,     4,   121,     5,   122,     6,
      22,   148,   149,   123,    21,    36,   124,    37,    50,    51,
      76,   134,    41,    19,    22,   167,   125,    20,    82,    54,
     109,   155,   162,   163,    23,     7,     8,    95,   104,   106,
     -63,     0,    21,    79,     0,   166,    95,     0,    80,     0,
       0,     0,    22,    96,    97,    98,    99,    36,     0,    37,
      50,    51,    76,     0,    41,    -3,     1,     0,     0,     0,
       0,    54,     0,     2,    -3,     0,     3,     4,     0,     5,
       0,     6,    -2,     1,    56,    57,    58,    59,     0,     0,
       2,    -2,     0,     3,     4,     0,     5,     0,     6,     0,
      60,   -41,     1,     0,     0,     0,     0,     7,     8,     2,
     -41,     0,     3,     4,     0,     5,     0,     6,   -37,     1,
       0,     0,     0,     0,     7,     8,     2,   -37,     0,     3,
       4,   111,     5,     0,     6,     0,     0,   -35,     1,     0,
       0,     0,     0,     7,     8,     2,   -35,    95,     3,     4,
       0,     5,     1,     6,    96,    97,    98,    99,     0,     2,
       7,     8,     3,     4,     0,     5,    95,     6,    90,    91,
      92,    93,    94,    96,    97,    98,    99,     0,     0,     7,
       8,    95,     0,    90,    91,    92,    93,    94,    96,    97,
      98,    99,     0,     7,     8,   130,    95,   100,   101,     0,
       0,    95,     0,    96,    97,    98,    99,     0,    96,    97,
      98,    99,   100,   101,    36,   117,    37,    38,    39,    40,
      36,    41,    37,    50,    51,    40,     0,    41,    42,     0,
       0,     0,     0,    36,    52,    37,    50,    51,    40,     0,
      41,    95,     0,     0,     0,     0,     0,    54,    96,    97,
      98,    99,    95,     0,     0,   154,     0,     0,     0,    96,
      97,    98,    99,    95,     0,     0,   130,     0,     0,     0,
      96,    97,    98,    99,     0,     0,     0,   164,    65,    66,
      67,    68,    69,    70,    65,    66,    67,    68,    69,    70,
       0,    71,     0,     0,     0,     0,     0,    73,    65,    66,
      67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
      19,    22,    29,    22,   104,    31,   106,    51,    27,    42,
      43,    89,    31,    51,    23,    24,    51,    17,    23,    24,
      23,    24,     0,    42,   102,    23,    24,    31,    51,     5,
      23,    24,    31,    52,    12,    54,    14,    56,    57,    58,
      59,    60,    42,    52,    53,    51,     0,    52,    53,    51,
      53,    38,    49,    50,    52,    22,    75,    49,    50,    52,
      47,    48,     9,    89,    22,    84,    23,    24,    23,    24,
      89,    90,    91,    92,    93,    94,   102,    96,    97,    98,
      99,   100,   101,   102,   103,    89,   105,    87,    88,   167,
      89,   118,   119,   120,   121,   122,   123,    52,   102,    75,
      15,     3,    80,   102,    53,     7,     8,   107,    51,    11,
      12,    50,    14,     0,     1,     3,    23,    24,    50,     7,
      22,     8,     9,    50,    11,    12,    50,    14,    50,    16,
      32,    42,    43,    50,    22,    37,    52,    39,    40,    41,
      42,   167,    44,     3,    32,    52,    52,     7,   167,    51,
      22,    22,    22,    22,    42,    42,    43,    38,    50,    50,
      22,    -1,    22,   167,    -1,   165,    38,    -1,   167,    -1,
      -1,    -1,    32,    45,    46,    47,    48,    37,    -1,    39,
      40,    41,    42,    -1,    44,     0,     1,    -1,    -1,    -1,
      -1,    51,    -1,     8,     9,    -1,    11,    12,    -1,    14,
      -1,    16,     0,     1,    33,    34,    35,    36,    -1,    -1,
       8,     9,    -1,    11,    12,    -1,    14,    -1,    16,    -1,
      49,     0,     1,    -1,    -1,    -1,    -1,    42,    43,     8,
       9,    -1,    11,    12,    -1,    14,    -1,    16,     0,     1,
      -1,    -1,    -1,    -1,    42,    43,     8,     9,    -1,    11,
      12,    22,    14,    -1,    16,    -1,    -1,     0,     1,    -1,
      -1,    -1,    -1,    42,    43,     8,     9,    38,    11,    12,
      -1,    14,     1,    16,    45,    46,    47,    48,    -1,     8,
      42,    43,    11,    12,    -1,    14,    38,    16,    25,    26,
      27,    28,    29,    45,    46,    47,    48,    -1,    -1,    42,
      43,    38,    -1,    25,    26,    27,    28,    29,    45,    46,
      47,    48,    -1,    42,    43,    52,    38,    54,    55,    -1,
      -1,    38,    -1,    45,    46,    47,    48,    -1,    45,    46,
      47,    48,    54,    55,    37,    52,    39,    40,    41,    42,
      37,    44,    39,    40,    41,    42,    -1,    44,    51,    -1,
      -1,    -1,    -1,    37,    51,    39,    40,    41,    42,    -1,
      44,    38,    -1,    -1,    -1,    -1,    -1,    51,    45,    46,
      47,    48,    38,    -1,    -1,    52,    -1,    -1,    -1,    45,
      46,    47,    48,    38,    -1,    -1,    52,    -1,    -1,    -1,
      45,    46,    47,    48,    -1,    -1,    -1,    52,    39,    40,
      41,    42,    43,    44,    39,    40,    41,    42,    43,    44,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    52,    39,    40,
      41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     8,    11,    12,    14,    16,    42,    43,    57,
      64,    66,    67,    68,    69,    22,    51,    51,    51,     3,
       7,    22,    32,    42,    62,    70,    71,    51,    51,    51,
       0,     9,    65,    57,    58,    57,    37,    39,    40,    41,
      42,    44,    51,    72,    73,    72,    42,    43,    59,    60,
      40,    41,    51,    73,    51,    73,    33,    34,    35,    36,
      49,    22,    57,    22,    73,    39,    40,    41,    42,    43,
      44,    52,    61,    52,    61,    14,    42,    63,    64,    66,
      67,    70,    73,    15,    51,    72,    73,    23,    24,    52,
      25,    26,    27,    28,    29,    38,    45,    46,    47,    48,
      54,    55,    52,    49,    50,    49,    50,    53,    73,    22,
      73,    22,    73,    73,    73,    73,    73,    52,    50,    50,
      50,    50,    50,    50,    52,    52,    70,    73,    73,    52,
      52,    72,    72,    63,    64,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    63,    73,    42,    43,
      60,    73,    60,    72,    52,    22,    61,    61,    61,    61,
      61,    61,    22,    22,    52,    53,    72,    52,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    57,    57,    57,    58,    57,    57,
      59,    59,    59,    59,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     0,     3,     2,
       0,     3,     3,     1,     1,     1,     3,     3,     1,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     5,     2,     2,     2,     5,     9,     2,     5,
       3,     3,     5,     5,     2,     0,     2,     1,     2,     1,
       3,     3,     2,     4,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     3,     3,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     2,     4,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* programa: LLAVEAPER sentencias  */
#line 45 "jparser.y"
                                                {;}
#line 1404 "y.tab.c"
    break;

  case 3: /* programa: ejecucion  */
#line 46 "jparser.y"
                                                {;}
#line 1410 "y.tab.c"
    break;

  case 4: /* programa: blo_condicional  */
#line 47 "jparser.y"
                                                {;}
#line 1416 "y.tab.c"
    break;

  case 5: /* programa: sentencia_while  */
#line 48 "jparser.y"
                                                {;}
#line 1422 "y.tab.c"
    break;

  case 6: /* programa: blo_for  */
#line 49 "jparser.y"
                                        {;}
#line 1428 "y.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 50 "jparser.y"
                                                {;}
#line 1434 "y.tab.c"
    break;

  case 8: /* programa: sentencia_switch $@1 LLAVECIE  */
#line 51 "jparser.y"
                                {;}
#line 1440 "y.tab.c"
    break;

  case 9: /* programa: error FINLINEA  */
#line 52 "jparser.y"
                                                        {yyerrok;}
#line 1446 "y.tab.c"
    break;

  case 11: /* declaraciones: ID '=' expr  */
#line 55 "jparser.y"
                                        {
							simbolo *s = buscarEnBloque(t, (yyvsp[-2].ptr_simbolo)->nombre, level);							
							if (s == NULL){					
								if((yyvsp[0].valor).tipo == 'i'){
									PrintError(5, "");						     
								}else{
									if((yyvsp[0].valor).tipo == 'e'){
										(yyvsp[-2].ptr_simbolo)->tipo = 'e';
										(yyvsp[-2].ptr_simbolo)->info.valor_int = (yyvsp[0].valor).info.valor_int;		       	
										insertar(&t, (yyvsp[-2].ptr_simbolo));
									} else if((yyvsp[0].valor).tipo == 'c'){ 
										(yyvsp[-2].ptr_simbolo)->tipo = 'c';
										strcpy((yyvsp[-2].ptr_simbolo)->info.valor_cad, (yyvsp[0].valor).info.valor_cad);	       	
										insertar(&t, (yyvsp[-2].ptr_simbolo));
									} else{ 
										(yyvsp[-2].ptr_simbolo)->tipo = 'b';
										(yyvsp[-2].ptr_simbolo)->info.valor_bool = (yyvsp[0].valor).info.valor_bool;	       	
										insertar(&t, (yyvsp[-2].ptr_simbolo));
									}											
								}	
							} else{
								PrintError(1, (yyvsp[-2].ptr_simbolo)->nombre);
							}		     
						}
#line 1475 "y.tab.c"
    break;

  case 12: /* declaraciones: ID_MALO '=' expr  */
#line 79 "jparser.y"
                                                {PrintError(4, "nombre de variable invalida");}
#line 1481 "y.tab.c"
    break;

  case 13: /* declaraciones: declara_multi  */
#line 80 "jparser.y"
                                        {;}
#line 1487 "y.tab.c"
    break;

  case 14: /* declara_multi: ID  */
#line 83 "jparser.y"
                                                {
							simbolo *s = buscarEnBloque(t, (yyvsp[0].ptr_simbolo)->nombre, level);		     
							if (s == NULL){	
								(yyvsp[0].ptr_simbolo)->tipo = 'i';				       	
								insertar(&t, (yyvsp[0].ptr_simbolo));
							} else{
								PrintError(1, (yyvsp[0].ptr_simbolo)->nombre);
							}
						}
#line 1501 "y.tab.c"
    break;

  case 15: /* declara_multi: ID_MALO  */
#line 92 "jparser.y"
                                                {PrintError(4, "nombre de variable invalida");}
#line 1507 "y.tab.c"
    break;

  case 16: /* declara_multi: ID ',' declara_multi  */
#line 93 "jparser.y"
                                                {
							simbolo *s = buscarEnBloque(t, (yyvsp[-2].ptr_simbolo)->nombre, level);		     
							if (s == NULL){	
								(yyvsp[-2].ptr_simbolo)->tipo = 'i';				       	
								insertar(&t, (yyvsp[-2].ptr_simbolo));
							} else{
								PrintError(1, (yyvsp[-2].ptr_simbolo)->nombre);
							}
						}
#line 1521 "y.tab.c"
    break;

  case 17: /* declara_multi: ID_MALO ',' declara_multi  */
#line 102 "jparser.y"
                                                {PrintError(4, "nombre de variable invalida");}
#line 1527 "y.tab.c"
    break;

  case 18: /* verifica_param: ID  */
#line 118 "jparser.y"
                                                {
							simbolo *s = buscarEnBloque(t, (yyvsp[0].ptr_simbolo)->nombre, level);		     
							if (s == NULL){	
								PrintError(2, (yyvsp[0].ptr_simbolo)->nombre);
							}
						}
#line 1538 "y.tab.c"
    break;

  case 19: /* verifica_param: ID_MALO  */
#line 124 "jparser.y"
                                                {PrintError(4, "nombre de parametro invalida");}
#line 1544 "y.tab.c"
    break;

  case 20: /* verifica_param: ID ',' verifica_param  */
#line 125 "jparser.y"
                                                {
							simbolo *s = buscarEnBloque(t, (yyvsp[-2].ptr_simbolo)->nombre, level);		     
							if (s == NULL){	
								PrintError(2, (yyvsp[-2].ptr_simbolo)->nombre);
							}
						}
#line 1555 "y.tab.c"
    break;

  case 21: /* verifica_param: ID_MALO ',' verifica_param  */
#line 131 "jparser.y"
                                                {PrintError(4, "nombre de parametro invalida");}
#line 1561 "y.tab.c"
    break;

  case 22: /* verifica_param: NUMERO  */
#line 132 "jparser.y"
                                                {;}
#line 1567 "y.tab.c"
    break;

  case 23: /* verifica_param: NUMERO ',' verifica_param  */
#line 133 "jparser.y"
                                                {;}
#line 1573 "y.tab.c"
    break;

  case 24: /* verifica_param: CADENA  */
#line 134 "jparser.y"
                                                {;}
#line 1579 "y.tab.c"
    break;

  case 25: /* verifica_param: CADENA ',' verifica_param  */
#line 135 "jparser.y"
                                                {;}
#line 1585 "y.tab.c"
    break;

  case 26: /* verifica_param: TRUE  */
#line 136 "jparser.y"
                                                {;}
#line 1591 "y.tab.c"
    break;

  case 27: /* verifica_param: TRUE ',' verifica_param  */
#line 137 "jparser.y"
                                                {;}
#line 1597 "y.tab.c"
    break;

  case 28: /* verifica_param: FALSE  */
#line 138 "jparser.y"
                                                {;}
#line 1603 "y.tab.c"
    break;

  case 29: /* verifica_param: FALSE ',' verifica_param  */
#line 139 "jparser.y"
                                                {;}
#line 1609 "y.tab.c"
    break;

  case 30: /* asig: ID '=' expr  */
#line 142 "jparser.y"
                                       {
                            simbolo *s = buscar(t, (yyvsp[-2].ptr_simbolo)->nombre);
                            if (s != NULL){                                                            
                                if(s->tipo == 'i'){ s->tipo = (yyvsp[0].valor).tipo;}
                                if((yyvsp[0].valor).tipo == 'i'){
                                    PrintError(5, "");                             
                                }else{
                                    if((yyvsp[0].valor).tipo != s->tipo){
										///VALIDAR SI ES NECESARIO
                                        ///PrintError(4, "tipos incompatibles");    
                                    } else if(s->tipo == 'e'){
                                        s->info.valor_int = (yyvsp[0].valor).info.valor_int;        
                                    } else if(s->tipo == 'c'){
                                        strcpy(s->info.valor_cad, (yyvsp[0].valor).info.valor_cad);    
                                    } else{
                                        s->info.valor_bool = (yyvsp[0].valor).info.valor_bool;
                                    }                                            
                                }     
                            } else{
                                (yyvsp[-2].ptr_simbolo)->tipo = (yyvsp[0].valor).tipo;                       
                                insertar(&t, (yyvsp[-2].ptr_simbolo));
                            }
                        }
#line 1637 "y.tab.c"
    break;

  case 31: /* asig: ID MENOS_IGUAL expr  */
#line 165 "jparser.y"
                                        {	
							simbolo *s = buscar(t, (yyvsp[-2].ptr_simbolo)->nombre);
							if (s != NULL){														
								if(s->tipo == 'i'){ s->tipo = (yyvsp[0].valor).tipo;}
								if((yyvsp[0].valor).tipo == 'i'){
									PrintError(5, "");						     
								}else{
									if((s->tipo == 'b') && ((yyvsp[0].valor).tipo == 'e')) {	//boolean -= entero 
                                        PrintError(5, "");
									} else if((s->tipo == 'e') && ((yyvsp[0].valor).tipo == 'b')) {	//entero -= boolean 
                                        PrintError(5, "");
									} else if((s->tipo == 'e') && ((yyvsp[0].valor).tipo == 'e')) {	//entero -= entero 
										s->tipo = 'e';
										s->info.valor_int = s->info.valor_int - (yyvsp[0].valor).info.valor_int;
									} 											
								} 									
							} else{
								PrintError(2, (yyvsp[-2].ptr_simbolo)->nombre);
							}
						}
#line 1662 "y.tab.c"
    break;

  case 32: /* asig: ID MAS_IGUAL expr  */
#line 185 "jparser.y"
                                        {
							simbolo *s = buscar(t, (yyvsp[-2].ptr_simbolo)->nombre);
							if (s != NULL){											
								if(s->tipo == 'i'){ s->tipo = (yyvsp[0].valor).tipo;}
								if((yyvsp[0].valor).tipo == 'i'){
									PrintError(5, "");						     
								}else{	
									if((s->tipo == 'b') && ((yyvsp[0].valor).tipo == 'c')) {		//boolean += cadena
                                        PrintError(5, "");
									} else if((s->tipo == 'b') && ((yyvsp[0].valor).tipo == 'e')) {	//boolean += entero
                                        PrintError(5, "");
									} else if((s->tipo == 'e') && ((yyvsp[0].valor).tipo == 'b')) {	//entero += boolean
                                         PrintError(5, "");
									} else if(((yyvsp[-2].ptr_simbolo)->tipo == 'e') && ((yyvsp[0].valor).tipo == 'e')) {	//entero += entero
										s->tipo = 'e';
										s->info.valor_int = s->info.valor_int + (yyvsp[0].valor).info.valor_int;
									} else if((s->tipo == 'c') && ((yyvsp[0].valor).tipo == 'c')) {	//cadena += cadena
										s->tipo = 'c';
										sprintf((yyvsp[-2].ptr_simbolo)->info.valor_cad, "%s%s", s->info.valor_cad, (yyvsp[0].valor).info.valor_cad);
									} else if((s->tipo == 'b') && ((yyvsp[0].valor).tipo == 'b')) {	//boolean += boolean
                                         PrintError(5, "");
									} else if((s->tipo == 'c') && ((yyvsp[0].valor).tipo == 'e')) {	//cadena += entero
										s->tipo = 'c';
										sprintf(s->info.valor_cad, "%s%d", s->info.valor_cad, (yyvsp[0].valor).info.valor_int);
									} else if((s->tipo == 'e') && ((yyvsp[0].valor).tipo == 'c')) {	//entero += cadena
                                        PrintError(5, "");
									} else{
										s->tipo = 'i';
										if((s->tipo != 'i') && ((yyvsp[0].valor).tipo != 'i'))
											PrintError(5, "");
									}										
								} 
							} else{
								PrintError(2, (yyvsp[-2].ptr_simbolo)->nombre);
							}
						}
#line 1703 "y.tab.c"
    break;

  case 33: /* asig: ID POR_IGUAL expr  */
#line 221 "jparser.y"
                                                {
							simbolo *s = buscar(t, (yyvsp[-2].ptr_simbolo)->nombre);
							if (s != NULL){											
								if(s->tipo == 'i'){ s->tipo = (yyvsp[0].valor).tipo;}
								if((yyvsp[0].valor).tipo == 'i'){
									PrintError(5, "");						     
								}else{
									if((s->tipo == 'b') && ((yyvsp[0].valor).tipo == 'e')) {	//boolean *= entero
										PrintError(5, "");
									} else if((s->tipo == 'e') && ((yyvsp[0].valor).tipo == 'b')) {	//entero *= boolean
										PrintError(5, "");
									} else if((s->tipo == 'e') && ((yyvsp[0].valor).tipo == 'e')) {	//entero *= entero
										s->tipo = 'e';
										s->info.valor_int = s->info.valor_int * (yyvsp[0].valor).info.valor_int;
									} else{
										s->tipo = 'i';
										if((s->tipo != 'i') && ((yyvsp[0].valor).tipo != 'i'))
											PrintError(5, "");
									}											
								} 
							} else{
								PrintError(2, (yyvsp[-2].ptr_simbolo)->nombre);
							}
						}
#line 1732 "y.tab.c"
    break;

  case 34: /* asig: ID ENTRE_IGUAL expr  */
#line 245 "jparser.y"
                                                {
							simbolo *s = buscar(t, (yyvsp[-2].ptr_simbolo)->nombre);
							if (s != NULL){										
								if(s->tipo == 'i'){ s->tipo = (yyvsp[0].valor).tipo;}
								if((yyvsp[0].valor).tipo == 'i'){
									PrintError(5, "");						     
								}else{
									if((s->tipo == 'b') && ((yyvsp[0].valor).tipo == 'e')) {	//boolean /= entero
										PrintError(5, "");
									} else if((s->tipo == 'e') && ((yyvsp[0].valor).tipo == 'b')) {	//entero /= boolean
										PrintError(5, "");
									} else if((s->tipo == 'e') && ((yyvsp[0].valor).tipo == 'e')) {	//entero /= entero
										s->tipo = 'e';
										s->info.valor_int = s->info.valor_int / (yyvsp[0].valor).info.valor_int;
									} else{
										s->tipo = 'i';
										if((s->tipo != 'i') && ((yyvsp[0].valor).tipo != 'i'))
											PrintError(5, "");
									}											
								} 
							} else{
								PrintError(2, (yyvsp[-2].ptr_simbolo)->nombre);
							}
						}
#line 1761 "y.tab.c"
    break;

  case 35: /* bloque: LLAVEAPER sentencias  */
#line 272 "jparser.y"
                                                                {;}
#line 1767 "y.tab.c"
    break;

  case 36: /* bloque: LLAVEAPER expr  */
#line 273 "jparser.y"
                                                                        {;}
#line 1773 "y.tab.c"
    break;

  case 37: /* bloque: sentencias  */
#line 274 "jparser.y"
                                                                        {;}
#line 1779 "y.tab.c"
    break;

  case 38: /* bloque: expr  */
#line 275 "jparser.y"
                                                                                {;}
#line 1785 "y.tab.c"
    break;

  case 39: /* bloque: blo_condicional  */
#line 276 "jparser.y"
                                                                        {;}
#line 1791 "y.tab.c"
    break;

  case 40: /* bloque: sentencia_while  */
#line 277 "jparser.y"
                                                                        {;}
#line 1797 "y.tab.c"
    break;

  case 41: /* bloque: blo_for  */
#line 278 "jparser.y"
                                                                                {;}
#line 1803 "y.tab.c"
    break;

  case 42: /* blo_condicional: IF '(' expr_comp ')' bloque  */
#line 280 "jparser.y"
                                                                        {;}
#line 1809 "y.tab.c"
    break;

  case 43: /* blo_condicional: blo_condicional blo_else  */
#line 281 "jparser.y"
                                                                {;}
#line 1815 "y.tab.c"
    break;

  case 44: /* blo_else: ELSE bloque  */
#line 284 "jparser.y"
                                                                                {;}
#line 1821 "y.tab.c"
    break;

  case 45: /* blo_else: ELSE blo_condicional  */
#line 285 "jparser.y"
                                                                {;}
#line 1827 "y.tab.c"
    break;

  case 46: /* sentencia_while: WHILE '(' expr_comp ')' bloque  */
#line 288 "jparser.y"
                                                                        {;}
#line 1833 "y.tab.c"
    break;

  case 47: /* blo_for: FOR '(' declaraciones ';' expr_comp ';' expr_comp ')' bloque  */
#line 291 "jparser.y"
                                                                                {;}
#line 1839 "y.tab.c"
    break;

  case 48: /* blo_for: blo_for programa  */
#line 292 "jparser.y"
                                              {;}
#line 1845 "y.tab.c"
    break;

  case 49: /* sentencia_switch: SWITCH '(' expr ')' FINLINEA  */
#line 295 "jparser.y"
                                                {;}
#line 1851 "y.tab.c"
    break;

  case 50: /* ejecucion: ID '(' ')'  */
#line 302 "jparser.y"
                                                { 
								simbolo *s = buscar(t, (yyvsp[-2].ptr_simbolo)->nombre);
								if(s == NULL){
									PrintError(8, (yyvsp[-2].ptr_simbolo)->nombre);
								}
							}
#line 1862 "y.tab.c"
    break;

  case 51: /* ejecucion: ID_MALO '(' ')'  */
#line 308 "jparser.y"
                                                {PrintError(4, "nombre de function invalida");}
#line 1868 "y.tab.c"
    break;

  case 52: /* ejecucion: ID '(' verifica_param ')' FINLINEA  */
#line 309 "jparser.y"
                                                        { 
								simbolo *s = buscar(t, (yyvsp[-4].ptr_simbolo)->nombre);
								if(s == NULL){
									PrintError(8, (yyvsp[-4].ptr_simbolo)->nombre);
								}
							}
#line 1879 "y.tab.c"
    break;

  case 53: /* ejecucion: ID_MALO '(' verifica_param ')' FINLINEA  */
#line 316 "jparser.y"
                                                        {PrintError(4, "nombre de function invalida");}
#line 1885 "y.tab.c"
    break;

  case 54: /* ejecucion: ejecucion programa  */
#line 317 "jparser.y"
                                                        {;}
#line 1891 "y.tab.c"
    break;

  case 56: /* sentencias: asig FINLINEA  */
#line 320 "jparser.y"
                                        {;}
#line 1897 "y.tab.c"
    break;

  case 57: /* sentencias: FINLINEA  */
#line 321 "jparser.y"
                                {;}
#line 1903 "y.tab.c"
    break;

  case 58: /* sentencias: imprimir FINLINEA  */
#line 322 "jparser.y"
                                        {;}
#line 1909 "y.tab.c"
    break;

  case 59: /* sentencias: EXIT_COMMAND  */
#line 323 "jparser.y"
                                        {exit(EXIT_SUCCESS);}
#line 1915 "y.tab.c"
    break;

  case 60: /* sentencias: RETURN expr FINLINEA  */
#line 324 "jparser.y"
                                                { 
						(yyval.valor).tipo = (yyvsp[-1].valor).tipo;
						if((yyvsp[-1].valor).tipo == 'e')
							(yyval.valor).info.valor_int = (yyvsp[-1].valor).info.valor_int;
						else if((yyvsp[-1].valor).tipo == 'c')
							strcpy((yyval.valor).info.valor_cad, (yyvsp[-1].valor).info.valor_cad);
						else 
							(yyval.valor).info.valor_bool = (yyvsp[-1].valor).info.valor_bool;
					}
#line 1929 "y.tab.c"
    break;

  case 61: /* sentencias: PRINT expr FINLINEA  */
#line 333 "jparser.y"
                                        {;}
#line 1935 "y.tab.c"
    break;

  case 62: /* sentencias: sentencias programa  */
#line 334 "jparser.y"
                                        {;}
#line 1941 "y.tab.c"
    break;

  case 63: /* imprimir: PRINT '(' expr ')'  */
#line 347 "jparser.y"
                                                        {
									if((yyvsp[-1].valor).tipo == 'i'){
													PrintError(4, "no se pueden comparar, tipos indefinidos");
									}
									else if((yyvsp[-1].valor).tipo == 'e')printf((yyvsp[-1].valor).info.valor_int);
									else if((yyvsp[-1].valor).tipo == 'c')printf((yyvsp[-1].valor).info.valor_cad);
									else printf((yyvsp[-1].valor).info.valor_cad);									
									printf("\n");
									}
#line 1955 "y.tab.c"
    break;

  case 64: /* expr_comp: expr '<' expr  */
#line 358 "jparser.y"
                                        { 
						if((yyvsp[-2].valor).tipo == 'i' || (yyvsp[0].valor).tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} else if((yyvsp[-2].valor).tipo != 'e' || (yyvsp[0].valor).tipo != 'e'){
							PrintError(4, "no se pueden comparar, tipos diferentes de int");
						} 
					}
#line 1967 "y.tab.c"
    break;

  case 65: /* expr_comp: expr '>' expr  */
#line 365 "jparser.y"
                                                { 
						if((yyvsp[-2].valor).tipo == 'i' || (yyvsp[0].valor).tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} else if((yyvsp[-2].valor).tipo != 'e' || (yyvsp[0].valor).tipo != 'e'){
							PrintError(4, "no se pueden comparar, tipos diferentes de int");
						} 
					}
#line 1979 "y.tab.c"
    break;

  case 66: /* expr_comp: expr MENOR_IGUAL expr  */
#line 372 "jparser.y"
                                                { 
						if((yyvsp[-2].valor).tipo == 'i' || (yyvsp[0].valor).tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} else if((yyvsp[-2].valor).tipo != 'e' || (yyvsp[0].valor).tipo != 'e'){
							PrintError(4, "no se pueden comparar, tipos diferentes de int");
						} 
					}
#line 1991 "y.tab.c"
    break;

  case 67: /* expr_comp: expr MAYOR_IGUAL expr  */
#line 379 "jparser.y"
                                        { 
						if((yyvsp[-2].valor).tipo == 'i' || (yyvsp[0].valor).tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} else if((yyvsp[-2].valor).tipo != 'e' || (yyvsp[0].valor).tipo != 'e'){
							PrintError(4, "no se pueden comparar, tipos diferentes de int");
						} 
					}
#line 2003 "y.tab.c"
    break;

  case 68: /* expr_comp: expr DIFERENTE expr  */
#line 386 "jparser.y"
                                                { 
						if((yyvsp[-2].valor).tipo == 'i' || (yyvsp[0].valor).tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} 
					}
#line 2013 "y.tab.c"
    break;

  case 69: /* expr_comp: expr COMPARISON1 expr  */
#line 391 "jparser.y"
                                        { 
						if((yyvsp[-2].valor).tipo == 'i' || (yyvsp[0].valor).tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} 
					}
#line 2023 "y.tab.c"
    break;

  case 70: /* expr_comp: expr COMPARISON2 expr  */
#line 396 "jparser.y"
                                        { 
						if((yyvsp[-2].valor).tipo == 'i' || (yyvsp[0].valor).tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} 
					}
#line 2033 "y.tab.c"
    break;

  case 71: /* expr_comp: TRUE  */
#line 401 "jparser.y"
                                        {
						(yyval.valor).tipo = 'b';
						(yyval.valor).info.valor_bool = true;
					}
#line 2042 "y.tab.c"
    break;

  case 72: /* expr_comp: FALSE  */
#line 405 "jparser.y"
                                        {
						(yyval.valor).tipo = 'b';
						(yyval.valor).info.valor_bool = false;
					}
#line 2051 "y.tab.c"
    break;

  case 73: /* expr_comp: expr  */
#line 409 "jparser.y"
                                        {PrintError(4,"no se puede comparar la expresion");
					}
#line 2058 "y.tab.c"
    break;

  case 74: /* expr_comp: '(' expr_comp ')'  */
#line 411 "jparser.y"
                                                { 
						(yyval.valor).tipo = (yyvsp[-1].valor).tipo;
						if((yyvsp[-1].valor).tipo == 'e')
							(yyval.valor).info.valor_int = (yyvsp[-1].valor).info.valor_int;
						else if((yyvsp[-1].valor).tipo == 'c')
							strcpy((yyval.valor).info.valor_cad, (yyvsp[-1].valor).info.valor_cad);
						else 
							(yyval.valor).info.valor_bool = (yyvsp[-1].valor).info.valor_bool;
					}
#line 2072 "y.tab.c"
    break;

  case 75: /* expr_comp: expr_comp AND expr_comp  */
#line 420 "jparser.y"
                                                {;}
#line 2078 "y.tab.c"
    break;

  case 76: /* expr_comp: expr_comp OR expr_comp  */
#line 421 "jparser.y"
                                                {;}
#line 2084 "y.tab.c"
    break;

  case 77: /* expr: NUMERO  */
#line 424 "jparser.y"
                                        { 						
						(yyval.valor).tipo = 'e';
						(yyval.valor).info.valor_int = (yyvsp[0].numero);
					}
#line 2093 "y.tab.c"
    break;

  case 78: /* expr: CADENA  */
#line 428 "jparser.y"
                                        {
						(yyval.valor).tipo = 'c';
						strcpy((yyval.valor).info.valor_cad, (yyvsp[0].cadena));
					}
#line 2102 "y.tab.c"
    break;

  case 79: /* expr: TRUE  */
#line 432 "jparser.y"
                                        {
						(yyval.valor).tipo = 'b';
						(yyval.valor).info.valor_bool = true;
					}
#line 2111 "y.tab.c"
    break;

  case 80: /* expr: FALSE  */
#line 436 "jparser.y"
                                        {
						(yyval.valor).tipo = 'b';
						(yyval.valor).info.valor_bool = false;
					}
#line 2120 "y.tab.c"
    break;

  case 81: /* expr: ID  */
#line 440 "jparser.y"
                                                { 
						simbolo *s = buscar(t, (yyvsp[0].ptr_simbolo)->nombre);
							if(s != NULL){
								(yyval.valor).tipo = s->tipo;
								if((yyval.valor).tipo == 'i'){
									PrintError(6, s->nombre);
							}else{
								if((yyval.valor).tipo == 'e'){
									(yyval.valor).info.valor_int = s->info.valor_int;
								} else if((yyval.valor).tipo == 'c'){
									strcpy((yyval.valor).info.valor_cad, s->info.valor_cad);
								} else{
									(yyval.valor).info.valor_bool = s->info.valor_bool;
								}
							} 
						} else{
							PrintError(2, (yyvsp[0].ptr_simbolo)->nombre);
						}
					}
#line 2144 "y.tab.c"
    break;

  case 82: /* expr: expr '+' expr  */
#line 459 "jparser.y"
                                                { 	
						if(((yyvsp[-2].valor).tipo == 'b') && ((yyvsp[0].valor).tipo == 'c')) {		//boolean + cadena
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(((yyvsp[-2].valor).tipo == 'b') && ((yyvsp[0].valor).tipo == 'e')) {	//boolean + entero
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(((yyvsp[-2].valor).tipo == 'e') && ((yyvsp[0].valor).tipo == 'b')) {	//entero + boolean
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(((yyvsp[-2].valor).tipo == 'e') && ((yyvsp[0].valor).tipo == 'e')) {	//entero + entero
							(yyval.valor).tipo = 'e';
							(yyval.valor).info.valor_int = (yyvsp[-2].valor).info.valor_int + (yyvsp[0].valor).info.valor_int;
						} else if(((yyvsp[-2].valor).tipo == 'c') && ((yyvsp[0].valor).tipo == 'c')) {	//cadena + cadena
							(yyval.valor).tipo = 'c';
							sprintf((yyval.valor).info.valor_cad, "%s%s", (yyvsp[-2].valor).info.valor_cad, (yyvsp[0].valor).info.valor_cad);
						} else if(((yyvsp[-2].valor).tipo == 'b') && ((yyvsp[0].valor).tipo == 'b')) {	//boolean + boolean
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(((yyvsp[-2].valor).tipo == 'c') && ((yyvsp[0].valor).tipo == 'e')) {	//cadena + entero
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(((yyvsp[-2].valor).tipo == 'e') && ((yyvsp[0].valor).tipo == 'c')) {	//entero + cadena
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else{
							(yyval.valor).tipo = 'i';
							if (((yyvsp[-2].valor).tipo != 'i') && ((yyvsp[0].valor).tipo != 'i'))
								PrintError(4, "Expresion de tipos indefinidos");
						}
					}
#line 2174 "y.tab.c"
    break;

  case 83: /* expr: expr '-' expr  */
#line 484 "jparser.y"
                                                { 
						if(((yyvsp[-2].valor).tipo == 'b') && ((yyvsp[0].valor).tipo == 'e')) {		//boolean - entero
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(((yyvsp[-2].valor).tipo == 'e') && ((yyvsp[0].valor).tipo == 'b')) {	//entero - boolean
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(((yyvsp[-2].valor).tipo == 'e') && ((yyvsp[0].valor).tipo == 'e')) {	//entero - entero
							(yyval.valor).tipo = 'e';
							(yyval.valor).info.valor_int = (yyvsp[-2].valor).info.valor_int - (yyvsp[0].valor).info.valor_int;
						} else {
							(yyval.valor).tipo = 'i';
							if (((yyvsp[-2].valor).tipo != 'i') && ((yyvsp[0].valor).tipo != 'i'))
								PrintError(4, "Expresion de tipos indefinidos");
						}
					}
#line 2193 "y.tab.c"
    break;

  case 84: /* expr: expr '*' expr  */
#line 498 "jparser.y"
                                                { 
						
						if(((yyvsp[-2].valor).tipo == 'b') && ((yyvsp[0].valor).tipo == 'e')) {		//boolean *= entero
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(((yyvsp[-2].valor).tipo == 'e') && ((yyvsp[0].valor).tipo == 'b')) {	//entero *= boolean
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(((yyvsp[-2].valor).tipo == 'e') && ((yyvsp[0].valor).tipo == 'e')) {	//entero *= entero
							(yyval.valor).tipo = 'e';
							(yyval.valor).info.valor_int = (yyvsp[-2].valor).info.valor_int * (yyvsp[0].valor).info.valor_int;
						} else{
							(yyvsp[-2].valor).tipo = 'i';
							if (((yyvsp[-2].valor).tipo != 'i') && ((yyvsp[0].valor).tipo != 'i'))
								PrintError(5, "");
						}
					}
#line 2213 "y.tab.c"
    break;

  case 85: /* expr: expr '/' expr  */
#line 513 "jparser.y"
                                                { 
						
						if(((yyvsp[-2].valor).tipo == 'b') && ((yyvsp[0].valor).tipo == 'e')) {		//boolean /= entero
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(((yyvsp[-2].valor).tipo == 'e') && ((yyvsp[0].valor).tipo == 'b')) {	//entero /= boolean
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(((yyvsp[-2].valor).tipo == 'e') && ((yyvsp[0].valor).tipo == 'e')) {	//entero /= entero
							(yyval.valor).tipo = 'e';
							(yyval.valor).info.valor_int = (yyvsp[-2].valor).info.valor_int / (yyvsp[0].valor).info.valor_int;
						} else{
							(yyvsp[-2].valor).tipo = 'i';
							if (((yyvsp[-2].valor).tipo != 'i') && ((yyvsp[0].valor).tipo != 'i'))
								PrintError(5, "");
						}
					}
#line 2233 "y.tab.c"
    break;

  case 86: /* expr: expr TOSTRING  */
#line 528 "jparser.y"
                                                {	
						if ((yyvsp[-1].valor).tipo != 'e') {
							(yyval.valor).tipo = 'i';
							PrintError(4, "se requiere un entero para la conversion en linea");
						} else {
							(yyval.valor).tipo = 'c';
							snprintf((yyval.valor).info.valor_cad, sizeof((yyval.valor).info.valor_cad), "%d",(yyvsp[-1].valor).info.valor_int);
						}
					}
#line 2247 "y.tab.c"
    break;

  case 87: /* expr: PARSEINT '(' expr ')'  */
#line 537 "jparser.y"
                                                {
						if ((yyvsp[-1].valor).tipo != 'c') {
		 					(yyval.valor).tipo = 'i';
							PrintError(4, "se requiere una cadena para la conversion en linea");
						} else if (esNumero((yyvsp[-1].valor).info.valor_cad)){
							(yyval.valor).tipo = 'e';
							(yyval.valor).info.valor_int = atoi((yyvsp[-1].valor).info.valor_cad);
						} else{
							(yyval.valor).tipo = 'i';
							PrintError(4, "la cadena a convertir solo puede tener digitos en linea");
						}
					}
#line 2264 "y.tab.c"
    break;

  case 88: /* expr: '(' expr ')'  */
#line 549 "jparser.y"
                                                        { 
						(yyval.valor).tipo = (yyvsp[-1].valor).tipo;
						if((yyvsp[-1].valor).tipo == 'e')
							(yyval.valor).info.valor_int = (yyvsp[-1].valor).info.valor_int;
						else if((yyvsp[-1].valor).tipo == 'c')
							strcpy((yyval.valor).info.valor_cad, (yyvsp[-1].valor).info.valor_cad);
						else 
							(yyval.valor).info.valor_bool = (yyvsp[-1].valor).info.valor_bool;
					}
#line 2278 "y.tab.c"
    break;


#line 2282 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 559 "jparser.y"


void yyerror(char *s){
	extern int yylineno;	// predefinida en lex.c
	extern char *yytext;	// predefinida en lex.c
	errores++; 
	
	printf("ERROR: %s en simbolo \"%s\" en linea %d \n",s,yytext,yylineno); 
}

void PrintError(int opc, char *s){
	extern int yylineno;	// predefinida en lex.c

	switch(opc){
		case 1:{
			errores++;
			printf("Error: variable '%s' repetetida en linea %d \n", s, yylineno);
			break;
		}
		case 2:{
			errores++;
			printf("Error: variable '%s' no declarada en linea %d \n", s, yylineno);
			break;
		}
		case 3:{
			errores++;
			printf("Error: se esperaba '%s' en linea %d \n", s, yylineno); 
			break;
		}
		case 4:{
			errores++;
			printf("Error: %s, en linea %d \n", s, yylineno); 
			break;
		}
		case 5:{
			errores++;
			printf("Error: asignacion de tipo indefinido en linea %d \n", yylineno); 
			break;
		}
		case 6:{
			errores++;
			printf("Error: tipo de '%s' no definido en linea %d.\n", s, yylineno); 
			break;
		}
		case 7:{
			errores++;
			printf("Error: se esperaba '%s' en linea %d.\n", s, yylineno); 
			break;
		}
		case 8:{
			errores++;
			printf("Error: function '%s' no declarada en linea %d \n", s, yylineno);
			break;
		}
	}	
}

void main(){ 
	t = crear();
	yyparse();	
	if(errores == 0){
		printf("La compilacion fue exitosa!\n"); 
	} else{
		printf("Total de errores: %d\n", errores); 
	}
}
