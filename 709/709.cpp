class Solution 
{
public:
    string toLowerCase(string s) 
    {
        using namespace std;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                s[i]+=32;
            }
        }
        return s;
    }
};