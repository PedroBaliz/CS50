from cs50 import get_string
from math import floor

while True:
    text = get_string("Text: ")
    break


letters = 0
words = 1
phrases = 0

for i in text:

    if i.isalpha():

        letters += 1

    elif i == " ":

        words += 1

    elif i in ("!",  ".",  "?"):

        phrases += 1


l = (letters / words) * 100
s = (phrases / words) * 100

index = 0.0588 * l - 0.296 * s - 15.8
grade = round(index)

if grade < 1:
    print(f"Before Grade 1")

elif grade >= 16:
    print("Grade 16+")

else:
    print(f"Grade {grade}")
