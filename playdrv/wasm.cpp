#include "io.hpp"

#include <cereal/cereal.hpp>
#include <cstdint>

#define G_BUFFER_SIZE 2048
static float g_buffer[G_BUFFER_SIZE];
static int g_buffer_index;

struct PlayResponse {
  uintptr_t address;

  template <class Archive> void serialize(Archive &archive) {
    archive(CEREAL_NVP(address));
  }
};

/* インライン関数にしたい */

void initPlay(vector<string> &args) { g_buffer_index = 0; }

bool isContinuePlay() { return g_buffer_index < G_BUFFER_SIZE; }

void storePlay(double sample) {
  g_buffer[g_buffer_index++] = static_cast<float>(sample);
}

void respondPlay() {
  PlayResponse response;
  response.address = reinterpret_cast<uintptr_t>(g_buffer);
  respond(response);
}
