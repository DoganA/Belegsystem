#ifndef TROOM_H
#define TROOM_H

class TRoom
{
	private:
		string name;
		string building;
		short seats;

	public:
		TRoom(string name, string building, short seats);
		TRoom() {}

		void setName(string name);
		void setBuilding(string building);
		void setSeats(short seats);

		string getName();
		string getBuilding();
		short getSeats();

		void print();

		friend istream& operator>>(istream& in, TRoom &obj);
};

#endif // TROOM_H