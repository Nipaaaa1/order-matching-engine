#pragma once

enum class Side { Buy, Sell };

struct Order {
  int id;
  Side side;
  double price;
  int quantity;
  long timestamp;
  bool cancelled = false;
};
