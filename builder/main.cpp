#include <iostream>
#include <string>
#include <memory>

class User
{
public:
    class Builder
    {
        public:
            explicit Builder(){};
            ~Builder() = default;

            std::shared_ptr<User> build()
            {
                return std::make_shared<User>(*this);
            };

            Builder* name(std::string name)
            {
                name_ = name;
                return this;
            };
            Builder* age(int age)
            {
                age_ = age;
                return this;
            };
            Builder* phone(int phone)
            {
                phone_ = phone;
                return this;
            };

            std::string name_;
            int age_;
            int phone_;
    };

public:
    User(Builder& builder): name_(builder.name_) , age_(builder.age_), phone_(builder.phone_){};
    ~User(){};

    std::string name()
    {
        return name_;
    };
    int age()
    {
        return age_;
    };
    int phone()
    {
        return phone_;
    };

private:
    std::string name_;
    int age_;
    int phone_;
};

int main()
{
    auto userPtr = User::Builder().name("tom")
                                ->age(10)
                                ->phone(110)
                                ->build();
    std::cout << "name:" << userPtr->name() << " ,age:" << userPtr->age() << " ,phone:" << userPtr->phone() <<std::endl;
    return 0;
}
