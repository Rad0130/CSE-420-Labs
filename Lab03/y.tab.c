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
#line 1 "22201909.y"


#include "symbol_table.h"

#define YYSTYPE symbol_info*

extern FILE *yyin;
int yyparse(void);
int yylex(void);
extern YYSTYPE yylval;

// create your symbol table here.
// You can store the pointer to your symbol table in a global variable
// or you can create an object

symbol_table *st;

int lines = 1;
int error_count = 0;

// Track lines with errors to avoid counting multiple errors on same line
set<int> lines_with_errors;

ofstream outlog;
ofstream errout;

// you may declare other necessary variables here to store necessary info
// such as current variable type, variable list, function name, return type, function parameter types, parameters names etc.
string current_type;
string data_type;
int array_size;
vector<string> param_names;
vector<string> param_types;
string current_func_return_type;

// Helper function to report semantic errors
void semantic_error(int line, string message) {
    // Only increment error count if this is the first error on this line
    if(lines_with_errors.find(line) == lines_with_errors.end()) {
        lines_with_errors.insert(line);
    }
    errout << "Error at line no: " << line << " : " << message << endl;
    outlog << "Error at line no: " << line << " : " << message << endl;
}

// Helper function to type check
bool type_compatible(string type1, string type2) {
    if (type1 == type2) return true;    
    return false;
}

// Helper functions for processing variable declarations
vector<string> split(const string& str, char delim) {
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

void process_variable(const string& var, const string& type) {
    size_t open_bracket = var.find('[');
    size_t close_bracket = var.find(']');

    if (open_bracket != string::npos && close_bracket != string::npos && close_bracket > open_bracket + 1) {
        // Array variable
        string array_name = var.substr(0, open_bracket);
        int array_size = stoi(var.substr(open_bracket + 1, close_bracket - open_bracket - 1));

        // Check if variable is already declared in current scope
        symbol_info* existing = st->lookup(array_name);
        if (existing != NULL) {
            semantic_error(lines, "Multiple declaration of variable " + array_name);
            return;
        }

        symbol_info* new_symbol = new symbol_info(array_name, "ID", "Array");
        new_symbol->set_array_size(array_size);
        new_symbol->set_data_type(type);
        st->insert(new_symbol);
    } else {
        // Normal variable
        // Check if variable is already declared in current scope
        symbol_info* existing = st->lookup(var);
        if (existing != NULL) {
            semantic_error(lines, "Multiple declaration of variable " + var);
            return;
        }

        symbol_info* new_symbol = new symbol_info(var, "ID", "Variable");
        new_symbol->set_data_type(type);
        st->insert(new_symbol);
    }
}

void yyerror(char *s)
{
	outlog<<"At line "<<lines<<" "<<s<<endl<<endl;

    // you may need to reinitialize variables if you find an error
    param_names.clear();
    param_types.clear();
}


#line 180 "y.tab.c"

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
# define YYDEBUG 1
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
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    WHILE = 261,                   /* WHILE  */
    DO = 262,                      /* DO  */
    BREAK = 263,                   /* BREAK  */
    INT = 264,                     /* INT  */
    CHAR = 265,                    /* CHAR  */
    FLOAT = 266,                   /* FLOAT  */
    DOUBLE = 267,                  /* DOUBLE  */
    VOID = 268,                    /* VOID  */
    RETURN = 269,                  /* RETURN  */
    SWITCH = 270,                  /* SWITCH  */
    CASE = 271,                    /* CASE  */
    DEFAULT = 272,                 /* DEFAULT  */
    CONTINUE = 273,                /* CONTINUE  */
    PRINTLN = 274,                 /* PRINTLN  */
    ADDOP = 275,                   /* ADDOP  */
    MULOP = 276,                   /* MULOP  */
    INCOP = 277,                   /* INCOP  */
    DECOP = 278,                   /* DECOP  */
    RELOP = 279,                   /* RELOP  */
    ASSIGNOP = 280,                /* ASSIGNOP  */
    LOGICOP = 281,                 /* LOGICOP  */
    NOT = 282,                     /* NOT  */
    LPAREN = 283,                  /* LPAREN  */
    RPAREN = 284,                  /* RPAREN  */
    LCURL = 285,                   /* LCURL  */
    RCURL = 286,                   /* RCURL  */
    LTHIRD = 287,                  /* LTHIRD  */
    RTHIRD = 288,                  /* RTHIRD  */
    COMMA = 289,                   /* COMMA  */
    SEMICOLON = 290,               /* SEMICOLON  */
    CONST_INT = 291,               /* CONST_INT  */
    CONST_FLOAT = 292,             /* CONST_FLOAT  */
    ID = 293,                      /* ID  */
    LOWER_THAN_ELSE = 294          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define INT 264
#define CHAR 265
#define FLOAT 266
#define DOUBLE 267
#define VOID 268
#define RETURN 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define CONTINUE 273
#define PRINTLN 274
#define ADDOP 275
#define MULOP 276
#define INCOP 277
#define DECOP 278
#define RELOP 279
#define ASSIGNOP 280
#define LOGICOP 281
#define NOT 282
#define LPAREN 283
#define RPAREN 284
#define LCURL 285
#define RCURL 286
#define LTHIRD 287
#define RTHIRD 288
#define COMMA 289
#define SEMICOLON 290
#define CONST_INT 291
#define CONST_FLOAT 292
#define ID 293
#define LOWER_THAN_ELSE 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_BREAK = 8,                      /* BREAK  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_FLOAT = 11,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 12,                    /* DOUBLE  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_SWITCH = 15,                    /* SWITCH  */
  YYSYMBOL_CASE = 16,                      /* CASE  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_PRINTLN = 19,                   /* PRINTLN  */
  YYSYMBOL_ADDOP = 20,                     /* ADDOP  */
  YYSYMBOL_MULOP = 21,                     /* MULOP  */
  YYSYMBOL_INCOP = 22,                     /* INCOP  */
  YYSYMBOL_DECOP = 23,                     /* DECOP  */
  YYSYMBOL_RELOP = 24,                     /* RELOP  */
  YYSYMBOL_ASSIGNOP = 25,                  /* ASSIGNOP  */
  YYSYMBOL_LOGICOP = 26,                   /* LOGICOP  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_LPAREN = 28,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 29,                    /* RPAREN  */
  YYSYMBOL_LCURL = 30,                     /* LCURL  */
  YYSYMBOL_RCURL = 31,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 32,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 33,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 35,                 /* SEMICOLON  */
  YYSYMBOL_CONST_INT = 36,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 37,               /* CONST_FLOAT  */
  YYSYMBOL_ID = 38,                        /* ID  */
  YYSYMBOL_LOWER_THAN_ELSE = 39,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_start = 41,                     /* start  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_unit = 43,                      /* unit  */
  YYSYMBOL_func_definition = 44,           /* func_definition  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_parameter_list = 47,            /* parameter_list  */
  YYSYMBOL_compound_statement = 48,        /* compound_statement  */
  YYSYMBOL_var_declaration = 49,           /* var_declaration  */
  YYSYMBOL_type_specifier = 50,            /* type_specifier  */
  YYSYMBOL_declaration_list = 51,          /* declaration_list  */
  YYSYMBOL_statements = 52,                /* statements  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_expression_statement = 54,      /* expression_statement  */
  YYSYMBOL_variable = 55,                  /* variable  */
  YYSYMBOL_expression = 56,                /* expression  */
  YYSYMBOL_logic_expression = 57,          /* logic_expression  */
  YYSYMBOL_rel_expression = 58,            /* rel_expression  */
  YYSYMBOL_simple_expression = 59,         /* simple_expression  */
  YYSYMBOL_term = 60,                      /* term  */
  YYSYMBOL_unary_expression = 61,          /* unary_expression  */
  YYSYMBOL_factor = 62,                    /* factor  */
  YYSYMBOL_argument_list = 63,             /* argument_list  */
  YYSYMBOL_arguments = 64                  /* arguments  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   117,   117,   128,   135,   144,   151,   161,   160,   224,
     223,   259,   282,   296,   308,   322,   335,   350,   377,   384,
     391,   400,   408,   418,   430,   438,   446,   458,   465,   474,
     481,   489,   496,   503,   510,   517,   524,   531,   544,   561,
     568,   577,   599,   636,   644,   689,   697,   709,   717,   729,
     737,   753,   761,   809,   816,   823,   832,   840,   893,   901,
     909,   917,   925,   935,   943,   951,   958
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "DO", "BREAK", "INT", "CHAR", "FLOAT", "DOUBLE", "VOID",
  "RETURN", "SWITCH", "CASE", "DEFAULT", "CONTINUE", "PRINTLN", "ADDOP",
  "MULOP", "INCOP", "DECOP", "RELOP", "ASSIGNOP", "LOGICOP", "NOT",
  "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "CONST_INT", "CONST_FLOAT", "ID", "LOWER_THAN_ELSE",
  "$accept", "start", "program", "unit", "func_definition", "$@1", "$@2",
  "parameter_list", "compound_statement", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,   -71,   -71,   -71,    23,    41,   -71,   -71,   -71,     0,
     -71,   -71,     5,    27,     1,    44,    11,   -71,   -71,   -14,
      51,    55,    57,    45,    61,   -71,    41,   -71,   -71,   -71,
      46,    65,   -71,    61,    56,    66,    72,    69,    70,    80,
      20,    81,    20,    20,    20,   -71,   -71,   -71,   -71,    32,
     -71,   -71,   -71,   101,   -71,   -71,    50,    76,   -71,    87,
      39,    95,   -71,   -71,   -71,   -71,   -71,   -71,    20,    -9,
      20,    82,    84,    64,   -71,   -71,    89,    20,    20,   -71,
     -71,   -71,   -71,    20,   -71,    20,    20,    20,    20,    90,
      -9,    94,   -71,    96,   -71,   -71,    97,    93,    91,   -71,
     -71,    95,   110,   -71,   137,    20,   137,    98,   -71,    20,
     -71,   130,   106,   -71,   -71,   -71,   137,   137,   -71,   -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,    19,    20,     0,     2,     4,     6,     5,     0,
       1,     3,    24,     0,     0,     0,     0,    17,     9,     0,
      14,     0,     0,    21,     0,     7,     0,    13,    25,    26,
       0,     0,    10,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    39,    59,    60,    41,
      30,    32,    29,     0,    27,    31,    56,     0,    43,    45,
      47,    49,    51,    55,     8,    11,    22,    23,     0,     0,
       0,     0,     0,    56,    53,    54,     0,    64,     0,    15,
      28,    61,    62,     0,    40,     0,     0,     0,     0,     0,
       0,     0,    38,     0,    58,    66,     0,    63,     0,    44,
      46,    50,    48,    52,     0,     0,     0,     0,    57,     0,
      42,    34,     0,    36,    37,    65,     0,     0,    35,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   -71,   136,    17,   -71,   -71,   -71,    -8,    31,
      -5,   -71,   -71,   -51,   -66,   -42,   -36,   -70,    59,    58,
      63,   -37,   -71,   -71,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    50,    33,    24,    19,    51,    52,
       9,    13,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    96,    97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      73,    73,    80,    90,    71,    74,    75,    95,    76,    20,
       1,    42,     2,    99,     3,    25,    32,     7,    43,    44,
      26,    34,     7,    10,   105,    64,    46,    47,    48,    49,
      18,     8,    89,    14,    91,    73,     8,    15,    12,   115,
      42,    73,    98,    73,    73,    73,    73,    43,    44,    23,
       1,   103,     2,   111,     3,   113,    47,    48,    49,    86,
      77,    16,    17,    87,    78,   118,   119,    73,    37,   112,
      38,    39,    81,    82,     1,    83,     2,    30,     3,    40,
      21,    22,    35,    36,    41,    42,    81,    82,    28,    27,
      29,    31,    43,    44,    65,    31,    45,    68,    69,    66,
      46,    47,    48,    49,    37,    67,    38,    39,    70,    72,
       1,    84,     2,    85,     3,    40,    88,    92,    94,   104,
      41,    42,    93,   106,   110,   107,   108,   109,    43,    44,
      86,    31,    79,   114,   116,   117,    46,    47,    48,    49,
      37,    11,    38,    39,   100,   102,     1,     0,     2,   101,
       3,    40,     0,     0,     0,     0,    41,    42,     0,     0,
       0,     0,     0,     0,    43,    44,     0,    31,     0,     0,
       0,     0,    46,    47,    48,    49
};

static const yytype_int8 yycheck[] =
{
      42,    43,    53,    69,    40,    42,    43,    77,    44,    14,
       9,    20,    11,    83,    13,    29,    24,     0,    27,    28,
      34,    26,     5,     0,    90,    33,    35,    36,    37,    38,
      29,     0,    68,    28,    70,    77,     5,    32,    38,   109,
      20,    83,    78,    85,    86,    87,    88,    27,    28,    38,
       9,    88,    11,   104,    13,   106,    36,    37,    38,    20,
      28,    34,    35,    24,    32,   116,   117,   109,     3,   105,
       5,     6,    22,    23,     9,    25,    11,    32,    13,    14,
      36,    37,    36,    37,    19,    20,    22,    23,    33,    38,
      33,    30,    27,    28,    38,    30,    31,    28,    28,    33,
      35,    36,    37,    38,     3,    33,     5,     6,    28,    28,
       9,    35,    11,    26,    13,    14,    21,    35,    29,    29,
      19,    20,    38,    29,    33,    29,    29,    34,    27,    28,
      20,    30,    31,    35,     4,    29,    35,    36,    37,    38,
       3,     5,     5,     6,    85,    87,     9,    -1,    11,    86,
      13,    14,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    30,    -1,    -1,
      -1,    -1,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    11,    13,    41,    42,    43,    44,    49,    50,
       0,    43,    38,    51,    28,    32,    34,    35,    29,    47,
      50,    36,    37,    38,    46,    29,    34,    38,    33,    33,
      32,    30,    48,    45,    50,    36,    37,     3,     5,     6,
      14,    19,    20,    27,    28,    31,    35,    36,    37,    38,
      44,    48,    49,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    48,    38,    33,    33,    28,    28,
      28,    56,    28,    55,    61,    61,    56,    28,    32,    31,
      53,    22,    23,    25,    35,    26,    20,    24,    21,    56,
      54,    56,    35,    38,    29,    57,    63,    64,    56,    57,
      58,    60,    59,    61,    29,    54,    29,    29,    29,    34,
      33,    53,    56,    53,    35,    57,     4,    29,    53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    45,    44,    46,
      44,    47,    47,    47,    47,    48,    48,    49,    50,    50,
      50,    51,    51,    51,    51,    51,    51,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     7,     0,
       6,     4,     3,     2,     1,     3,     2,     3,     1,     1,
       1,     3,     6,     6,     1,     4,     4,     1,     2,     1,
       1,     1,     1,     7,     5,     7,     5,     5,     3,     1,
       2,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     0,     3,     1
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
  case 2: /* start: program  */
#line 118 "22201909.y"
        {
		outlog<<"At line no: "<<lines<<" start : program "<<endl<<endl;
		outlog<<"Symbol Table"<<endl<<endl;
		
		// Print your whole symbol table here
		st->print_all_scopes(outlog);
		outlog<<endl<<endl;
	}
#line 1445 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 129 "22201909.y"
        {
		outlog<<"At line no: "<<lines<<" program : program unit "<<endl<<endl;
		outlog<<yyvsp[-1]->get_name()+"\n"+yyvsp[0]->get_name()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[-1]->get_name()+"\n"+yyvsp[0]->get_name(),"program");
	}
#line 1456 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 136 "22201909.y"
        {
		outlog<<"At line no: "<<lines<<" program : unit "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[0]->get_name(),"program");
	}
#line 1467 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 145 "22201909.y"
         {
		outlog<<"At line no: "<<lines<<" unit : var_declaration "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[0]->get_name(),"unit");
	 }
#line 1478 "y.tab.c"
    break;

  case 6: /* unit: func_definition  */
#line 152 "22201909.y"
     {
		outlog<<"At line no: "<<lines<<" unit : func_definition "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[0]->get_name(),"unit");
	 }
#line 1489 "y.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 161 "22201909.y"
                {
			// Create the function definition in symbol table
			symbol_info* func = new symbol_info(yyvsp[-3]->get_name(), "ID", "Function");
			func->set_data_type(yyvsp[-4]->get_name());
			
			// Get the parameter information from parameter_list
			vector<string> param_types = yyvsp[-1]->get_param_types();
			vector<string> param_names = yyvsp[-1]->get_param_names();
			
			func->set_param_types(param_types);
			func->set_param_names(param_names);
			
			// Check if the function is already declared in the current scope
			// Use the getter method instead of direct access
			symbol_info* existing_func = st->get_current_scope()->lookup(yyvsp[-3]->get_name());
			if(existing_func != NULL && existing_func->get_symbol_type() == "Function") {
				semantic_error(lines, "Redefinition of function: " + yyvsp[-3]->get_name());
			} else {
				st->insert(func);
			}
			
			// Create a new scope for function body
			st->enter_scope();
			outlog << "Entered new scope with ID: " << st->get_current_scope_id() << endl;
			
			// Add parameters to the new scope
			for(size_t i = 0; i < param_types.size(); i++) {
				string param_name = param_names[i];
				if(param_name.empty()) continue; // Skip unnamed parameters
				
				// Check for duplicate parameter names within the parameter list only
				bool duplicate = false;
				for(size_t j = 0; j < i; j++) {
					if(param_names[j] == param_name) {
						semantic_error(lines, "Multiple declaration of variable " + param_name + " in parameter list");
						duplicate = true;
						break;
					}
				}
				
				if(!duplicate) {
					// Add the parameter to the symbol table
					symbol_info* param = new symbol_info(param_name, "ID", "Variable");
					param->set_data_type(param_types[i]);
					st->insert(param);
				}
			}

			// Store the current function's return type for later validation
			if(yyvsp[-4]->get_name() == "void") {
				current_func_return_type = "void";
			} else {
				current_func_return_type = yyvsp[-4]->get_name();
			}
		}
#line 1549 "y.tab.c"
    break;

  case 8: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 217 "22201909.y"
                {	
			outlog<<"At line no: "<<lines<<" func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement "<<endl<<endl;
			outlog<<yyvsp[-6]->get_name()<<" "<<yyvsp[-5]->get_name()<<"("+yyvsp[-3]->get_name()+")\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-6]->get_name()+" "+yyvsp[-5]->get_name()+"("+yyvsp[-3]->get_name()+")\n"+yyvsp[0]->get_name(),"func_def");
		}
#line 1560 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 224 "22201909.y"
                {
			// Create the function in symbol table
			symbol_info* func = new symbol_info(yyvsp[-2]->get_name(), "ID", "Function");
			func->set_data_type(yyvsp[-3]->get_name());
			func->set_param_types(vector<string>());
			func->set_param_names(vector<string>());
			
			// Check if the function is already declared in the current scope
			symbol_info* existing_func = st->lookup(yyvsp[-2]->get_name());
			if(existing_func != NULL && existing_func->get_symbol_type() == "Function") {
				semantic_error(lines, "Redefinition of function: " + yyvsp[-2]->get_name());
			} else {
				st->insert(func);
			}
			
			// Create a new scope for function body
			st->enter_scope();
			outlog << "Entered new scope with ID: " << st->get_current_scope_id() << endl;

			// Store the current function's return type for later validation
			if(yyvsp[-3]->get_name() == "void") {
				current_func_return_type = "void";
			} else {
				current_func_return_type = yyvsp[-3]->get_name();
			}
		}
#line 1591 "y.tab.c"
    break;

  case 10: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 251 "22201909.y"
                {
			outlog<<"At line no: "<<lines<<" func_definition : type_specifier ID LPAREN RPAREN compound_statement "<<endl<<endl;
			outlog<<yyvsp[-5]->get_name()<<" "<<yyvsp[-4]->get_name()<<"()\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-5]->get_name()+" "+yyvsp[-4]->get_name()+"()\n"+yyvsp[0]->get_name(),"func_def");
		}
#line 1602 "y.tab.c"
    break;

  case 11: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 260 "22201909.y"
                {
 		  	outlog<<"At line no: "<<lines<<" parameter_list : parameter_list COMMA type_specifier ID "<<endl<<endl;
 		  	outlog<<yyvsp[-3]->get_name()<<","<<yyvsp[-1]->get_name()<<" "<<yyvsp[0]->get_name()<<endl<<endl;
					
			yyval = new symbol_info(yyvsp[-3]->get_name()+","+yyvsp[-1]->get_name()+" "+yyvsp[0]->get_name(),"param_list");
			
			// Check for duplicate parameter names within THIS parameter list only (not across entire scope)
			bool duplicate = false;
			vector<string> param_names = yyvsp[-3]->get_param_names();
			for(const auto& param_name : param_names) {
				if(param_name == yyvsp[0]->get_name()) {
					semantic_error(lines, "Multiple declaration of variable " + yyvsp[0]->get_name() + " in parameter list");
					duplicate = true;
					break;
				}
			}
			
            // store the necessary information about the function parameters
			yyval->set_param_types(yyvsp[-3]->get_param_types());
			yyval->set_param_names(yyvsp[-3]->get_param_names());
			yyval->add_parameter(yyvsp[-1]->get_name(), yyvsp[0]->get_name());
		}
#line 1629 "y.tab.c"
    break;

  case 12: /* parameter_list: parameter_list COMMA type_specifier  */
#line 283 "22201909.y"
                {
			outlog<<"At line no: "<<lines<<" parameter_list : parameter_list COMMA type_specifier "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<","<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->get_name()+","+yyvsp[0]->get_name(),"param_list");
			
            // store the necessary information about the function parameters
            // They will be needed when you want to enter the function into the symbol table

			yyval->set_param_types(yyvsp[-2]->get_param_types());
			yyval->set_param_names(yyvsp[-2]->get_param_names());
			yyval->add_parameter(yyvsp[0]->get_name(), "");
		}
#line 1647 "y.tab.c"
    break;

  case 13: /* parameter_list: type_specifier ID  */
#line 297 "22201909.y"
                {
			outlog<<"At line no: "<<lines<<" parameter_list : type_specifier ID "<<endl<<endl;
			outlog<<yyvsp[-1]->get_name()<<" "<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-1]->get_name()+" "+yyvsp[0]->get_name(),"param_list");
			
            // store the necessary information about the function parameters
            // They will be needed when you want to enter the function into the symbol table

			yyval->add_parameter(yyvsp[-1]->get_name(), yyvsp[0]->get_name());
		}
#line 1663 "y.tab.c"
    break;

  case 14: /* parameter_list: type_specifier  */
#line 309 "22201909.y"
                {
			outlog<<"At line no: "<<lines<<" parameter_list : type_specifier "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"param_list");
			
            // store the necessary information about the function parameters
            // They will be needed when you want to enter the function into the symbol table
			
			yyval->add_parameter(yyvsp[0]->get_name(), "");
		}
#line 1679 "y.tab.c"
    break;

  case 15: /* compound_statement: LCURL statements RCURL  */
#line 323 "22201909.y"
                {
			outlog << "At line no: " << lines << " compound_statement : LCURL statements RCURL " << endl << endl;
			outlog << "{\n" << yyvsp[-1]->get_name() << "\n}" << endl << endl;

			yyval = new symbol_info("{\n" + yyvsp[-1]->get_name() + "\n}", "comp_stmnt");

			// Print the ID of the scope being removed
			outlog << "Exiting scope with ID: " << st->get_current_scope_id() << endl;
			outlog << "Current state of the symbol table before exiting scope:" << endl;
			st->print_all_scopes(outlog);
			st->exit_scope();
		}
#line 1696 "y.tab.c"
    break;

  case 16: /* compound_statement: LCURL RCURL  */
#line 336 "22201909.y"
                {
			outlog << "At line no: " << lines << " compound_statement : LCURL RCURL " << endl << endl;
			outlog << "{\n}" << endl << endl;

			yyval = new symbol_info("{\n}", "comp_stmnt");

			// Print the ID of the scope being removed
			outlog << "Exiting scope with ID: " << st->get_current_scope_id() << endl;
			outlog << "Current state of the symbol table before exiting scope:" << endl;
			st->print_all_scopes(outlog);
			st->exit_scope();
		}
#line 1713 "y.tab.c"
    break;

  case 17: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 351 "22201909.y"
{
    outlog << "At line no: " << lines << " var_declaration : type_specifier declaration_list SEMICOLON " << endl << endl;
    outlog << yyvsp[-2]->get_name() << " " << yyvsp[-1]->get_name() << ";" << endl << endl;

    yyval = new symbol_info(yyvsp[-2]->get_name() + " " + yyvsp[-1]->get_name() + ";", "var_dec");

    data_type = yyvsp[-2]->get_name();
    
    // Check if variable type is void
    if (data_type == "void") {
        semantic_error(lines, "variable type can not be void");
    }
    
    string decl_list = yyvsp[-1]->get_name();
    size_t start = 0, end;

    while ((end = decl_list.find(',', start)) != string::npos) {
        string var = decl_list.substr(start, end - start);
        process_variable(var, data_type);
        start = end + 1;
    }
    // Process the last variable (or the only one if no commas)
    process_variable(decl_list.substr(start), data_type);
}
#line 1742 "y.tab.c"
    break;

  case 18: /* type_specifier: INT  */
#line 378 "22201909.y"
                {
			outlog<<"At line no: "<<lines<<" type_specifier : INT "<<endl<<endl;
			outlog<<"int"<<endl<<endl;
			
			yyval = new symbol_info("int","type");
	    }
#line 1753 "y.tab.c"
    break;

  case 19: /* type_specifier: FLOAT  */
#line 385 "22201909.y"
                {
			outlog<<"At line no: "<<lines<<" type_specifier : FLOAT "<<endl<<endl;
			outlog<<"float"<<endl<<endl;
			
			yyval = new symbol_info("float","type");
	    }
#line 1764 "y.tab.c"
    break;

  case 20: /* type_specifier: VOID  */
#line 392 "22201909.y"
                {
			outlog<<"At line no: "<<lines<<" type_specifier : VOID "<<endl<<endl;
			outlog<<"void"<<endl<<endl;
			
			yyval = new symbol_info("void","type");
	    }
#line 1775 "y.tab.c"
    break;

  case 21: /* declaration_list: declaration_list COMMA ID  */
#line 401 "22201909.y"
                  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : declaration_list COMMA ID "<<endl<<endl;
 		  	outlog<<yyvsp[-2]->get_name()+","<<yyvsp[0]->get_name()<<endl<<endl;

            // you may need to store the variable names to insert them in symbol table here or later
			yyval = new symbol_info(yyvsp[-2]->get_name()+","+yyvsp[0]->get_name(),"declaration_list");
 		  }
#line 1787 "y.tab.c"
    break;

  case 22: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 409 "22201909.y"
                  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD "<<endl<<endl;
 		  	outlog<<yyvsp[-5]->get_name()+","<<yyvsp[-3]->get_name()<<"["<<yyvsp[-1]->get_name()<<"]"<<endl<<endl;
			
			current_type = "array";
			array_size = stoi(yyvsp[-1]->get_name()); // Convert string to int
            // Store array name and size
			yyval = new symbol_info(yyvsp[-5]->get_name()+","+yyvsp[-3]->get_name()+"["+ yyvsp[-1]->get_name()+"]","declaration_list");
 		  }
#line 1801 "y.tab.c"
    break;

  case 23: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_FLOAT RTHIRD  */
#line 419 "22201909.y"
                  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : declaration_list COMMA ID LTHIRD CONST_FLOAT RTHIRD "<<endl<<endl;
 		  	outlog<<yyvsp[-5]->get_name()+","<<yyvsp[-3]->get_name()<<"["<<yyvsp[-1]->get_name()<<"]"<<endl<<endl;
			
            // Report error for float array size
            semantic_error(lines, "Array size must be an integer, not float");
			
			current_type = "array";
			array_size = 0; // Invalid array size
			yyval = new symbol_info(yyvsp[-5]->get_name()+","+yyvsp[-3]->get_name()+"["+ yyvsp[-1]->get_name()+"]","declaration_list");
 		  }
#line 1817 "y.tab.c"
    break;

  case 24: /* declaration_list: ID  */
#line 431 "22201909.y"
                  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : ID "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;

            // you may need to store the variable names to insert them in symbol table here or later
			yyval = new symbol_info(yyvsp[0]->get_name(),"declaration_list");
 		  }
#line 1829 "y.tab.c"
    break;

  case 25: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 439 "22201909.y"
                  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : ID LTHIRD CONST_INT RTHIRD "<<endl<<endl;
			outlog<<yyvsp[-3]->get_name()<<"["<<yyvsp[-1]->get_name()<<"]"<<endl<<endl;

            // Store array name and size
			yyval = new symbol_info(yyvsp[-3]->get_name()+"["+ yyvsp[-1]->get_name()+"]","declaration_list");
 		  }
#line 1841 "y.tab.c"
    break;

  case 26: /* declaration_list: ID LTHIRD CONST_FLOAT RTHIRD  */
#line 447 "22201909.y"
                  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : ID LTHIRD CONST_FLOAT RTHIRD "<<endl<<endl;
			outlog<<yyvsp[-3]->get_name()<<"["<<yyvsp[-1]->get_name()<<"]"<<endl<<endl;

            semantic_error(lines, "Array size must be an integer, not float");
			
			yyval = new symbol_info(yyvsp[-3]->get_name()+"["+ yyvsp[-1]->get_name()+"]","declaration_list");
 		  }
#line 1854 "y.tab.c"
    break;

  case 27: /* statements: statement  */
#line 459 "22201909.y"
           {
	    	outlog<<"At line no: "<<lines<<" statements : statement "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"stmnts");
	   }
#line 1865 "y.tab.c"
    break;

  case 28: /* statements: statements statement  */
#line 466 "22201909.y"
           {
	    	outlog<<"At line no: "<<lines<<" statements : statements statement "<<endl<<endl;
			outlog<<yyvsp[-1]->get_name()<<"\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-1]->get_name()+"\n"+yyvsp[0]->get_name(),"stmnts");
	   }
#line 1876 "y.tab.c"
    break;

  case 29: /* statement: var_declaration  */
#line 475 "22201909.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : var_declaration "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"stmnt");
	  }
#line 1887 "y.tab.c"
    break;

  case 30: /* statement: func_definition  */
#line 482 "22201909.y"
          {
	  		outlog<<"At line no: "<<lines<<" statement : func_definition "<<endl<<endl;
            outlog<<yyvsp[0]->get_name()<<endl<<endl;

            yyval = new symbol_info(yyvsp[0]->get_name(),"stmnt");
	  		
	  }
#line 1899 "y.tab.c"
    break;

  case 31: /* statement: expression_statement  */
#line 490 "22201909.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : expression_statement "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"stmnt");
	  }
#line 1910 "y.tab.c"
    break;

  case 32: /* statement: compound_statement  */
#line 497 "22201909.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : compound_statement "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"stmnt");
	  }
#line 1921 "y.tab.c"
    break;

  case 33: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 504 "22201909.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement "<<endl<<endl;
			outlog<<"for("<<yyvsp[-4]->get_name()<<yyvsp[-3]->get_name()<<yyvsp[-2]->get_name()<<")\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info("for("+yyvsp[-4]->get_name()+yyvsp[-3]->get_name()+yyvsp[-2]->get_name()+")\n"+yyvsp[0]->get_name(),"stmnt");
	  }
#line 1932 "y.tab.c"
    break;

  case 34: /* statement: IF LPAREN expression RPAREN statement  */
#line 511 "22201909.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : IF LPAREN expression RPAREN statement "<<endl<<endl;
			outlog<<"if("<<yyvsp[-2]->get_name()<<")\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info("if("+yyvsp[-2]->get_name()+")\n"+yyvsp[0]->get_name(),"stmnt");
	  }
#line 1943 "y.tab.c"
    break;

  case 35: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 518 "22201909.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : IF LPAREN expression RPAREN statement ELSE statement "<<endl<<endl;
			outlog<<"if("<<yyvsp[-4]->get_name()<<")\n"<<yyvsp[-2]->get_name()<<"\nelse\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info("if("+yyvsp[-4]->get_name()+")\n"+yyvsp[-2]->get_name()+"\nelse\n"+yyvsp[0]->get_name(),"stmnt");
	  }
#line 1954 "y.tab.c"
    break;

  case 36: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 525 "22201909.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : WHILE LPAREN expression RPAREN statement "<<endl<<endl;
			outlog<<"while("<<yyvsp[-2]->get_name()<<")\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info("while("+yyvsp[-2]->get_name()+")\n"+yyvsp[0]->get_name(),"stmnt");
	  }
#line 1965 "y.tab.c"
    break;

  case 37: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 532 "22201909.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON "<<endl<<endl;
			outlog<<"printf("<<yyvsp[-2]->get_name()<<");"<<endl<<endl; 
			
			// Check if the variable exists
			symbol_info* var = st->lookup(yyvsp[-2]->get_name());
			if(var == NULL) {
				semantic_error(lines, "Undeclared variable " + yyvsp[-2]->get_name());
			}
			
			yyval = new symbol_info("printf("+yyvsp[-2]->get_name()+");","stmnt");
	  }
#line 1982 "y.tab.c"
    break;

  case 38: /* statement: RETURN expression SEMICOLON  */
#line 545 "22201909.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : RETURN expression SEMICOLON "<<endl<<endl;
			outlog<<"return "<<yyvsp[-1]->get_name()<<";"<<endl<<endl;
			
			yyval = new symbol_info("return "+yyvsp[-1]->get_name()+";","stmnt");
			
			// Check if return type is compatible with function return type
			if (current_func_return_type == "void" && yyvsp[-1]->get_name() != "") {
				semantic_error(lines, "Void function cannot return a value");
			}
			else if (current_func_return_type == "int" && yyvsp[-1]->get_data_type() == "float") {
				semantic_error(lines, "Error: Possible loss of precision when returning float from an int function");
			}
	  }
#line 2001 "y.tab.c"
    break;

  case 39: /* expression_statement: SEMICOLON  */
#line 562 "22201909.y"
                        {
				outlog<<"At line no: "<<lines<<" expression_statement : SEMICOLON "<<endl<<endl;
				outlog<<";"<<endl<<endl;
				
				yyval = new symbol_info(";","expr_stmt");
	        }
#line 2012 "y.tab.c"
    break;

  case 40: /* expression_statement: expression SEMICOLON  */
#line 569 "22201909.y"
                        {
				outlog<<"At line no: "<<lines<<" expression_statement : expression SEMICOLON "<<endl<<endl;
				outlog<<yyvsp[-1]->get_name()<<";"<<endl<<endl;
				
				yyval = new symbol_info(yyvsp[-1]->get_name()+";","expr_stmt");
	        }
#line 2023 "y.tab.c"
    break;

  case 41: /* variable: ID  */
#line 578 "22201909.y"
      {
	    outlog<<"At line no: "<<lines<<" variable : ID "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->get_name(),"varbl");
		
		// Check if the variable is declared - in ANY scope (includes global scope)
		symbol_info* var = st->lookup(yyvsp[0]->get_name());
		if(var == NULL) {
			semantic_error(lines, "Undeclared variable " + yyvsp[0]->get_name());
			yyval->set_data_type("error");
		} else {
			yyval->set_data_type(var->get_data_type());
			yyval->set_symbol_type(var->get_symbol_type());
			
			// Check if it's an array being used without index
			if(var->is_array()) {
				semantic_error(lines, "variable is of array type : " + yyvsp[0]->get_name());
			}
		}
	 }
#line 2049 "y.tab.c"
    break;

  case 42: /* variable: ID LTHIRD expression RTHIRD  */
#line 600 "22201909.y"
         {
	 	outlog<<"At line no: "<<lines<<" variable : ID LTHIRD expression RTHIRD "<<endl<<endl;
		outlog<<yyvsp[-3]->get_name()<<"["<<yyvsp[-1]->get_name()<<"]"<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[-3]->get_name()+"["+yyvsp[-1]->get_name()+"]","varbl");
		
		// Check if the array is declared
		symbol_info* var = st->lookup(yyvsp[-3]->get_name());
		if(var == NULL) {
			semantic_error(lines, "Undeclared variable " + yyvsp[-3]->get_name());
			yyval->set_data_type("error");
		} else {
			// Check if it's actually an array
			if(!var->is_array()) {
				semantic_error(lines, "variable is not of array type : " + yyvsp[-3]->get_name());
				yyval->set_data_type(var->get_data_type());
			} else {
				yyval->set_data_type(var->get_data_type());
				yyval->set_symbol_type("Array");
				
				// Check if index is integer
				if(yyvsp[-1]->get_data_type() != "int") {
					semantic_error(lines, "array index is not of integer type : " + yyvsp[-3]->get_name());
					yyval->set_data_type("error"); // Mark as error to prevent further operations
				}
				
				// Check if the index is a float literal by looking for a decimal point
				if(yyvsp[-1]->get_name().find('.') != string::npos) {
				    semantic_error(lines, "array index is not an integer : " + yyvsp[-3]->get_name());
				    yyval->set_data_type("error"); // Mark as error to prevent further operations
				}
			}
		}
	 }
#line 2088 "y.tab.c"
    break;

  case 43: /* expression: logic_expression  */
#line 637 "22201909.y"
           {
	    	outlog<<"At line no: "<<lines<<" expression : logic_expression "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"expr");
			yyval->set_data_type(yyvsp[0]->get_data_type());
	   }
#line 2100 "y.tab.c"
    break;

  case 44: /* expression: variable ASSIGNOP logic_expression  */
#line 645 "22201909.y"
           {
	    	outlog<<"At line no: "<<lines<<" expression : variable ASSIGNOP logic_expression "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<"="<<yyvsp[0]->get_name()<<endl<<endl;

			yyval = new symbol_info(yyvsp[-2]->get_name()+"="+yyvsp[0]->get_name(),"expr");
			
			// Check if types are compatible
			if(yyvsp[-2]->get_data_type() != "error" && yyvsp[0]->get_data_type() != "error") {
				string var_type = yyvsp[-2]->get_data_type();
				string expr_type = yyvsp[0]->get_data_type();
				string expr_val = yyvsp[0]->get_name();
				
				// Check if the expression is a void function call
				if(expr_type == "void") {
					semantic_error(lines, "Void function used in expression");
					yyval->set_data_type("error");
				}
				else if(var_type == "int" && (expr_type == "float" || expr_val.find('.') != string::npos)) {
					semantic_error(lines, "Warning: Assignment of float value into variable of integer type");
					if(lines_with_errors.find(lines) == lines_with_errors.end()) {
						lines_with_errors.insert(lines);
					}
					
					yyval->set_data_type(var_type);
				}
				// Handle empty (null) expression values
				else if(expr_type == "") {
					yyval->set_data_type(var_type);
				}
				
				// Regular type compatibility check for other cases
				else if(!type_compatible(var_type, expr_type)) {
					semantic_error(lines, "Type mismatch in assignment. " + var_type + " variable cannot be assigned " + expr_type + " value");
					yyval->set_data_type(var_type); 
				} 
				else {
					yyval->set_data_type(var_type);
				}
			} else {
				yyval->set_data_type("error");
			}
	   }
#line 2147 "y.tab.c"
    break;

  case 45: /* logic_expression: rel_expression  */
#line 690 "22201909.y"
             {
	    	outlog<<"At line no: "<<lines<<" logic_expression : rel_expression "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"lgc_expr");
			yyval->set_data_type(yyvsp[0]->get_data_type());
	     }
#line 2159 "y.tab.c"
    break;

  case 46: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 698 "22201909.y"
                 {
	    	outlog<<"At line no: "<<lines<<" logic_expression : rel_expression LOGICOP rel_expression "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<yyvsp[-1]->get_name()<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->get_name()+yyvsp[-1]->get_name()+yyvsp[0]->get_name(),"lgc_expr");
			
			// Result of logical operation should always be int
			yyval->set_data_type("int");
	     }
#line 2173 "y.tab.c"
    break;

  case 47: /* rel_expression: simple_expression  */
#line 710 "22201909.y"
                {
	    	outlog<<"At line no: "<<lines<<" rel_expression : simple_expression "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"rel_expr");
			yyval->set_data_type(yyvsp[0]->get_data_type());
	    }
#line 2185 "y.tab.c"
    break;

  case 48: /* rel_expression: simple_expression RELOP simple_expression  */
#line 718 "22201909.y"
                {
	    	outlog<<"At line no: "<<lines<<" rel_expression : simple_expression RELOP simple_expression "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<yyvsp[-1]->get_name()<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->get_name()+yyvsp[-1]->get_name()+yyvsp[0]->get_name(),"rel_expr");
			
			// Result of relational operation should always be int
			yyval->set_data_type("int");
	    }
#line 2199 "y.tab.c"
    break;

  case 49: /* simple_expression: term  */
#line 730 "22201909.y"
          {
	    	outlog<<"At line no: "<<lines<<" simple_expression : term "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"simp_expr");
			yyval->set_data_type(yyvsp[0]->get_data_type());
	      }
#line 2211 "y.tab.c"
    break;

  case 50: /* simple_expression: simple_expression ADDOP term  */
#line 738 "22201909.y"
                  {
	    	outlog<<"At line no: "<<lines<<" simple_expression : simple_expression ADDOP term "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<yyvsp[-1]->get_name()<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->get_name()+yyvsp[-1]->get_name()+yyvsp[0]->get_name(),"simp_expr");
			
			// Type check for ADDOP
			if(yyvsp[-2]->get_data_type() == "float" || yyvsp[0]->get_data_type() == "float") {
				yyval->set_data_type("float");
			} else {
				yyval->set_data_type("int");
			}
	      }
#line 2229 "y.tab.c"
    break;

  case 51: /* term: unary_expression  */
#line 754 "22201909.y"
     {
	    	outlog<<"At line no: "<<lines<<" term : unary_expression "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"term");
			yyval->set_data_type(yyvsp[0]->get_data_type());
	 }
#line 2241 "y.tab.c"
    break;

  case 52: /* term: term MULOP unary_expression  */
#line 762 "22201909.y"
     {
	    	outlog<<"At line no: "<<lines<<" term : term MULOP unary_expression "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<yyvsp[-1]->get_name()<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->get_name()+yyvsp[-1]->get_name()+yyvsp[0]->get_name(),"term");
			
			// Type checks for multiplication, division, and modulus
			string op = yyvsp[-1]->get_name();
			
			// Both operands should be integers for modulus
			if(op == "%") {
				if(yyvsp[-2]->get_data_type() != "int" || yyvsp[0]->get_data_type() != "int") {
					semantic_error(lines, "Modulus operator on non integer type");
					yyval->set_data_type("error");
				} else {
					yyval->set_data_type("int");
				}
				if(yyvsp[0]->get_name() == "0") {
					semantic_error(lines, "Modulus by 0 ");
					yyval->set_data_type("error");
				}
			} 
			// Check for division by zero (for constants)
			else if(op == "/" || op == "%") {
				if(yyvsp[0]->get_name() == "0") {
					semantic_error(lines, "Division by zero");
					yyval->set_data_type("error");
				} 
				else {
					if(op == "/" && (yyvsp[-2]->get_data_type() == "float" || yyvsp[0]->get_data_type() == "float")) {
						yyval->set_data_type("float");
					} else {
						yyval->set_data_type("int");
					}
				}
			}
			// For multiplication
			else {
				if(yyvsp[-2]->get_data_type() == "float" || yyvsp[0]->get_data_type() == "float") {
					yyval->set_data_type("float");
				} else {
					yyval->set_data_type("int");
				}
			}
	 }
#line 2291 "y.tab.c"
    break;

  case 53: /* unary_expression: ADDOP unary_expression  */
#line 810 "22201909.y"
                 {
	    	outlog<<"At line no: "<<lines<<" unary_expression : ADDOP unary_expression "<<endl<<endl;
			outlog<<yyvsp[-1]->get_name()<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-1]->get_name()+yyvsp[0]->get_name(),"un_expr");
	     }
#line 2302 "y.tab.c"
    break;

  case 54: /* unary_expression: NOT unary_expression  */
#line 817 "22201909.y"
                 {
	    	outlog<<"At line no: "<<lines<<" unary_expression : NOT unary_expression "<<endl<<endl;
			outlog<<"!"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info("!"+yyvsp[0]->get_name(),"un_expr");
	     }
#line 2313 "y.tab.c"
    break;

  case 55: /* unary_expression: factor  */
#line 824 "22201909.y"
                 {
	    	outlog<<"At line no: "<<lines<<" unary_expression : factor "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"un_expr");
	     }
#line 2324 "y.tab.c"
    break;

  case 56: /* factor: variable  */
#line 833 "22201909.y"
    {
	    outlog<<"At line no: "<<lines<<" factor : variable "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->get_name(),"fctr");
		yyval->set_data_type(yyvsp[0]->get_data_type());
	}
#line 2336 "y.tab.c"
    break;

  case 57: /* factor: ID LPAREN argument_list RPAREN  */
#line 841 "22201909.y"
        {
	    outlog<<"At line no: "<<lines<<" factor : ID LPAREN argument_list RPAREN "<<endl<<endl;
		outlog<<yyvsp[-3]->get_name()<<"("<<yyvsp[-1]->get_name()<<")"<<endl<<endl;

		yyval = new symbol_info(yyvsp[-3]->get_name()+"("+yyvsp[-1]->get_name()+")","fctr");
		
		// Check if the function exists
		symbol_info* func = st->lookup(yyvsp[-3]->get_name());
		if(func == NULL) {
			semantic_error(lines, "Undeclared function: " + yyvsp[-3]->get_name());
			yyval->set_data_type("error");
		} else {
			// Check if it's actually a function
			if(!func->is_function()) {
				semantic_error(lines, yyvsp[-3]->get_name() + " is not a function");
				yyval->set_data_type("error");
			} else {
				// Check if it's a void function used in an expression
				if(func->get_data_type() == "void") {
					semantic_error(lines, "operation on void type");
					yyval->set_data_type("error");
				} else {
					yyval->set_data_type(func->get_data_type());
				}
				
				// Parse arguments
				vector<string> arg_types;
				string args = yyvsp[-1]->get_name();
				if(!args.empty()) {
					size_t start = 0, end;
					while((end = args.find(',', start)) != string::npos) {
						arg_types.push_back("int"); // track actual types
						start = end + 1;
					}
					arg_types.push_back("int"); 
				}
				
				// Check number of arguments
				vector<string> param_types = func->get_param_types();
				if(arg_types.size() != param_types.size()) {
					semantic_error(lines, "Inconsistencies in number of arguments in function call: " + yyvsp[-3]->get_name());
				}
				
				// Check argument types (simplified)
				for(size_t i = 0; i < min(arg_types.size(), param_types.size()); i++) {
					if(param_types[i] == "int" && arg_types[i] != "int") {
						semantic_error(lines, "argument " + to_string(i+1) + " type mismatch in function call: " + yyvsp[-3]->get_name());
					}
				}
			}
		}
	}
#line 2393 "y.tab.c"
    break;

  case 58: /* factor: LPAREN expression RPAREN  */
#line 894 "22201909.y"
        {
	   	outlog<<"At line no: "<<lines<<" factor : LPAREN expression RPAREN "<<endl<<endl;
		outlog<<"("<<yyvsp[-1]->get_name()<<")"<<endl<<endl;
		
		yyval = new symbol_info("("+yyvsp[-1]->get_name()+")","fctr");
		yyval->set_data_type(yyvsp[-1]->get_data_type());
	}
#line 2405 "y.tab.c"
    break;

  case 59: /* factor: CONST_INT  */
#line 902 "22201909.y"
        {
	    outlog<<"At line no: "<<lines<<" factor : CONST_INT "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->get_name(),"fctr");
		yyval->set_data_type("int");
	}
#line 2417 "y.tab.c"
    break;

  case 60: /* factor: CONST_FLOAT  */
#line 910 "22201909.y"
        {
	    outlog<<"At line no: "<<lines<<" factor : CONST_FLOAT "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->get_name(),"fctr");
		yyval->set_data_type("float");
	}
#line 2429 "y.tab.c"
    break;

  case 61: /* factor: variable INCOP  */
#line 918 "22201909.y"
        {
	    outlog<<"At line no: "<<lines<<" factor : variable INCOP "<<endl<<endl;
		outlog<<yyvsp[-1]->get_name()<<"++"<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-1]->get_name()+"++","fctr");
			yyval->set_data_type(yyvsp[-1]->get_data_type());
	}
#line 2441 "y.tab.c"
    break;

  case 62: /* factor: variable DECOP  */
#line 926 "22201909.y"
        {
	    outlog<<"At line no: "<<lines<<" factor : variable DECOP "<<endl<<endl;
		outlog<<yyvsp[-1]->get_name()<<"--"<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-1]->get_name()+"--","fctr");
			yyval->set_data_type(yyvsp[-1]->get_data_type());
	}
#line 2453 "y.tab.c"
    break;

  case 63: /* argument_list: arguments  */
#line 936 "22201909.y"
                          {
					outlog<<"At line no: "<<lines<<" argument_list : arguments "<<endl<<endl;
					outlog<<yyvsp[0]->get_name()<<endl<<endl;
						
					yyval = new symbol_info(yyvsp[0]->get_name(),"arg_list");
			  }
#line 2464 "y.tab.c"
    break;

  case 64: /* argument_list: %empty  */
#line 943 "22201909.y"
                          {
					outlog<<"At line no: "<<lines<<" argument_list :  "<<endl<<endl;
					outlog<<""<<endl<<endl;
						
					yyval = new symbol_info("","arg_list");
			  }
#line 2475 "y.tab.c"
    break;

  case 65: /* arguments: arguments COMMA logic_expression  */
#line 952 "22201909.y"
                  {
				outlog<<"At line no: "<<lines<<" arguments : arguments COMMA logic_expression "<<endl<<endl;
				outlog<<yyvsp[-2]->get_name()<<","<<yyvsp[0]->get_name()<<endl<<endl;
						
				yyval = new symbol_info(yyvsp[-2]->get_name()+","+yyvsp[0]->get_name(),"arg");
		  }
#line 2486 "y.tab.c"
    break;

  case 66: /* arguments: logic_expression  */
#line 959 "22201909.y"
              {
				outlog<<"At line no: "<<lines<<" arguments : logic_expression "<<endl<<endl;
				outlog<<yyvsp[0]->get_name()<<endl<<endl;
						
				yyval = new symbol_info(yyvsp[0]->get_name(),"arg");
	      }
#line 2497 "y.tab.c"
    break;


#line 2501 "y.tab.c"

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

#line 968 "22201909.y"


int main(int argc, char *argv[])
{
	if(argc != 2) 
	{
		cout<<"Please provide input file name"<<endl;
		return 0;
	}
	yyin = fopen(argv[1], "r");
	
	// Extract student ID from filename and create output file names
	string inputfile = argv[1];
	
	outlog.open("log.txt", ios::trunc);
	errout.open("error.txt", ios::trunc);
	
	if(yyin == NULL)
	{
		cout<<"Couldn't open input file"<<endl;
		return 0;
	}
	// Enter the global or the first scope here
	st = new symbol_table(10);
	st->enter_scope();
	outlog << "Entered new scope with ID: " << st->get_current_scope_id() << endl;

	yyparse();
	
	// Reset error count based on unique lines with errors
	error_count = lines_with_errors.size();

	outlog<<endl<<"Total lines: "<<lines<<endl;
	outlog<<"Total error lines: "<<error_count<<endl;

	// Add error count to error file too
	errout<<endl<<"Total error lines: "<<error_count<<endl;
	
	outlog.close();
	errout.close();
	
	fclose(yyin);
	
	return 0;
}
