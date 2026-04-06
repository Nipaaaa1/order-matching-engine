#include "matching_engine.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main() {
  OrderBook book;
  MatchingEngine engine;

  std::string line;
  int orderId = 1;
  long timestamp = 1;

  std::cout << "Simple Matching Engine (type EXIT to quit)\n";

  while (true) {
    std::cout << "> ";
    std::getline(std::cin, line);

    if (line == "EXIT")
      break;

    std::istringstream iss(line);

    std::string sideStr;
    double price;
    int quantity;

    if (!(iss >> sideStr >> price >> quantity)) {
      std::cout << "Invalid input\n";
      continue;
    }

    Side side;
    if (sideStr == "BUY") {
      side = Side::Buy;
    } else if (sideStr == "SELL") {
      side = Side::Sell;
    } else {
      std::cout << "Invalid side\n";
      continue;
    }

    Order order{orderId++, side, price, quantity, timestamp++};

    book.addOrder(order);

    engine.process(book);
  }

  return 0;
}
