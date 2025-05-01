#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//Function for printing the whole shopping list
void print(const vector<string>& ShoppingList)
{
    cout << "\nShopping List: ";
    
    for(auto& item : ShoppingList)
    {
        cout << "\n - " << item;
    }
}

int main()
{
    //Creating the shopping list vector
    vector<string> ShoppingList;
    
    //Adding the products to the list
    ShoppingList.push_back("wine");
    ShoppingList.push_back("beetroot");
    ShoppingList.push_back("bananas");
    ShoppingList.push_back("sugar");
    ShoppingList.push_back("chocolate");
    ShoppingList.push_back("carrot");
    
    //Printing the whole shopping list
    print(ShoppingList);
    
    //Printing the last product in the shopping list
    cout << "\nThe last item in the shopping list: " << ShoppingList.back();
    //Removing the last item
    ShoppingList.pop_back();
    
    //Inserting the coffee as the third element in the vector
    ShoppingList.insert(ShoppingList.begin() + 2, "coffee");
    
    //Printing the shopping list after deleting last item and inserting coffee as the third item 
    print(ShoppingList);
    
    //Writing a loop for finding the sugar product and replacing it with candy
    for(auto& item : ShoppingList)
    {
        if(item == "sugar")
        {
            item = "candy";
            break;
        }
            
    }
    
    //Printing the list after replacement
    print(ShoppingList);

    //Finding chocolate and deleting it
    for(auto& item : ShoppingList)
    {
        if(item == "chocolate")
        {
            item.erase();
            break;
        }
    }
    
    //Printing after erasing the chocolate
    print(ShoppingList);
    
    //Sorting the shopping list
    sort(ShoppingList.begin(), ShoppingList.end());
    
    //Printing the shopping list after sorting
    cout << "\nShopping List after being sorted: ";
    print(ShoppingList);
    

    return 0;
}