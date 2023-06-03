#include "doctest.h"
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;
TEST_CASE("Test Magical Container"){
 MagicalContainer mc;
    mc.addElement(22);
    mc.addElement(-2);
    mc.addElement(27);
    mc.addElement(9);

    //size should be 4
    CHECK(mc.size() == 4);

    CHECK(mc.getElements()[0] == 22);
    CHECK(mc.getElements()[1] == -2);
    CHECK(mc.getElements()[2] == 27);
    CHECK(mc.getElements()[3] == 9);


    //remove element
    CHECK_NOTHROW(mc.removeElement(27));
    CHECK(mc.size() == 3);

    //remove element that does not exist
    CHECK_THROWS(mc.removeElement(27));
    CHECK(mc.size() == 3);

    //remove all elements
    CHECK_NOTHROW(mc.removeElement(22));
    CHECK_NOTHROW(mc.removeElement(-2));
    CHECK_NOTHROW(mc.removeElement(9));
    CHECK(mc.size() == 0);

    //empty can't remove
    CHECK_THROWS(mc.removeElement(22));

    //empty can't get elements
    CHECK_THROWS(mc.getElements());

}


TEST_CASE("Test Ascending Iterator"){
    MagicalContainer mc;
    mc.addElement(22);
    mc.addElement(-2);
    mc.addElement(27);
    mc.addElement(9);

    //size should be 4
    CHECK(mc.size() == 4);

    CHECK(mc.getElements()[0] == 22);
    CHECK(mc.getElements()[1] == -2);
    CHECK(mc.getElements()[2] == 27);
    CHECK(mc.getElements()[3] == 9);

    //test iterator
    MagicalContainer::AscendingIterator it(mc);
    CHECK(it.operator*() == -2);    //first element
    CHECK(it.operator++() == 9); //second element
    CHECK(it.operator++() == 22); //third element
    CHECK(it.operator++() == 27); //fourth element
    CHECK_THROWS(it.operator++()); //out of bounds
    CHECK(it.operator--() == 22); //third element
    CHECK(it.operator--() == 9); //second element
    CHECK(it.operator--() == -2); //first element
    CHECK_THROWS(it.operator--()); //out of bounds
    
    //test == operator , != operator , copy constructor , assignment operator , destructor
    MagicalContainer::AscendingIterator  it1(mc);
    CHECK(it1.operator*() == -2);    //first element
    CHECK(it1.operator++() == 9); //second element
    CHECK(it1.operator++() == 22); //third element
    CHECK(it1.operator++() == 27); //fourth element
    CHECK(!it1.operator==(*it)); //false
    CHECK(it1.operator!=(*it)); //true
     MagicalContainer::AscendingIterator  it4(it1);
    CHECK(it4.operator==(*it1)); //true
    CHECK(it4.operator!=(*it1)); //false
     MagicalContainer::AscendingIterator  it5(mc);
    it5 = it1;
    CHECK(it5.operator==(*it1)); //true
    CHECK(it5.operator!=(*it1)); //false

    //test iterator on container with one element
    MagicalContainer mc3;
    mc3.addElement(22);
     MagicalContainer::AscendingIterator it3(mc3);
    CHECK(it3.operator*() == 22);    //first element
    CHECK_THROWS(it3.operator++()); //out of bounds
    CHECK_THROWS(it3.operator--()); //out of bounds

}

TEST_CASE("Test Prime Iterator"){
    MagicalContainer mc;
    mc.addElement(22);
    mc.addElement(7);
    mc.addElement(-2);
    mc.addElement(27);
    mc.addElement(9);

    //check prime iterator functionality
    MagicalContainer::PrimeIterator it(mc);
    CHECK(it.operator*() == 7);    //first element
    CHECK(it.operator++() == 9); // 7 9
    CHECK(it.operator--() == 7); // 7 9
    CHECK_THROWS(it.operator--()); // no elment less than 7
    CHECK(it.operator++() == 9); // 7 9    
}

TEST_CASE("Test Side Cross Iterator"){
    // side cross takes one from the filrst and one from the end each time
    MagicalContainer mc;
    mc.addElement(22);
    mc.addElement(7);
    mc.addElement(-2);
    mc.addElement(27);
    mc.addElement(9);

    //check side cross iterator functionality
    ariel::MagicalContainer::SideCrossIterator it(mc);
    CHECK(it.operator*() == 22);    //first element
    CHECK(it.operator++() == 9); // 22 9
    CHECK(it.operator++() == 7); // 22 9 7
    CHECK(it.operator++() == 27); // 22 9 7 27
    CHECK(it.operator++() == -2); // 22 9 7 27 -2
    CHECK_THROWS(it.operator++()); // out of bounds
    CHECK(it.operator--() == 27); // 22 9 7 27
    CHECK(it.operator--() == 7); // 22 9 7
    CHECK(it.operator--() == 9); // 22 9
    CHECK(it.operator--() == 22); // 22

}