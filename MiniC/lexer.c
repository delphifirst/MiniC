#include "lexer.h"

#include "stdio.h"

struct array* lex(char source_code[])
{
	struct array* token_list = array_create(sizeof(struct token));
	struct token new_token;

	for (long pos = 0; source_code[pos] != 0;)
	{
		char start_char = source_code[pos];
		if (start_char == '\t' || start_char == ' ' || start_char == '\n' || start_char == '\r')
		{
			++pos;
			continue;
		}
		
		if (start_char == '(')
		{
			new_token.type = TOK_LEFTPA;
			++pos;
		}
		else if (start_char == ')')
		{
			new_token.type = TOK_RIGHTPA;
			++pos;
		}
		else if (start_char == '+')
		{
			new_token.type = TOK_PLUS;
			++pos;
		}
		else if (start_char == '-')
		{
			new_token.type = TOK_MINUS;
			++pos;
		}
		else if (start_char == '*')
		{
			new_token.type = TOK_MUL;
			++pos;
		}
		else if (start_char == '/')
		{
			new_token.type = TOK_DIV;
			++pos;
		}
		else if (start_char >= '0' && start_char <= '9')
		{
			new_token.type = TOK_NUM;
			new_token.num = 0;
			for (; source_code[pos] >= '0' && source_code[pos] <= '9'; ++pos)
				new_token.num = new_token.num * 10 + source_code[pos] - '0';
		}
		else
		{
			printf("Wrong token: \"%c\" at %d!\n", start_char, pos);
			new_token.type = TOK_ERROR;
			++pos;
		}
		array_append(token_list, &new_token);
	}
	new_token.type = TOK_END;
	array_append(token_list, &new_token);
	return token_list;
}