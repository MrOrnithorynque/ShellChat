#include <stdlib.h>

#include "MYCPP/array.hpp"

template <typename T>
void my_cpp::malloc_2d_array(const T &array_2d, unsigned int length, unsigned int width)
{
	array_2d = (T*)malloc(sizeof(T) * (width + 1));

	for (unsigned int i = 0; i < width; ++i)
	{
		malloc_array(&array_2d[i], length);
	}

	array_2d[width] = NULL;
}