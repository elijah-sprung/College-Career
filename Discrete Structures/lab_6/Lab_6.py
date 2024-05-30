__author__ = "Elijah Sprung"
__copyright__ = "Copyright 2021"
__credits__ = [""]
__license__ = "GPLv3"
__version__ = "1.0.0"
__maintainer__ = "None"
__email__ = "esprung@highpoint.edu"
__status__ = "Release"

# Grade Attempt: A

def get_num():

  number = int(input("Please enter a postitive integer to be tested. Whether it is a prime or composite will be returned.\n"))
  
  if number <= 0:
    while number <= 0:
      number = int(input("You failed to enter a positive integer, please try again.\n"))

  return number

def is_prime(number):

  if number == 1:
    return False
  elif number == 2:
    return True
  elif number > 2:
    for i in range(2, number):
      if number % i == 0:
        return False

    return True

repeat = True

while repeat:
  number = get_num()

  if is_prime(number) == True:
    print(number, "is a prime number.")
  else:
    print(number, "is a composite number.")

  choice = input("Would you like to go again? Input yes or no.\n")
  print("\n")
  if choice.lower() == "yes":
    repeat = True
  else:
    repeat = False