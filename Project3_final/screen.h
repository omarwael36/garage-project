#pragma once
using namespace std;
class screen {
public:
	void display_menu() {
		cout << "1-park in" << endl;
		cout << "2-park out" << endl;
		cout << "3-display slots" << endl;
		cout << "4-exit" << endl;
	}
	void print_ticket(ticket& t) {
		cout << "your slot ID is : " << t.getID() << endl;
		cout << "your entry time is :  " << t.getentry_hour() << " : " << t.getentry_minute() << endl;
	}
	void print_receipt(receipt& r) {
		cout << endl;
		cout << "***************************" << endl;
		cout << "thanks for using our garage" << endl;
		cout << "hope you enjoyed the service " << endl;
		cout << "your entry time is :  " << r.getentry_hour() << " : " << r.getentry_minute() << endl;
		cout << "your exit time is :  " << r.getexit_hour() << " : " << r.getexit_minute() << endl;
		cout << "your total fees = " << r.getfees() << "EGP " << endl;
		cout << "***************************" << endl;
	}

	void Display_slots(garage& g) {
		for (int i = 0; i < g.maxcapacity; i++) {
			cout << g.s[i].getstate() << " ";
		}
		cout << endl;
	}
};
