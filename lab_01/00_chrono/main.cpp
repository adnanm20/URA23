#include <chrono>
#include <iostream>

// std::chrono
//
// std::chrono zaglavlje za rad sa vremenom.
// Dva osnovna tipa:
// *duration* tipovi (nanosekunde, milisekunde, sati i slicno)
// *time_point* tipovi (vrijeme koje je proteklo od neke epohe)
//
// Potpisi templetizirani, preporucena je upotreba *auto* dedukcije tipova.

int main(int argc, char *argv[]) {

  // time_point
  // vrijeme u nanosekundama od Unix epohe (1.1.1970.).
  auto now = std::chrono::system_clock::now();

  // zelimo da izmjerimo vrijeme izvrsenja dijela koda
  std::cout << "Hello, world!" << std::endl;

  // od novog time pointa oduzmemeo stari, dobijemo proteklo vrijeme
  auto elapsed = std::chrono::system_clock::now() - now;
  std::cout << elapsed.count()/1000 << "ms" << std::endl;

  return 0;
}
