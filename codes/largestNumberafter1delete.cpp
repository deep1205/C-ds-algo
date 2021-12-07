
#include <bits/stdc++.h>
using namespace std;


bool checkPalin(string word)
{
    int n = word.length();
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    for (int i = 0; i < n; i++, n--)
        if (word.at(i) != word.at(n - 1))
            return false;
    return true;
}


int countPalin(string input1,int input2)
{
    
   input1 =input1 + " ";
    string word = "";
    int count = 0;
    for (int i = 0; i < input1.length(); i++)
    {
        char ch = input1.at(i);
        if (ch != ' ')
            word = word + ch;
        else
        {
            if (checkPalin(word))
                count++;
            word = "";
        }
    }

    return count;
}


int main()
{
    string s;
    int n;
   
   getline(cin,s);
   cin>>n;
    cout << countPalin(s,n) << endl;

   
}


