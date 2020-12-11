#include <string>
#include <vector>
#include <utility>

using namespace std;

class Bag {
    private:
        string color;
        vector<pair<int, Bag*>> contents;
        vector<Bag*> parents;
        bool hasBag, checked;

    public:
        Bag(string color);
        string getColor();
        void addContentBag(int n, Bag* bag);
        vector<pair<int, Bag*>>* getContents();
        void addParentBag(Bag* bag);
        vector<Bag*>* getParents();
        void setHasBag(bool c);
        bool getHasBag();
        void setChecked(bool c);
        bool getChecked();
};
