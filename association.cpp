#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#include "association.h"

string Association::pop_link() {
	if (has_link()) {
		string link = links.back();
		links.pop_back();

		return link;
	}

	return "";
}

bool Association::has_link() {
	return (links.size() > 0) ? true : false;
}

void Association::push_link(string link) {
	links.push_back(link);
}