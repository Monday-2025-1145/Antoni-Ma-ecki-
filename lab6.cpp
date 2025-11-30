#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Pojazd {
public:
    virtual void przyspiesz() {
        cout << "Pojazd przyspiesza" << endl;
    }

    virtual void zatrzymaj() {
        cout << "Pojazd zatrzymuje się" << endl;
    }

    virtual ~Pojazd() {}
};

class Samochod : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Samochód przyspiesza: Brum brum!" << endl;
    }

    void zatrzymaj() override {
        cout << "Samochód zatrzymuje się." << endl;
    }
};

class Rower : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Rower przyspiesza: Pedałuję szybciej!" << endl;
    }

    void zatrzymaj() override {
        cout << "Rower zatrzymuje się." << endl;
    }
};

class Motocykl : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Motocykl przyspiesza: Wrrrum!" << endl;
    }

    void zatrzymaj() override {
        cout << "Motocykl zatrzymuje się." << endl;
    }
};

class Skuter : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Skuter przyspiesza: Bzzzzzt!" << endl;
    }

    void zatrzymaj() override {
        cout << "Skuter zatrzymuje się." << endl;
    }
};

int main() {
    vector<unique_ptr<Pojazd>> pojazdy;

    pojazdy.push_back(make_unique<Samochod>());
    pojazdy.push_back(make_unique<Rower>());
    pojazdy.push_back(make_unique<Motocykl>());
    pojazdy.push_back(make_unique<Skuter>());

    for (const auto& pojazd : pojazdy) {
        pojazd->przyspiesz();
        pojazd->zatrzymaj();
        cout << endl;
    }

    return 0;
}