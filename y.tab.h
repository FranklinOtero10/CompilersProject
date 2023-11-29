/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
	

#line 117 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */