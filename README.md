🚀 Order Matching Engine (C++)

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Build](https://img.shields.io/badge/build-CMake-green)
![License](https://img.shields.io/badge/license-MIT-yellow)

A simple order matching engine written in C++ using a price-time priority (FIFO) algorithm.
This project simulates how a basic trading engine works in financial markets.

---

✨ Features

- 📈 Limit order (BUY / SELL)
- ⚖️ Price-time priority (FIFO)
- 🔄 Automatic matching engine
- ❌ Cancel order support
- 🖥️ Interactive CLI
- 🧠 In-memory order book
- 📊 Trade logging

---

🧱 Project Structure

```
order-matching-engine/
├── CMakeLists.txt
├── include/
│   ├── order.hpp
│   ├── order_book.hpp
│   ├── matching_engine.hpp
│   └── parser.hpp
├── src/
│   └── main.cpp
└── build/
```

---

⚙️ Build & Run

🔧 Requirements

- C++17 or higher
- CMake (>= 3.16)

---

▶️ Build

```
mkdir build
cd build
cmake ..
cmake --build .
```

---

▶️ Run

```
./engine

(Windows)

engine.exe
```

---

🖥️ Usage

📥 Input Format

```
BUY <price> <quantity>
SELL <price> <quantity>
CANCEL <order_id>
EXIT
```
---

💡 Example
```
BUY 100 10
BUY 105 5
SELL 102 7
SELL 99 3
```
---

📤 Output Example
```
[ORDER] BUY Price=100 Qty=10 ID=1
[ORDER] BUY Price=105 Qty=5 ID=2
[ORDER] SELL Price=102 Qty=7 ID=3
[ORDER] SELL Price=99 Qty=3 ID=4

[TRADE] Price=99 Qty=3 (BuyID=2, SellID=4)
[TRADE] Price=102 Qty=2 (BuyID=2, SellID=3)
[TRADE] Price=102 Qty=5 (BuyID=1, SellID=3)
```
---

🧠 How It Works

The engine follows a price-time priority model:

1. Orders are stored in two priority queues:
   
   - Buy → highest price first
   - Sell → lowest price first

2. Matching occurs when:

buy_price >= sell_price

3. If matched:
   
   - Execute trade
   - Reduce quantity
   - Reinsert remaining order (if any)

4. FIFO is applied when prices are equal:
   
   - Earlier orders get priority

---

⚠️ Limitations

This is a simplified simulation and does NOT include:

- ❌ Market orders
- ❌ Persistence (database)
- ❌ Multi-threading
- ❌ Network/API (REST/WebSocket)
- ❌ Advanced matching rules

---

🛠️ Future Improvements

- [ ] Order cancellation (improved version)
- [ ] Order book visualization ("BOOK" command)
- [ ] Persistent storage
- [ ] REST / WebSocket API
- [ ] Performance optimization

---

📚 Learning Goals

This project is designed to explore:

- Data structures ("priority_queue")
- System design basics
- Matching algorithms
- Trade-offs in real-world systems

---

📄 License

This project is licensed under the MIT License.

---

💬 Notes

This is a learning project, not production-ready.
Built to understand how trading systems work under the hood.

---
