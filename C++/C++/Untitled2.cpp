#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >>n;
    int *a=new int[n]; //khai bao mang
    for(int i=0;i<n;i++)
    {
            fin>>a[i];}
    for(int i=0;i<n;i++)
    {
    cout<<a[i]<<" "<<endl;
    system("pause");}                
    }
