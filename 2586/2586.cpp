class Solution 
{
    bool isVowel(char ch)
    {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) 
    {
        int n=0;
        for(int i=left;i<=right;i++)
        {
            size_t len=words[i].length();
            if(len>0&&isVowel(words[i][0])&&isVowel(words[i][len-1]))
            {
                n++;
            }
        }
        return n;
    }
};