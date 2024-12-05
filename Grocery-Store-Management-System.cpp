#include<iostream>
#include<string>
using namespace std;

// Base class to manage item details
class ItemDetails {
   protected:
   int iteam_id;  // Item ID
   string iteam_name;  // Item name
   double cost_price;  // Cost price of item
   double selling_price;  // Selling price of item
   int no_of_iteams;  // Number of items

   // Arrays to store details of multiple items
   string iteamname[100];
   int iteamid[100];
   double costprice[100];
   double sellingprice[100];
   int quantity[100];

   public:
   // Method to add items to the inventory
   void add_iteam() {
       cout << "Number of products to be added: ";
       cin >> no_of_iteams;

       for (int i = 0; i < no_of_iteams; i++) {
           cout << "Enter details for item " << i + 1 << ":" << endl;
           cout << "Item ID: ";
           cin >> iteam_id;
           iteamid[i] = iteam_id;

           cout << "Item Name: ";
           cin >> iteam_name;
           iteamname[i] = iteam_name;

           cout << "Cost Price: ";
           cin >> cost_price;
           costprice[i] = cost_price;

           cout << "Selling Price: ";
           cin >> selling_price;
           sellingprice[i] = selling_price;

           cout << "Quantity: ";
           cin >> quantity[i];

           cout << endl;
       }
   }

   // Method to display all items in the inventory
   void displayiteams() {
    
       for (int i = 0; i < no_of_iteams; i++) {
           cout << "Item " << i + 1 << " Details:" << endl;
           cout << "ID: " << iteamid[i] << endl;
           cout << "Name: " << iteamname[i] << endl;
           cout << "Cost Price: " << costprice[i] << endl;
           cout << "Selling Price: " << sellingprice[i] << endl;
           cout << "Quantity: " << quantity[i] << endl;
           cout << "-------------------------------" << endl;
       }
   }

   // Method to update item details by ID
   void update_iteam() {
       cout << "Enter the item ID to update: ";
       cin >> iteam_id;

       for (int i = 0; i < no_of_iteams; i++) {
           if (iteamid[i] == iteam_id) {
               cout << "Enter new details for item ID " << iteam_id << ":" << endl;

               cout << "New Name: ";
               cin >> iteam_name;
               iteamname[i] = iteam_name;

               cout << "New Cost Price: ";
               cin >> cost_price;
               costprice[i] = cost_price;

               cout << "New Selling Price: ";
               cin >> selling_price;
               sellingprice[i] = selling_price;

               cout << "New Quantity: ";
               cin >> quantity[i];

               cout << "Item updated successfully!" << endl;
               return;
           }
       }
       cout << "Item ID not found!" << endl;
   }

   // Method to delete an item from the inventory by ID
   void delete_iteam() {
       cout << "Enter the item ID to delete: ";
       cin >> iteam_id;

       for (int i = 0; i < no_of_iteams; i++) {
           if (iteamid[i] == iteam_id) {
               // Shift remaining items one position up to fill the gap
               for (int j = i; j < no_of_iteams - 1; j++) {
                   iteamid[j] = iteamid[j + 1];
                   iteamname[j] = iteamname[j + 1];
                   costprice[j] = costprice[j + 1];
                   sellingprice[j] = sellingprice[j + 1];
                   quantity[j] = quantity[j + 1];
               }
               no_of_iteams--;
               cout << "Item deleted successfully!" << endl;
               return;
           }
       }
       cout << "Item ID not found!" << endl;
   }

   // Method to search for an item by ID or name
   void search_iteam() {
       int choice;
       cout << "Search by: \n1. Item ID \n2. Item Name\nEnter your choice: ";
       cin >> choice;

       if (choice == 1) { 
           cout << "Enter the item ID to search: ";
           cin >> iteam_id;

           for (int i = 0; i < no_of_iteams; i++) {
               if (iteamid[i] == iteam_id) {
                   cout << "Item " << i + 1 << " Details:" << endl;
                   cout << "ID: " << iteamid[i] << endl;
                   cout << "Name: " << iteamname[i] << endl;
                   cout << "Cost Price: " << costprice[i] << endl;
                   cout << "Selling Price: " << sellingprice[i] << endl;
                   cout << "Quantity: " << quantity[i] << endl;
                   cout << "-------------------------------" << endl;
                   return;
               }
           }
           cout << "Item ID not found!" << endl;

       } else if (choice == 2) {
           string name;
           cout << "Enter the item name to search: ";
           cin >> name;

           for (int i = 0; i < no_of_iteams; i++) {
               if (iteamname[i] == name) {
                   cout << "Item " << i + 1 << " Details:" << endl;
                   cout << "ID: " << iteamid[i] << endl;
                   cout << "Name: " << iteamname[i] << endl;
                   cout << "Cost Price: " << costprice[i] << endl;
                   cout << "Selling Price: " << sellingprice[i] << endl;
                   cout << "Quantity: " << quantity[i] << endl;
                   cout << "-------------------------------" << endl;
                   return;
               }
           }
           cout << "Item Name not found!" << endl;

       } else {
           cout << "Invalid choice!" << endl;
       }
   }
};

// Derived class to handle billing and profit calculation
class BillingOperations : public ItemDetails {
   private:
   double profit = 0.0;  // Total profit
   int total_sold = 0;   // Total items sold

   public:
   // Method to sell an item and update inventory and profit
   void sell_item() {
       int id, qty;
       cout << "Enter the item ID to sell: ";
       cin >> id;

       for (int i = 0; i < no_of_iteams; i++) {
           if (iteamid[i] == id) {
               cout << "Enter quantity to sell: ";
               cin >> qty;

               if (qty <= quantity[i]) {
                   quantity[i] -= qty;  // Reduce quantity
                   double profit_per_item = sellingprice[i] - costprice[i];
                   profit += profit_per_item * qty;
                   total_sold += qty;

                   cout << "Sold " << qty << " units of " << iteamname[i] << "." << endl;
                   cout << "Profit from this sale: $" << profit_per_item * qty << endl;
                   cout << "\n\n************ SuperMart ************\n";
                   cout << "Item ID: " << id << endl;
                   cout << "Item Name: " << iteamname[i] << endl;
                   cout << "Quantity: " << qty << endl;
                   cout << "Price per item: $" << sellingprice[i] << endl;
                   cout << "Total Price: $" << sellingprice[i] * qty << endl;
                   cout << "-----------------------------------\n";
                   cout << "Thank you for shopping at SuperMart!" << endl;
                   cout << "************************************\n\n";
                
               } else {
                   cout << "Not enough stock available!" << endl;
               }
               return;
           }
       }
       cout << "Item ID not found!" << endl;
   }

   // Method to display total profit and items sold
   void display_profit() {
       cout << "************************************\n\n";
       cout << "Total items sold: " << total_sold << endl;
       cout << "Total profit: $" << profit << endl;
       cout << "************************************\n\n";
   }
};

int main() {
   BillingOperations billing;

   int choice1;
   cout << "\n \t\t\t=========================\n";
   cout << "\n\t\t\t  WELCOME TO SUPER MART\n";
   cout << "\n \t\t\t=========================\n\n";
   cout << "\n\t\t\t  1. OPEN STORE";
   cout << "\n\t\t\t  2. CLOSE STORE";
   cout << "\n\n\t\t\t Enter Your choice: ";
   cin >> choice1;

   if (choice1 == 1) {
       int choice;
       while (true) {
           // Main menu for store operations
           cout << "\nMenu:\n1. Add Item\n2. Display Items\n3. Update Item\n4. Delete Item\n5. Search Item\n6. Sell Item\n7. Display Profit\n8. Exit\n";
           cout << "Enter your choice: ";
           cin >> choice;

           switch (choice) {
               case 1:
                   billing.add_iteam();  // Add new items
                   break;
               case 2:
                   billing.displayiteams();  // Display all items
                   break;
               case 3:
                   billing.update_iteam();  // Update item details
                   break;
               case 4:
                   billing.delete_iteam();  // Delete an item
                   break;
               case 5:
                   billing.search_iteam();  // Search for an item
                   break;
               case 6:
                   billing.sell_item();  // Sell an item
                   break;
               case 7:
                   billing.display_profit();  // Display profit
                   break;
               case 8:
                   exit(0);  // Exit program
               default:
                   cout << "Invalid choice!" << endl;
           }
       }
   } else {
       cout << "Store is closed." << endl;
   }

   return 0;
}
