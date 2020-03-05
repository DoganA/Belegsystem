#ifndef ASSOCIATION_H
#define ASSOCIATION_H

class Association
{
	private:
		vector<string> links;
	public:
		void push_link(string link);
		string pop_link();
		bool has_link();
};

#endif // ASSOCIATION_H