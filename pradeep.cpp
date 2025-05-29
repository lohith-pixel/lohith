#include <iostream>
using namespace std;
  
  int main() {
    // Create variables of different data types
    auto items = 50;
    auto cost_per_item = 9.99;
    auto total_cost = items * cost_per_item;
    auto currency = '$';
  
    // Print variables
    cout << "Number of items: " << items << "\n";
    cout << "Cost per item: " << cost_per_item << currency << "\n";
    cout << "Total cost = " << total_cost << currency << "\n";
  
    return 0;
} 

  
    