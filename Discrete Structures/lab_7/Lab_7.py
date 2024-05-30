__author__ = "Elijah Sprung"
__copyright__ = "Copyright 2021"
__credits__ = ["Connor Bass"]
__license__ = "GPLv3"
__version__ = "1.0.0"
__maintainer__ = "None"
__email__ = "esprung@highpoint.edu"
__status__ = "Release"

# Grade Attempt: A

def factorial(set):
  output = 1
  
  if set < 0:
    print("There is no factorial for a negative number, please try again.")
    return 0
  elif set == 0:
    return output
  elif set > 0:
    for i in range(1, set + 1):
      output *= i
    return output

decision = input("Input whether order of output matters. Valid input it 'yes' and 'no'.\n")

while decision.lower() != "yes" and decision.lower() != "no":
  decision = input("You have input an invalid string, please try again.\n")

if decision.lower() == "no":
  set = [""]
  sum_output = 0
  product_output = 1
  
  print("Enter a set of inputs separated by spaces.\nAn input looks like: 'a b c', '1 2 3', or 'a b c 1 2 3'.\nPress 'Retrun' or 'Enter' to create a new line and enter a new set.\nPress 'Return' or 'Enter' without putting anything to stop.")

  while len(set) > 0:
    set = input()
    set = set.split()
    sum_output += len(set)
    if len(set) > 0:
      product_output *= len(set)

  print("Sum Rule:", sum_output)
  print("Product Rule:", product_output)

if decision.lower() == "yes":
  print("Enter a set of inputs separated by spaces.\nAn input looks like: 'a b c', '1 2 3', or 'a b c 1 2 3'.\n")
  set = input("")

  size = int(input("Input the the size of the subset, it must be greater than or equal to zero or less than or equal to the length of the set.\n"))
  while size < 0 and size > len(set):
    size = int(input("You have input and invalid value, try again."))

  set = set.split()

  pnr = factorial(len(set))
  print("P(n):", pnr)

  rperms = factorial(len(set)) / factorial(((len(set) - size)))
  print("P(n, r):", pnr)