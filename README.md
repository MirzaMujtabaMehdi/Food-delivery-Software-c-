# Food Delivery Software – "Super Quality Foods" (C++)

> **Academic notice:** This project was written for learning and academic purposes only. It is a classroom exercise in procedural C++ (functions, arrays, `switch`, strings and file handling). It is not a real ordering system.

---

## 1. Overview

A console application for a fictional restaurant. A customer can view the menu, place an order (with several dishes and quantities), choose packing, receive an itemised bill, and later look up past orders by mobile number.

Main menu:

| Choice | Action |
|---|---|
| `1` | Show the menu (Desi Foods, Fast Food, Rolls, Beverages) |
| `2` | Book an order |
| `3` | Order history (search by mobile number) |
| `4` (or anything else) | Exit |

## 2. Files

| File | Purpose |
|---|---|
| `decode15.cpp` | The complete program (the 15th version of an incrementally developed program – see below) |

`text.txt` is created next to the program on the first saved order.

## 3. Build and run

```bash
g++ decode15.cpp -o food
./food          # Windows: food.exe
```

## 4. How the program grew

`decode15.cpp` is the end of a series (`Decode9.cpp` → `decode15.cpp`) kept in `Practice Sets/C++ Practice`. In order, the versions added: one price variable per dish → a `prices[]` array → category sub-menus and `goto` → menu functions → a `customer` struct and a reusable `slip_calculation()` function → file handling → order history search. The comment inside `main()` lists the concepts used so far: data types, arrays, do-while loops, operators, if/else, switch, strings, basic I/O and escape sequences.

## 5. Concepts used

`struct`, functions, **pass-by-reference** (`int &`, `string &`), arrays, `do-while`, `switch` with 17 cases, nested `if / else if`, the **ternary operator**, `goto` labels, string concatenation, `to_string`, and text-file handling in append and read modes.

## 6. Functions

### 6.1 User-defined

| Name | Signature | Purpose |
|---|---|---|
| `struct customer` | `string Name; string Address; int Mobilenumber;` | Holds one customer's details |
| `main_menu()` | `void main_menu()` | Prints all menu categories with prices |
| `slip_calculation()` | `void slip_calculation(int &totalamount, string &detailed, int quantity, string item, int prices)` | Adds one bill line: `amount = quantity × price`; adds it to the running total; appends `" quantity item amount"` to the bill text |
| `main()` | `int main()` | Menu loop, order loop, history search |

`totalamount` and `detailed` are passed **by reference** so that the function changes the caller's variables directly; this is how one helper can update both the running total and the bill text without returning two values.

### 6.2 Built-in / library features

| Feature | Header | Used for | Why |
|---|---|---|---|
| `cout`, `cin`, `endl` | `<iostream>` | Console I/O | Standard |
| `getline(cin, str)` | `<string>` | Customer name and address | Accepts spaces |
| `cin.ignore()` | `<iostream>` | Remove the newline left by `cin >> choice` | Otherwise `getline` returns an empty string |
| `to_string(n)` | `<string>` | Convert numbers to text for the bill | Allows numbers to be joined to a string with `+` |
| `string +` | `<string>` | Build the bill line by line | Simple accumulation in `detailed` |
| `fstream`, `ios::app`, `ios::in` | `<fstream>` | Save and read `text.txt` | `app` keeps old orders; `in` reads them |
| `getline(record, line)` | `<string>` | Read the history file line by line | One order per line |
| `line.find(x)` and `string::npos` | `<string>` | Search a line for the mobile number | `find` returns `npos` when the text is not found |
| `cond ? a : b` | language | Packing choice (Box / Bag / Tin) | Compact choice between three values |
| `goto Start` | language | Return to the main menu | Simple menu loop for a beginner program |
| `int prices[20]` | language | Dish prices indexed by dish number | One place to change a price |

## 7. Step-by-step logic

1. **Start** – print the welcome text and jump to the `Start:` label; show the four menu options.
2. **Choice 1** – call `main_menu()` and `goto Start`.
3. **Choice 2 (order)**
   1. `cin.ignore()`, then read name and address with `getline` and the mobile number with `cin`.
   2. Inside a `do … while (dishes != 0)` loop: print the numbered dish list (1–17), read the dish number.
   3. A `switch` selects the dish: print its price, ask for the quantity, and call `slip_calculation()` with the dish label and its price from `prices[]`. Entering `0` matches no case, so the loop ends.
   4. Ask for packing (1 Box, 2 Bag, otherwise Tin) using the ternary operator.
   5. If the total is not zero, print the bill and **append** one line to `text.txt`.
   6. `goto Start`.
4. **Choice 3 (history)** – read a number as text, open `text.txt`, read every line with `getline`, and print the lines that contain that text.
5. **Anything else** – print a thank-you message and end.

## 8. Data format (`text.txt`)

```
Phone:300123456 | Name:Ana | Items: 1 Biryani 350 | Total:350Rs
```

One order per line. (The bill text contains no line breaks: a comment in the code says earlier versions used line breaks and that this "skips items in our .txt file", so the breaks were replaced by spaces to keep each order on a single line.)

## 9. Known limitations (checked by running the program)

1. **Prices are misaligned from dish 6 onward.** The `prices[]` array has only 15 values but the menu has 17 dishes, and two entries are missing (Burger 350 and Pizza 500 should come after index 4). Result: Pizza is billed 350 (menu says 500), Burger 380 (menu 350), Broast 120 (menu 380), and the two water bottles are billed **0**. The array that matches the menu is `{350,200,800,120,250,350,500,380,350,120,140,170,110,160,140,90,50}`.
2. **Juice labels swapped.** The numbered list shows `14 Mango Juice, 15 Apple Juice`, but `case 14` bills "Apple juice" and `case 15` bills "Mango juice".
3. **Mobile number is an `int`.** An 11-digit number (e.g. `03001234567`) overflows an `int`, `cin` fails, and the program falls into an endless loop. Store the number as a `string`.
4. **History search is a substring search** on the whole line, so searching `12` also matches prices or other numbers containing `12`.
5. On exit the program prints "YOUR BILL IS 0" from a leftover variable (`bill`).
6. No input validation (negative quantities, letters instead of numbers).

## 10. Ideas for improvement

Fix the price table (or use parallel arrays / a `struct Dish { string name; int price; }` array so name and price can never drift apart); store the phone as `string`; replace `goto` with loops; validate input; add order numbers and a delete/cancel option.
