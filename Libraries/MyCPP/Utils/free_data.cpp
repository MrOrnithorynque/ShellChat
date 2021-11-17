/*
** MYCPP library - free_data from utils
*/

#include <stdlib.h>

#include "MYCPP/utils.hpp"

template <typename T>
void free_data(const T &data)
{
	free(data);
}