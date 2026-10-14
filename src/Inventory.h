#pragma once

#include <string>
#include <vector>

#include "Item.h"

class Inventory
{
public:
    explicit Inventory(float maxWeight);

    bool AddItem(const Item& item);                      // false si le poids max serait dépassé
    bool RemoveItem(const std::string& name);            // false si l'objet n'existe pas
    float GetTotalWeight() const;
    const Item* FindMostValuable() const;                // nullptr si l'inventaire est vide
    Item* FindByName(const std::string& name);           // nullptr si introuvable
    void Print() const;

private:
    float maxWeight;
    std::vector<Item> items;
};
