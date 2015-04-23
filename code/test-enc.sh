#!/usr/bin/env sh

ENC="apps/openssl enc -caesar"
PLAINTEXT="Lorem ipsum dolor sit amet, consectetur adipiscing elit."
KEY=$(openssl rand 16 | xxd -p)
IV=$(openssl rand 16 | xxd -p)


echo "$PLAINTEXT"
echo "key=$KEY"
echo "iv=$IV"
echo
CIPHERTEXT=$(echo -n "$PLAINTEXT" | $ENC -K $KEY -iv $IV | xxd -p)
echo
echo "$CIPHERTEXT"
echo
PLAINTEXT2=$(echo -n "$CIPHERTEXT" | xxd -r -p | $ENC -d -K $KEY -iv $IV)
echo
echo "$PLAINTEXT2"
echo


if [ "$PLAINTEXT" == "$PLAINTEXT2" ]; then
  echo "ok"
else
  echo "fail"
fi
