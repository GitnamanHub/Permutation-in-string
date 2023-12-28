#include<iostream>
#include<string>
using namespace std;

bool checkInclusion(string s1, string s2) {

        int l1=s1.length();
        int l2=s2.length();
        
        if(l1>l2)
        return false;

        int ans[26]={0};
        for(int i=0;i<l1;i++)
        {
            int kans=s1[i]-'a';
            ans[kans]++;
        }

        int arr[26]={0};
        for(int i=0;i<l1;i++)
        {
            int karr=s2[i]-'a';
            arr[karr]++;
        }

        int flag{0};

        for(int i=0;i<=(l2-l1);i++)
        {
            if(i!=0)
            {
                int karr=s2[i-1]-'a';
                arr[karr]--;
                karr=s2[i+l1-1]-'a';
                arr[karr]++;
            }
            for(int j=0;j<26;j++)
            {
                if(arr[j]!=ans[j])
                {
                    flag=1;
                }
            }

            if (flag==0)
            return true;
            flag=0;
        }

        return false;
    }

int main()
{
    string s1="nat";
    string s2="naman";
    cout<<boolalpha<<checkInclusion(s1,s2)<<endl;
}