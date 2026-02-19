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
using std::getline;

using laik = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> int_dis;

struct studentas{
    std::string vard;
    std::string pav;
    int egz;
    int* nd=nullptr;
    long nd_sk =0;
    double vid;
    double med;
    double suma=0;
    double gal;
    double gal2;
};

int gen_pazym(){
    mt19937 rnd(static_cast<long unsigned int>(laik::now().time_since_epoch().count()));
    int_dis paskirst(1,10);  

    return paskirst(rnd); 
};

void skaiciai(int &n, int &m){
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

int main(){

    int x;
    int n;  // nd sk
    int m;  //studentu sk
    int meniu; 
    studentas* A = nullptr;
    long stud_sk = 0;

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
    if(meniu==4){
        return 0;
    }

    if(meniu==1){
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while(true)
        {
            studentas tmp;
            cout<<"Ivesk studento varda arba paspausk ENTER jei nebenori ivesti daugiau studentu"<<endl;
            getline(cin, tmp.vard);
            if(tmp.vard.empty()){break;}

            cout<<"Ivesk studento pavarde"<<endl;
            getline(cin, tmp.pav);

            int* ndtmp = nullptr;
            int sktmp =0;
            cout<<"Ivesk pazymi nuo 1 iki 10 arba 0 jei nori baigti ivedineti pazymius"<<endl;
            while(true){
                int pazymys;
                cin>>pazymys;
                 if(cin.fail()){
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout<<"Ivesti galima tik sveikuosius skaicius nuo 1 iki 10 arba 0"<<endl;
                    }
                    else if(cin.peek() !=' ' && cin.peek() != '\n'){
                        cin.ignore(10000, '\n');
                        cout<<"Ivesti galima tik sveikuosius skaicius nuo 1 iki 10"<<endl;
                    }
                    else if(pazymys==0){break;}

                    else if(pazymys<1 || pazymys>10){
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout<<"Ivesti galima tik sveikuosius skaicius nuo 1 iki 10"<<endl;
                    }
                    int* la = new int [sktmp +1];
                    for(int i=0; i<sktmp; i++){
                        la[i]=ndtmp[i];
                    }
                    la[sktmp]=pazymys;
                    delete[] ndtmp;
                    ndtmp = la;
                    sktmp++;
            }
            tmp.nd = ndtmp;
            tmp.nd_sk=sktmp;
            tmp.suma= 0;
            for(int i=0; i<sktmp; i++){
                tmp.suma += tmp.nd[i];
            }
            
            cout<<"Ivesk pazymi gauta uz egzamina"<<endl;
                while(true){
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
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            studentas* stud = new studentas[stud_sk + 1];
            for(int i=0; i<stud_sk; i++){
                stud[i]= A[i];
            }
            stud[stud_sk]=tmp;
            delete[] A;
            A=stud;
            stud_sk++;

        }
    }
    else if(meniu==2){
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while(true){
            studentas tmp;
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
            tmp.nd = new int [n];
            tmp.nd_sk = n;
            for(int i=0; i<n; i++){
                int pazymys = gen_pazym();
                tmp.nd[i]=pazymys;
                tmp.suma+=pazymys;
            }
            tmp.egz=gen_pazym();
            cin.ignore(10000, '\n');

            studentas* st = new studentas[stud_sk + 1];
            for(int i=0; i<stud_sk; i++){
                st[i]= A[i];
            }
            st[stud_sk]=tmp;
            delete[] A;
            A=st;
            stud_sk++;   
        }
    }
    
    else if(meniu==3){
        skaiciai(n,m);
        A=new studentas[m];
        stud_sk=m;
        for(int i=0; i<m; i++){
            A[i] = gen_vrd();
            A[i].suma=0;
            A[i].nd= new int[n];
            A[i].nd_sk=n;
            for(int j=0; j<n; j++){
                int pazymys=gen_pazym();
                A[i].nd[j] = pazymys;
                A[i].suma+=pazymys;
            }
            A[i].egz=gen_pazym();
        }
    }


     for(int i=0; i<stud_sk; i++){
        int n= A[i].nd_sk;
        if(n>0){
            A[i].vid=(float)A[i].suma/n;
            std::sort(A[i].nd, A[i].nd + n);
            if(n%2==1){
            A[i].med=A[i].nd[n/2];
            }
            else{
                A[i].med=(A[i].nd[n/2-1] + A[i].nd[n/2])/2.0;
            }
        }
        else {
            A[i].vid = 0;
            A[i].med = 0;
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
        for(int i=0; i<stud_sk; i++){
            cout<<left<<setw(15)<<A[i].pav<<setw(15)<<A[i].vard<<fixed<<setprecision(2)<<A[i].gal<<endl;
        }
    }
    if(is==2){
        cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<"Galutinis (Med.)"<<endl;
        cout<<"----------------------------------"<<endl;
        for(int i=0; i<stud_sk; i++){
            cout<<left<<setw(15)<<A[i].pav<<setw(15)<<A[i].vard<<fixed<<setprecision(2)<<A[i].gal2<<endl;
        }
    }


    for(int i=0; i<stud_sk; i++){
        delete[] A[i].nd;
    }
    delete[] A;
}
