#include "matching_engine.hpp"
#include "order_book.hpp"

int main() {
  OrderBook book;
  MatchingEngine engine;

  book.addOrder({1, Side::Buy, 100, 10, 1});
  book.addOrder({2, Side::Buy, 105, 5, 2});
  book.addOrder({3, Side::Sell, 102, 7, 3});
  book.addOrder({4, Side::Sell, 99, 3, 4});

  engine.process(book);

  return 0;
}
