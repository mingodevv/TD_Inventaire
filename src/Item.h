#pragma once
#include <string>

class Item
{
public:
    Item(std::string name, float weight, int value);

    const std::string& GetName() const;
    float GetWeight() const;
    int GetValue() const;

    void SetValue(int newValue);

private:
    std::string name;
    float weight;
    int value;
};
