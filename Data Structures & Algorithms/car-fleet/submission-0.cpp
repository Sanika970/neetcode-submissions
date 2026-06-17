class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, double>> cars;

        int n = position.size();

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(),
             [](auto &a, auto &b) {
                 return a.first > b.first;   // descending position
             });

        int fleets = 0;
        double maxTime = 0;

        for (auto &car : cars) {
            if (car.second > maxTime) {
                fleets++;
                maxTime = car.second;
            }
        }

        return fleets;
    }
};