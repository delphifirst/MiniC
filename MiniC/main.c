#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage:\nMiniC xxx\n");
		return 0;
	}

	char* filename = argv[1];
	FILE* f = fopen(filename, "rb");
	fseek(f, 0, SEEK_END);
	long filesize = ftell(f);
	fseek(f, 0, SEEK_SET);
	char* filedata = malloc(filesize + 1);
	fread(filedata, 1, filesize, f);
	fclose(f);
	filedata[filesize] = 0;
	printf("%d\n", parse(filedata));
	free(filedata);
}