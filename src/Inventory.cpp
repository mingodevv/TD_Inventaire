#include "Inventory.h"

#include <iostream>

Inventory::Inventory(float maxWeight)
    : maxWeight(maxWeight)
{
}

bool Inventory::AddItem(const Item& item)
{
    if (GetTotalWeight() + item.GetWeight() > maxWeight)
    {
        return false;
    }

    items.push_back(item);
    return true;
}

bool Inventory::RemoveItem(const std::string& name)
{
    for (std::size_t i = 0; i < items.size(); ++i)
    {
        if (items[i].GetName() == name)
        {
            items.erase(items.begin() + i);
            return true;
        }
    }
    return false;
}

float Inventory::GetTotalWeight() const
{
    float total = 0.0f;
    for (const Item& item : items)
    {
        total += item.GetWeight();
    }
    return total;
}

const Item* Inventory::FindMostValuable() const
{
    if (items.empty())
    {
        return nullptr;
    }

    const Item* best = &items[0];
    for (const Item& item : items)
    {
        if (item.GetValue() > best->GetValue())
        {
            best = &item;
        }
    }
    return best;
}

Item* Inventory::FindByName(const std::string& name)
{
    for (Item& item : items)
    {
        if (item.GetName() == name)
        {
            return &item;
        }
    }
    return nullptr;
}

void Inventory::Print() const
{
    std::cout << "Contenu du sac (" << GetTotalWeight() << " / " << maxWeight << " kg) :\n";
    for (const Item& item : items)
    {
        std::cout << "  - " << item.GetName()
                  << " (" << item.GetWeight() << " kg, "
                  << item.GetValue() << " po)\n";
    }
}
