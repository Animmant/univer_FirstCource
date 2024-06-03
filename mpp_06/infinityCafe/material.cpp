#include "material.h"
#include <iostream>
#include "liboai.h"
using namespace std;

using namespace liboai;

int main() {
  OpenAI oai;
  oai.auth.SetKeyEnv("OPENAI_API_KEY");
	
  Response res = oai.Image->create(
    "A snake in the grass!",
    1,
    "256x256"
  );

  std::cout << res["data"][0]["url"] << std::endl;
}