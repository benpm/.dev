def sum_multi(*args):
  total = 0
  print(type(args))
  for n in args:
    total += n
  print(total)
  return total

def divide(a, b):
  assert(b != 0)
  return a // b

sumIntegers = sum_multi(1, 2, 3)
result = divide(4, sumIntegers)
print(result)