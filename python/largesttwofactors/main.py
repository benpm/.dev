import math

def ltf(x: int):
  i = math.floor(math.sqrt(x))
  while x % i != 0:
    i = math.floor(math.sqrt(i))
  return (i, x // i)

for x in range(1, 100):
  print(x, ltf(x))