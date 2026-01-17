#include <iostream>
#include <string>

using namespace std;

// --- ZADANIE 1: SINGLETON ---

class DatabaseConnection {
    static DatabaseConnection* instancja;

    DatabaseConnection() { }

public:
    DatabaseConnection(const DatabaseConnection&) = delete;
    void operator=(const DatabaseConnection&) = delete;

    static DatabaseConnection* getInstance() {
        if (instancja == nullptr) {
            instancja = new DatabaseConnection();
        }
        return instancja;
    }

    void executeQuery(string zapytanie) {
        cout << "Wykonuje SQL: " << zapytanie << endl;
    }
};

DatabaseConnection* DatabaseConnection::instancja = nullptr;

// --- ZADANIE 2: FACTORY METHOD ---

class Vehicle {
public:
    virtual void drive() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void drive() override {
        cout << "Jade autem." << endl;
    }
};

class Bike : public Vehicle {
public:
    void drive() override {
        cout << "Jade rowerem." << endl;
    }
};

class VehicleFactory {
public:
    static Vehicle* stworzPojazd(string typ) {
        if (typ == "auto") return new Car();
        if (typ == "rower") return new Bike();
        return nullptr;
    }
};

// --- ZADANIE 3: BUILDER ---

class Pizza {
    string ciasto, sos, dodatek;
    friend class Builder;

public:
    class Builder;

    Pizza(const Builder& b);

    void display() const {
        cout << "Pizza gotowa: " << ciasto << ", " << sos << ", " << dodatek << endl;
    }

    class Builder {
        friend class Pizza;
        string d = "cienkie";
        string s = "pomidorowy";
        string t = "ser";

    public:
        Builder& setDough(string val) { d = val; return *this; }
        Builder& setSauce(string val) { s = val; return *this; }
        Builder& setTopping(string val) { t = val; return *this; }
        
        Pizza build();
    };
};

Pizza::Pizza(const Builder& b) : ciasto(b.d), sos(b.s), dodatek(b.t) {}

Pizza Pizza::Builder::build() {
    return Pizza(*this);
}

// --- MAIN ---

int main() {
    DatabaseConnection* db1 = DatabaseConnection::getInstance();
    db1->executeQuery("SELECT * FROM studenci");
    cout << "Adresy te same? " << (db1 == DatabaseConnection::getInstance()) << endl;

    Vehicle* v1 = VehicleFactory::stworzPojazd("auto");
    if(v1) v1->drive();
    
    Vehicle* v2 = VehicleFactory::stworzPojazd("rower");
    if(v2) v2->drive();

    Pizza p1 = Pizza::Builder().setDough("grube").setTopping("pieczarki").build();
    p1.display();

    Pizza p2 = Pizza::Builder().setSauce("czosnkowy").build();
    p2.display();

    return 0;
}
