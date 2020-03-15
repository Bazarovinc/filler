run = True
f = open('text.txt', 'w')
while run:
    try:
        s = input()
    except EOFError:
        run = False
    f.write(s + '\n')
f.close()