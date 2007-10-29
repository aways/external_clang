// RUN: clang -fsyntax-only -verify %s

int foo(int x) {
  return x == x; // expected-warning {{self-comparison always results}}
}

int foo2(int x) {
  return (x) != (((x))); // expected-warning {{self-comparison always results}}
}

int bar(float x) {
  return x == x; // no-warning
}

int bar2(float x) {
  return x != x; // no-warning
}