
doubleStack = [20]

def push(doubleStack, stackPosition, val):
    if stackPosition == 'top':
        # add to top stack
        doubleStack.append(val)
    else:
        # add to bottom stack
        doubleStack.prepend(val)

def pop(doubleStack, stackPosition):
    if stackPosition == 'top':
        return doubleStack.pop() # remove the last element and return it
    return doubleStack.remove(0) # remove the first element and return it


push(doubleStack, "top", 5)
push(doubleStack, "top", 10)
push(doubleStack, "bottom", 3)
push(doubleStack, "bottom", -8)
print(pop(doubleStack, "bottom"))
print(pop(doubleStack, "bottom"))
print(pop(doubleStack, "bottom"))
print(pop(doubleStack, "top"))



10

====================


Console: -8
3
10
5

