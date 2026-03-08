class Solution
{
public:
    int carFleet(int target, vector<int> &pos, vector<int> &s)
    {
        int n = pos.size();
        vector<vector<double>> cars(n, vector<double>(2));
        for (int i = 0; i < n; i++)
        {
            cars[i][0] = pos[i];
            cars[i][1] = s[i];
        }

        sort(cars.begin(), cars.end(), [](auto &a, auto &b)
             { return a[0] > b[0]; });

        stack<double> st;

        for (int i = 0; i < n; i++)
        {
            double time = (target - cars[i][0]) / cars[i][1];
            if (st.empty() || time > st.top())
            {
                st.push(time);
            }
        }

        return st.size();
    }
};

// optimal

class Solution
{
public:
    int carFleet(int target, vector<int> &pos, vector<int> &speed)
    {

        int n = pos.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++)
        {
            double time = (double)(target - pos[i]) / speed[i];
            cars.push_back({pos[i], time});
        }

        sort(cars.begin(), cars.end(), greater<pair<int, double>>());

        int fleets = 0;
        double lastTime = 0;

        for (auto &car : cars)
        {
            if (car.second > lastTime)
            {
                fleets++;
                lastTime = car.second;
            }
        }

        return fleets;
    }
};