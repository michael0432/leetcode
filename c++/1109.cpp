class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        sort(bookings.begin(), bookings.end(), [](const vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        vector<int> output;
        vector<int> front_sum(n+1, 0);
        vector<int> to(n+1, 0);
        int sum = 0;
        for (int i = 0; i < bookings.size(); i++){
            sum += bookings[i][2];
            front_sum[bookings[i][0]] = sum;
            to_sum[bookings[i][1]] = bookings[i][2];
        }
        for (int i = 0; i < n + 1; i++){
            output.push_back(front_sum[i] - )
        }
    }
};