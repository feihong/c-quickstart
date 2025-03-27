env:
  ZDOTDIR=env zsh

install:
  #!/usr/bin/env zsh
  (( $+commands[entr] )) || brew install entr
  (( $+commands[clang] )) || xcode-select --install
