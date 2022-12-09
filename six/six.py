data = open("input.txt").read()

#PART 1
for i in range(0,len(data)):
    if len(set(data[i:i+4])) == 4:
        break
print(i+4, data[i:i+4], len(set(data[i:i+4])))

#PART 2
for i in range(0,len(data)):
    if len(set(data[i:i+14])) == 14:
        break
print(i+14, data[i:i+14], len(set(data[i:i+14])))