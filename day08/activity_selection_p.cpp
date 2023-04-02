#include<bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool activityCompare(Activity a, Activity b) {
    return (a.finish < b.finish);
}
void selectActivities(vector<Activity> activities) {
    sort(activities.begin(), activities.end(), activityCompare);
    int i = 0;
    cout << "(" << activities[i].start << ", " << activities[i].finish << "), ";
    for (int j = 1; j < activities.size(); j++) {
        if (activities[j].start >= activities[i].finish) {
            cout << "(" << activities[j].start << ", " << activities[j].finish << ") ";
            i = j;
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;
    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter start time and finish time for activity " << i+1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }
    cout << "Selected activities: ";
    selectActivities(activities);
    return 0;
}