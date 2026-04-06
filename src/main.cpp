#include "matching_engine.hpp"
#include "parser.hpp"
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

    Order order;

    if (!parseInput(line, order, orderId++, timestamp++)) {
      std::cout << "Invalid input\n";
      continue;
    }

    book.addOrder(order);

    engine.process(book);
  }

  return 0;
}
