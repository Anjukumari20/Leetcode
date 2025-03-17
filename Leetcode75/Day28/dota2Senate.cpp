class Solution {
    public:
        string predictPartyVictory(string senate) {
            queue<int> radiant, dire;
            int n = senate.size();
            
            // Populate the queues with the index of each senator
            for (int i = 0; i < n; i++) {
                if (senate[i] == 'R') {
                    radiant.push(i);
                } else {
                    dire.push(i);
                }
            }
            
            // Process bans in rounds
            while (!radiant.empty() && !dire.empty()) {
                int rIndex = radiant.front(); radiant.pop();
                int dIndex = dire.front(); dire.pop();
                
                // The senator with the smaller index bans the other
                if (rIndex < dIndex) {
                    radiant.push(rIndex + n); // Push to next round
                } else {
                    dire.push(dIndex + n);
                }
            }
            
            return radiant.empty() ? "Dire" : "Radiant";
        }
    };