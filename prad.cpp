#include <iostream>
#include <iomanip>
using namespace std;

using namespace std;

struct studentas{
string vard, pav;
int nd[10], egz;
int suma;
double vid;    
};

int main(){

    studentas A[10];

    for(int i=0; i<2; i++){
        cout<<"Iveskite studento varda ir pavarde"<<endl;
        cin>>A[i].vard>>A[i].pav;
        cout<<"Iveskite 2 gautus namu darbu pazymius"<<endl;
        for(int j=0; j<2; j++){
            cin>>A[i].nd[j];
            A[i].suma+=A[i].nd[j];
        }
        cout<<"Iveskite pazymi gauta uz egzamina"<<endl;
        cin>>A[i].egz;
    }

}