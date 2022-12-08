#pragma once
using namespace std;
class slots {
private:
	int depth;
	int width;
	static int ID;
	string state;
	string type;
	float hourly_rate;
public:
	slots() {
		depth = 200;
		width = 150;
		ID++;
	}

	void setstate(string s) {
		state = s;
	}
	string getstate() {
		return state;
	}
	void setdepth(int d) {
		depth = d;
	}
	int getdepth() {
		return depth;
	}
	void setwidth(int w) {
		width = w;
	}
	int getwidth() {
		return width;
	}
	void setrate(float hr) {
		hourly_rate = hr;
	}
	float getrate() {
		return hourly_rate;
	}
	void settype(string t) {
		type = t;
	}
	string gettype() {
		return type;
	}
	int getID() {
		return ID;
	}
};
int slots::ID = 0;
class garage {
public:
	slots* s;
	int maxcapacity;
	garage() {
		maxcapacity = 1000;
		s = new slots[maxcapacity];
		for (int i = 0; i < maxcapacity; i++) {
			s[i].setstate(" o ");
		}
	}
	garage(int size) {
		maxcapacity = size;
		s = new slots[maxcapacity];
	}
	int current = 0;
	void setslots(int x, string t, int d, int w, float hr) {
		for (int i = 0; i < x; i++, current++) {
			if (s[current].getstate() == " o ") {
				s[current].setdepth(d);
				s[current].setwidth(w);
				s[current].settype(t);
				s[current].setstate(t);
				s[current].setrate(hr);
			}
		}
	}
	~garage() {
	}
};
