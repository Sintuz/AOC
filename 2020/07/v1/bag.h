#include <string>
#include <vector>

using namespace std;

class ContentBag {

    private:
        string color;
        int num;

    public:
        ContentBag(string col, int n);
        string getColor();
        int getNum();

};

class Bag {

    private:
        string color;
        vector<ContentBag> contents;
        bool hasBag, checked;

    public:
        Bag(string color);
        string getColor();
        vector<ContentBag>* getContents(void);
        void setHasBag(bool h);
        void setChecked(bool c);
        bool getHasBag();
        bool getChecked();
        void addContent(string col, int n);

};

extern vector<Bag> bags;

Bag* findBag(string color);
bool contains(Bag *bag, string color);
