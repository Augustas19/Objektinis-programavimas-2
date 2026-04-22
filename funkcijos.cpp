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
#include <list>
#include <deque>

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

Studentas gen_vrd(){
    Studentas A;
    mt19937 rnd(static_cast<long unsigned int>(laik::now().time_since_epoch().count()));
    int_dis paskirst(0,9);
    std::string v[10] = {"Jonas", "Paulius", "Saulius", "Matas", "Egle", "Ruta", "Rima", "Lukas", "Juste", "Laura"};
    std::string p_v[10] = {"Jonaitis", "Saulenas", "Pavardaits", "Vardaitis", "Rimauskas", "Paulauskas", "Mataitis", "Saulaitis", "Jonauskas", "Jokubaitis"};
    std::string p_m[10] = {"Eglaite", "Rutaite", "Rimaite", "Justiene", "Lauraite", "Joniene", "Jonaite", "Mataite", "Paulaitiene", "Pavardiene"};
    A.setVardas(v[paskirst(rnd)]);
    switch (*A.vardas().rbegin())
    {
    case 's' :
        A.setPavarde(p_v[paskirst(rnd)]);
        break;
    default:
        A.setPavarde(p_m[paskirst(rnd)]);
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

template <typename Konteineris>
void skt_visi(Konteineris& A, const string& failopav){
    //std::stringstream buf;
   
    std::ifstream f(failopav);
    
    string eilut;
    if(!f.is_open()){throw std::runtime_error("Nepavyko atidaryti failo");
    }

    std::string antr;
    getline(f, antr); // antraste

    Studentas tmp;
    while (f>>tmp)
    {
        A.push_back(tmp);
    }

    f.close();
}

void skt(std::vector<Studentas>& A, string failopav){skt_visi(A,failopav);}
void skt(std::list<Studentas>& A, string failopav){skt_visi(A,failopav);}
void skt(std::deque<Studentas>& A, string failopav){skt_visi(A,failopav);}

void isved(std::vector<Studentas>& A){
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
        for(const auto& s: A){
            cout<<left<<setw(15)<<s.pavarde()<<setw(15)<<s.vardas()<<fixed<<setprecision(2)<<s.galutBalas(vidurkis)<<endl;
        }
    }
    if(is==2){
        cout<<left<<setw(15)<<"Pavardė"<<setw(15)<<"Vardas"<<"Galutinis (Med.)"<<endl;
        cout<<"----------------------------------"<<endl;
        for(const auto& s: A){
            cout<<left<<setw(15)<<s.pavarde()<<setw(15)<<s.vardas()<<fixed<<setprecision(2)<<s.galutBalas()<<endl;
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

template <typename Konteineris>
void isvedimas_faila_visi(Konteineris& A, string pav){
    std::ofstream r(pav);
    r<<left<<setw(20)<<"Pavardė"<<setw(20)<<"Vardas"<<setw(17)<<"Galutinis (Vid.)"<<"Galutinis (Med.)"<<"\n";
    r<<"-----------------------------------------------------------"<<"\n";
    for(const auto& s : A){
    r<<left<<setw(20)<<s.pavarde()<<setw(20)<<s.vardas()<<setw(17)<<fixed<<setprecision(2)<<s.galutBalas(vidurkis)<<fixed<<setprecision(2)<<s.galutBalas()<<"\n";
    }
    r.close();
}
void isvedimas_faila(std::vector<Studentas>& A, string pav){isvedimas_faila_visi(A, pav);}
void isvedimas_faila(std::list<Studentas>& A, string pav){isvedimas_faila_visi(A, pav);}
void isvedimas_faila(std::deque<Studentas>& A, string pav){isvedimas_faila_visi(A, pav);}

int pasirink(){
    int rik;
        cout<<"1 - Rikiuosti pagal vardą mažėjančiai\n" 
        <<"2 - pagal vardą didėjančiai\n"
        <<"3 - pagal pavardę mažėjančiai\n" 
        <<"4 - pagal pavardę didėjančiai\n" 
        <<"5 - pagal vidurkį mažėjančiai\n"
        <<"6 - pagal vidurki didėjančiai\n"
        <<"7 - pagal mediana mažėjančiai\n"
        <<"8 - pagal mediana didėjančiai"<<endl;
        while(true){
            cin>>rik;
                if(cin.fail() ||rik<1 || rik>8){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout<<"Įvesti galima tik 1, 2, 3, 4, 5, 6, 7 arba 8"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout<<"Įvesti galima tik 1, 2, 3, 4, 5, 6, 7 arba 8"<<endl;
                }
                else{
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;}
        }
        return rik;
}

auto rikiav_visi(int rik){
        return [rik](const Studentas& A, const Studentas& B){
            switch (rik)
            {
            case 1:
                return A.vardas() > B.vardas();
            case 2:
                return A.vardas() < B.vardas();
            case 3:
                return A.pavarde() > B.pavarde() ;
            case 4:
                return A.pavarde()  < B.pavarde() ;
            case 5:
                return A.galutBalas(vidurkis) > B.galutBalas(vidurkis);
            case 6:
                return A.galutBalas(vidurkis) < B.galutBalas(vidurkis);
            case 7:
                return A.galutBalas()> B.galutBalas();
            case 8:
                return A.galutBalas() < B.galutBalas();
            default: return false;
            }

        };
}
void rikiav(std::vector<Studentas>& A, int rik){std::sort(A.begin(), A.end(), rikiav_visi(rik));}
void rikiav(std::list<Studentas>& A, int rik){A.sort(rikiav_visi(rik));}
void rikiav(std::deque<Studentas>& A, int rik){std::sort(A.begin(), A.end(), rikiav_visi(rik));}


// 1 STRATEGIJA
template <typename Konteineris>
void rusiavimas_visi(Konteineris& A, Konteineris& vargsai, Konteineris& kietekai){
for(const auto& s: A){
    if(s.galutBalas(vidurkis)<5.0){
        vargsai.push_back(s);
    }
    else{kietekai.push_back(s);}
}
}
void rusiavimas(std::vector<Studentas>& A, std::vector<Studentas>& vargsai, std::vector<Studentas>& kietekai){rusiavimas_visi(A,vargsai,kietekai);}
void rusiavimas(std::list<Studentas>& A, std::list<Studentas>& vargsai, std::list<Studentas>& kietekai){rusiavimas_visi(A,vargsai,kietekai);}
void rusiavimas(std::deque<Studentas>& A, std::deque<Studentas>& vargsai, std::deque<Studentas>& kietekai){rusiavimas_visi(A,vargsai,kietekai);}

// 2 STRATEGIJA 
template <typename Konteineris>
void strat2_visi(Konteineris& A, Konteineris& vargsai){
  for(const auto& s: A){
    if(s.galutBalas(vidurkis)<5.0){
        vargsai.push_back(s);
    }
}
   A.erase(std::remove_if(A.begin(), A.end(), [](const Studentas& s){
    return s.galutBalas(vidurkis) < 5.0;
   }),
   A.end()
);
}
void strat2(std::vector<Studentas>& A, std::vector<Studentas>& vargsai){strat2_visi(A,vargsai);}
void strat2(std::list<Studentas>& A, std::list<Studentas>& vargsai){strat2_visi(A,vargsai);}
void strat2(std::deque<Studentas>& A, std::deque<Studentas>& vargsai){strat2_visi(A,vargsai);}

// 3 STRATEGIJA
template <typename Konteineris>
void strat3_visi(Konteineris& A, Konteineris& vargsai){
    vargsai.clear();
    if constexpr(std::is_same_v<Konteineris, std::list<Studentas>>){
        std::remove_copy_if(A.begin(), A.end(), std::back_inserter(vargsai), [](const Studentas& s){
        return s.galutBalas(vidurkis) >=5.0;});
    A.remove_if([](const Studentas& s){
        return s.galutBalas(vidurkis) < 5.0;});
    }

    else {auto i = std::partition(A.begin(), A.end(), [](const Studentas& s){
        return s.galutBalas(vidurkis) >=5.0;
    });
    vargsai.insert(vargsai.end(), i, A.end());
    A.erase(i, A.end());
    }   
}
void strat3(std::vector<Studentas>& A, std::vector<Studentas>& vargsai){strat3_visi(A,vargsai);}
void strat3(std::list<Studentas>& A, std::list<Studentas>& vargsai){strat3_visi(A,vargsai);}
void strat3(std::deque<Studentas>& A, std::deque<Studentas>& vargsai){strat3_visi(A,vargsai);}

void tyrimas1(){
    auto startas = std::chrono::high_resolution_clock::now();
    failu_kurimas();    
    std::chrono::duration<double> diff=laik::now()-startas;
    cout<<"Visų failų kūrimas užtruko "<<diff.count()<<" s"<<endl;
}


void tyrimas2(std::vector<Studentas>& A){
    std::vector<long> kiekiai = {1000, 10000, 100000, 1000000, 10000000};
    int rik = pasirink(); 
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
    cout<<"Failo nuskaitymas užtruko "<<diff1.count()<<" s\n";

    auto ti3= std::chrono::high_resolution_clock::now();    // rusiavimas
    std::vector<Studentas> vargsai, kietekai;   
    rusiavimas(A,vargsai, kietekai);
    rikiav(vargsai,rik);
    rikiav(kietekai,rik);
    std::chrono::duration<double> diff3=laik::now()-ti3;
    cout<<"Studentų rūšiavimas užtruko "<<diff3.count()<<" s\n";

    auto ti4= std::chrono::high_resolution_clock::now();    // rasymas i failus
    isvedimas_faila(vargsai, "vargsai.txt");
    isvedimas_faila(kietekai,"kietekai.txt");
    std::chrono::duration<double> diff4=laik::now()-ti4;
    cout<<"Rašymas į failus užtruko "<<diff4.count()<<" s\n";
    cout<<"\n";
}
    
    std::chrono::duration<double> diff=laik::now()-startas;
    cout<<"Visos programos veikimas užtruko "<<diff.count()<<" s\n";
    

}
template <typename Konteineris>
void tyrimas2_visi(Konteineris& A){
    std::vector<long> kiekiai = {1000, 10000, 100000, 1000000, 10000000};
    int rik = pasirink(); 
    auto startas = std::chrono::high_resolution_clock::now();

    for(long y: kiekiai){
    A.clear();
    string pavad = "failas"+std::to_string(y)+".txt";
    
    cout<<y<<" failas :"<<endl;
    // nuskaitymas
    auto ti1= std::chrono::high_resolution_clock::now();    
    try{
        skt(A, pavad);
        }
        catch(const std::exception& e){
        std::cerr<<"Klaida : "<<e.what()<<endl;
        return void();
    }
    std::chrono::duration<double> diff1=laik::now()-ti1;
    cout<<"Failo nuskaitymas užtruko "<<diff1.count()<<" s\n";

    // rusiavimas
    // 1 STRATEGIJA
    Konteineris vargsai, kietekai, cop(A), c1(A), c2(A);  
    vargsai.clear();
    auto ti3= std::chrono::high_resolution_clock::now();    
    rusiavimas(cop,vargsai, kietekai);
    std::chrono::duration<double> diff3=laik::now()-ti3;
    cout<<"1 Strategija studentų rūšiavimas užtruko "<<diff3.count()<<" s\n";

    // 2 STRATEGIJA 
    vargsai.clear();
    auto st2= std::chrono::high_resolution_clock::now();       
    strat2(c1,vargsai);
    std::chrono::duration<double> stdif2=laik::now()-st2;
    cout<<"2 Strategija studentų rūšiavimas užtruko "<<stdif2.count()<<" s\n";

    // 3 STRATEGIJA 
    vargsai.clear();
    auto st3= std::chrono::high_resolution_clock::now();    
    strat3(c2,vargsai);
    std::chrono::duration<double> stdif3=laik::now()-st3;
    cout<<"3 Strategija studentų rūšiavimas užtruko "<<stdif3.count()<<" s\n";

    // rikiavimas 
    auto ti4= std::chrono::high_resolution_clock::now();  
    rikiav(vargsai,rik);
    rikiav(c2,rik);
    std::chrono::duration<double> diff4=laik::now()-ti4;
    cout<<"Studentų rikiavimas užtruko "<<diff4.count()<<" s\n";

    isvedimas_faila(vargsai, "vargsai.txt");
    isvedimas_faila(c2,"kietekai.txt");

}
}
void tyrimas2_ve(std::vector<Studentas>& A){tyrimas2_visi(A);}
void tyrimas2_li(std::list<Studentas>& A){tyrimas2_visi(A);}
void tyrimas2_de(std::deque<Studentas>& A){tyrimas2_visi(A);}


// rule of five testavimas
void check(bool salyga, const string pavad){
    if(salyga){cout<<pavad<<" - veikia teisingai\n";}
    else{cout<<pavad<<" - Neveikia teisignai\n";}
}

void testavimas(){
    std::vector<double> nd = {8, 9, 5};
    Studentas pradinis("Jonas", "Jonaitis", 10, nd);

    cout<<pradinis<<"\n";

    Studentas kopija(pradinis);
    cout<<kopija<<"\n";

    check(kopija.vardas()==pradinis.vardas(), "Kopija");  // copy constr

    Studentas move1(std::move(pradinis));  // move kostr
    cout<<"move kontsr - "<<move1<<"\n";

    Studentas prisk;  // priskyrimas
    prisk = pradinis;
    check(prisk.vardas()==pradinis.vardas(), "Priskyrimas");

    Studentas move2;    // priskyrimo move
    move2 = std::move(kopija);
    cout<<move2<<"\n";
    
    std::istringstream is("Paulius Lukaitis 6 7 8 8");  // ivestis
    Studentas skaitymas;
    is>>skaitymas;
    cout<<skaitymas<<"\n";

    std::ostringstream o;  // isvestis
    o<<skaitymas;
    string isv = o.str();
    cout<<isv<<"\n";

}