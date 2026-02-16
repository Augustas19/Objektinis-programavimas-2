#include <iomanip>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::mt19937;
using std::setprecision;
using std::fixed;

using laik = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> int_dis;

struct studentas{
    std::string vard;
    std::string pav;
    int egz;
    double* nd=nullptr;
    double vid;
    double med;
    double suma=0;
    double gal;
    double gal2;
};

int gen_pazym(){
    mt19937 rnd(static_cast<long unsigned int>(laik::now().time_since_epoch().count()));
    int_dis paskirst(0,9);  

    return paskirst(rnd); 
};

void skaiciai(int &n, int &m){
    cout<<"Ivesk kiek pazymiu gavo uz namu darbus"<<endl;
    cin>>n;
    cout<<"Ivesk studentu skaiciu"<<endl;
    cin>>m;
}
/*
studentas gen_vrd(){
    studentas A;
    mt19937 rnd(static_cast<long unsigned int>(laik::now().time_since_epoch().count()));
    int_dis paskirst(0,9);
    std::string v[10] = {"Jonas", "Paulius", "Saulius", "Matas", "Egle", "Ruta", "Rima", "Lukas", "Juste", "Laura"};
    std::string p_v[10] = {"Pavardenis1", "Pavardenis2", "Pavardenis3", "Pavardenis4", "Pavardenis5", "Pavardenis6", "Pavardenis7", "Pavardenis8", "Pavardenis9", "Pavardenis10"};
    std::string p_m[10] = {"Pavardaite1", "Pavardaite2", "Pavardaite3", "Pavardaite4", "Pavardaite5", "Pavardaite6", "Pavardaite7", "Pavardaite8", "Pavardaite9", "Pavardaite10"};
    A.vard=v[paskirst(rnd)];
    switch (*A.vard.rbegin())
    {
    case 's' :
        A.pav=p_v[paskirst(rnd)];
        break;
    default:
        A.pav=p_m[paskirst(rnd)];
        break;
        
    };
    return A;
};*/

int main(){

    int x;
    int n;  // nd sk
    int m;  //studentu sk
    int meniu; 
    
    cout<<"1 - ranka, 2 - generuoti pazymius, 3 - generuoti pazymius, vardus, pavardes, 4 - baigti darba"<<endl;
    cin>> meniu;
    if(meniu==4){
        exit(EXIT_SUCCESS);
    }
    skaiciai(n,m);


    studentas* A = new studentas[m];

    if(meniu==1){
        for(int i=0; i<m; i++){
        cout<<"Ivesk studento varda"<<endl;
            cin>>A[i].vard;
            cout<<"Ivesk studento pavarde"<<endl;
            cin>>A[i].pav;
            cout<<"Ivesk "<<n<<" gautus namu darbu pazymius"<<endl;

            A[i].nd= new double[n];
            for(int j=0; j<n; j++){
                cin>>A[i].nd[j];
            }
            cout<<"Ivesk pazymi gauta uz egzamina"<<endl;
            cin>>A[i].egz;

        }
    }
    else if(meniu==2){

    }
    else if(meniu==3){

    }


    for(int i=0; i<m; i++){
        delete[] A[i].nd;
    }
    delete[] A;
}
