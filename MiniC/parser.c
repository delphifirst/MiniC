#include "parser.h"

#include <stdio.h>

#include "lexer.h"
#include "array.h"

static struct token peek_token(struct array* token_list, long pos)
{
	struct token result;
	array_get(token_list, pos, &result);
	return result;
}

static int additive_expression(struct array* token_list, long* pos);

static int primary_expression(struct array* token_list, long* pos)
{
	struct token cur_token = peek_token(token_list, *pos);
	++*pos;
	if (cur_token.type == TOK_NUM)
	{
		return cur_token.num;
	}
	else if (cur_token.type == TOK_LEFTPA)
	{
		int result = additive_expression(token_list, pos);
		cur_token = peek_token(token_list, *pos);
		++*pos;
		if (cur_token.type != TOK_RIGHTPA)
		{
			printf("Expect \")\" but get \"%d\"!\n", cur_token.type);
		}
		return result;
	}
	else
	{
		printf("Expect number or \"(\" but get \"%d!\n", cur_token.type);
		return 0;
	}
}

static int multiplicative_expression(struct array* token_list, long* pos)
{
	int result = primary_expression(token_list, pos);
	struct token cur_token = peek_token(token_list, *pos);
	while (cur_token.type == TOK_MUL || cur_token.type == TOK_DIV)
	{
		++*pos;
		if (cur_token.type == TOK_MUL)
		{
			result *= primary_expression(token_list, pos);
		}
		else
		{
			result /= primary_expression(token_list, pos);
		}
		cur_token = peek_token(token_list, *pos);
	}
	return result;
}

static int additive_expression(struct array* token_list, long* pos)
{
	int result = multiplicative_expression(token_list, pos);
	struct token cur_token = peek_token(token_list, *pos);
	while (cur_token.type == TOK_PLUS || cur_token.type == TOK_MINUS)
	{
		++*pos;
		if (cur_token.type == TOK_PLUS)
		{
			result += multiplicative_expression(token_list, pos);
		}
		else
		{
			result -= multiplicative_expression(token_list, pos);
		}
		cur_token = peek_token(token_list, *pos);
	}
	return result;
}

int parse(char source_code[])
{
	struct array* token_list = lex(source_code);
	long pos = 0;
	int result = additive_expression(token_list, &pos);
	array_destroy(token_list);
	return result;
}