__author__ = "Elijah Sprung"
__copyright__ = "Copyright 2021"
__credits__ = []
__license__ = "GPLv3"
__version__ = "1.0.0"
__maintainer__ = "None"
__email__ = "esprung@highpoint.edu"
__status__ = "Release"

import math

def main():
  user_string = input("Please enter a basic string with no spaces, a sample input is 'string'. The length of this string will be used at n in a k-permutation. \n")
  n = len(user_string)
  if n < 0:
    checker = False
    while checker == False:
      user_string = input("You input a string with a length lower than 0, please try again. \n")
      n = len(user_string)
      if n >= 0:
        checker = True

  print("Please enter a value for k, this value must be greater than or equal to", n,)
  user_k = int(input())
  if user_k < n:
    checker = False
    while checker == False:
      print("You input a value lower than", n, "please try again.")
      user_k = int(input())
      if user_k >= n:
        checker = True

  if n - user_k < 0:
    print("Cannot calculate the factorial of a negative number, there is no output.")
  else:
    num_perms = math.factorial(n) / math.factorial(n - user_k)
    print("The number of k-permutations possible given a string of length", n, "and a k of", user_k, "is:", num_perms)

if __name__ == "__main__":
  main()