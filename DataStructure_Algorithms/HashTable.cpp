#include <iostream>
#include <list>

class Item
{
    private:
        int key;
        std::string value;
    public :Item(){}
    Item(int key, std::string value){this->key = key; this->value = value;}
    std::string getValue(){return value;}
    int getKey(){return key;}
    void setKey(int key){this->key = key;}
    void setValue(std::string value){this->value = value;}
};

class HashTable
{
private:
    int SIZE_OF_BUCKET = 5;
    Item *hashTable;
public:
    HashTable(/* args */){hashTable = new Item[SIZE_OF_BUCKET];};
    ~HashTable(){delete []hashTable;};
    void insertItem(int, std::string);
    int hashing(int key){return key % SIZE_OF_BUCKET;}
    void display();
};

void HashTable::insertItem(int key, std::string value)
{
    int index = hashing(key);
    while (hashTable[index].getValue() != "")
    {
        ++index;
    }
    hashTable[index].setKey(key);
    hashTable[index].setValue(value);
}

void HashTable::display()
{
    for(int i = 0; i < SIZE_OF_BUCKET; ++i)
    {
        std::cout << i <<  " : " << hashTable[i].getKey() << "---->" << hashTable[i].getValue(); 
    }
    std::cout << std::endl;
}

int main()
{
    HashTable hash = HashTable();
    hash.insertItem(11, "Tran Trung Tien");
    hash.insertItem(23, "Tran Thi Phuong Anh");
    hash.insertItem(32, "Tran Thi Thao");
    hash.insertItem(17, "Nguyen Thi Truc");
    hash.insertItem(43, "Nguyen Thi Mai");
    hash.display();
    
    return 0;
}