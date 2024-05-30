#!/usr/bin/env python3

__author__ = "Elijah D. Sprung"
__copyright__ = "Copyright 2021"
__credits__ = ["Elijah D. Sprung, Jason M. Pittman"]
__license__ = ""
__version__ = "1.0.0"
__maintainer__ = "Elijah D. Sprung"
__email__ = "esprung@highpoint.edu"
__status__ = "Release"

from sympy import *

class Proof:

  def Proposition(self, p):

    return sympify(p)

  def Implication(self, p, q):

    x, y = symbols('x, y')
        
    return (x >> y).subs({x : p, y: q})

  def Modus_Ponens(self, p, q):

    if p and proof.Implication(p, q):
      return True
    else:
      return False

  def Modus_Tollens(self, p, q):

    if not q and proof.Implication(p, q):
      return True
    else:
      return False

proof = Proof()

p = input("Please input a value or mathematical proposition for p. Valid inputs are: 'True' for true, '~true' for false, or something similar to '2 < 5'.\n")

q = input("Please input a value or mathematical proposition for q. Valid inputs are: 'True' for true, '~true' for false, or something similar to '2 < 5'.\n")

p = proof.Proposition(p)
q = proof.Proposition(q)

i = input("Please enter which implication you wish to use. Valid inputs are 'Modus Ponens' and 'Modus Tollens'.\n")

if i != "Modus Ponens" and i != "Modus Tollens":
  sys.exit("You have entered an invalid value for your implication of choice. Run the program and try again.")

if i == "Modus Ponens":
  print(proof.Modus_Ponens(p, q))
elif i == "Modus Tollens":
  print(proof.Modus_Tollens(p, q))