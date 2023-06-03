#include "MagicalContainer.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace ariel;
 
  
 MagicalContainer::AscendingIterator::AscendingIterator( MagicalContainer container){
        elements = container.getElements();
        
        index = 0;

     // Sort the elements in ascending order
    std::sort(elements.begin(), elements.end());
    }
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator& ascIter){
        elements = ascIter.elements;
        index = ascIter.index;
    }
    //~ AscendingIterator::AscendingIterator() = default;

   int * MagicalContainer::AscendingIterator::begin() {
         //AscendingIterator temp(*this);
    return 0;
}

  int * MagicalContainer::AscendingIterator::end(){
    //MagicalContainer mc;

   //AscendingIterator temp(*this);
    return 0;
}
    int MagicalContainer::AscendingIterator::operator++(){
        if(index<elements.size() -1){
        index++;
        }
        return elements[index];
    }
    int MagicalContainer::AscendingIterator::operator--(){
        index--;
        return elements[index];
    }
    int MagicalContainer::AscendingIterator::operator*(){
        return elements[index];
    }
    bool MagicalContainer::AscendingIterator::operator!=(int element){
        if (elements[index] != element){
            return true;
        }
        return false;
    }
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator&ascIter){
        if(elements[index]!=ascIter.elements[index]){
            return true;
        }
        return false;
    }
    bool MagicalContainer::AscendingIterator::operator==(int element){
        if (elements[index] == element){
            return true;
        }
        return false;
    }
    bool MagicalContainer::AscendingIterator::operator>(int element){
        if (elements[index] > element){
            return true;
        }
        return false;
    }
    bool MagicalContainer::AscendingIterator::operator<(int element){
        if (elements[index] < element){
            return true;
        }
        return false;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &ascIter){
        elements = ascIter.elements;
        index = ascIter.index;
        return *this;
    }




    //////////////////////////////////////////////////////////////////////


    // Helper function to check if a number is prime
bool isPrime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

MagicalContainer::PrimeIterator::PrimeIterator( MagicalContainer container){
        elements = container.getElements();
        
        index = 0;

    // Filter out non-prime numbers
    elements.erase(remove_if(elements.begin(), elements.end(), [](int num) { return !isPrime(num); }), elements.end());
    }
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator& ascIter){
        elements = ascIter.elements;
        index = ascIter.index;
    }
    //~ PrimeIterator::PrimeIterator() = default;

    int * MagicalContainer::PrimeIterator::begin() {
    return &elements[0];
}

  int * MagicalContainer::PrimeIterator::end(){
    return &elements[elements.size()];
}
    int MagicalContainer::PrimeIterator::operator++(){
        if(index<elements.size() -1){
        index++;
        }
        return elements[index];
    }
    int MagicalContainer::PrimeIterator::operator--(){
        index--;
        return elements[index];
    }
    int MagicalContainer::PrimeIterator::operator*(){
        return elements[index];
    }
    bool MagicalContainer::PrimeIterator::operator!=(int element){
        if (elements[index] != element){
            return true;
        }
        return false;
    }
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator&ascIter){
        if(elements[index]!=ascIter.elements[index]){
            return true;
        }
        return false;
    }
    bool MagicalContainer::PrimeIterator::operator==(int element){
        if (elements[index] == element){
            return true;
        }
        return false;
    }
    bool MagicalContainer::PrimeIterator::operator>(int element){
        if (elements[index] > element){
            return true;
        }
        return false;
    }
    bool MagicalContainer::PrimeIterator::operator<(int element){
        if (elements[index] < element){
            return true;
        }
        return false;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &ascIter){
        elements = ascIter.elements;
        index = ascIter.index;
        return *this;
    }



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////


     MagicalContainer::SideCrossIterator::SideCrossIterator( MagicalContainer container){
        elements = container.getElements();
        
        index = 0;

      
    }
     MagicalContainer::SideCrossIterator::SideCrossIterator(const  MagicalContainer::SideCrossIterator& ascIter){
        elements = ascIter.elements;
        index = ascIter.index;
    }
    //~ SideCrossIterator::SideCrossIterator() = default;

    int *  MagicalContainer::SideCrossIterator::begin() {
    return &elements[0];
}

  int *  MagicalContainer::SideCrossIterator::end(){
    return &elements[elements.size()];
}
    int  MagicalContainer::SideCrossIterator::operator++(){
        if(index<elements.size() -1){
        index++;
        }
        return elements[index];
    }
    int  MagicalContainer::SideCrossIterator::operator--(){
        index--;
        return elements[index];
    }
    int  MagicalContainer::SideCrossIterator::operator*(){
        return elements[index];
    }
    bool  MagicalContainer::SideCrossIterator::operator!=(int element){
        if (elements[index] != element){
            return true;
        }
        return false;
    }
    bool  MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator&ascIter){
        if(elements[index]!=ascIter.elements[index]){
            return true;
        }
        return false;
    }
    bool  MagicalContainer::SideCrossIterator::operator==(int element){
        if (elements[index] == element){
            return true;
        }
        return false;
    }
    bool  MagicalContainer::SideCrossIterator::operator>(int element){
        if (elements[index] > element){
            return true;
        }
        return false;
    }
    bool  MagicalContainer::SideCrossIterator::operator<(int element){
        if (elements[index] < element){
            return true;
        }
        return false;
    }
