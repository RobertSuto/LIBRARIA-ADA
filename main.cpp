#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class citire_afisare
{
public:
    virtual void citire(istream& ) =0;
    virtual void afisare(ostream&) =0;
    friend istream& operator>>(istream &in, citire_afisare& ob)
    {
        ob.citire(in);
        return in;
    }
    friend ostream& operator<<(ostream &out, citire_afisare& ob)
    {
        ob.afisare(out);
        return out;
    }
};
class Produs: public citire_afisare{
protected:
    double pret;
    int cantitate;
    static int ID;
    int id;
public:
    Produs(): pret(0),cantitate(0){this->ID++;id=ID;}
    Produs(double _pret, int _cantitate): pret(_pret),cantitate(_cantitate){
    this->ID++;
    }
    int getID(){
    return ID;
}


    virtual ~Produs(){};

};
int Produs::ID =0;
class Carte: public Produs{
private:
    string titlu;
    string autori;
public:
    Carte():Produs(),titlu("anonim"),autori({}){};
    Carte(const Carte& c):Produs(c.pret,c.cantitate),titlu(c.titlu),autori(c.autori){}
    Carte& operator=(const Carte& c){
    if (this == &c)
        return *this;
    pret=c.pret;
    cantitate=c.cantitate;
    titlu=c.titlu;
    autori=c.autori;
    }
    void citire(istream&);
    void afisare(ostream&);
    string getTitlu(){return titlu;}


    ~Carte(){};
};
void Carte::citire(istream& in)
{
    cout<<"Pret :";in>> pret;
    cout<<"Cantitate :";in>> cantitate;
    cout<<"Introduceti autorii:"; in>>autori;
    cout<<"titlu: ";in>>titlu;
}
void Carte::afisare(ostream& out)
{
    out<<"ID: "<<id;
    out<<"Pret :"<<pret;
    out<<"Cantitate :"<< cantitate;
    out<<" autorii: "<< autori;
    out<<"titlu: "<<titlu;


}
class DVD : public Produs{
protected:
    int minute;
public:
    DVD():Produs(),minute(0){};
    DVD(double _pret,int _cantitate,int _minute):Produs(_pret,_cantitate),minute(_minute){};
    ~DVD(){};


};
class DVDm :public DVD{
    string titlu;
    string interpreti;
public:
    DVDm():DVD(),titlu("anonim"),interpreti("necunoscuti"){};
    DVDm(double _pret,int _cantitate,int _minute,string _titlu,string _interpreti):DVD(_pret,_cantitate,_minute),titlu(_titlu),interpreti(_interpreti){};
    DVDm(const DVDm& d):DVD(d.pret,d.cantitate,d.minute),titlu(d.titlu),interpreti(d.interpreti){};
    DVDm& operator =(const DVDm& d){
    if(this == &d)
        return *this;
    pret=d.pret;
    cantitate=d.cantitate;
    minute=d.minute;
    titlu=d.titlu;
    interpreti=d.interpreti;
    return *this;

    }
    ~DVDm(){};
    void citire(istream&);
    void afisare(ostream&);
};
void DVDm::citire(istream& in)
{
    cout<<"Pret :"; in>>pret;
    cout<<"Cantitate :"; in>>cantitate;
    cout<<"Minute :"; in>>minute;
    cout<<"Titlu :"; in>>titlu;
    cout<<"Interpreti :"; in>>interpreti;

}
void DVDm::afisare(ostream& out)
{
    out<<"ID :"<<id;
    out<<"Durata "<< minute;
    out<<"Titlu :"<< titlu;
    out<<"Interpreti :"<<interpreti;
    out<<"Pret :"<<pret;
    out<<"Cantitate :"<<cantitate;
}
class DVDf :public DVD{
    string titlu;
    string gen;
public:
    DVDf():DVD(),titlu("anonim"),gen("necunoscut"){};
    DVDf(double _pret,int _cantitate,int _minute,string _titlu,string _gen):DVD(_pret,_cantitate,_minute),titlu(_titlu),gen(_gen){};
    DVDf(const DVDf& d):DVD(d.pret,d.cantitate,d.minute),titlu(d.titlu),gen(d.gen){};
    DVDf& operator =(const DVDf& d){
    if(this == &d)
        return *this;
    pret=d.pret;
    cantitate=d.cantitate;
    minute=d.minute;
    titlu=d.titlu;
    gen=d.gen;
    return *this;

    }


    ~DVDf(){};
void citire(istream&);
void afisare(ostream&);
};
void DVDf::citire(istream& in)
{
    cout<<"Minute :"; in>>minute;
    cout<<"Titlu :"; in>>titlu;
    cout<<"Gen :"; in>>gen;
}
void DVDf::afisare(ostream& out)
{
    out<<"Durata "<< minute;
    out<<"Titlu :"<< titlu;
    out<<"Gen :"<<gen;
}
class Obiecte: public Produs{
protected:
    string denumire;
public:
    Obiecte():Produs(),denumire("necunoscuta"){}
    Obiecte(string _denumire,double _pret,int _cantitate):Produs(_pret,_cantitate),denumire(_denumire){}
    ~Obiecte(){};
};
class fig: public Obiecte{
    string categoria;
    string brand;
    string material;
public:
    fig(): Obiecte(),categoria("unkown"),brand("unkown"),material("unkown"){};
    fig(string _categoria,string _brand, string _material,string _denumire,double _pret,int _cantitate):Obiecte(_denumire,_pret,_cantitate),categoria(_categoria),brand(_brand),material(_material){};
    fig(const fig& f){
    categoria=f.categoria;
    brand=f.brand;
    material=f.material;
    denumire=f.denumire;
    pret=f.pret;
    cantitate=f.cantitate;
    }
    fig& operator =(const fig& f)
    {
        if (this==&f)
            return *this;
        categoria=f.categoria;
        brand=f.brand;
        material=f.material;
        denumire=f.denumire;
        pret=f.pret;
        cantitate=f.cantitate;
    }
void citire(istream&);
void afisare(ostream&);
};
void fig::citire(istream& in){
    cout<<"Pret :"; in>>pret;
    cout<<"Cantitate :"; in>>cantitate;
    cout<<"denumire :"; in>>denumire;
    cout<<"categoria :"; in>>categoria;
    cout<<"brand :"; in>>brand;
    cout<<"material :"; in>>material;
}
void fig::afisare(ostream& out){
    out<<"Pret :" <<pret;
    out<<"Cantitate :" <<cantitate;
    out<<"denumire :" <<denumire;
    out<<"categoria :"<<categoria;
    out<<"brand :"<<brand;
    out<<"material :"<<material;



}
class poster: public Obiecte{
    string marime;
public:
    poster():Obiecte(),marime("unkown"){}
    poster(string _marime,string _denumire,double _pret,int _cantitate):Obiecte(_denumire,_pret,_cantitate),marime(_marime){};
    poster(const poster& p){

    marime=p.marime;
    denumire=p.denumire;
    pret=p.pret;
    cantitate=p.cantitate;
    }
    poster& operator =(const poster& p)
    {
        if (this==&p)
            return *this;
        denumire=p.denumire;
        pret=p.pret;
        cantitate=p.cantitate;
        marime=p.marime;
    }
    void citire(istream&);
    void afisare(ostream&);

};
void poster::citire(istream& in){
    cout<<"Pret :"; in>>pret;
    cout<<"Cantitate :"; in>>cantitate;
    cout<<"denumire :"; in>>denumire;
    cout<<"marime :"; in>>marime;
}
void poster::afisare(ostream& out){
    out<<"Pret :" <<pret;
    out<<"Cantitate :" <<cantitate;
    out<<"denumire :" <<denumire;
    out<<"marime :"<<marime;
}

class Manager{
    vector<Produs*> produse;
    static Manager* instance;
    Manager() {}
    Manager(const Manager& ob) = delete;// si liniile acestea cu delete tot din laborator<3
    Manager(Manager&& ob) noexcept = delete;
    Manager& operator=(const Manager& ob) = delete;
    Manager& operator=(Manager&& ob) = delete;
public:
    static Manager* getInstance() {
        if (instance == nullptr) return new Manager();
        return instance;
    }

    void citireProd(){
        cout<<"cate produse?\n";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"Ce produs doriti sa adaugati?";
            int nr;
            cout<<"1.Carte/2.DVDMUZICA/3.DVDFILM/4.Figurina/5.Poster\n";
            cin>>nr;
            if (nr==1){
                Produs* p=new Carte();
                cin>>*p;
                produse.push_back(p);
            }
            else if (nr==2){
                Produs* p=new DVDm();
                cin>>*p;
                produse.push_back(p);

            }
            else if (nr==3){
                Produs* p=new DVDf();
                cin>>*p;
                produse.push_back(p);

            }
            else if (nr==4){
                Produs* p=new poster();
                cin>>*p;
                produse.push_back(p);
            }
            else if (nr==3){
                Produs* p=new fig();
                cin>>*p;
                produse.push_back(p);
            }


    }
    }
    void afisareProd()
    {
        for(int i=0;i<produse.size();i++)
        {
            cout<<*(produse[i])<<endl;
        }
    }
    void cauta()
    {
        cout<<"Scrie titlu:";
        string s;
        cin>>s;
        for(int i=0;i<produse.size();i++){
            if (dynamic_cast<Carte*>(produse[i])){
               if (dynamic_cast<Carte*>(produse[i])->getTitlu()==s)
                    cout<<*produse[i];
                    else cout<<"NU AM GASIT";
                    }
                else
                    cout<<"NU AM GASIT CARTI";


        }
    }
};
Manager* Manager::instance = nullptr;


int main()
{
    int var;
    Manager* M = M->getInstance();
    while (1){
        cout<<"1.Adaugare/2.Afisare/3.Cauta dupa titlu cartea\n";
        cin>>var;
        if (var==1)M->citireProd();
    else if (var==2)M->afisareProd();
    else if (var==3)M->cauta();

    }

    return 0;
}
