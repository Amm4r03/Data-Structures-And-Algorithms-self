# implements linear search in python lists (array)

inp = 'hello i am going to implement linear search in an array in python'

array = list(inp.split(" "))
print(array)

key = input("enter a key to be searched in the array : ")

keyFound = False
for index, element in enumerate(array):
    if element == key:
        keyFound = True
        print("Found key ({}) at index {}".format(key, index))
        break

if not keyFound:
    print(f"key ({key}) not found in the array")