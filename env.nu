def b [...rest] {
  print $"clang -Wall ($rest | str join ' ')"
  clang -Wall ...$rest
}

def r [file ...rest] {
  print $"clang -Wall ($file) ; ./a.out ($rest | str join ' ')"
  clang -Wall $file
  ./a.out ...$rest
}

def w [file ...rest] {
  watch $file {||
    print $"clang -Wall ($file) ; ./a.out ($rest | str join ' ')"
    clang -Wall $file
    ./a.out ...$rest
  }
}

alias q = exit 0
