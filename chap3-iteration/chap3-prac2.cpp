#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_format(int layer)
{
    if(layer>0)
    {
        for(int i=0; i<layer; i++)
            cout<<'|'<<"     ";
    }
}

void print_file(int layer, vector<vector<string>> &file_name)
{
    sort(file_name[layer].begin(), file_name[layer].end());
    for(int i=0; i<file_name[layer].size(); i++)
    {
        print_format(layer);
        cout<<file_name[layer][i]<<endl;
    }
    file_name[layer].clear();
}

int main()
{
    string str;
    cin>>str;
    int cnt = 1;
    while(1)
    {
        cout<<"DATA SET "<<cnt++<<":"<<endl;
        cout<<"ROOT"<<endl;
        int layer = 0;
        vector<vector<string>> file_name(30, vector<string>());
        while(str[0] != '*')
        {
            if(str[0] == 'f') file_name[layer].push_back(str);
            if(str[0] == 'd')
            {
                layer++;
                print_format(layer);
                cout<<str<<endl;
            }
            if(str[0] == ']')
            {
                print_file(layer, file_name);
                layer--;
            }
            cin>>str;
        }
        print_file(layer, file_name);
        cin>>str;
        if(str[0] != '#') cout<<endl;
        else break;
    }

    return 0;
}