#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "Enter the number of process: ";
  int n; cin >> n;
  vector<pair<int, pair<int, pair<int, int>>>> process;
  cout << "Enter arrival time , burst time and priority: " << endl;
  int timer = 10000000;
  for (int i = 0; i < n; ++i) {
    int x, y, z; cin >> x >> y >> z;
    process.push_back({z, {x, {i, y}}});
    timer = min(timer, x);
  }

  priority_queue<pair<int, pair<int, pair<int, int>>>> q;
  for (int i = 0; i < n; ++i) {
    if (timer == process[i].second.first) {
      q.push(process[i]);
      process[i].second.first = -1;
    }
  }

  vector<int> waitingTime(n, 0), turnAroundTime(n, 0);
  while (!q.empty()) {
    pair<int, pair<int, pair<int, int>>> temp = q.top();
    q.pop();
    int x = temp.second.first, id = temp.second.second.first, y = temp.second.second.second;
    if (timer > x) {
      waitingTime[id] += timer - x;
    } else timer = x;
    timer += y;
    turnAroundTime[id] = timer - x;
    for (int i = 0; i < n; ++i) {
      if (timer >= process[i].second.first and process[i].second.first != -1) {
        q.push(process[i]);
        process[i].second.first= -1;
      }
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
