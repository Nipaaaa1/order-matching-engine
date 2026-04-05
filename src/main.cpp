#include "order_book.hpp"
#include <iostream>

int main() {
  OrderBook book;

  book.addOrder({1, Side::Buy, 100, 10, 1});
  book.addOrder({2, Side::Buy, 105, 5, 2});
  book.addOrder({3, Side::Sell, 110, 7, 3});
  book.addOrder({4, Side::Sell, 102, 3, 4});

  if (book.hasBuyOrders()) {
    auto topBuy = book.getTopBuy();
    std::cout << "Top Buy: " << topBuy.price << "\n";
  }

  if (book.hasSellOrders()) {
    auto topSell = book.getTopSell();
    std::cout << "Top Sell: " << topSell.price << "\n";
  }

  return 0;
}
