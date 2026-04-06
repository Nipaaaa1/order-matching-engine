#pragma once

#include "order.hpp"
#include <iostream>
#include <sstream>
#include <string>

inline bool parseInput(const std::string &line, Order &order, int id,
                       long timestamp) {
  std::istringstream iss(line);

  std::string sideStr;
  double price;
  int quantity;

  if (!(iss >> sideStr >> price >> quantity)) {
    return false;
  }

  Side side;
  if (sideStr == "BUY") {
    side = Side::Buy;
  } else if (sideStr == "SELL") {
    side = Side::Sell;
  } else {
    return false;
  }

  order = Order{id, side, price, quantity, timestamp};

  std::cout << "[ORDER] " << (side == Side::Buy ? "BUY" : "SELL")
            << " Price=" << price << " Qty=" << quantity << " ID=" << order.id
            << "\n";

  return true;
}
