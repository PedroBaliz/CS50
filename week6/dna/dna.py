import csv
import sys


def main():

    # Check command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    # Read database file
    database = []

    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)

        # Save STR names
        strs = reader.fieldnames[1:]

        # Save database rows
        for row in reader:
            database.append(row)

    # Read DNA sequence file
    with open(sys.argv[2]) as file:
        sequence = file.read()

    # Find longest match of each STR
    results = {}

    for str in strs:
        results[str] = longest_match(sequence, str)

    # Check for matching profile
    for person in database:

        match = True

        for str in strs:

            if int(person[str]) != results[str]:
                match = False
                break

        if match:
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):

        count = 0

        while True:

            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run


main()
