#include "MYCPP/string.hpp"

class string
{
	private:
		char *str;
		unsigned int len;

	public:
		inline unsigned int strlen() {return (len = my_cpp::strlen(str)); }
		inline char *strdup() {return my_cpp::strdup(str); }
		inline char **str_to_2d_array(char *parser, FLAG option = 0) {return my_cpp::str_to_2d_array(str, parser, option); }

		string () {}
		~string () {}
};