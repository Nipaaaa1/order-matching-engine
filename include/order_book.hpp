#pragma once

#include "order.hpp"
#include <queue>
#include <vector>

struct BuyCompare {
  bool operator()(const Order &a, const Order &b) { return a.price < b.price; }
};

struct SellCompare {
  bool operator()(const Order &a, const Order &b) { return a.price > b.price; }
};

class OrderBook {
public:
  void addOrder(const Order &order) {
    if (order.side == Side::Buy) {
      buyOrders.push(order);
    } else {
      sellOrders.push(order);
    }
  }

  bool hasBuyOrders() const { return !buyOrders.empty(); }

  bool hasSellOrders() const { return !sellOrders.empty(); }

  Order getTopBuy() const { return buyOrders.top(); }

  Order getTopSell() const { return sellOrders.top(); }

  void popTopBuy() { buyOrders.pop(); }

  void popTopSell() { sellOrders.pop(); }

private:
  std::priority_queue<Order, std::vector<Order>, BuyCompare> buyOrders;
  std::priority_queue<Order, std::vector<Order>, SellCompare> sellOrders;
};
