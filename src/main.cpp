#include <iostream>

#include "Inventory.h"
#include "Item.h"

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

void EnchantCopy(Item item, int bonus)
{
    item.SetValue(item.GetValue() + bonus);
}

void Enchant(Item& item, int bonus)
{
    item.SetValue(item.GetValue() + bonus);
}

int main()
{
#ifdef _WIN32
    // Affiche correctement les accents dans la console Windows.
    SetConsoleOutputCP(CP_UTF8);
#endif

    // B.3
    Inventory bag(20.0f);

    bag.AddItem(Item("Épée courte", 3.5f, 40));
    bag.AddItem(Item("Potion de soin", 0.5f, 25));
    bag.AddItem(Item("Bouclier", 6.0f, 55));

    if (!bag.AddItem(Item("Enclume", 15.0f, 10)))
    {
        std::cout << "L'enclume est trop lourde : elle est refusée.\n";
    }

    bag.Print();

    // C.1 et C.2
    Item* sword = bag.FindByName("Épée courte");
    if (sword != nullptr)
    {
        EnchantCopy(*sword, 100);
        std::cout << "Valeur de l'épée après EnchantCopy : " << sword->GetValue() << " po\n";

        Enchant(*sword, 100);
        std::cout << "Valeur de l'épée après Enchant : " << sword->GetValue() << " po\n";
    }

    // C.3
    Item* bow = bag.FindByName("Arc long");
    if (bow == nullptr)
    {
        std::cout << "Pas d'arc long dans le sac.\n";
    }

    // C.4
    if (bag.RemoveItem("Potion de soin"))
    {
        std::cout << "La potion a été retirée.\n";
    }

    const Item* best = bag.FindMostValuable();
    if (best != nullptr)
    {
        std::cout << "Objet le plus précieux : " << best->GetName()
                  << " (" << best->GetValue() << " po)\n";
    }

    bag.Print();

    return 0;
}
