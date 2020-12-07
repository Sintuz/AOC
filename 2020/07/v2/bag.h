#include <string>
#include <vector>
#include <utility>

using namespace std;

class Bag {
    private:
        string color;
        vector<Bag*> parents;
        vector<pair<int, Bag*>> contents;
        bool hasBag, checked;

    public:
        Bag(string color);
        string getColor();
        vector<pair<int, Bag*>>* getContents(void);
        void setHasBag(bool h);
        void setChecked(bool c);
        bool getHasBag();
        bool getChecked();
        void addContent(string col, int n);
        void addParent(Bag* b);
        bool isRoot();

};

extern vector<Bag> bags;

Bag* findBag(string color);
