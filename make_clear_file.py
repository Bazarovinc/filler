f = "text.txt"
with open(f, 'r') as fo:
    lines = fo.readlines()

n_f = "file.txt"
file = open(n_f, 'w')
i = 1
file.write(lines[0])
flag = True
while i < len(lines):
    if 'Plateau ' in lines[i]:
        line_s = lines[i].split()
        map_size = int(line_s[1])
        for j in range(map_size + 2):
            if flag:
                file.write(lines[i])
            i += 1
        if flag:
            print('map', i)
    if 'Piece ' in lines[i]:
        s_line = lines[i].split()
        p_size = int(s_line[1])
        piece = []
        for k in range(p_size + 1):
            piece.append(lines[i])
            i += 1
        if '<got (O): [0, 0]' in lines[i]:
            for p in piece:
                file.write(p)
        elif '<got (O): ' in lines[i]:
            for p in piece:
                file.write(p)
            print('piece', i)
            flag = False
        elif '<got (X): ' in lines[i]:
            flag = True
        i += 1
    if '==' in lines[i]:
        i += 1
