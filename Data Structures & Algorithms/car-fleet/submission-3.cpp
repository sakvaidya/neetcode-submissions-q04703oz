class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //calc time to reach for all vehicles
        //then keep count of all lesstime vehicles behind more time vehicle and bundle as one
        vector<float> ttr;
        for (int i = 0; i < position.size(); i++) {
            int max = INT_MIN;
            int maxindex = 0;
            for (int j = i; j < position.size(); j++) {
                if (max < position[j]) {
                    max = position[j];
                    maxindex = j;
                }
            }
            position[maxindex] = position[i];
            position[i] = max;
            int mspeed = speed[maxindex];
            speed[maxindex] = speed[i];
            speed[i] = mspeed;
        }
        for (int i = 0; i < position.size(); i++) {
            cout << position[i] << speed[i] << endl;
        }
        for (int i = 0; i < position.size(); i++) {
            ttr.push_back(((float)target-position[i])/speed[i]);
        }
        int count = 0;
        float curmax = 0;

        for (int i = 0; i < ttr.size(); i++) {
            if (ttr[i] > curmax) {
                curmax = ttr[i];
                count++;
            }
        }
        return count;
    }
};
