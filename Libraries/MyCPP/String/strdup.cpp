#include <stdlib.h>

#include "MYCPP/string.hpp"

char *strdup(char *src)
{
	unsigned int src_len = my_cpp::strlen(src);
	char *dest = (char *)malloc(sizeof(char) * (src_len + 1));

	for (unsigned int i = 0; i < src_len; ++i)
	{
		dest[i] = src[i]; 
	}
	dest[src_len] = '\0';

	return dest;
}