#pragma once

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <thread>
using namespace std;

class Toy
{
  string name;
  public:
    explicit Toy(string _name): name(std::move(_name)) {}
    string getName() { return name; }
    ~Toy() = default;
};

///////////////////////////////////////////////////

/*
 * this.getInt() -->> count
 * this.getToy() -->> toy
 * this.assign(SharedPtrToy) -->> this = new SharedPtrToy
 * this.itDelete() -->> remove minor pointer
 * this.reset() -->> remove main pointer
 */

class SharedPtrToy
{
  private:
    Toy* toy;
    int* count;

  public:
    Toy& getToy() { return *toy; }

    //starts
    SharedPtrToy& operator=(SharedPtrToy& shToy)
    {
        if (this->toy->getName() == shToy.toy->getName()) return *this;
        count = shToy.count;
        toy = shToy.toy;
        return *this;
    }
    SharedPtrToy(): count(nullptr), toy(nullptr) {}
    SharedPtrToy(SharedPtrToy* shToy): toy(shToy->toy) { count = shToy->count; *count+=1; }
    explicit SharedPtrToy(const string& _name): count(new int (0)) {
        toy = new Toy(_name);
    }
    ~SharedPtrToy() {
        if (*count == 0) {
            delete count;
            delete toy;
        }
    }

    //functions
    void itDelete()
    {
        *count -= 1;
        count = nullptr;
        toy = nullptr;
    }
};