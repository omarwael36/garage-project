#pragma once
using namespace std;
class paymentcheck {
public:
	paymentcheck() {}
	bool check_payment(float payed, float fees) {
		if (payed < fees) {
			cout << "please enter the rest of the required fees !" << endl;
			return false;
		}
		else {
			if (payed > fees) {
				cout << "please take the change :  " << payed - fees << " EGP " << endl;
				return true;
			}
			if (payed == fees) {
				return true;
			}
		}
	}
};
class slotcheck {
public:
	slotcheck() {}
	bool check_slots(garage g, int s) {
		bool flag = true;
		for (int i = 0; i < s; i++) {
			if (g.s[i].getstate() != " RESERVED ") {
				flag = true;
			}
			else {
				flag = false;
			}
		}
		return flag;
	}
};
class vehiclepark_in {
public:
	vehiclepark_in() {}
	void reserve_slot(garage& g, int key, ticket& t) {
		g.s[key].setstate(" RESERVED ");
		t.setID(key);
	}
	void save_time(ticket& t, receipt& r) {
		time_t now;
		struct tm nowlocal;
		now = time(NULL);
		nowlocal = *localtime(&now);
		t.setentry_hour(nowlocal.tm_hour);
		t.setentry_minute(nowlocal.tm_min);
		r.setentry_hour(nowlocal.tm_hour);
		r.setentry_minute(nowlocal.tm_min);
	}
};

class vehiclepark_out {
public:
	vehiclepark_out() {}
	void free_slot(garage& g, int key) {
		g.s[key].setstate(g.s[key].gettype());
	}
};
class slot_selection {
public:
	slot_selection() {}
	int first_selection(int l, int w, garage g) {
		for (int i = 0; i < g.maxcapacity; i++) {
			if (g.s[i].getdepth() > l && g.s[i].getwidth() > w && g.s[i].getstate() != " RESERVED ") {
				return i;
			}
		}
	}
	int best_selection(int l, int w, garage g) {
		int min = 0;
		for (int i = 0; i < g.maxcapacity; i++) {
			if (g.s[i].getdepth() > l && g.s[i].getwidth() > w && g.s[i].getstate() != " RESERVED ") {
				if (g.s[min].getdepth() > g.s[i].getdepth() && g.s[min].getwidth() > g.s[i].getwidth()) {
					min = i;
				}
			}
		}
		return min;
	}
};

