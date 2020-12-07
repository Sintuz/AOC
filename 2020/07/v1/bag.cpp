#include <string>
#include <vector>
#include <iostream>
#include "bag.h"

using namespace std;

vector<Bag> bags;

Bag* findBag(string color) {
    for(vector<Bag>::iterator i = bags.begin(); i != bags.end(); i++) {
        if(i->getColor()==color) {
            return &*i;
        }
    }
    throw "Not found bag";
}

bool contains(Bag *bag, string col) {
    vector<ContentBag>* contents = bag->getContents();

    if(!bag->getChecked()) {
        if(contents->size()==0 || bag->getColor()==col) {
            bag->setHasBag(false);
        } else {
            for (vector<ContentBag>::iterator i = contents->begin(); i != contents->end(); i++) {
                if (i->getColor()==col) {
                    //cout << bag->getColor() << endl;
                    bag->setHasBag(true);
                } else {
                    Bag *b = findBag(i->getColor());

                    if(!b->getChecked() && contains(b, col)) {
                        bag->setHasBag(true);
                        //cout << bag->getColor() << endl;
                        break; //find 1st, no need to analyze other ones
                    }
                }
            }
        }
        bag->setChecked(true);
    }
    return bag->getHasBag();
}

ContentBag::ContentBag(string col, int n) {
    color=col;
    num=n;
}

string ContentBag::getColor() {
    return color;
}

int ContentBag::getNum() {
    return num;
}

Bag::Bag(string col) {
    color=col;
    hasBag=false;
    checked=false;
}

string Bag::getColor(void) {
    return color;
}

vector<ContentBag>* Bag::getContents(void) {
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
    ContentBag bag(col, n);
    contents.push_back(bag);
}

