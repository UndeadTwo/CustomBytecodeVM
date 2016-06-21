#ifndef _src_commandList_h_
#define _src_commandList_h_

// Arithmetic
int add(int arga, int argb) {
  return argb + arga;
}

int sub(int arga, int argb) {
  return argb - arga;
}

//Bitwise arithmetic
int bitwiseand(int arga, int argb) {
  return argb & arga;
}

int bitwisenand(int arga, int argb) {
  return ~(argb & arga);
}

int bitwiseor(int arga, int argb) {
  return argb | arga;
}

int bitwisenor(int arga, int argb) {
  return ~(argb | arga);
}

int bitwisexor(int arga, int argb) {
  return argb ^ arga;
}

#endif