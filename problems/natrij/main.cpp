#include <cstdio>

// 12:34:56 = 45296 seconds
// 14:36:22 = 52582 seconds
// 02:01:26 = 7286 seconds

struct Time
{
	int hour;
	int min;
	int sec;
	Time() : hour(0), min(0), sec(0) { }
	Time(int seconds) : hour(seconds/(60*60)), min((seconds/60)%60), sec(seconds%60) { }
	inline int toSeconds() const { return (hour*60*60) + (min*60) + sec; }
};

int main()
{
	static const int ONE_DAY = 24*60*60;
	Time now, goal;
	scanf("%d:%d:%d", &now.hour, &now.min, &now.sec);
	scanf("%d:%d:%d", &goal.hour, &goal.min, &goal.sec);

	int dt = goal.toSeconds() - now.toSeconds();
	if (dt < 0) dt += ONE_DAY;
	if (dt == 0) dt = ONE_DAY;
	Time diff(dt);

	printf("%02d:%02d:%02d\n", diff.hour, diff.min, diff.sec);
	return 0;
}