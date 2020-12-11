#include <string>
#include <vector>
#include <iostream>
#include "bag.h"

using namespace std;

Bag::Bag(string col) {
    color=col;
    hasBag=false;
    checked=false;
}

string Bag::getColor() {
    return color;
}

vector<pair<int, Bag*>>* Bag::getContents() {
    return &contents;
}

void Bag::addContentBag(int n, Bag* bag) {
    pair<int, Bag*> p = {n, bag};
    contents.push_back(p);
}

vector<Bag*>* Bag::getParents() {
    return &parents;
}

void Bag::addParentBag(Bag* bag) {
    parents.push_back(bag);
}

void Bag::setHasBag(bool c) {
    hasBag=c;
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

