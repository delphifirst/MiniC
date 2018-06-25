#ifndef _MINI_C_ARRAY_
#define _MINI_C_ARRAY_

struct array
{
	int _elem_size;
	long _count;
	long _capacity;
	char* _data;
};

#define ARRAY_INIT_COUNT 10

struct array* array_create(int elem_size);
void array_destroy(struct array* a_array);
void array_append(struct array* a_array, char* data);
void array_get(struct array* a_array, long index, char* data);
long array_count(struct array* a_array);
int array_elem_size(struct array* a_array);
#endif