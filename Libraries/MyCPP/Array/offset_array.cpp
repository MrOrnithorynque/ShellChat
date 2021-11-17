/*
**
*/

#include <stdlib.h>

#include "MYCPP/array.hpp"

template <typename T>
T *my_cpp::offset_array(T *array, size_t offset, size_t length)
{
    T *array_tmp = (T *)malloc(sizeof(T) * (length - 1));
    size_t j = 0;

    for (size_t i = 0; i <= length; ++i) {
        if (i == offset)
            ++i;
        array_tmp[j] = array[i];
        ++j;
    }
	// TODO: free array? cause think

    return array_tmp;
}