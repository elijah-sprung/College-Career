#!/usr/bin/env python3

__author__ = "Elijah D. Sprung"
__copyright__ = "Copyright 2021"
__credits__ = ["Elijah D. Sprung, Connor Bass"]
__license__ = ""
__version__ = "1.0.0"
__maintainer__ = "Elijah D. Sprung"
__email__ = "esprung@highpoint.edu"
__status__ = "Release"

import time
l = []
start_time = time.time()

def powerset(set_list):

  if len(set_list) == 0:
    return [[]]

  subsets = []
  first_element = set_list[0]
  remaining_list = set_list[1:]

  for partial_subset in powerset(remaining_list):
    subsets.append(partial_subset)
    subsets.append(partial_subset[:] + [first_element])

  return subsets

def replacement(set_list):
  
  string = str(set_list)
  string = string.replace("[]", "0")
  string = string.replace("[", "{")
  string = string.replace("]", "}")

  return string

theset = (powerset(l))

a = replacement(theset)
time1 = time.time() - start_time

theset = powerset(theset)
b = replacement(theset)
time2 = (time.time() - start_time) - time1

theset = powerset(theset)
c = replacement(theset)
time3 = (time.time() - start_time) - time2

theset = powerset(theset)
d = replacement(theset)
time4 = (time.time() - start_time) - time3

theset = powerset(theset)
e = replacement(theset)
time5 = (time.time() - start_time) - time4

with open ("results.txt", "w") as text_file:
  print("Generation 1 took ", time1, " seconds:",  file = text_file)
  print(a,  file = text_file)
  print("Generation 2 took ", time2, " seconds:", file = text_file)
  print(b,  file = text_file)
  print("Generation 3 took ", time3, " seconds:",  file = text_file)
  print(c,  file = text_file)
  print("Generation 4 took ", time4, " seconds:", file = text_file)
  print(d,  file = text_file)
  print("Generation 5 took ", time5, " seconds:", file = text_file)
  print(e,  file = text_file)