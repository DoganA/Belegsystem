#ifndef XML_H
#define XML_H

#include <fstream>
#include <string>
#include <vector>

class XML
{
	public:
		static string node_name(string line);
		static bool is_open_tag(string line);
		static bool is_close_tag(string line);
		static string peek_line(istream& in);
		static string* extract_elements(string line);

		static bool is_string_in(string needle, vector<string> hay);
		
		/* converter methods */
		static bool conv_bool(string boolean);
		static int conv_int(string integer);
};

#endif // XML_H