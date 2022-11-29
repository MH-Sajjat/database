#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "Enter the number of process: ";
  int n; cin >> n;
  vector<int> arrivalTime;
  vector<pair<int, pair<int, int>>> process;
  cout << "Enter arrival time and burst time" << endl;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    process.push_back({x, {y, i}});
    arrivalTime.push_back(x);
  }
  cout << "Enter quantum time: ";
  int quantum; cin >> quantum;
  sort(process.begin(), process.end());

  queue<pair<int, pair<int, int>>> q;
  vector<int> waitingTime(n, 0), turnAroundTime(n, 0);
  for (auto x : process) q.push(x);
  int timer = 0;
  while (!q.empty()) {
    pair<int, pair<int, int>> temp = q.front();
    int x = temp.first, y = temp.second.first, id = temp.second.second;
    q.pop();
    if (timer > x) {
      waitingTime[id] += timer - x;
    } else timer = x;
    if (y <= quantum) {
      timer += y;
      turnAroundTime[id] = timer - arrivalTime[id];
    } else {
      y -= quantum;
      timer += quantum;
      x = timer;
      q.push({x, {y, id}});
    }
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
  cout << endl;
  cout << "Average waiting time =  " << averageWaitingTime << endl;
  cout << "Average turn around time " << averageTurnAroundTime << endl;
  return 0;
}
