#include<iostream>
#include<cmath>

int main()
{
    uint64_t num = 100000000000000;

    // print num
    std::cout<<"num is "<<num<<std::endl;
    
    uint32_t frontNum;
    uint32_t backNum;

    // store the front 32bit of double in frontNum
    frontNum = *(uint32_t*)&num;

    // store the back 32bit of double in backNum
    backNum = *((uint32_t*)&num + 1);

    // print them
    std::cout<<"frontNum is "<<frontNum<<std::endl;
    std::cout<<"backNum is "<<backNum<<std::endl;

    // add frontNum and backNum to a double
    uint64_t newNum = frontNum + backNum * std::pow(2, 32);

    // print the result
    std::cout<<"newNum is "<<newNum<<std::endl;

    std::cout<<"----------------------"<<std::endl;

    // let num left shift 32 bit and store it in backNum
    backNum = num >> 32;

    // store the front 32bit of num in frontNum through the same method
    frontNum = num;

    // print them
    std::cout<<"frontNum is "<<frontNum<<std::endl;
    std::cout<<"backNum is "<<backNum<<std::endl;

    // add frontNum and backNum to a double
    newNum = frontNum + backNum * std::pow(2, 32);

    // print the result
    std::cout<<"newNum is "<<newNum<<std::endl;

    return 0;
}