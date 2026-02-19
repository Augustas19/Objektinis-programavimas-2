#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>

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


struct studentas{
    string vard;
    string pav;
    int egz;
    std::vector<int> nd;    
    double vid;
    double med;
    double suma=0;
    double gal;
    double gal2;
};


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
    cout<<"Ivesk kiek pazymiu gavo uz namu darbus"<<endl;
     while(true){
            cin>>n;
                if(cin.fail()||n<=0){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Ivesti galima tik sveikuosius teigiamus skaicius"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                         cin.ignore(10000, '\n');
                         cout<<"Ivesti galima tik sveikuosius skaicius"<<endl;    
                        }
                else{break;}
        }
    cout<<"Ivesk studentu skaiciu"<<endl;
    while(true){
            cin>>m;
                if(cin.fail()|| m<=0){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Ivesti galima tik sveikuosius teigiamus skaicius"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                         cin.ignore(10000, '\n');
                         cout<<"Ivesti galima tik sveikuosius skaicius"<<endl;
                    }
                else{break;}
        }
}

int main(){

    int x;
    long n;  // nd sk
    long m;  //studentu sk
    int meniu; 
    std::vector<studentas> A;
    studentas tmp;
    

    cout<<"1 - ranka, 2 - generuoti pazymius, 3 - generuoti pazymius, vardus, pavardes, 4 - baigti darba"<<endl;
    while(true){
            cin>>meniu;
                if(cin.fail() ||meniu<1 || meniu>4){
                cin.clear();
                cin.ignore(10000, '\n' );
                    cout<<"Ivesti galima tik 1, 2, 3 arba 4"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                    cin.ignore(10000, '\n');
                    cout<<"Ivesti galima tik sveikuosius skaicius 1, 2, 3 arba 4"<<endl;
                }
                else{break;}
        }
    
    if(meniu==1){
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while(true){
            tmp.nd.clear();
            tmp.suma=0;
            cout<<"Ivesk studento varda arba paspausk ENTER jei nebenori ivesti daugiau studentu"<<endl;
            getline(cin, tmp.vard);
            if(tmp.vard.empty()){break;}

            cout<<"Ivesk studento pavarde"<<endl;
            getline(cin, tmp.pav);

            cout<<"Ivesk pazymi nuo 1 iki 10 arba 0 jei nori baigti ivedima"<<endl;
            while(true){
                cin>>x;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout<<"Ivesti galima tik sveikuosius skaicius nuo 1 iki 10 arba 0"<<endl;
                    }
                    else if(cin.peek() !=' ' && cin.peek() != '\n'){
                        cin.ignore(10000, '\n');
                        cout<<"Ivesti galima tik sveikuosius skaicius nuo 1 iki 10"<<endl;
                    }
                    else if(x==0){break;}

                    else if(x<1 || x>10){
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout<<"Ivesti galima tik sveikuosius skaicius nuo 1 iki 10"<<endl;
                    }
                    tmp.nd.push_back(x);
                    tmp.suma+=x;
            }
            cout<<"Ivesk egzamino pazymi nuo 1 iki 10"<<endl;
            while (true){
            cin>>tmp.egz;
            if(cin.fail()|| tmp.egz<1 || tmp.egz>10){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Ivesti galima tik sveikuosius skaicius nuo 1 iki 10"<<endl;
            }
            else if(cin.peek() !=' ' && cin.peek() != '\n'){
                cin.ignore(10000, '\n');
                cout<<"Ivesti galima tik sveikuosius skaicius nuo 1 iki 10"<<endl;
            }
            else{break;}
        }
        A.push_back(tmp);
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    else if(meniu==2){
       cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       while(true){
            tmp.nd.clear();
            tmp.suma=0;
            cout<<"Ivesk studento varda arba paspausk ENTER jei nebenori ivesti daugiau studentu"<<endl;
            getline(cin, tmp.vard);
            if(tmp.vard.empty()){break;}

            cout<<"Ivesk studento pavarde"<<endl;
            getline(cin, tmp.pav);

            cout<<"Ivesk kiek pazymiu gavo uz namu darbus"<<endl;
            while(true){
            cin>>n;
                if(cin.fail()||n<=0){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Ivesti galima tik sveikuosius teigiamus skaicius"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                         cin.ignore(10000, '\n');
                         cout<<"Ivesti galima tik sveikuosius skaicius"<<endl;    
                        }
                else{break;}
            }

            for(long j=0; j<n; j++){
                int pazymys = gen_pazym();
                tmp.nd.push_back(pazymys);
                tmp.suma+=pazymys;
            }
            tmp.egz=gen_pazym();
            A.push_back(tmp);
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       }
    }


    else if(meniu==3){
        skaiciai(n,m);
        A.reserve(m);
        for(int i=0; i<m; i++){
            studentas temp = gen_vrd();
            for(int j=0; j<n; j++){
                int pazymys = gen_pazym();
                temp.nd.push_back(pazymys);
                temp.suma+=pazymys; 
            }
            temp.egz = gen_pazym();
            A.push_back(temp);
            temp.nd.clear();
        }
    }

    else if(meniu==4){
        return 0;
    }


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
   

    int is;
    cout<<"1 - Isvesti su vidurkiu, 2 - Isvesti su mediana"<<endl;
    while(true){
            cin>>is;
                if(cin.fail() ||is<1 || is>2){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Ivesti galima tik skaicius 1 arba 2"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                         cin.ignore(10000, '\n');
                         cout<<"Ivesti galima tik sveikuosius skaicius"<<endl;
                }
                else{break;}
    }
    if(is==1){
         cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<"Galutinis (Vid.)"<<endl;
        cout<<"----------------------------------"<<endl;
        for(int i=0; i<A.size(); i++){
            cout<<left<<setw(15)<<A[i].pav<<setw(15)<<A[i].vard<<fixed<<setprecision(2)<<A[i].gal<<endl;
        }
    }
    if(is==2){
        cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<"Galutinis (Med.)"<<endl;
        cout<<"----------------------------------"<<endl;
        for(int i=0; i<A.size(); i++){
            cout<<left<<setw(15)<<A[i].pav<<setw(15)<<A[i].vard<<fixed<<setprecision(2)<<A[i].gal2<<endl;
        }
    }
}