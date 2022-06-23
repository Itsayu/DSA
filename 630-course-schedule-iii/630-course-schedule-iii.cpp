class Solution {
public:
   int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& lhs, auto& rhs) { return lhs[1] < rhs[1]; }); 
        
        int prefix = 0; 
        priority_queue<int> pq; 
        for (auto& course : courses) {
            prefix += course[0]; 
            pq.push(course[0]); 
            if (prefix > course[1]) {
                prefix -= pq.top(); 
                pq.pop(); 
            }
        }
        return pq.size();
    }
};