#include <iostream>
#include <iomanip>
#include <algorithm>
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
    int is;

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
        A[i].med=A[i].nd[3/2];

        cout<<"Iveskite pazymi gauta uz egzamina"<<endl;
        cin>>A[i].egz;

        A[i].gal=A[i].vid*0.4+A[i].egz*0.6; // su vidurkiu

        A[i].gal2=A[i].med*0.4+A[i].egz*0.6; // su mediana
    }

    cout<<"1 - Isvesti su vidurkiu, 2 - Isvesti su mediana"<<endl;
    cin>>is;
    if(is==1){
         cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<"Galutinis (Med.)"<<endl;
        cout<<"----------------------------------"<<endl;
        for(int i=0; i<2; i++){
            cout<<left<<setw(15)<<A[i].pav<<setw(15)<<A[i].vard<<fixed<<setprecision(2)<<A[i].gal<<endl;
        }
    }
    if(is==2){
        cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<"Galutinis (Med.)"<<endl;
        cout<<"----------------------------------"<<endl;
        for(int i=0; i<2; i++){
            cout<<left<<setw(15)<<A[i].pav<<setw(15)<<A[i].vard<<fixed<<setprecision(2)<<A[i].gal2<<endl;
        }
    }
}