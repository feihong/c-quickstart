source ~/.zshrc

b() {
  echo "clang -Wall $1"
  clang -Wall $1
}
compdef _files b

r() {
  echo "clang -Wall $1 && ./a.out ${argv[2,-1]}"
  clang -Wall $1 && ./a.out ${argv[2,-1]}
}
compdef _files r

w() {
  echo "ls $1 | entr -s \"clang -Wall $1 && ./a.out ${argv[2,-1]}\""
  ls $1 | entr -s "clang -Wall $1 && ./a.out ${argv[2,-1]}"
}
compdef _files w

alias q='exit 0'
