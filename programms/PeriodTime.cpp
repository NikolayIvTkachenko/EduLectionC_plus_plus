#include <iostream>

using namespace std;

struct TIME
{
    int seconds;
    int minutes;
    int hours;
};

void computeTimeDifference(struct TIME, struct TIME, struct TIME *);

void func001()
{
    struct TIME t1, t2, difference;

    cout << "Start time. " << endl;
    cout << "Input hours, minutes, seconds: ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    cout << "End time. " << endl;
    cout << "Input hours, minutes, seconds: ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    computeTimeDifference(t2, t1, &difference);

    cout << endl << "Difference: " << t1.hours << " : " << t1.minutes << " : " << t1.seconds;
    cout << " -> " << t2.hours << " : " << t2.minutes << " : " << t2.seconds;

    cout << " = " << difference.hours << " : " << difference.minutes << " : " << difference.seconds;

    cout << endl;
}


int main()
{
    func001();

    return 0;
}

void computeTimeDifference(struct TIME t1, struct TIME t2, struct TIME *difference)
{
    if(t2.seconds > t1.seconds)
    {
        --t1.minutes;
        t1.seconds += 60;
    }

    difference->seconds = t1.seconds - t2.seconds;
    if(t2.minutes > t1.minutes)
    {
        --t1.hours;
        t1.minutes += 60;
    }

    difference->minutes = t1.minutes-t2.minutes;
    difference->hours = t1.hours-t2.hours;

}

