#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

#include "./bag.h"

void printBagTree(Bag *bag, int depth);

int main() {
    char line[200];
    int tot=0;

    do {
        cin.getline(line, 200);

        if(line[0]!='\0') {

            string l=string(line);
            string delim = " bags contain ";

            size_t pos=l.find(delim);

            string color=l.substr(0, pos);

            Bag bag(color);
            bags.push_back(bag);

            l.erase(0, pos+delim.length());                                 // removing color and bag words

            delim = ", ";

            if(l.substr(0,2)!="no") {                                       // checking if there are subBags
                while ((pos = l.find(delim)) != string::npos) {
                    string subBag = l.substr(0, pos);
                    l.erase(0, pos + delim.length());                       // get subBag and erase it

                    int num = atoi(subBag.c_str());
                    subBag.erase(0, subBag.find(" ")+1);                    // removing number

                    string color = subBag.substr(0, subBag.find("bag")-1);  // get color by finding bag position

                    bags.back().addContent(color, num);
                }

                int num = atoi(l.c_str());
                l.erase(0, l.find(" ")+1);

                string color = l.substr(0, l.find("bag")-1);
                bags.back().addContent(color, num);
            }


        }

    } while (line[0] != '\0');

        /*
        cout << i->getColor() << endl;
        printBagTree(bags, &*i, 1);
        */

    for(vector<Bag>::iterator i = bags.begin(); i != bags.end(); i++) {
        //tot+=contains(&*i, "shiny gold");
    }

    for(vector<Bag>::iterator i = bags.begin(); i != bags.end(); i++) {
        cout << i->getColor() << endl;
        printBagTree(&*i, 1);
    }

    cout << tot << endl;

    return 0;
}

void printBagTree(Bag *bag, int depth) {
    vector<pair<int, Bag*>>* contents = bag->getContents();
    if(contents->size()!=0) {
        for(pair<int, Bag*> p : *contents) {
            cout << string(depth*2, ' ') + "- " << p.first << " " << p.second->getColor() << endl;
            printBagTree(p.second, depth+1);
        }//guarda anydesk pri
        //cosa metto?
    }//poi faccio commit
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