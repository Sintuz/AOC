#include <string>
#include <vector>
#include <iostream>
#include "bag.h"

using namespace std;

vector<Bag> bags;

Bag* getBagIfExists(string color) {
    for(vector<Bag>::iterator i = bags.begin(); i != bags.end(); i++) {
        if(i->getColor()==color) {
            return &*i;
        }
    }
    Bag* b = new Bag(color);
    bags.push_back(*b);
    return b;
}

Bag::Bag(string col) {
    color=col;
    hasBag=false;
    checked=false;
}

string Bag::getColor(void) {
    return color;
}

vector<pair<int, Bag*>>* Bag::getContents(void) {
    return &contents;
}

void Bag::setHasBag(bool h) {
    hasBag=h;
}

void Bag::setChecked(bool c) {
    checked=c;
}

bool Bag::getHasBag() {
    return hasBag;
}

bool Bag::getChecked() {
    return checked;
}

void Bag::addContent(string col, int n) {
    pair<int, Bag*> p = {n, getBagIfExists(col)};
    getContents()->push_back(p);
}

bool Bag::isRoot() {
    return parents.size() == 0;
}

void Bag::addParent(Bag* b) {
    parents.push_back(b);
}