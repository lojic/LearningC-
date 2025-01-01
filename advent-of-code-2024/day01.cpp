#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <unordered_map>
#include <vector>

using namespace std::ranges;

std::pair<std::vector<int>,std::vector<int>> parse() {
  std::ifstream    ifs { "day01.txt" };
  std::vector<int> left;
  std::vector<int> right;
  int num1, num2;

  while (ifs >> num1 >> num2) {
    left.emplace_back(num1);
    right.emplace_back(num2);
  }

  return std::pair<std::vector<int>,std::vector<int>> { left, right };
}

int part1(std::vector<int> left, std::vector<int> right) {
  sort(left);
  sort(right);

  auto total = 0;

  for (size_t i = 0; i < left.size(); ++i) {
    total += abs(left[i] - right[i]);
  }

  return total;
}

int part2(std::vector<int> left, std::vector<int> right) {
  std::unordered_map<int, int> counter;

  for (const auto& n : right) {
    counter[n] += 1;
  }

  return std::accumulate(left.begin(),
                         left.end(),
                         0,
                         [&counter](int acc, int n) { return acc + n * counter[n]; });
}

int main() {
  const auto result = parse();
  auto left         = result.first;
  auto right        = result.second;

  std::cout << part1(left, right) << '\n';
  std::cout << part2(left, right) << '\n';

  return 0;
}
