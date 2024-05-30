#!/usr/bin/env python3

__author__ = "Elijah D. Sprung"
__copyright__ = "Copyright 2021"
__credits__ = ["Elijah D. Sprung, Jason M. Pittman"]
__license__ = ""
__version__ = "1.0.0"
__maintainer__ = "Elijah D. Sprung"
__email__ = "esprung@highpoint.edu"
__status__ = "Release"
__grade_attempt__ = "A"

import algorithm
import time

numbers = input("Enter a list of positive integers separated by spaces.\n")

numbers = numbers.split()
start_time = time.time()

algorithm = algorithm.Algorithm()

algorithm.sort(numbers, len(numbers))

print("The sort of", numbers, "took", time.time() - start_time, "seconds.")

# The algorithm is a recursive heap sort.
# The determination of the algorithm complexity of time in Big O notation is O(nlog(n)).
# The determination of the algorithm complexity of space in Big O notation is O(n).
# The sort of ['1', '2', '3'] took 0.0 seconds.
# The sort of ['4', '1', '2', '3'] took 0.0004990100860595703 seconds.
# The sort of ['1', '3', '5', '4', '2'] took 0.002000093460083008 seconds.
# The sort of ['6', '1', '3', '5', '4', '2'] took 0.01199960708618164 seconds.
# The sort of ['7', '1', '3', '5', '4', '2', '6', '8'] took 0.7494997978210449 seconds.
# The sort of ['5', '1', '3', '15', '4', '2', '6', '8', '7', '10'] took 70.4369969367981 seconds.
# These sorts were run on a pc with a 3.90 GHz AMD Ryzen 5 2600X with 6 cores, 16 GB of DDR4-3200 RAM (2x8 GB),
# and a Samsumng 970 Evo 500 GB M.2-2280 NVME SSD.