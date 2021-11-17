#pragma once

#include <unistd.h>

namespace my_cpp
{
	template <typename T> unsigned int 	array_2d_len(T **array);
	template <typename T> void 			malloc_array(const T &array, unsigned int length);
	template <typename T> void 			malloc_2d_array(const T &array_2d, unsigned int length, unsigned int width);
	template <typename T> void 			malloc_3d_array(const T &array_3d, unsigned int length, unsigned int widht, unsigned int depth);
	template <typename T> T 			*offset_array(T *array, size_t offset, size_t length);
}