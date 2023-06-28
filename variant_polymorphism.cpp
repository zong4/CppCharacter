// variant polymorphism

#include <variant>
#include <vector>
#include <iostream>
#include <chrono>

class Base
{
public:
    Base() {}

    virtual void add() = 0;
};

class Drive1 : public Base
{
public:
    static int num;

public:
    Drive1() {}

    virtual void add() override
    {
        // num += 1;
    }
};

int Drive1::num = 0;

class Drive2 : public Base
{
public:
    static int num;

public:
    Drive2() {}

    virtual void add() override
    {
        // num += 2;
    }
};

int Drive2::num = 0;

int main()
{
    int size = 100;

    // point
    std::vector<Base*> pointVec(size);
    {
        for(int i = 0; i < size/2; i++)
        {
            Base* tmp = new Drive1();
            pointVec[i] = tmp;
        }
        for(int i = size/2; i < size; i++)
        {
            pointVec[i] = new Drive2();

        }
    }

    // variant
    std::vector<std::variant<Drive1, Drive2>> variantVec(size);
    {
        for(int i = 0; i < size/2; i++)
        {
            variantVec[i] = Drive1();
        }
        for(int i = size/2; i < size; i++)
        {
            variantVec[i] = Drive2();
        }
    }

    int time = 10;

    auto start_time = std::chrono::steady_clock::now();
    for(int i = 0; i < time; i++)
    {
        for(auto const& ele : pointVec)
        {
            ele->add();
        }
    }
    auto end_time = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "point(vtb) cast time: " << duration.count() << std::endl;

    start_time = std::chrono::steady_clock::now();
    for(int i = 0; i < time; i++)
    {
        for(auto const& ele : pointVec)
        {
            if(dynamic_cast<Drive1*>(ele))
                ele->add();
            else if(dynamic_cast<Drive2*>(ele))
                ele->add();
        }
    }
    end_time = std::chrono::steady_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "point(dynamic_cast) cast time: " << duration.count() << std::endl;

    auto CallAdd = [](auto& ele) { ele.add(); };

    start_time = std::chrono::steady_clock::now();
    for(int i = 0; i < time; i++)
    {
        for(auto& ele : variantVec)
        {
            // if(std::is_same_v())
            // {
            //     std::get<0>(ele).add();
            // }
            // catch(const std::bad_variant_access& e)
            // {
            //     std::get<1>(ele).add();
            // }
                     
            // ele.add(); // variant is a class
            std::visit(CallAdd, ele);
        }
    }
    end_time = std::chrono::steady_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "variant cast time: " << duration.count() << std::endl;

    return 0;
}