class Solution {
public:
    int countRotations(string s, int k) 
    {
        int n = s.length();
        int valid = 0;

        for(int i =0; i<n; ++i)
        {
            int score = 0;
            for(int j =0; j<n-1;++j)
            {
                if(s[(i+j)%n] == s[(i + j+1)%n])
                {
                    score++;
                }
            }
            if(score == k)
            {
                valid++;
            }
        }
        return valid;
    }
};