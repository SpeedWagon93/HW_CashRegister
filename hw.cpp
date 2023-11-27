#include <iostream>
#include <string>
#include <list>



class Retailitem
{
    private:
    static unsigned int s_idGenerator;
    unsigned int m_ID;
    std::string m_Name;
    unsigned int m_Quantity;
    float m_Price;
    public:
    
    Retailitem(std::string Name = "unknown", unsigned int Quantity = 0, float Price = 0){m_ID = s_idGenerator++; m_Name = Name; m_Quantity = Quantity; m_Price = Price;};
    unsigned int GetID()const{return m_ID;}
    std::string GetName(){return m_Name;}
    unsigned int GetQuantity(){return m_Quantity;}
    float GetPrice(){return m_Price;}
    void ShowItemInfo()
    {
        std::cout << m_ID << "  " << m_Name << "    " << m_Quantity << "    " << m_Price << std::endl;
    }

    void ShowItem()
    {
        std::cout << m_Name << "    Цена: " << m_Price << std::endl;
    }
};

unsigned int Retailitem::s_idGenerator = 1;

class CashRegister
{
    private:
    std::list<Retailitem> ItemList;

    public:

    void buy_item(Retailitem Item)
    {
        ItemList.push_back(Item);
    }

    float get_total()
    {
        float TotalPrice;
        for (Retailitem i : ItemList)
        {
            TotalPrice += i.GetPrice();
        }
        return TotalPrice;
    }

    void show_items()
    {
        std::cout << "Товары в корзине: " << std::endl;
        for (Retailitem i : ItemList)
        {
            i.ShowItem();
        }
    }

    void clear()
    {
        ItemList.clear();
    }
};

int main()
{
    Retailitem jacket("Jacket", 12, 59.95); //создаю объект
    Retailitem jeans("Jeans", 40, 34.95); //создаю объект
    Retailitem shirt("Shirt", 20, 24.95); //создаю объект
    jacket.ShowItemInfo();
    jeans.ShowItemInfo();
    shirt.ShowItemInfo();
    CashRegister cashRegister;
    cashRegister.buy_item(jacket); //добавляю в корзину пиджак
    cashRegister.buy_item(jeans); // добавляю в корзину джинсы
    std::cout << "Общая сумма покупки: " << cashRegister.get_total() << std::endl; // вывожу общую сумму товаров, добавленных в корзину
    cashRegister.show_items(); // показываю список товаров в корзине
    cashRegister.clear(); // очищаю корзину
    cashRegister.show_items(); // показываю очищенную корзину
}
