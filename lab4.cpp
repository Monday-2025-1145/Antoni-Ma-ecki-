#include <iostream>
#include <string>

using namespace std;

class Osoba {
private:
    string imie;
    string nazwisko;
    int wiek;
    string email;
    string telefon;
public:
    void setWiek(int w) { wiek = w; }
    void setImie(string im) { imie = im; }
    void setNazwisko(string nazw) { nazwisko = nazw; }

    void setEmail(string emal) {
        if (emal.find('@') == string::npos) {
            cout << "niepoprawny email" << endl;
            return;
        }
        email = emal;
    }

    void setTelefon(string tel) {
        if (tel.size() != 9) {
            cout << "nie poprawna dlugosc numeru telefonu" << endl;
            return;
        }
        telefon = tel;
    }

    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    int getWiek() { return wiek; }
    string getEmail() { return email; }
    string getTelefon() { return telefon; }
};

class Pracownik {
protected:
    string stanowisko;
    float wynagrodzenie;
};

class Nauczyciel : protected Pracownik {
private:
    string przedmiot;
public:
    void setStanowisko(string w) { stanowisko = w; }
    void setWynagrodzenie(float im) { wynagrodzenie = im; }
    void setPrzedmiot(string nazw) { przedmiot = nazw; }
    
    void pokazDane() {
        cout << "Stanowisko: " << stanowisko << endl;
        cout << "Wynagrodzenie: " << wynagrodzenie << " PLN" << endl;
        cout << "Przedmiot: " << przedmiot << endl;
    }
};

class Administracja : protected Pracownik {
private:
    string dzial;
public:
    void setStanowisko(string w) { stanowisko = w; }
    void setWynagrodzenie(float im) { wynagrodzenie = im; }
    void setDzial(string nazw) { dzial = nazw; }
    
    void pokazDane() {
        cout << "Stanowisko: " << stanowisko << endl;
        cout << "Wynagrodzenie: " << wynagrodzenie << " PLN" << endl;
        cout << "Dzial: " << dzial << endl;
    }
};

int main() {

    Nauczyciel n1;
    n1.setStanowisko("Wykladowca");
    n1.setWynagrodzenie(4500.50);
    n1.setPrzedmiot("Programowanie Obiektowe");
    n1.pokazDane();

    cout << endl;

    Administracja a1;
    a1.setStanowisko("Sekretarka");
    a1.setWynagrodzenie(3200.00);
    a1.setDzial("Kadry");
    a1.pokazDane();

    cout << endl;


    Osoba o1;
    o1.setImie("Jan");
    o1.setNazwisko("Kowalski");
    o1.setTelefon("123456789"); // Musi mieć 9 znaków
    o1.setEmail("jan@poczta.pl"); // Musi mieć @
    
    cout << o1.getImie() << " " << o1.getNazwisko() << ", Tel: " << o1.getTelefon() << endl;

    return 0;
}

