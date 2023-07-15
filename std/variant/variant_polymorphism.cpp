// variant polymorphism

#include <variant>
#include <vector>
#include <iostream>
#include <chrono>

class Base
{
public:
    Base() {}
    ~Base() {}

    virtual void add() = 0;
};

class Drive1 : public Base
{
public:
    static int num;

public:
    Drive1() {}
    ~Drive1() {}

    virtual void add() override final
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
    ~Drive2() {}

    virtual void add() override final
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

    int time = 100000;

    {
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
    }

    {
        auto start_time = std::chrono::steady_clock::now();
        for(int i = 0; i < time; i++)
        {
            for(auto const& ele : pointVec)
            {
                if(dynamic_cast<Drive1*>(ele))
                    ele->add();
                else
                    ele->add();
            }
        }
        auto end_time = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "point(dynamic_cast) cast time: " << duration.count() << std::endl;
    }

    {
        auto start_time = std::chrono::steady_clock::now();
        for(int i = 0; i < time; i++)
        {
            for(auto& ele : variantVec)
            {
                if(std::holds_alternative<Drive1>(ele))
                    std::get<0>(ele).add();
                else
                    std::get<1>(ele).add();
            }
        }
        auto end_time = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "variant(holds_alternative) cast time: " << duration.count() << std::endl;
    }

    {
        auto CallAdd = [](auto& ele) { ele.add(); };

        auto start_time = std::chrono::steady_clock::now();
        for(int i = 0; i < time; i++)
        {
            for(auto& ele : variantVec)
            {
                std::visit(CallAdd, ele);
            }
        }
        auto end_time = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "variant(visit) cast time: " << duration.count() << std::endl;
    }

    return 0;
}