#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "Enter the number of process: ";
  int n; cin >> n;
  vector<pair<int, pair<int, int>>> process;
  cout << "Enter arrival time and burst time:" << endl;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    process.push_back({y, {x, i}});
  }

  vector<int> waitingTime(n, 0), turnAroundTime(n, 0);
  int timer = 0;
  for (int i = 0; i < n; ++i) {
    int x = process[i].first, y = process[i].second.first, id = process[i].second.second;
    if (timer > y) {
      waitingTime[id] = timer - y;
    } else timer = y;
    timer += x;
    turnAroundTime[id] = timer - y;
  }

  double averageWaitingTime = 0, averageTurnAroundTime = 0;
  for (int i = 0; i < n; ++i) {
    averageWaitingTime += waitingTime[i];
    averageTurnAroundTime += turnAroundTime[i];
  }
  averageWaitingTime /= n;
  averageTurnAroundTime /= n;
  for (int i = 0; i < n; ++i) {
    cout << "Process " << i << " waiting time = " << waitingTime[i] << endl;
    cout << "Process " << i << " turn around time = " << turnAroundTime[i] << endl;
  }
  cout << nl;
  cout << "Average waiting time =  " << averageWaitingTime << endl;
  cout << "Average turn around time " << averageTurnAroundTime << endl;
  return 0;
}
