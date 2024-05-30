__author__ = "Elijah Sprung"
__copyright__ = "Copyright 2020"
__credits__ = [""]
__license__ = "GPLv3"
__version__ = "0.0.0"
__maintainer__ = ""
__email__ = "esprung@highpoint.edu"
__status__ = "Development"

import sys
from distutils.util import strtobool

def get_input():
  variable_input = input("Please enter what number of predicate variables are being used. Words or numbers may be used. (Unary: x, Binary: x and y, and Ternary: x, y, and z)\n")
  if ((variable_input != "unary") and (variable_input != "Unary") and (variable_input != "one") and (variable_input != "One") and (variable_input != "1") and (variable_input != "binary") and (variable_input != "Binary") and (variable_input != "two") and (variable_input != "Two") and (variable_input != "2") and (variable_input != "ternary") and (variable_input != "Ternary") and (variable_input != "three") and (variable_input != "Three") and (variable_input != "3")):
    sys.exit("You gave an invalid input foe the number of predicate variables, please run the program and try again.")

  function_input = input("Please enter the arithmetic function that is being evaluated. An example is x > y.\n")

  domain_input = input("Please choose an option for the domain: you may choose from all real numbers, all integers, or a range of numbers. An example input is R, Z, or range.\n")
  if ((domain_input != "R") and (domain_input != "Z") and (domain_input != "range")):
    sys.exit("You gave an invalid input for the domain, please run the program and try again.")

  if ((domain_input == "range") or (domain_input == "Range")):
    lower_bound = int(input("Enter the number of your lower bound.\n"))
    upper_bound = int(input("Enter the number of your upper bound.\n"))
  if (variable_input == "unary") or (variable_input == "Unary") or (variable_input == "one") or (variable_input == "One") or (variable_input == "1"):
    quantifier_x = input("Enter the quantifier for the singular variable x. Valid input would be U for universal and E for existential.\n")
    if ((quantifier_x != "u") and (quantifier_x != "U") and (quantifier_x != "e") and (quantifier_x != "E")):
      sys.exit("You gave an invalid input for the quantifier for x, please run the program and try again.")
  if (variable_input == "binary") or (variable_input == "Binary") or (variable_input == "two") or (variable_input == "Two") or (variable_input == "2"):
    quantifier_x = input("Enter the quantifier for the variable x. Valid input would be U for universal and E for existential.\n")
    if ((quantifier_x != "u") and (quantifier_x != "U") and (quantifier_x != "e") and (quantifier_x != "E")):
      sys.exit("You gave an invalid input for the quantifier for x, please run the program and try again.")
    quantifier_y = input("Enter the quantifier for the variable y. Valid input would be U for universal and E for existential.\n")
    if ((quantifier_y != "u") and (quantifier_y != "U") and (quantifier_y != "e") and (quantifier_y != "E")):
      sys.exit("You gave an invalid input for the quantifier for y, please run the program and try again.")
  if (variable_input == "ternary") or (variable_input == "Ternary") or (variable_input == "three") or (variable_input == "Three") or (variable_input == "3"):
    quantifier_x = input("Enter the quantifier for the variable x. Valid input would be U for universal and E for existential.\n")
    if ((quantifier_x != "u") and (quantifier_x != "U") and (quantifier_x != "e") and (quantifier_x != "E")):
      sys.exit("You gave an invalid input for the quantifier for x, please run the program and try again.")
    quantifier_y = input("Enter the quantifier for the variable y. Valid input would be U for universal and E for existential.\n")
    if ((quantifier_y != "u") and (quantifier_y != "U") and (quantifier_y != "e") and (quantifier_y != "E")):
      sys.exit("You gave an invalid input for the quantifier for y, please run the program and try again.")
    quantifier_z = input("Enter the quantifier for the variable z. Valid input would be U for universal and E for existential.\n")
    if ((quantifier_z != "u") and (quantifier_z != "U") and (quantifier_z != "e") and (quantifier_z != "E")):
      sys.exit("You gave an invalid input for the quantifier for z, please run the program and try again.")
  
  output = []
  output.append(variable_input)
  output.append(function_input)
  output.append(domain_input)
  if ((domain_input == "range") or (domain_input == "Range")):
    output.append(lower_bound)
    output.append(upper_bound)
  if (variable_input == "unary") or (variable_input == "Unary") or (variable_input == "one") or (variable_input == "One") or (variable_input == "1"):
    output.append(quantifier_x)
  if (variable_input == "binary") or (variable_input == "Binary") or (variable_input == "two") or (variable_input == "Two") or (variable_input == "2"):
    output.append(quantifier_x)
    output.append(quantifier_y)
  if (variable_input == "ternary") or (variable_input == "Ternary") or (variable_input == "three") or (variable_input == "Three") or (variable_input == "3"):
    output.append(quantifier_x)
    output.append(quantifier_y)
    output.append(quantifier_z)
  
  return output
  

def main():

  input = get_input()
  print(input)

  if (input[2] == "range") or (input[2] == "Range"):
    if (input[0] == "unary") or (input[0] == "Unary") or (input[0] == "one") or (input[0] == "One") or (input[0] == "1"):
      table_x = []
      for i in range(input[3], input[4] + 1):
        table_x.append(i)
    if (input[0] == "binary") or (input[0] == "Binary") or (input[0] == "two") or (input[0] == "Two") or (input[0] == "2"):
      table_x = []
      table_y = []
      for i in range(input[3], input[4] + 1):
        table_x.append(i)
        table_y.append(i)
    if (input[0] == "ternary") or (input[0] == "Ternary") or (input[0] == "three") or (input[0] == "Three") or (input[0] == "3"):
      table_x = []
      table_y = []
      table_z = []
      for i in range(input[3], input[4] + 1):
        table_x.append(i)
        table_y.append(i)
        table_z.append(i)

    #if (input[2] == "range") or (input[2] == "Range"):
    #  if (input[0] == "unary") or (input[0] == "Unary") or (input[0] == "one") or (input[0] == "One") or (input[0] == "1"):
    #    for i in range(input[3], input[4] + 1):
          
  
  
if __name__ == "__main__":
    main()