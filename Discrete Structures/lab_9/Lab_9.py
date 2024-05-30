__author__ = "Elijah Sprung"
__copyright__ = "Copyright 2021"
__credits__ = ["Tyler Felts"]
__license__ = "GPLv3"
__version__ = "1.0.0"
__maintainer__ = "None"
__email__ = "esprung@highpoint.edu"
__status__ = "Release"
__grade_attempt__ = "A"

def main():
  A = float(input("Enter the probability of a person having skin cancer. This should be given as a decimal. An example is: '0.15'.\n"))
  BgA = float(input("Enter the probability of a person with cancer having moles. This should be given as a decimal. An example is: '1.00'.\n"))
  BgNA = float(input("Enter the probability of a person having moles but no skin cancer. This should be given as a decimal. An example is: '0.20'.\n"))
  

  B = (BgA * A + BgNA * (1 - A))
  AgB = (BgA * A) / B

  print("The probability of you having cancer given that you have a mole is: ", AgB)

if __name__ == "__main__":
  main()