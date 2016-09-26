#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    vector <int> valores;
    int soma=0,j=0;
    cin>>n;
    int fat =1;
    for(int i=1; i<n; i++)
    {
        fat = fat*i;
        if(fat<=n)
        {
            valores.push_back(fat);
        }
        else
        {
            break;
        }
    }
    int i=valores.size()-1;
    while(i>=0)
    {
        if((valores[i]+soma)<=n){
            soma=soma+valores[i];
            j++;
        }
        else{
            i--;
        }
    }
    cout<<j<<endl;
    return 0;
}
