class Solution 
{
public:
    int maxScore(string s) 
    {
        int result=0;
        int n=s.size();
        for(int i=1;i<n;i++)
        {
            int score=0;
            for(int j=0;j<i;j++)
            {
                if(s[j]=='0')
                {
                    score++;
                }
            }
            for(int j=i;j<n;j++)
            {
                if(s[j]=='1')
                {
                    score++;
                }
            }
            result=max(result,score);
        }
        return result;
    }
};