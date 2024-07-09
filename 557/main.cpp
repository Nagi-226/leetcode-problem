class Solution 
{
public:
    string reverseWords(string s) 
    {
        int i=0;
        while(i<s.length())
        {
            int start=i;
            while(i<s.length()&&s[i]!=' ')
            {
                i++;
            }
            int left=start,right=i-1;
            while(left<right)
            {
                swap(s[left],s[right]);
                left++;
                right--;
            }
            while(i<s.length()&&s[i]==' ')
            {
                i++;
            }
        }
        return s;
    }
};