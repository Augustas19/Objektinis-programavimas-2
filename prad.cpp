#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

using namespace std;

struct studentas{
string vard, pav;
int nd[10], egz;
int suma=0;
double vid;  
double med;  
double gal;
double gal2;
};

int main(){

    studentas A[10];

    for(int i=0; i<2; i++){
        cout<<"Iveskite studento varda ir pavarde"<<endl;
        cin>>A[i].vard>>A[i].pav;
        cout<<"Iveskite 3 gautus namu darbu pazymius"<<endl;
        for(int j=0; j<3; j++){
            cin>>A[i].nd[j];
            A[i].suma+=A[i].nd[j];
        }

         A[i].vid=(float)A[i].suma/3;

        sort(A[i].nd, A[i].nd+3);
        A[i].med=(A[i].nd[3/2-1] + A[i].nd[3/2])/2.0;

        cout<<"Iveskite pazymi gauta uz egzamina"<<endl;
        cin>>A[i].egz;

       
    }


    

   
      // cout<<tmp[0]<<" "<<tmp[1]<<tmp
    
}