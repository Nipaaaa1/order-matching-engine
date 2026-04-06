#pragma once

#include "order.hpp"
#include <queue>
#include <unordered_set>
#include <vector>

struct BuyCompare {
  bool operator()(const Order &a, const Order &b) {
    if (a.price == b.price) {
      return a.timestamp > b.timestamp;
    }

    return a.price < b.price;
  }
};

struct SellCompare {
  bool operator()(const Order &a, const Order &b) {
    if (a.price == b.price) {
      return a.timestamp > b.timestamp;
    }

    return a.price > b.price;
  }
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

  bool cancelOrder(int id) {
    cancelledOrders.insert(id);
    return true;
  }

  bool isCancelled(int id) const {
    return cancelledOrders.find(id) != cancelledOrders.end();
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
  std::unordered_set<int> cancelledOrders;
};
