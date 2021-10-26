// TEST
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <windows.h>

using namespace std;

struct wektory {

    float x,y,z;

};

void wczytaj(wektory &wektor){ // funkcja dostaje oryginal struktury "wektor" i wczytuje jego dane

    cout<<"Podaj pierwsza wspolrzedna wektora: "<<endl;
    cin>>wektor.x;

    cout<<"Podaj druga wspolrzedna wektora: "<<endl;
    cin>>wektor.y;

    cout<<"Podaj trzecia wspolrzedna wektora: "<<endl;
    cin>>wektor.z;

}

void wypisz(wektory wektor){

    cout<<"["<<wektor.x<<",";
    cout<<wektor.y<<",";
    cout<<wektor.z<<"]";
    cout<<endl;
    
}

void iloczynSkalarny(){ // funkcja ma za zadanie obliczyc iloczyn skalarny dwoch wektorow
                        // oraz oznajmic czy sa prostopadle czy tez nie

    wektory wektor1;
    wektory wektor2;

    float IS=0;
    
    cout<<"Podaj pierwsza wspolrzedna wektora 1: "<<endl;
    cin>>wektor1.x;

    cout<<"Podaj druga wspolrzedna wektora 1: "<<endl;
    cin>>wektor1.y;

    cout<<"Podaj trzecia wspolrzedna wektora 1: "<<endl;
    cin>>wektor1.z;

    cout<<"Podaj pierwsza wspolrzedna wektora 2: "<<endl;
    cin>>wektor2.x;

    cout<<"Podaj druga wspolrzedna wektora 2: "<<endl;
    cin>>wektor2.y;

    cout<<"Podaj trzecia wspolrzedna wektora 2: "<<endl;
    cin>>wektor2.z;

    IS = (wektor1.x * wektor2.x) + (wektor1.y * wektor2.y) + (wektor1.z * wektor2.z);

    cout<<"Iloczyn skalarny podanych wektorow wynosi: "<<IS<<endl;

    if(IS == 0){

        cout<<"Wektory sa prostopadle";
    }
    else{
        cout<<"Wektory nie sa prostopadle";
    }

}

void iloczynWektorowy() {// funkcja ma za zadanie obliczyc iloczyn wektorowy dwoch wektorow
                        // oraz oznajmic czy sa rownolegle czy tez nie

    wektory wektor1;
    wektory wektor2;

    wektory IW;
    
    cout<<"Podaj pierwsza wspolrzedna wektora 1: "<<endl;
    cin>>wektor1.x;

    cout<<"Podaj druga wspolrzedna wektora 1: "<<endl;
    cin>>wektor1.y;

    cout<<"Podaj trzecia wspolrzedna wektora 1: "<<endl;
    cin>>wektor1.z;

    cout<<"Podaj pierwsza wspolrzedna wektora 2: "<<endl;
    cin>>wektor2.x;

    cout<<"Podaj druga wspolrzedna wektora 2: "<<endl;
    cin>>wektor2.y;

    cout<<"Podaj trzecia wspolrzedna wektora 2: "<<endl;
    cin>>wektor2.z;

    IW.x = (wektor1.y) * (wektor2.z) - (wektor1.z) * (wektor2.y); 
    IW.y = (wektor1.z) * (wektor2.x) - (wektor1.x) * (wektor2.z); 
    IW.z = (wektor1.x) * (wektor2.y) - (wektor1.y) * (wektor2.x); 

    cout<<"Iloczyn wektorowy podanych wektorow wynosi: ["<<IW.x<<","<<IW.y<<","<<IW.z<<"]"<<endl;

    if(IW.x == 0 && IW.y == 0 && IW.z == 0){

        cout<<"Wektory sa rownolegle"<<endl;
    }
    else{
        cout<<"Wektory nie sa rownolegle"<<endl;
    }


}

int main(){

    bool wyjscie=false;
    string x;

    vector <wektory> v1; // tworzymy vector v1
    wektory w1; // tworzymy strukture wektory

    while(wyjscie==false){ // petla glowna, czyli menu ktore wywoluje sie dopoki nie uzyjemy '-q'
 
        cout<<endl;
        cout<<"-d - dodaj wektor do przestrzeni V"<<endl;
        cout<<"-w - wyswietl"<<endl;
        cout<<"-u - usun"<<endl;
        cout<<"-is - oblicz iloczyn skalarny dwoch wektorow"<<endl;
        cout<<"-iw - oblicz iloczyn wektorowy dwoch wektorow"<<endl;
        cout<<"-q - wyjdz"<<endl;
        cin>>x;

         //---------------------------------MENU GLOWNE----------------------------------

        if(x=="-q"){
            wyjscie=true;
        }

        if(x=="-d"){ 

                wczytaj(w1);
                v1.push_back(w1);
                cout<<"Dodano pomyslnie!"<<endl;

        } //----------------------------------------------------------------------------
 
        if(x=="-w"){

            cout<<"Wszystkie wektory w przestrzeni: "<<endl;

            for (int i = 0; i < v1.size(); i++)
                        {
                            wypisz(v1[i]);
                        }

        } //----------------------------------------------------------------------------
 
        if(x=="-u"){        

            if(v1.size()>0){ // sprawdza rozmiar vectora. Nie robi nic w przypadku gdzie kolektor jest pusty
            cout<<"Usunieto ostatni wektor z przestrzeni."<<endl;
            v1.erase (v1.end()-1);
            }
            else{

                cout<<"Nie ma co usunac."<<endl;

            }
        }//----------------------------------------------------------------------------
 
        if(x=="-is"){
            iloczynSkalarny();
        }//----------------------------------------------------------------------------

        if(x=="-iw"){
            iloczynWektorowy();
        }//----------------------------------------------------------------------------

    }  

    return 0;
}
