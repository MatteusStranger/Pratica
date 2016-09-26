#include <iostream>
#include<fstream>
using namespace std;
int main(){
	char cardeais[4] = {'N','L','S','O'};
	char comandos;
	int serie,i,j=0;
	cin>>serie;
	while((serie!=0)){
        for(i=0;i<serie;i++){
            cin>>comandos;
            if(comandos=='D'){
                if(j==3){
                    j=0;
                }else{
                    j++;
                }
            }else if(comandos=='E'){
                if(j==0){
                    j=3;
                }else{
                    j--;
                }
            }
        }
        cout<<cardeais[j]<<endl;
        cin>>serie;
        j=0;
	}
	return 0;
}
