source ~/.zshrc

echo 'Starting C programming environment...'

b() {
  echo "clang -Wall $1"
  clang -Wall $1
}
compdef _files b

r() {
  echo "clang -Wall $1 && ./a.out"
  clang -Wall $1 && ./a.out
}
compdef _files r

w() {
  echo "ls $1 | entr -s \"clang -Wall $1 && ./a.out\""
  ls $1 | entr -s "clang -Wall $1 && ./a.out"
}
compdef _files w

alias q='echo "Stopping C programming environment"; exit'
