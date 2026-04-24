//
// Created by Rakhimboy Adamboev Muzaffarovich on 24/04/26.
//

#ifndef JNIDEMO_PEOPLE_H
#define JNIDEMO_PEOPLE_H

#include <iostream>

class People {
private:
    std::string name;
    int age;
public:
    People(std::string name, int age);

    virtual ~People() noexcept;

    std::string &getName();

    int getAge() const;

    void sayHi();
};


#endif //JNIDEMO_PEOPLE_H
