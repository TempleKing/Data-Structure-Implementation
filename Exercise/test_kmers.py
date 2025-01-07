"""
Skeleton for COMP3506/7505 A1, S2, 2024
The University of Queensland
Joel Mackenzie and Vladimir Morozov

NOTE: This file is not used for assessment. It is just a driver program for
you to write your own test cases and execute them against your data structures.
"""

# Import helper libraries
import random
import sys
import time
import argparse

from malloclabs.kmer_structure import KmerStore
  

def test_kmer_store_build(filepath : str):
    """
    A set of tests for building a kmer store
    This is not marked and is just here for you to test your code.
    """
    ks = KmerStore(31) # test using 31-mers
    ks.read(filepath)
    

# The actual program we're running here
if __name__ == "__main__":
    # Get and parse the command line arguments
    parser = argparse.ArgumentParser(description="COMP3506/7505 Assignment One: Testing K-mer structure")
    parser.add_argument("--build", type=str, help="Path to a file containing DNA sequences.")
    parser.add_argument("--seed", type=int, default='42', help="Seed the PRNG.")
    args = parser.parse_args()

    # No arguments passed
    if len(sys.argv) == 1:
        parser.print_help()
        sys.exit(-1)

    # Seed the PRNG in case you are using randomness
    random.seed(args.seed)

    # Now check/run the selected algorithm
    if args.build:
        test_kmer_store_build(args.build)

  
    # You probably want to expand with more testing!
