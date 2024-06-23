# Implementation of Find S algorithm
import csv

# Read the data from the CSV file
a = []
with open('find_s.csv', 'r') as csvfile:
    next(csvfile)  # Skip the header row
    for row in csv.reader(csvfile):
        a.append(row)

print(a)
print("\nThe total number of training instances are: ", len(a))

# Determine the number of attributes
num_attribute = len(a[0]) - 1

# Initialize the hypothesis
print("\nThe initial hypothesis is:")
hypothesis = ['0'] * num_attribute
print(hypothesis)

# Iterate over each instance in the dataset
for i in range(len(a)):
    if a[i][num_attribute] == 'yes':
        print("\nInstance", i + 1, "is", a[i], "and is a Positive Instance")
        for j in range(num_attribute):
            if hypothesis[j] == '0' or hypothesis[j] == a[i][j]:
                hypothesis[j] = a[i][j]
            else:
                hypothesis[j] = '?'
        print("The hypothesis for the training instance", i + 1, "is:", hypothesis, "\n")
    if a[i][num_attribute] == 'no':
        print("\nInstance", i + 1, "is", a[i], "and is a Negative Instance Hence Ignored")
        print("The hypothesis for the training instance", i + 1, "is:", hypothesis, "\n")

print("\nThe Maximally specific hypothesis for the training instance is", hypothesis)
