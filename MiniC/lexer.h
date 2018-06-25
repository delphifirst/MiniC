#ifndef _MINI_C_LEXER_
#define _MINI_C_LEXER_

#include "array.h"

#define TOK_ERROR 0
#define TOK_LEFTPA 1
#define TOK_RIGHTPA 2
#define TOK_PLUS 3
#define TOK_MINUS 4
#define TOK_MUL 5
#define TOK_DIV 6
#define TOK_NUM 7
#define TOK_END 8

struct token
{
	int type;
	long num;
};

struct array* lex(char source_code[]);

#endif