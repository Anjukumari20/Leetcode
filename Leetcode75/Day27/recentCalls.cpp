
class RecentCounter {
    private:
        std::queue<int> requests; // Queue to store timestamps
    
    public:
        RecentCounter() {
            // Constructor initializes an empty queue
        }
        
        int ping(int t) {
            requests.push(t); // Add new request to the queue
            
            // Remove requests that are older than t - 3000 milliseconds
            while (!requests.empty() && requests.front() < t - 3000) {
                requests.pop();
            }
            
            return requests.size(); // Return the number of recent requests
        }
    };