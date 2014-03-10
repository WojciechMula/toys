# split words
cat $1 \
  | tr -s -c "a-zA-Z" " " \
  | awk '{for (i=0; i <= NF; i++) print $i}' \
  | sort -u \
  > $2
