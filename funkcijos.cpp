#include "funkcijos.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>
#include <fstream>
#include <windows.h>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::mt19937;
using std::setprecision;
using std::fixed;
using std::string;
using std::getline;

using laik = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> int_dis;

studentas gen_vrd(){
    studentas A;
    mt19937 rnd(static_cast<long unsigned int>(laik::now().time_since_epoch().count()));
    int_dis paskirst(0,9);
    std::string v[10] = {"Jonas", "Paulius", "Saulius", "Matas", "Egle", "Ruta", "Rima", "Lukas", "Juste", "Laura"};
    std::string p_v[10] = {"Jonaitis", "Saulenas", "Pavardaits", "Vardaitis", "Rimauskas", "Paulauskas", "Mataitis", "Saulaitis", "Jonauskas", "Jokubaitis"};
    std::string p_m[10] = {"Eglaite", "Rutaite", "Rimaite", "Justiene", "Lauraite", "Joniene", "Jonaite", "Mataite", "Paulaitiene", "Pavardiene"};
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
};

int gen_pazym(){
    mt19937 rnd(static_cast<long unsigned int>(laik::now().time_since_epoch().count()));
    int_dis paskirst(1,10);  

    return paskirst(rnd); 
};

void skaiciai(long &n, long &m){
    cout<<"Įvesk kiek pažymių gavo už namų darbus"<<endl;
     while(true){
            cin>>n;
                if(cin.fail()||n<=0){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Įvesti galima tik sveikuosius teigiamus skaičius"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                         cin.ignore(10000, '\n');
                         cout<<"Įvesti galima tik sveikuosius skaičius"<<endl;    
                        }
                else{break;}
        }
    cout<<"Įvesk studentų skaičių"<<endl;
    while(true){
            cin>>m;
                if(cin.fail()|| m<=0){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Įvesti galima tik sveikuosius teigiamus skaičius"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                         cin.ignore(10000, '\n');
                         cout<<"Įvesti galima tik sveikuosius skaičius"<<endl;
                    }
                else{break;}
        }
}


void skt(std::vector<studentas>& A, string failopav){
std::stringstream buf;
string eilut;
std::vector<string> skaid;

std::ifstream f(failopav);

if(!f.is_open()){throw std::runtime_error("Nepavyko atidaryti failo");
}
buf << f.rdbuf();
f.close();

getline(buf, eilut);
while(buf){
    if(!buf.eof()){
        getline(buf, eilut);
        skaid.push_back(eilut);

    }
    else break;
}
for(const auto& line : skaid){
    std::stringstream t(line);

    studentas temp;
    temp.nd.clear();
    temp.suma=0;

    t>>temp.vard>>temp.pav;
    int paz;
    std::vector<int> sk;
    while(t>>paz){
        sk.push_back(paz);
    }

    if(sk.size()<1){continue;}

    temp.egz=sk.back();
    sk.pop_back();
    temp.nd=sk;
    for(int i:temp.nd){
        temp.suma+=i;
    }
    A.push_back(temp);
}
}

void skaiciavimai(std::vector<studentas>& A){
    for(size_t i=0; i<A.size(); i++){
            size_t sk =A[i].nd.size();

            if(sk == 0){
                A[i].vid=0;
                A[i].med=0;
            }
            else{
                A[i].vid=(float)A[i].suma/sk;
                std::sort(A[i].nd.begin(), A[i].nd.end());

                if(sk%2==1){
                    A[i].med=A[i].nd[sk/2];
                }
                else if(sk>=2){
                    A[i].med=(A[i].nd[sk/2-1] + A[i].nd[sk/2])/2.0;
                }
                else {A[i].med=A[i].nd[0];}
            }
            A[i].gal=A[i].vid*0.4+A[i].egz*0.6; 
            A[i].gal2=A[i].med*0.4+A[i].egz*0.6;
        }
}

void isved(std::vector<studentas>& A){
    int is;
    cout<<"1 - Išvesti su vidurkiu, 2 - Išvesti su mediana"<<endl;
    while(true){
            cin>>is;
                if(cin.fail() ||is<1 || is>2){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Įvesti galima tik skaičius 1 arba 2"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                         cin.ignore(10000, '\n');
                         cout<<"Įvesti galima tik sveikuosius skaičius"<<endl;
                }
                else{break;}
    }
    if(is==1){
         cout<<left<<setw(15)<<"Pavardė"<<setw(15)<<"Vardas"<<"Galutinis (Vid.)"<<endl;
        cout<<"----------------------------------"<<endl;
        for(int i=0; i<A.size(); i++){
            cout<<left<<setw(15)<<A[i].pav<<setw(15)<<A[i].vard<<fixed<<setprecision(2)<<A[i].gal<<endl;
        }
    }
    if(is==2){
        cout<<left<<setw(15)<<"Pavardė"<<setw(15)<<"Vardas"<<"Galutinis (Med.)"<<endl;
        cout<<"----------------------------------"<<endl;
        for(int i=0; i<A.size(); i++){
            cout<<left<<setw(15)<<A[i].pav<<setw(15)<<A[i].vard<<fixed<<setprecision(2)<<A[i].gal2<<endl;
        }
    }
}
void failu_kurimas(){
    std::vector<long> kiekiai = {1000, 10000, 100000, 1000000, 10000000};
   
    for(long y: kiekiai){ 
        auto startas = std::chrono::high_resolution_clock::now();
        string pavad = "failas"+std::to_string(y)+".txt";
        std::ofstream f(pavad);
        f<<left<<setw(25)<<"Vardas"<<setw(25)<<"Pavardė";
        for(int i=1; i<=15; i++){
            f<<setw(10)<<("ND"+std::to_string(i));
        }
        f<<"Egz."<<endl;  // pirma eil

            mt19937 rnd(static_cast<long unsigned int>(laik::now().time_since_epoch().count()));
            int_dis paskirst(1,10);

            for(long i=1; i<=y; i++){
                f<<left<<setw(25)<<("VardasN"+std::to_string(i))<<setw(25)<<("PavardėN"+std::to_string(i));
                for(int j=0; j<15; j++){
                    f<<setw(10)<<paskirst(rnd);
                }
                f<<paskirst(rnd)<<endl;
            }
        f.close();
        std::chrono::duration<double> diff=laik::now()-startas;
        cout<<pavad<<" failo kūrimas užtruko "<<diff.count()<<" s"<<endl;
}
}

void isvedimas_faila(std::vector<studentas>& A, string pav){
    std::ofstream r(pav);
    r<<left<<setw(15)<<"Pavardė"<<setw(15)<<"Vardas"<<setw(17)<<"Galutinis (Vid.)"<<"Galutinis (Med.)"<<endl;
    r<<"-----------------------------------------------------------"<<endl;
    for(int i=0; i<A.size(); i++){
    r<<left<<setw(15)<<A[i].pav<<setw(15)<<A[i].vard<<setw(17)<<fixed<<setprecision(2)<<A[i].gal<<fixed<<setprecision(2)<<A[i].gal2<<endl;
    }
}


void rusiavimas(std::vector<studentas>& A, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai){
for(const auto& s: A){
    if(s.gal<5.0){
        vargsai.push_back(s);
    }
    else{kietekai.push_back(s);}
}
}

void tyrimas1(){
    auto startas = std::chrono::high_resolution_clock::now();
    failu_kurimas();    
    std::chrono::duration<double> diff=laik::now()-startas;
    cout<<"Visų failų kūrimas užtruko "<<diff.count()<<" s"<<endl;
}

void tyrimas2(std::vector<studentas>& A){
    std::vector<long> kiekiai = {1000, 10000, 100000, 1000000, 10000000};
    auto startas = std::chrono::high_resolution_clock::now();

    for(long y: kiekiai){
    A.clear();
    A.reserve(y);
    string pavad = "failas"+std::to_string(y)+".txt";

    cout<<y<<" failas :"<<endl;
    auto ti1= std::chrono::high_resolution_clock::now();    // nuskaitymas
    try{
        skt(A, pavad);
        }
        catch(const std::exception& e){
        std::cerr<<"Klaida : "<<e.what()<<endl;
        return void();
    }
    
    std::chrono::duration<double> diff1=laik::now()-ti1;
    cout<<"Failo nuskaitymas užtruko "<<diff1.count()<<" s"<<endl;

    auto ti2= std::chrono::high_resolution_clock::now();    // vidurkio radimas
    skaiciavimai(A);
    std::chrono::duration<double> diff2=laik::now()-ti2;
    cout<<"Skaičiavimai užtruko "<<diff2.count()<<" s"<<endl;

    auto ti3= std::chrono::high_resolution_clock::now();    // rusiavimas
    std::vector<studentas> vargsai, kietekai;   
    rusiavimas(A,vargsai, kietekai);
    std::chrono::duration<double> diff3=laik::now()-ti3;
    cout<<"Studentų rūšiavimas užtruko "<<diff3.count()<<" s"<<endl;

    auto ti4= std::chrono::high_resolution_clock::now();    // rasymas i failus
    isvedimas_faila(vargsai, "vargsai.txt");
    isvedimas_faila(kietekai,"kietekai.txt");
    std::chrono::duration<double> diff4=laik::now()-ti4;
    cout<<"Rašymas į failus užtruko "<<diff4.count()<<" s\n";
    cout<<"\n";
}
    
    std::chrono::duration<double> diff=laik::now()-startas;
    cout<<"Visos programos veikimas užtruko "<<diff.count()<<" s"<<endl;
    

}