#pragma once
using namespace std;
class fees {
public:
	fees() {}
	float calc_fees(ticket& t, float rate, receipt& r) {
		float fees;
		int staytime_hours = 0;
		int staytime_minutes = 0;
		int exittime_hours = 0, exittime_minutes = 0;
		time_t now;
		struct tm nowlocal;
		now = time(NULL);
		nowlocal = *localtime(&now);
		exittime_hours = nowlocal.tm_hour;
		exittime_minutes = nowlocal.tm_min;
		r.setexit_hour(exittime_hours);
		r.setexit_minute(exittime_minutes);
		staytime_hours = r.getexit_hour() - t.getentry_hour();
		staytime_minutes = r.getexit_minute() - t.getentry_minute();
		fees = ((staytime_minutes / 60) + staytime_hours) * rate;
		return fees;
	}
};
