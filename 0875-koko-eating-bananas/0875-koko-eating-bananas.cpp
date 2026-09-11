class Solution {
public:

    // int f(int n, vector<int>& a) {
    //     int t = 0;

    //     for (int i = 0; i < a.size(); i++) {
    //         t += (a[i] + n - 1) / n;
    //     }

    //     return t;
    // }
    long long f(int n, vector<int>& a) {
    long long t = 0;

    for (int x : a) {
        t += x / n;
        if (x % n != 0)
            t++;
    }

    return t;
}

    int minEatingSpeed(vector<int>& a, int h) {
        int l = 1;
        int r = *max_element(a.begin(), a.end());

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (f(mid, a) <= h)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};