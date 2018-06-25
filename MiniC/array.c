#include "array.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct array* array_create(int elem_size)
{
	struct array* result = malloc(sizeof(struct array));
	result->_count = 0;
	result->_elem_size = elem_size;
	result->_data = malloc(ARRAY_INIT_COUNT * elem_size);
	result->_capacity = ARRAY_INIT_COUNT;
	return result;
}

void array_destroy(struct array* a_array)
{
	free(a_array->_data);
	free(a_array);
}

void array_append(struct array* a_array, char* data)
{

	if (a_array->_count == a_array->_capacity)
	{
		a_array->_capacity *= 2;
		a_array->_data = realloc(a_array->_data, a_array->_capacity * a_array->_elem_size);
	}
	memcpy(a_array->_data + a_array->_count * a_array->_elem_size, data, a_array->_elem_size);
	a_array->_count += 1;
}

void array_get(struct array* a_array, long index, char* data)
{
	assert(index < a_array->_count);
	memcpy(data, a_array->_data + index * a_array->_elem_size, a_array->_elem_size);
}

long array_count(struct array* a_array)
{
	return a_array->_count;
}

int array_elem_size(struct array* a_array)
{
	return a_array->_elem_size;
}