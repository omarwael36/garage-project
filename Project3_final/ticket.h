#pragma once
using namespace std;


class ticket {
private:
	int ID;
	Time entry_time;
public:
	ticket() {
	}
	void setID(int id) {
		ID = id;
	}
	void setentry_hour(int h) {
		entry_time.hour = h;
	}
	void setentry_minute(int m) {
		entry_time.minute = m;
	}
	int getentry_hour() {
		return entry_time.hour;
	}
	int getentry_minute() {
		return entry_time.minute;
	}
	int getID() {
		return ID;
	}
};
