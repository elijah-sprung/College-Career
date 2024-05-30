#!/usr/bin/env python3

__author__ = "Elijah D. Sprung"
__copyright__ = "Copyright 2021"
__credits__ = ["Elijah D. Sprung, Connor Bass"]
__license__ = ""
__version__ = "1.0.0"
__maintainer__ = "Elijah D. Sprung"
__email__ = "esprung@highpoint.edu"
__status__ = "Release"
__grade_attempt__ = "A"

def one_to_one(set_1, set_2):
  
  x = 0
  while x < len(set_1):
    print(set_1[x], "->", set_2[x])
    x += 1

  return

def onto(set_1, set_2):
  
  x = 0
  while x < len(set_2):
    print(set_1[x], "->", set_2[x])
    x += 1
  
  while x < len(set_1):
    print(set_1[x], "->", set_2[len(set_2) - 1])
    x += 1

  return

repeat = "yes"

while repeat == "yes":
  set_1 = {}
  set_1 = input("Input set 1. A valid input is 123... or abc...\n")
  
  set_2 = {}
  set_2 = input("Input set 1. A valid input is 123... or abc...\n")

  operation = input("Onto or One-to-One? Valid input is spelled the same.\n")

  if operation == "Onto" and len(set_1) >= len(set_2):
    onto(set_1, set_2)
    repeat = input("Repeat? Valid input is 'yes' or 'no'.\n")
  elif operation == "Onto" and len(set_1) < len(set_2):
    print("For onto, the number of variables in set 1 must be greater than or equal to the number of variables in set 2.")

  if operation == "One-to-One" and len(set_1) <= len(set_2):
    one_to_one(set_1, set_2)
    repeat = input("Repeat? Valid input is 'yes' or 'no'.\n")
  elif operation == "One-to-One" and len(set_1) > len(set_2):
    print("For one-to-One, the number of variables in set 1 must be less than or equal to the number of variables in set 2.")