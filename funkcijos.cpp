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

template <typename Konteineris>
void skt_visi(Konteineris& A, const string& failopav){
    std::stringstream buf;
    string eilut;
    std::vector<string> skaid;

    std::ifstream f(failopav);

    if(!f.is_open()){throw std::runtime_error("Nepavyko atidaryti failo");
    }
    buf << f.rdbuf();
    f.close();

    getline(buf, eilut);
    while (getline(buf, eilut))
    {
        std::stringstream t(eilut);
        Studentas laik;
        laik.readStudent(t);
        A.push_back(laik);
    }
    
   /* while(buf){
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
    }*/
}

void skt(std::vector<studentas>& A, string failopav){skt_visi(A,failopav);}
void skt(std::list<studentas>& A, string failopav){skt_visi(A,failopav);}
void skt(std::deque<studentas>& A, string failopav){skt_visi(A,failopav);}

template <typename Konteineris>
void skaiciavimai_visi(Konteineris& A){
    for(auto& s : A){
    //for(size_t i=0; i<A.size(); i++){
            size_t sk =s.nd.size();

            if(sk == 0){
                s.vid=0;
                s.med=0;
            }
            else{
                s.vid=(float)s.suma/sk;
                std::sort(s.nd.begin(), s.nd.end());

                if(sk%2==1){
                    s.med=s.nd[sk/2];
                }
                else if(sk>=2){
                    s.med=(s.nd[sk/2-1] + s.nd[sk/2])/2.0;
                }
                else {s.med=s.nd[0];}
            }
            s.gal=s.vid*0.4+s.egz*0.6; 
            s.gal2=s.med*0.4+s.egz*0.6;
        }
}
void skaiciavimai(std::vector<studentas>& A){skaiciavimai_visi(A);}
void skaiciavimai(std::list<studentas>& A){skaiciavimai_visi(A);}
void skaiciavimai(std::deque<studentas>& A){skaiciavimai_visi(A);}

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

template <typename Konteineris>
void isvedimas_faila_visi(Konteineris& A, string pav){
    std::ofstream r(pav);
    r<<left<<setw(20)<<"Pavardė"<<setw(20)<<"Vardas"<<setw(17)<<"Galutinis (Vid.)"<<"Galutinis (Med.)"<<endl;
    r<<"-----------------------------------------------------------"<<endl;
    for(auto& s : A){
    r<<left<<setw(20)<<s.pav<<setw(20)<<s.vard<<setw(17)<<fixed<<setprecision(2)<<s.gal<<fixed<<setprecision(2)<<s.gal2<<endl;
    }
    r.close();
}
void isvedimas_faila(std::vector<studentas>& A, string pav){isvedimas_faila_visi(A, pav);}
void isvedimas_faila(std::list<studentas>& A, string pav){isvedimas_faila_visi(A, pav);}
void isvedimas_faila(std::deque<studentas>& A, string pav){isvedimas_faila_visi(A, pav);}

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
        return [rik](const studentas& A, const studentas& B){
            switch (rik)
            {
            case 1:
                return A.vard > B.vard;
            case 2:
                return A.vard < B.vard;
            case 3:
                return A.pav > B.pav;
            case 4:
                return A.pav < B.pav;
            case 5:
                return A.gal > B.gal;
            case 6:
                return A.gal < B.gal;
            case 7:
                return A.gal2> B.gal2;
            case 8:
                return A.gal2 < B.gal2;
            default: return false;
            }

        };
}
void rikiav(std::vector<studentas>& A, int rik){std::sort(A.begin(), A.end(), rikiav_visi(rik));}
void rikiav(std::list<studentas>& A, int rik){A.sort(rikiav_visi(rik));}
void rikiav(std::deque<studentas>& A, int rik){std::sort(A.begin(), A.end(), rikiav_visi(rik));}


// 1 STRATEGIJA
template <typename Konteineris>
void rusiavimas_visi(Konteineris& A, Konteineris& vargsai, Konteineris& kietekai){
for(const auto& s: A){
    if(s.gal<5.0){
        vargsai.push_back(s);
    }
    else{kietekai.push_back(s);}
}
}
void rusiavimas(std::vector<studentas>& A, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai){rusiavimas_visi(A,vargsai,kietekai);}
void rusiavimas(std::list<studentas>& A, std::list<studentas>& vargsai, std::list<studentas>& kietekai){rusiavimas_visi(A,vargsai,kietekai);}
void rusiavimas(std::deque<studentas>& A, std::deque<studentas>& vargsai, std::deque<studentas>& kietekai){rusiavimas_visi(A,vargsai,kietekai);}

// 2 STRATEGIJA 
template <typename Konteineris>
void strat2_visi(Konteineris& A, Konteineris& vargsai){
  for(const auto& s: A){
    if(s.gal<5.0){
        vargsai.push_back(s);
    }
}
   A.erase(std::remove_if(A.begin(), A.end(), [](const studentas& s){
    return s.gal < 5.0;
   }),
   A.end()
);
}
void strat2(std::vector<studentas>& A, std::vector<studentas>& vargsai){strat2_visi(A,vargsai);}
void strat2(std::list<studentas>& A, std::list<studentas>& vargsai){strat2_visi(A,vargsai);}
void strat2(std::deque<studentas>& A, std::deque<studentas>& vargsai){strat2_visi(A,vargsai);}

// 3 STRATEGIJA
template <typename Konteineris>
void strat3_visi(Konteineris& A, Konteineris& vargsai){
    vargsai.clear();
    if constexpr(std::is_same_v<Konteineris, std::list<studentas>>){
        std::remove_copy_if(A.begin(), A.end(), std::back_inserter(vargsai), [](const studentas& s){
        return s.gal >=5.0;});
    A.remove_if([](const studentas& s){
        return s.gal < 5.0;});
    }

    else {auto i = std::partition(A.begin(), A.end(), [](const studentas& s){
        return s.gal >=5.0;
    });
    vargsai.insert(vargsai.end(), i, A.end());
    A.erase(i, A.end());
    }   
}
void strat3(std::vector<studentas>& A, std::vector<studentas>& vargsai){strat3_visi(A,vargsai);}
void strat3(std::list<studentas>& A, std::list<studentas>& vargsai){strat3_visi(A,vargsai);}
void strat3(std::deque<studentas>& A, std::deque<studentas>& vargsai){strat3_visi(A,vargsai);}

void tyrimas1(){
    auto startas = std::chrono::high_resolution_clock::now();
    failu_kurimas();    
    std::chrono::duration<double> diff=laik::now()-startas;
    cout<<"Visų failų kūrimas užtruko "<<diff.count()<<" s"<<endl;
}


void tyrimas2(std::vector<studentas>& A){
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

    auto ti2= std::chrono::high_resolution_clock::now();    // vidurkio radimas
    skaiciavimai(A);
    std::chrono::duration<double> diff2=laik::now()-ti2;
    cout<<"Skaičiavimai užtruko "<<diff2.count()<<" s\n";

    auto ti3= std::chrono::high_resolution_clock::now();    // rusiavimas
    std::vector<studentas> vargsai, kietekai;   
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

    // vidurkio radimas
    skaiciavimai(A);
    
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

}
}
void tyrimas2_ve(std::vector<studentas>& A){tyrimas2_visi(A);}
void tyrimas2_li(std::list<studentas>& A){tyrimas2_visi(A);}
void tyrimas2_de(std::deque<studentas>& A){tyrimas2_visi(A);}