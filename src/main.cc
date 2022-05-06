#include <iostream>
#include <memory>
class Base
{
public:
    virtual void say() const;
};
void Base::say() const
{
    std::cerr << "hello, base class\n";
};
class AnotherChild:public Base
{
    public:
    void say()const override final;
};
void AnotherChild::say()const
{
    std::cerr<<"Another child, say hello\n";

};

class AnotherChild1:public AnotherChild
{
    public:
    //void say()const override;
};

class Child final : public Base
{
public:
    void say() const override;
};

void Child::say() const
{
    std::cerr << "hello, child class\n";
};
static int mainRUNS{0};
int main(int x = 0, const char *str = nullptr)
{
    if (str != nullptr)
        printf("main arg: %s", str);
    ++mainRUNS;
    std::unique_ptr<Base> base = std::make_unique<Child>();
    base->say();

    base = nullptr;
    if (base == nullptr)
    {
        base = std::make_unique<Base>();
        base->say();
        base = nullptr;
    };
    std::cerr << "would yyou like to exit  : y/n ?";
    char c{};
    std::cin >> c;
    if (c == 'n')
    {
        printf("Main Runs : %d\n", mainRUNS);

        main(0, "Vishal is here");
    }
    else
    {
        return 0;
    }
}