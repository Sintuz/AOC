#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

#include "./bag.h"

void printBagTree(Bag *bag, int depth);
void load();
void found(Bag* i);
Bag* getBag(string color);
void find(vector<pair<int, Bag*>>* toSearch, string toFind);
vector<Bag> bags;


int main() {
    int tot=0;
    string toFind = "shiny gold";
    
    load();

    for(vector<Bag>::iterator i = bags.begin(); i != bags.end(); i++) {
        //cout << i->getColor() << endl;
        //printBagTree(&*i, 1);
    }

    for(vector<Bag>::iterator i = bags.begin(); i != bags.end(); i++) {
        find(i->getContents(), toFind);
    }

    for(vector<Bag>::iterator i = bags.begin(); i != bags.end(); i++) {
        tot+=i->getHasBag();
    }

    cout << tot << endl;

    return 0;
}

void printBagTree(Bag* bag, int depth) {
    vector<pair<int, Bag*>>* contents = bag->getContents();
    if(contents->size()!=0) {
        for(pair<int, Bag*> p : *contents) {
            cout << string(depth*2, ' ') + "- " << p.first << " " << p.second->getColor() << endl;
            printBagTree(p.second, depth+1);
        }
    }
}

void load() {
    char line[200];
    vector<string> in;

    do {
        cin.getline(line, 200);
        if(line[0]!='\0') {
            in.push_back(string(line));
        }
    } while (line[0] != '\0');
    cout << "Loaded " << in.size() << " rules" << endl;

    for(string s : in) {
        bags.push_back(*new Bag(s.substr(0, s.find(" bags contain "))));
    }

    int count = 0;
    for (string s : in) {
        string del = " bags contain ";
        Bag* parent = &bags.at(count++);

        s = s.substr(s.find(del)+del.length(), s.length());                     //get s after " bags contain "
        
        if(s.find("no other bags") == string::npos) {
            size_t pos;
            while ((pos = s.find(", ")) != string::npos) {
                string current = s.substr(0, pos);                              // get part after ", "
                s = s.substr(pos+2, s.length());                                // trim string
                
                int num = atoi(current.c_str());
                current = current.substr(current.find(" ")+1, current.length());                        // trim bag #
                string color = current.substr(0, current.find(" bag"));
                parent->addContentBag(num, getBag(color));
                (&parent->getContents()->back())->second->addParentBag(parent);
            }
            int num = atoi(s.c_str());
            s = s.substr(s.find(" ")+1, s.length());                            // trim bag #
            string color = s.substr(0, s.find(" bag"));
            parent->addContentBag(num, getBag(color));
            (&parent->getContents()->back())->second->addParentBag(parent);
        }
    }
}

/*
light red bags contain 1 bright white bag, 2 muted yellow bags.
dark orange bags contain 3 bright white bags, 4 muted yellow bags.
bright white bags contain 1 shiny gold bag.
muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.
shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.
dark olive bags contain 3 faded blue bags, 4 dotted black bags.
vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.
faded blue bags contain no other bags.
dotted black bags contain no other bags.
*/

void find(vector<pair<int, Bag*>>* toSearch, string toFind) {
    for (auto i = toSearch->begin(); i != toSearch->end(); i++) {
        if (!i->second->getChecked() && i->second->getColor() == toFind) {
            found(i->second);
        }
    }
}

void found(Bag* i) {
    auto parents = i->getParents();
    for (auto j = parents->begin(); j != parents->end(); j++) {
        (*j)->setChecked(true);
        (*j)->setHasBag(true);
        if ((*j)->getParents()->size() > 0) {
            found(*j);
        }
    }
}

Bag* getBag(string color) {
    for (auto i = bags.begin(); i != bags.end(); i++) {
        if (i->getColor() == color) {
            return &*i;
        }
    }
    throw "Bag " + color + " not found.";
}
