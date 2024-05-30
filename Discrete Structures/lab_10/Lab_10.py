__author__ = "Elijah Sprung"
__copyright__ = "Copyright 2021"
__credits__ = ["Connor Bass"]
__license__ = "GPLv3"
__version__ = "1.0.0"
__maintainer__ = "None"
__email__ = "esprung@highpoint.edu"
__status__ = "Release"
__grade_attempt__ = "A"

def main():
  print("Enter a set of ordered pairs in the format 'ab ac bc'.")
  x = list(map(str, input("Enter set V: ").split()))
  n = len(x)
  n -= 1
  vertex = input("Which vertex would you like to use in calculating N(v): \n")
  lst = []
  while n >= 0:
      if vertex in x[n]:
          lst.append(x[n].strip(vertex))
          n -= 1
      else:
          n -= 1
  print("N","(",(vertex),")"," = ", lst)

if __name__ == "__main__":
  main()