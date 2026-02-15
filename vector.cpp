#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <map>
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::map;
using std::mt19937;


using laik = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> int_dis;


struct studentas{
    std::string vard;
    std::string pav;
    int egz;
    std::vector<double> nd;
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
};

/*std::vector<double> gen_paz(int n){
    std::vector<double> nd;
    mt19937 rnd(static_cast<long unsigned int>(laik::now().time_since_epoch().count()));
    int_dis paskirst(0,9);  

    for(int i=0; i<n; i++){
        nd.push_back(paskirst(rnd)); 
    }
    return nd;
};
int gen_egz(){
    mt19937 rnd(static_cast<long unsigned int>(laik::now().time_since_epoch().count()));
    int_dis paskirst(0,9);  

    return paskirst(rnd); 
};*/
int gen_pazym(){
    mt19937 rnd(static_cast<long unsigned int>(laik::now().time_since_epoch().count()));
    int_dis paskirst(0,9);  

    return paskirst(rnd); 
};
int main(){

    int x;

    int n;  // nd sk
    int m;  //studentu sk
    int meniu; 

    std::vector<studentas> A;
    studentas tmp;

    A.reserve(10);

    cout<<"1 - ranka, 2 - generuoti pazymius, 3 - generuoti pazymius, vardus, pavardes, 4 - baigti darba";
    cin>> meniu;

    cout<<"Ivesk kiek pazymiu gavo uz namu darbus"<<endl;
    cin>>n;
    cout<<"Ivesk studentu skaiciu"<<endl;
    cin>>m;

    if(meniu==1){
        for(int i=0; i<m; i++){
            cout<<"Ivesk studento varda"<<endl;
            cin>>tmp.vard;
            cout<<"Ivesk studento pavarde"<<endl;
            cin>>tmp.pav;
            cout<<"Ivesk "<<n<<" gautus namu darbu pazymius"<<endl;

            for(int j=0; j<n; j++){
                cin>>x;
                tmp.nd.push_back(x);
                tmp.suma+=x;
            }
            cout<<"Ivesk pazymi gauta uz egzamina"<<endl;
            cin>>tmp.egz;
            A.push_back(tmp);
            tmp.nd.clear();
        }
    }


    else if(meniu==2){
        for(int i=0; i<m; i++){
            cout<<"Ivesk studento varda"<<endl;
            cin>>tmp.vard;
            cout<<"Ivesk studento pavarde"<<endl;
            cin>>tmp.pav;
            for(int j=0; j<n; j++){
                tmp.nd[i]=gen_pazym();
                tmp.suma+=tmp.nd[i];
            }
            tmp.egz=gen_pazym();
            A.push_back(tmp);
            tmp.nd.clear();
        }
    }


    else if(meniu==3){
        for(int i=0; i<m; i++){
            studentas temp = gen_vrd();
            for(int j=0; j<n; j++){
                temp.nd[i]=gen_pazym();
                temp.suma+=temp.nd[i];
            }
            temp.egz = gen_pazym();
            A.push_back(temp);
        }
    }

    else if(meniu==4){

    }


    for(int i=0; i<m; i++){
        A[i].vid=(float)A[i].suma/n;

        sort(A[i].nd.begin(), A[i].nd.begin());

        if(n%2==1){
            A[i].med=A[i].nd[n/2];
        }

        else{
            A[i].med=(A[i].nd[n+1/2] + A[i].nd[n/2])/2.0;
        }

        A[i].gal=A[i].vid*0.4+A[i].egz*0.6; 
        A[i].gal2=A[i].med*0.4+A[i].egz*0.6;
    }
   
    //cout<<A[0].vard<<A[0].nd[1];
}