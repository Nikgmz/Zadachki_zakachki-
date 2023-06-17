#include<iostream>
#include<string>
using namespace std;
int main ()
{
    string t;
    getline(cin, t);
    string w;
    getline(cin, w);
    int index[w.length()];
    int k=0;
    for(int i=0; i<w.length(); ++i)
    {
        if(i==0)
        {
            index[0]=0;
        }
        else
        {
            if(w[i]==w[k])
            {
                ++k;
                index[i]=k;

            }
            else
            {
                k=0;
                index[i]=k;
            }
        }

    }
    int j=0;
    for(int i=0; i<t.length();)
    {
        if(w[j]==w[i])
        {
            ++j;
            ++i;
        }
        else
        {

        }
        if(j==w.length())
        {
            cout<<i<<endl;
            j=index[j]+1;
        }
        else
        {
            j=index[j]+1;
        }
    }
    return 0;
}
//aabaacaabaacaabaacaabaa
