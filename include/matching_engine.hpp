#pragma once

#include "order.hpp"
#include "order_book.hpp"
#include <algorithm>
#include <iostream>

class MatchingEngine {
public:
  void process(OrderBook &book) {
    while (book.hasBuyOrders() && book.hasSellOrders()) {

      Order buy = book.getTopBuy();
      Order sell = book.getTopSell();

      if (buy.price < sell.price) {
        break;
      }

      int tradedQty = std::min(buy.quantity, sell.quantity);

      std::cout << "[TRADE] "
                << "Price=" << sell.price << " Qty=" << tradedQty
                << " (BuyID=" << buy.id << ", SellID=" << sell.id << ")\n";

      buy.quantity -= tradedQty;
      sell.quantity -= tradedQty;

      book.popTopBuy();
      book.popTopSell();

      if (buy.quantity > 0) {
        book.addOrder(buy);
      }

      if (sell.quantity > 0) {
        book.addOrder(sell);
      }
    }
  }
};
