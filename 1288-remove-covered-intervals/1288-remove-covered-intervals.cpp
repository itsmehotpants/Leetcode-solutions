class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& slots) {
        sort(slots.begin(), slots.end(), [](auto &a, auto &b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
});

        stack<vector<int>> st;
        st.push(slots[0]);

        for (auto &v : slots) {
    if (v[1] > st.top()[1]) {
        st.push(v);
    }
}
        return st.size();
    }
};