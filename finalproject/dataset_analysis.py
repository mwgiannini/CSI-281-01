num_entries = 0
longest = ["", 0]
characters_used = ""

with open("codes.txt") as file:
    while True:
        line = file.readline()
        if not line:
            break
        num_entries += 1
        [word, code] = line.split()
        if len(word) > longest[1]:
            longest[0] = word
            longest[1] = len(word)
        for character in word:
            if character not in characters_used:
                characters_used += character

print(f"The dataset contains {num_entries} entries")
print(f"The longest word is {longest}")
print(f"Characters used in the dataset: {characters_used}")