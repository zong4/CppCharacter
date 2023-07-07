#include "Point.h"
#include "Segment.h"
#include "intersection.h"

int main()
{
    {
        Item* item1 = new Point();
        Item* item2 = new Segment();

        std::cout<<"------------------------------"<<std::endl;
        Register::printSet();
        std::cout<<"------------------------------"<<std::endl;
        Register::printMap();

        delete item1;
        delete item2;
    }

    // add again
    {
        Item* item1 = new Point();
        Item* item2 = new Segment();

        std::cout<<"------------------------------"<<std::endl;
        Register::printSet();
        std::cout<<"------------------------------"<<std::endl;
        Register::printMap();

        delete item1;
        delete item2;
    }

    // intersection
    {
        Item* item1 = new Point();
        Item* item2 = new Segment();

        std::cout<<"------------------------------"<<std::endl;
        bool const b = isIntersection(item1, item2);
        std::cout<<"intersection answer: "<<std::boolalpha<<b<<std::endl;
        std::cout<<"------------------------------"<<std::endl;

        delete item1;
        delete item2;
    }

    return 0;
}