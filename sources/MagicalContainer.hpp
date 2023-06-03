#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <algorithm>
#include <vector>

using namespace std;
namespace ariel{
    
     // class AscendingIterator;
     // class PrimeIterator;
     //  class SideCrossIterator;

class MagicalContainer
    {
    private:
        std::vector<int> elements;
    public:
      //  using AscendingIterator=ariel::AscendingIterator;
      // using PrimeIterator=ariel::PrimeIterator;
      // using SideCrossIterator=ariel::SideCrossIterator;

        MagicalContainer()=default;
        
        ~MagicalContainer() = default;
        void addElement(int element){
            return elements.push_back(element);
        }
     void removeElement(int element) {
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it != elements.end()) {
        elements.erase(std::next(elements.begin(), std::distance(elements.begin(), it)));
    }
}

        int size() const{
            return elements.size();
        }
  std::vector<int> getElements() {
    return elements;
}

class AscendingIterator{
    private:
        std::vector<int> elements;
        std::vector<int>::size_type index;
    public:
   AscendingIterator( MagicalContainer container);
   AscendingIterator(const AscendingIterator& ascIter);
    ~AscendingIterator() = default;
    int * begin();
    int * end();
    int operator++();
    int operator--();
    int operator*();
    bool operator!=(int element);
    bool operator==(int element);
    bool operator>(int element);
    bool operator<(int element);
   AscendingIterator operator=(const AscendingIterator &ascIter);
    bool operator!=(const AscendingIterator& ascIter); 
};

class PrimeIterator{
    private:
        std::vector<int> elements;
        std::vector<int>::size_type index;
    public:
    PrimeIterator( MagicalContainer container);
    PrimeIterator(const PrimeIterator& ascIter);
    ~PrimeIterator() = default;
    int * begin();
    int * end();
    int operator++();
    int operator--();
    int operator*();
    bool operator!=(int element);
    bool operator==(int element);
    bool operator>(int element);
    bool operator<(int element);
    PrimeIterator operator=(const PrimeIterator &ascIter);
    bool operator!=(const PrimeIterator& ascIter); 
};

class SideCrossIterator{
    private:
        std::vector<int> elements;
        std::vector<int>::size_type index;
    public:
    SideCrossIterator( MagicalContainer container);
    SideCrossIterator(const SideCrossIterator& ascIter);
    ~SideCrossIterator() = default;
    int * begin();
    int * end();
    int operator++();
    int operator--();
    int operator*();
    bool operator!=(int element);
    bool operator==(int element);
    bool operator>(int element);
    bool operator<(int element);
    SideCrossIterator operator=(const SideCrossIterator &ascIter);
    bool operator!=(const SideCrossIterator& ascIter); 
};
    };

}


#endif