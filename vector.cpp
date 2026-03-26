#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>
#include <fstream>
#include <windows.h>
#include <list>
#include <deque>
#include "funkcijos.h"

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

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int x;
    long n; 
    long m; 
    int meniu; 
    std::vector<studentas> A;
    std::list<studentas> L;
    std::deque<studentas> D;
  
    studentas tmp;
while(true){
    cout<< "1 - ranka\n"
        << "2 - generuoti payžmius\n"
        << "3 - generuoti pažymius, vardus, pavardes\n"
        << "4 - nuskaityti iš failo\n"
        << "5 - generuoti failus\n" 
        << "6 - testas 1 \n"
        << "7 - testas 2 \n"
        << "8 - testas 2 su vector\n"
        << "9 - testas 2 su list\n"
        << "10 - testas 2 su deque\n"
        << "11 - baigti darbą"<<endl;
    while(true){
            cin>>meniu;
                if(cin.fail() ||meniu<1 || meniu>8){
                    cin.clear();
                   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout<<"Įvesti galima tik skaičius nuo 1 iki 11"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout<<"Įvesti galima tik sveikuosius skaičius nuo 1 iki 11"<<endl;
                }
                else{
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;}
        }
    
    if(meniu==1){
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while(true){
            tmp.nd.clear();
            tmp.suma=0;
            cout<<"Įvesk studento vardą arba paspausk ENTER, jei nebenori įvesti daugiau studentų"<<endl;
            getline(cin, tmp.vard);
            if(tmp.vard.empty()){break;}

            cout<<"Įvesk studento pavardę"<<endl;
            getline(cin, tmp.pav);

            cout<<"Įvesk pažymį nuo 1 iki 10 arba 0, jei nori baigti įvedimą"<<endl;
            while(true){
                cin>>x;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout<<"Įvesti galima tik sveikuosius skaičius nuo 1 iki 10 arba 0"<<endl;
                    continue;
                    }
                    else if(cin.peek() !=' ' && cin.peek() != '\n'){
                        cin.ignore(10000, '\n');
                        cout<<"Įvesti galima tik sveikuosius skaičius nuo 1 iki 10"<<endl;
                        continue;
                    }
                    else if(x==0){break;}

                    else if(x<1 || x>10){
                        cout<<"Įvesti galima tik sveikuosius skaičius nuo 1 iki 10"<<endl;
                        continue;
                    }
                    tmp.nd.push_back(x);
                    tmp.suma+=x;
            }
            cout<<"Įvesk egzamino pažymį nuo 1 iki 10"<<endl;
            while (true){
            cin>>tmp.egz;
            if(cin.fail()|| tmp.egz<1 || tmp.egz>10){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"Įvesti galima tik sveikuosius skaičius nuo 1 iki 10"<<endl;
            }
            else if(cin.peek() !=' ' && cin.peek() != '\n'){
                cin.ignore(10000, '\n');
                cout<<"Įvesti galima tik sveikuosius skaičius nuo 1 iki 10"<<endl;
            }
            else{break;}
        }
        A.push_back(tmp);
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        skaiciavimai(A);
        isved(A);
    }

    else if(meniu==2){
       cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       while(true){
            tmp.nd.clear();
            tmp.suma=0;
            cout<<"Įvesk studento vardą arba paspausk ENTER, jei nebenori įvesti daugiau studentų"<<endl;
            getline(cin, tmp.vard);
            if(tmp.vard.empty()){break;}

            cout<<"Įvesk studento pavardę"<<endl;
            getline(cin, tmp.pav);

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

            for(long j=0; j<n; j++){
                int pazymys = gen_pazym();
                tmp.nd.push_back(pazymys);
                tmp.suma+=pazymys;
            }
            tmp.egz=gen_pazym();
            A.push_back(tmp);
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        skaiciavimai(A);
        isved(A);
    }


    else if(meniu==3){
        skaiciai(n,m);
        A.reserve(m);
        for(int i=0; i<m; i++){
            studentas temp = gen_vrd();
            temp.suma = 0;  
            for(int j=0; j<n; j++){
                int pazymys = gen_pazym();
                temp.nd.push_back(pazymys);
                temp.suma+=pazymys; 
            }
            temp.egz = gen_pazym();
            A.push_back(temp);
            temp.nd.clear();
        }
        skaiciavimai(A);
        isved(A);

    }

    else if (meniu == 4){
        try{
            skt(A, "studentai10000.txt");
        }
        catch(const std::exception& e){
            std::cerr<<"Klaida : "<<e.what()<<endl;
            return 1;
        }
        skaiciavimai(A);
        int rik = pasirink();
        rikiav(A,rik);
       
        int m2;
        cout<<"1 - Išvesti į ekraną, 2 - Išvesti į failą"<<endl;
        while(true){
            cin>>m2;
                if(cin.fail() ||m2<1 || m2>2){
                cin.clear();
                cin.ignore(10000, '\n' );
                    cout<<"Įvesti galima tik 1, arba 2"<<endl;
                }
                else if(cin.peek() !=' ' && cin.peek() != '\n'){
                    cin.ignore(10000, '\n');
                    cout<<"Įvesti galima tik sveikuosius skaičius 1, arba 2"<<endl;
                }
                else{break;}
        }
        
        if(m2==1){
            
            //isved(A);
            cout<<left<<setw(15)<<"Pavardė"<<setw(15)<<"Vardas"<<setw(17)<<"Galutinis (Vid.)"<<"Galutinis (Med.)"<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            for(int i=0; i<A.size(); i++){
            cout<<left<<setw(15)<<A[i].pav<<setw(15)<<A[i].vard<<setw(17)<<fixed<<setprecision(2)<<A[i].gal<<fixed<<setprecision(2)<<A[i].gal2<<endl;
        }   
        }
        else if(m2==2){
            // ofstream
            std::ofstream r("rezultatai.txt");
            r<<left<<setw(15)<<"Pavardė"<<setw(15)<<"Vardas"<<setw(17)<<"Galutinis (Vid.)"<<"Galutinis (Med.)"<<endl;
            r<<"-----------------------------------------------------------"<<endl;
            for(int i=0; i<A.size(); i++){
            r<<left<<setw(15)<<A[i].pav<<setw(15)<<A[i].vard<<setw(17)<<fixed<<setprecision(2)<<A[i].gal<<fixed<<setprecision(2)<<A[i].gal2<<endl;
           
        }
            r.close();
        }
    }
    else if(meniu==5){
      failu_kurimas();
    }
    else if(meniu==6){
        tyrimas1();
    }
    else if(meniu==7){
        tyrimas2(A);
    }
    else if(meniu==8){
        // su vektoriais
        tyrimas2_ve(A);

    }
    else if(meniu==9){
        // su list
        //tyrimas2(A);
    }
    else if(meniu==10){
        // su deque
       // tyrimas2(A);
    }
    else if(meniu==11){
        break;
    }
}
}