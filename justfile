env:
  # Starting C programming environment...
  ZDOTDIR=env zsh || true
  # Stopped C programming environment

install:
  #!/usr/bin/env zsh
  (( $+commands[entr] )) || brew install entr
  (( $+commands[clang] )) || xcode-select --install
