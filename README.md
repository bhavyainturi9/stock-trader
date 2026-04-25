# Stock Trading Optimizer

A C++ implementation of the classic stock trading problem using Dynamic Programming. Given a list of stock prices over several days, the program calculates the maximum profit you can make under different trading constraints.

## Problem Variants

| Variant | Description |
|---|---|
| Unlimited trades | Buy and sell as many times as you want |
| k transactions | At most k buy-sell pairs allowed |
| Cooldown | Must wait 1 day after selling before buying again |
| k + cooldown | Both constraints combined |

## How It Works

The program uses a 3D DP state:

dp[day][canBuy][transactions_left]

At every day, you're in one of two modes:
- canBuy = 1 → holding cash, can buy or skip
- canBuy = 0 → holding stock, can sell or hold

The DP evaluates all possible futures simultaneously and picks the globally optimal sequence of decisions.

## Example

Enter number of days: 10
Enter prices: 3 8 5 1 9 3 6 4 10 2
Enter max transactions (k): 2

Max profit (no cooldown): $16
Max profit (with cooldown): $14

## Why Not Greedy?

Greedy fails when constraints like cooldown or transaction limits are added. A decision to sell today might block a much bigger gain 3 days from now. DP is needed to evaluate all futures at once.

## Complexity

| Variant | Time | Space |
|---|---|---|
| Unlimited | O(n) | O(1) |
| k transactions | O(n·k) | O(k) |
| Cooldown | O(n) | O(1) |
| k + cooldown | O(n·k) | O(n·k) |

## Running the Project

g++ -std=c++17 -o stock main.cpp
./stock

## Tech Stack

- Language: C++17
- Concepts: Dynamic Programming, State Machine DP, Optimization