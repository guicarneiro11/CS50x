import csv
import sys


def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    database = []
    with open(sys.argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            database.append(row)

    with open(sys.argv[2], 'r') as file:
        dna_sequence = file.read()

    str_counts = {}
    for str_name in database[0].keys() - {'name'}:
        str_counts[str_name] = longest_consecutive_repeats(dna_sequence, str_name)

    for person in database:
        if all(int(person[str_name]) == str_counts[str_name] for str_name in str_counts):
            print(person['name'])
            return

    print("No match")


def longest_consecutive_repeats(sequence, str_sequence):
    i = 0
    max_repeats = 0
    while i < len(sequence):
        repeats = 0
        while sequence[i:i+len(str_sequence)] == str_sequence:
            repeats += 1
            i += len(str_sequence)
        max_repeats = max(max_repeats, repeats)
        i += 1
    return max_repeats


if __name__ == "__main__":
    main()
