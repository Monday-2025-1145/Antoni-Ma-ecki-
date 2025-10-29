#include <iostream>


using namespace std;

class Osoba{
    private:
        string imie;
        string nazwisko;
        int wiek;
        string email;
        string telefon;
    public:

    void setWiek(int w){ wiek=w;}
    void setImie(string im){ imie=im;}
    void setWiek(string nazw){ nazwisko=nazw;}
    void setEmail(string emal){ 
        if(emal.find('@')==string::npos)
        {    cout<<"niepoprawny email"<<endl;
            return; 
        }
        email=emal;
    }
    void setWiek(string tel){ 
        if(tel.size()!=9){
            cout<<"nie poprawna dlugosc numeru telefonu"<<endl;
            return;
        }
        telefon=tel;
    }

    string getImie(){return imie;}
    string getNazwisko(){return nazwisko;}
    int getWiek(){return wiek;}
    string getEmail(){return email;}
    string getTelefon(){return telefon;}
};


class Pracownik{
    protected:
        string stanowisko;
        float wynagrodzenie;
};
class Nauczyciel: protected Pracownik{
    private:
        string przedmiot;
    public:
        void setStanowisko(string w){ stanowisko=w;}
        void setWynagrodzenie(float im){ wynagrodzenie=im;}
        void setPrzedmiot(string nazw){ przedmiot=nazw;}
        void pokazDane(){
            cout<<stanowisko<<endl<<wynagrodzenie<<endl<<przedmiot<<endl;
        }
};

class Administracja: protected Pracownik{
    private: 
        string dzial;
    public:
        void setStanowisko(string w){ stanowisko=w;}
        void setWynagrodzenie(float im){ wynagrodzenie=im;}
        void setDzial(string nazw){ dzial=nazw;}
        void pokazDane(){
            cout<<stanowisko<<endl<<wynagrodzenie<<endl<<dzial<<endl;

        }

};

int main(){



    return 0;
}