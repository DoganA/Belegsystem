#include <iostream>
#include <cstdio>
#include <regex>

using namespace std;

#include "xml.h"


string XML::node_name(string line) {
	regex start("^[\\s]*<[/]?([\\w]*)>$");
	smatch match;

	regex_search(line, match, start);

	return match[1];
}

bool XML::is_open_tag(string line) {
	regex start_tag("^[\\s]*<[\\w]*>$");
	return regex_match(line, start_tag);
}

bool XML::is_close_tag(string line) {
	regex start_tag("^[\\s]*</[\\w]*>$");
	return regex_match(line, start_tag);
}

string* XML::extract_elements(string line) {
	string *matches = new string[2]; 

	regex extract("^[\\s]*<([\\w]*)>([^<>]*)</[\\w]*>$");
	smatch match;

	regex_search(line, match, extract);

	matches[0] = match[1];
	matches[1] = match[2];

	return matches;
}

string XML::peek_line(istream& in) {
	string peek;
	streampos bak = in.tellg();
	
	getline(in, peek);

	in.seekg(bak);

	return peek;
}

bool XML::conv_bool(string boolean) {
	return (boolean == "true") ? true : false;
}

int XML::conv_int(string integer) {
	return atoi(integer.c_str());
}

bool XML::is_string_in(string needle, vector<string> hay) {
	for (int i = 0; i < hay.size(); i++)
		if (needle == hay[i])
			return true;

    return false;
}