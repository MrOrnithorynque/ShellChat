/*
**
*/

#include "MYCPP/array.hpp"

template <typename T>
unsigned int my_cpp::array_2d_len(T **array)
{
	T **array_ptr;

	for (array_ptr = array; *array_ptr ; ++array_ptr);

	return *array_ptr == NULL ? (unsigned int)(array_ptr - array - 1) : 0; // (array_ptr - array) maybe wrong cause counting NULL so (array_ptr - array - 1) better 
}