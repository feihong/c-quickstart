set shell := ["nu", "-c"]

env:
  nu --config env.nu

install:
  if (which clang | is-empty) { xcode-select --install }
