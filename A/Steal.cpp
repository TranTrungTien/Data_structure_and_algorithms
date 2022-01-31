
#include <iostream>
#include <vector>

struct Item 
{
    unsigned capacity;
    unsigned value;
    Item(unsigned capacities, unsigned values)
    {
        capacity = capacities;
        value = values;
    }
};

float shouldToSteal(Item item)
{
    return static_cast<float>(item.value / item.capacity);
}

void sortItems(std::vector<Item>& items)
{
    unsigned max = items.size();
    for(int i = max - 1; i >= 0; --i)
    {
        for(int j = 0; j < i;++j)
        {
            if(shouldToSteal(items[j]) < shouldToSteal(items[j + 1]))
            {
                Item tmp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = tmp;
            }
        }
    }
}

signed int steal(std::vector<Item>& items, unsigned& bag)
{
    int maxItem = 0;
    auto max= items.size();

    for(unsigned i = 0; i < max ; ++i)
    {
        if(bag >= items[i].capacity)
        {
            ++maxItem;
            bag -= items[i].capacity;
        }
    }
    return maxItem;
}

int main(int argc, char* argv[])
{
    unsigned bag = 10;

    std::vector<Item> items = {
        Item(3, 4), Item(2, 5), Item(6, 4), Item(1, 1), Item(2, 1)
    };

    sortItems(items);

    
    std::cout << "Max items can steal : " << steal(items, bag) << std::endl;
    std::cout << "Remaining free space in bag " << bag << std::endl;

    return EXIT_SUCCESS;
}