#include "order.hpp"
#include <iostream>

int main() {
  Order order1{1, Side::Buy, 100.5, 10, 1};

  std::cout << "Order ID: " << order1.id << "\n";
  std::cout << "Price: " << order1.price << "\n";
  std::cout << "Quantity: " << order1.quantity << "\n";
}
