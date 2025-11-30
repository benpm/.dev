import re

with open("input.txt") as input_file:
  t_input = input_file.read()
  t_rules = [line.strip() for line in t_input.split("\n\n")[0].split("\n")]
  t_strings = [line.strip() for line in t_input.split("\n\n")[1].split("\n")]
  rules = dict()
  for line in t_rules:
    if re.match(r"\d+: \d+ \d+ \| \d+ \d+", line):
      m = re.match(r"(\d+): (\d+) (\d+) \| (\d+) (\d+)", line)
      rules[f" {m.group(2)} {m.group(3)} "] = f" {m.group(1)} "
      rules[f" {m.group(4)} {m.group(5)} "] = f" {m.group(1)} "
    elif re.match(r"\d+: \d+ \d+", line):
      m = re.match(r"(\d+): (\d+) (\d+)", line)
      rules[f" {m.group(2)} {m.group(3)} "] = f" {m.group(1)} "
    elif re.match(r"\d+: \d+", line):
      m = re.match(r"(\d+): (\d+)", line)
      rules[f" {m.group(2)} "] = f" {m.group(1)} "
    elif re.match(r"\d+: \"(.)\"", line):
      m = re.match(r"(\d+): \"(.)\"", line)
      rules[f" {m.group(2)} "] = f" {m.group(1)} "
  print(rules)