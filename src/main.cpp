#include <iostream>
#include <nlohmann/json.hpp>

int main() {
  nlohmann::json document;
  document["Hello"] = "World";
  std::cout << document.dump(4) << std::endl;
  return 0;
}
