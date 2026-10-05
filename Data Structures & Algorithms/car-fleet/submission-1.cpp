class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> p1;
        for (int i = 0; i < position.size(); i++) {
            p1.push_back({position[i], speed[i]});
        }

        sort(p1.rbegin(), p1.rend());   // closest to target first
        // reverse order sort descending order
        // first elements of the pair

        stack<double> s1;

        for (auto &p : p1) {
            double time = (double)(target - p.first) / p.second;
            if (s1.empty() || time > s1.top()) {
                s1.push(time);           // new fleet
            }
            // else: merges into the fleet ahead, do nothing
        }

        return s1.size();
    }
};
