__author__ = "Elijah Sprung"
__copyright__ = "Copyright 2020"
__credits__ = [""]
__license__ = "GPLv3"
__version__ = "0.0.0"
__maintainer__ = ""
__email__ = "@highpoint.edu"
__status__ = "Development"


from distutils.util import strtobool

# define your functions here
def filter_proposition(proposition):
  filtered_prop = ""
  for char in proposition:
    if (ord(char) == 40 or ord(char) == 41 or ord(char) == 62 or (ord(char) >= 65 and ord(char) <= 90) or ord(char) == 92 or ord(char) == 47 or ord(char) == 126 or (ord(char) >= 97 and ord(char) <= 122) or (ord(char) == 32)):
      filtered_prop += char
  proposition = filtered_prop.lower()
  proposition = proposition.split()

  return proposition
def find_unique_vars(prop_list):
  unique_list = []
  for x in range(0, len(prop_list)):
    if ((prop_list[x] not in unique_list) and (prop_list[x] != '\\/') and (prop_list[x] != '/\\') and (prop_list[x] != '>')):
      unique_list.append(prop_list[x])
  
  return unique_list
def make_string_statement(list):
  string_phrase = ""
  for i in range(len(list)):
    if list[i] == '\\/':
      list[i] = 'or'
    elif list [i] == '/\\':
      list[i] = 'and'
    elif list[i] == '>':
      list[i] = 'implies'

  for i in range(len(list)):
    string_phrase += (list[i] + ' ')
  string_phrase = string_phrase.rstrip()

  return string_phrase
def evaluate_statement(string, table, rows, cols, table_header):
  column = []
  
  for i in range(rows):
    holder = string

    if cols == 1:
      break

    if cols == 2:
      if bool(strtobool(str((table[i][0]).lower()))):
        holder = holder.replace(str(table_header[0]), "True")
      else:
        holder = holder.replace(str(table_header[0]), "False")
      if bool(strtobool(str((table[i][1]).lower()))):
        holder = holder.replace(str(table_header[1]), "True")
      else:
        holder = holder.replace(str(table_header[1]), "False")

    if cols == 3:
      if bool(strtobool(str((table[i][0]).lower()))):
        holder = holder.replace(str(table_header[0]), "True")
      else:
        holder = holder.replace(str(table_header[0]), "False")
      if bool(strtobool(str((table[i][1]).lower()))):
        holder = holder.replace(str(table_header[1]), "True")
      else:
        holder = holder.replace(str(table_header[1]), "False")
      if bool(strtobool(str((table[i][2]).lower()))):
        holder = holder.replace(str(table_header[2]), "True")
      else:
        holder = holder.replace(str(table_header[2]), "False")

    if eval(holder):
      column.append('T')
    else:
      column.append('F')

  return column

def main():
    
  proposition = input("Please input a logical proposition using only letters as variables and the connectives /\ for and, \/ for or, > for\nimplies, the negation operator as ~,and any partentheses as needed.\nA sample proposition looks like this: ( p /\ ~ p \/ q ) > r.\n")

  prop_list = filter_proposition(proposition)
  unique_vars = find_unique_vars(prop_list)
  string_phrase = make_string_statement(prop_list)

  num_rows = 2**len(unique_vars)
  num_cols = len(unique_vars)

  table = [[0]*num_cols for i in range(num_rows)]

  for i in range (num_cols):
    row_counter = 0
    workaround_float = (num_rows) / (2**(i+1))
    workaround_int = int(workaround_float)
    repeater_float = num_rows / workaround_int
    repeater_int = int(repeater_float)
    for j in range (repeater_int):
      if (j%2 == 0):
        for k in range(workaround_int):
          table[row_counter][i] = 'T'
          row_counter = row_counter + 1
      else:
        for k in range(workaround_int):
          table[row_counter][i] = 'F'
          row_counter = row_counter + 1

  statement = evaluate_statement(string_phrase, table, num_rows, num_cols, unique_vars)

  for i in range (num_cols):
    print(unique_vars[i], end = "   ")
  if (len(unique_vars) != 1):
    print(string_phrase, end = "   ")
  print()

  for i in range (num_rows):
    for j in range (num_cols):
      print(table[i][j], end = "   ")
      if (len(unique_vars) == 1):
        print()
    if (len(unique_vars) != 1): 
      print(statement[i])
  print()

if __name__ == "__main__":
  main()