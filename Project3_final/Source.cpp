#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
#include"garage.h"
#include"vehicle.h"
#include"ticket.h"
#include"receipt.h"
#include"screen.h"
#include"fees.h"
#include"controls.h"

using namespace std;

int Total_income = 0;
struct Time {
	int hour;
	int minute;
};
int main() {
	garage g;
	vehicle* v = new vehicle[g.maxcapacity];
	screen s;
	ticket* t = new ticket[g.maxcapacity];
	receipt* r = new receipt[g.maxcapacity];
	fees f;
	string type;
	int depth, width, size;
	int vlength, vwidth;
	float rate;
	int selected_slot;
	int choice = 0;
	cout << "please enter the max capacity of the garage : " << endl;
	cin >> g.maxcapacity;
	char cont = 'y';
	int i = 0;
	while (cont != 'n') {
		cout << "please enter the type of the slots : ";
		cin.ignore();
		getline(cin, type);
		cout << "please enter the number of the slots with type " << type << " : ";
		cin >> size;
		cout << "please enter the depth of the slot  : ";
		cin >> depth;
		cout << "please enter the width of the slot : ";
		cin >> width;
		cout << "please enter the hourly rate of this type : ";
		cin >> rate;
		g.setslots(size, type, depth, width, rate);
		cout << "do you want to add more type of slots : ";
		cin >> cont;
	}
	do {
		s.display_menu();
		cin >> choice;
		if (choice == 1) {
			cout << "please enter the vehicle length : ";
			cin >> vlength;
			v[i].setlength(vlength);
			cout << "please enter the vehicle width : ";
			cin >> vwidth;
			v[i].setlength(vwidth);
			slotcheck sc;
			vehiclepark_in pin;
			slot_selection ss;
			if (sc.check_slots(g, g.maxcapacity)) {
				//selected_slot = ss.first_selection(vlength, vwidth, g);
				selected_slot = ss.best_selection(vlength, vwidth, g);
				pin.reserve_slot(g, selected_slot, t[i]);
				pin.save_time(t[i], r[i]);
				s.print_ticket(t[i]);
			}
			else {
				cout << "no";
				//throw exeption
			}
			i++;
		}
		else if (choice == 2) {
			int key;
			vehiclepark_out pout;
			paymentcheck pc;
			float money;
			cout << "please enter the ticket ID : ";
			cin >> key;
			pout.free_slot(g, key);
			float fees;
			fees = f.calc_fees( t[key],g.s[key].getrate(), r[key]);
			r[key].setfees(fees);
			s.print_receipt(r[i]);
			cout << "please enter " << r[i].getfees() << " : ";
			cin >> money;
			pc.check_payment(money, r[i].getfees());
		}
		else if (choice == 3)
		{
			s.Display_slots(g);
		}
	} while (choice != 4);
	delete[]t;
	delete[]r;
	delete[]v;
	return 0;
}