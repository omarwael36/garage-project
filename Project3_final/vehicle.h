#pragma once
using namespace std;
class vehicle {
private:
	string model_name;
	int model_year;
	int ID;
	int length;
	int width;
public:
	vehicle() {
		model_name = " ";
		model_year = 0;
		length = 0;
		width = 0;
	}
	void setmodel_name(string mn) {
		model_name = mn;
	}
	void setmodel_year(int my) {
		model_year = my;
	}
	void setlength(int l) {
		length = l;
	}
	void setwidth(int w) {
		width = w;
	}
	string getmodel_name() {
		return model_name;
	}
	int getmodel_year() {
		return model_year;
	}
	int getlength() {
		return length;
	}
	int getwidth() {
		return width;
	}

};
