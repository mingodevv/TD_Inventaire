#include "Item.h"

Item::Item(std::string name, float weight, int value)
    : name(name), weight(weight), value(value)
{
}

const std::string& Item::GetName() const
{
    return name;
}

float Item::GetWeight() const
{
    return weight;
}

int Item::GetValue() const
{
    return value;
}

void Item::SetValue(int newValue)
{
    value = newValue;
}
