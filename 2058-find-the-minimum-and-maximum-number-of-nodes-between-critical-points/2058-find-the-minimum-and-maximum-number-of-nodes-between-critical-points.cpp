class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int idx = 2;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next) {

            bool isCritical =
                (curr->val < prev->val && curr->val < curr->next->val) ||
                (curr->val > prev->val && curr->val > curr->next->val);

            if (isCritical) {

                if (first == -1) {
                    first = idx;
                } else {
                    minDist = min(minDist, idx - last);
                }

                last = idx;
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (first == last) {
            return {-1, -1};
        }

        int maxDist = last - first;

        return {minDist, maxDist};
    }
};