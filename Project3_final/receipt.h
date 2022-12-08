#pragma once
using namespace std;
class receipt {
private:
	Time exit_time;
	Time entry_time;
	float fees;
public:
	receipt() {}
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
	void setexit_hour(int h) {
		exit_time.hour = h;
	}
	void setexit_minute(int m) {
		exit_time.minute = m;
	}
	int getexit_hour() {
		return exit_time.hour;
	}
	int getexit_minute() {
		return exit_time.minute;
	}
	void setfees(float f) {
		fees = f;
	}
	float getfees() {
		return fees;
	}



};
