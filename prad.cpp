#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct studentas{
string vard, pav;
double nd[10], egz;
double suma=0;
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
            while(true){
                cin>>A[i].nd[j];
                if(cin.fail() || A[i].nd[j]<1 || A[i].nd[j]>10){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Ivesti galima tik skaicius nuo 1 iki 10";
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                        cin.ignore(10000, '\n');
                        cout<<"Ivesti galima tik sveikuosius skaicius nuo 1 iki 10"<<endl;
                    }
                else{break;}
            }
            A[i].suma+=A[i].nd[j];
        }

        A[i].vid=(float)A[i].suma/3;

        std::sort(A[i].nd, A[i].nd+3);
        A[i].med=A[i].nd[3/2];

        cout<<"Iveskite pazymi gauta uz egzamina"<<endl;
        while(true){
            cin>>A[i].egz;
                if(cin.fail() ||A[i].egz<1 || A[i].egz>10){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Ivesti galima tik skaicius nuo 1 iki 10"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                         cin.ignore(10000, '\n');
                         cout<<"Ivesti galima tik sveikuosius skaicius nuo 1 iki 10"<<endl;
                    }
                else{
                    break;
                }
        }

        A[i].gal=A[i].vid*0.4+A[i].egz*0.6; // su vidurkiu

        A[i].gal2=A[i].med*0.4+A[i].egz*0.6; // su mediana
    }

    cout<<"1 - Isvesti su vidurkiu, 2 - Isvesti su mediana"<<endl;
    while(true){
            cin>>is;
                if(cin.fail()||is<1 || is>2){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Ivesti galima tik skaicius 1 arba 2"<<endl;
                }
                    else if(cin.peek() !=' ' && cin.peek() != '\n'){
                         cin.ignore(10000, '\n');
                         cout<<"Ivesti galima tik sveikuosius skaicius 1 arba 2"<<endl;
                    }
                else{
                    break;
                }
    }
    if(is==1){
         cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<"Galutinis (Vid.)"<<endl;
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