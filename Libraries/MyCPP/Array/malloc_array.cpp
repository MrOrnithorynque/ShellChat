#include <stdlib.h>

#include "MYCPP/array.hpp"

template <typename T>
void my_cpp::malloc_array(const T &array, unsigned int length)
{
	array = (T*)malloc(sizeof(T) * length);
}